//
// Created by Stasiek on 2018-12-16.
//

#include "Game.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Game::Game() {
    playersNumber = 0;
    roulette = Roulette();
    players = CyclicList<Player>();
}

int Game::whichPlayer() {
    int which;
    for (int i = 0; i < playersNumber; i++) {
        cout << i + 1 << ". " << players.getByIndex(i)->getName() << endl;
    }
    cout << "\t0. Exit" << endl;
    cin >> which;
    return which;
}

int Game::printMenu() {
    int output;

    cout << "====================================================" << endl;
    cout << "1. Spin roulette" << endl;
    cout << "2. Add player" << endl;
    cout << "3. Add bet" << endl;
    cout << "4. Show money" << endl;
    cout << "5. Show bets" << endl;
    cout << "6. Delete player" << endl;
    cout << "7. Delete bet" << endl;
    cout << "8. Load player from file" << endl;
    cout << "9. Save player to file" << endl;
    cout << "10. Tests" << endl;
    cout << "\t 0. Exit" << endl;
    cout << "====================================================" << endl;

    cin >> output;

    return output;
}

void Game::menuSwitch(int x) {
    switch (x) {
        default: {
        }
            break;
        case 0: {
        }
            break;
        case 1: {
            rouletteSpin();
        }
            break;
        case 2: {
            string name;
            int money;
            cout << "Enter name of new player: " << endl;
            cin >> name;
            cout << "How much money for start: " << endl;
            cin >> money;
            addPlayer(name,money);
        }
            break;
        case 3: {
            int which=whichPlayer();
            if(which != 0){
                which--;
                addBet(players.getByIndex(which));
            }
        }
            break;
        case 4: {
            int which=whichPlayer();
            if(which != 0){
                which--;
                cout<<showMoney(players.getByIndex(which));
            }
        }
            break;
        case 5: {
            int which=whichPlayer();
            if(which != 0){
                which--;
                cout<<showBets(players.getByIndex(which));
            }
        }
            break;
        case 6: {
            int which=whichPlayer();
            if(which != 0){
                which--;
                players.deleteByIndex(which);
                playersNumber--;
            }
        }
            break;
        case 7: {
            int which=whichPlayer();
            if(which != 0){
                which--;
                deleteBet(players.getByIndex(which));
            }
        }
            break;
        case 8: {
            string name;
            cout << "Whats the name of new player?\n";
            cin >> name;
            load(name);
        }
            break;
        case 9: {
            int which=whichPlayer();
            if(which != 0){
                which--;
                save(players.getByIndex(which));
            }
        }
            break;
        case 10: {
            tests();
        }
            break;
    }
}

void Game::run() {
    int end;
    cout << "Let's start the game!" << endl;
    while (true) {
        end = printMenu();
        menuSwitch(end);
        if (end == 0)
            return;
        cout << "\tPress enter" << endl;
        getchar();
        getchar();
    }
}

void Game::rouletteSpin() {
    Component *random;
    random = roulette.draw();
    cout << "It's: " << random->getColor() << " " << random->getValue() << endl;
    for (int i = 0; i < playersNumber; i++) {
        players.getByIndex(i)->checkBets(random);
        players.getByIndex(i)->clearBets();
    }
}

void Game::addPlayer(std::string name,int money) {
    Player nP;
    nP.addMoney(money);
    nP.setName(name);
    playersNumber++;
    players.pushBack(nP);
}

void Game::addBet(Player *player) {
        int money;
        int bt;
        cout << "How much money would you like to bet? (You have: " << player->getMoney() << ")"
             << endl;
        do {
            cin >> money;
        } while (money > player->getMoney());
        cout << "What type of bet?" << endl;
        cout << "1. Red" << endl;
        cout << "2. Black" << endl;
        cout << "3. 1st 18" << endl;
        cout << "4. 2nd 18" << endl;
        cout << "5. Even" << endl;
        cout << "6. Odd" << endl;
        cout << "7. 1st dozen" << endl;
        cout << "8. 2nd dozen" << endl;
        cout << "9. 3rd dozen" << endl;
        cout << "10. 1st four numbers" << endl;
        cout << "11. Column" << endl;
        cout << "12. Six line" << endl;
        cout << "13. Corner bet" << endl;
        cout << "14. Line" << endl;
        cout << "15. Split" << endl;
        cout << "16. Straight" << endl;
        cout << "\t0. Exit" << endl;
        cin >> bt;
        switch (bt) {
            default: {
            }
                break;
            case 0: {
            }
                break;
            case 1: {
                player->addBet(money, red);
            }
                break;
            case 2: {
                player->addBet(money, black);
            }
                break;
            case 3: {
                player->addBet(money, st18);
            }
                break;
            case 4: {
                player->addBet(money, nd18);
            }
                break;
            case 5: {
                player->addBet(money, even);
            }
                break;
            case 6: {
                player->addBet(money, odd);
            }
                break;
            case 7: {
                player->addBet(money, stDozen);
            }
                break;
            case 8: {
                player->addBet(money, ndDozen);
            }
                break;
            case 9: {
                player->addBet(money, rdDozen);
            }
                break;
            case 10: {
                player->addBet(money, stFour);
            }
                break;
            case 11: {
                int c;
                cout << "Which column would you like to bet: [1-3]" << endl;
                cin >> c;
                int *tab = (int *) malloc(12 * sizeof(int));
                tab[0] = 1 + (c - 1);
                tab[1] = 4 + (c - 1);
                tab[2] = 7 + (c - 1);
                tab[3] = 10 + (c - 1);
                tab[4] = 13 + (c - 1);
                tab[5] = 16 + (c - 1);
                tab[6] = 19 + (c - 1);
                tab[7] = 22 + (c - 1);
                tab[8] = 25 + (c - 1);
                tab[9] = 28 + (c - 1);
                tab[10] = 31 + (c - 1);
                tab[11] = 34 + (c - 1);
                player->addBet(money, column, tab, 12);
            }
                break;
            case 12: {
                int c;
                cout << "Which sixline would you like to bet: [1-11]" << endl;
                cin >> c;
                int *tab = (int *) malloc(6 * sizeof(int));
                tab[0] = 1 + 3 * (c - 1);
                tab[1] = 2 + 3 * (c - 1);
                tab[2] = 3 + 3 * (c - 1);
                tab[3] = 4 + 3 * (c - 1);
                tab[4] = 5 + 3 * (c - 1);
                tab[5] = 6 + 3 * (c - 1);
                player->addBet(money, sixLine, tab, 6);
            }
                break;
            case 13: {
                int c;
                cout << "Which corner would you like to bet: [1-22]" << endl;
                cin >> c;
                int *tab = (int *) malloc(4 * sizeof(int));
                if (c % 2 == 1) {
                    tab[0] = 1 + 3 * (c - 1) / 2;
                    tab[1] = 2 + 3 * (c - 1) / 2;
                    tab[2] = 4 + 3 * (c - 1) / 2;
                    tab[3] = 5 + 3 * (c - 1) / 2;
                    player->addBet(money, cornerBet, tab, 4);
                } else {
                    tab[0] = 2 + 3 * (c - 1) / 2;
                    tab[1] = 3 + 3 * (c - 1) / 2;
                    tab[2] = 5 + 3 * (c - 1) / 2;
                    tab[3] = 6 + 3 * (c - 1) / 2;
                    player->addBet(money, cornerBet, tab, 4);
                }
            }
                break;
            case 14: {
                int c;
                cout << "Which line would you like to bet: [1-12]" << endl;
                cin >> c;
                int *tab = (int *) malloc(3 * sizeof(int));
                tab[0] = 1 + 3 * (c - 1);
                tab[1] = 2 + 3 * (c - 1);
                tab[2] = 3 + 3 * (c - 1);
                player->addBet(money, line, tab, 3);
            }
                break;
            case 15: {
                int c1, c2;
                cout << "Which numbers to split would you like to bet: " << endl;
                cin >> c1;
                cin >> c2;
                int *tab = (int *) malloc(2 * sizeof(int));
                tab[0] = c1;
                tab[1] = c2;
                player->addBet(money, split, tab, 2);
            }
                break;
            case 16: {
                int number;
                cout << "What number would you like to bet? [0-36]" << endl;
                cin >> number;
                int *tab = (int *) malloc(1 * sizeof(int));
                tab[0] = number;
                player->addBet(money, straight, tab, 1);
            }
                break;
        }

}


std::string Game::showMoney(Player* player) {
    string output;
    output="Player "+player->getName()+" has " + std::to_string(player->getMoney())+" money"+"\n";
    return output;
}

std::string Game::showBets(Player* player) {
    string output;
    output=player->showBets();
    return output;
}

void Game::deleteBet(Player* player) {
        int betNr;
        cout << "Which bet would you like to delete?" << endl;
        cout << player->showBets();
        cout << "\t0. Exit" << endl;
        cin >> betNr;
        if (betNr != 0) {
            betNr--;
            player->deleteBet(betNr);
        }
}

void Game::load(std::string name) {
    std::fstream f;
    name += ".txt";
    f.open(name, std::ios::in);
    if (f.good()) {
        string pName;
        int money;
        f >> pName;
        f >> money;
        Player nP;
        nP = Player();
        nP.setName(pName);
        nP.addMoney(money);
        playersNumber++;
        players.pushBack(nP);
        while (!f.eof()) {
            int bt;
            enum betType typ;
            int nrFields, m;
            f >> bt;
            switch (bt) {
                default: {
                }
                    break;
                case 1: {
                    typ = red;
                }
                    break;
                case 2: {
                    typ = black;
                }
                    break;
                case 3: {
                    typ = st18;
                }
                    break;
                case 4: {
                    typ = nd18;
                }
                    break;
                case 5: {
                    typ = even;
                }
                    break;
                case 6: {
                    typ = odd;
                }
                    break;
                case 7: {
                    typ = stDozen;
                }
                    break;
                case 8: {
                    typ = ndDozen;
                }
                    break;
                case 9: {
                    typ = rdDozen;
                }
                    break;
                case 10: {
                    typ = stFour;
                }
                    break;
                case 11: {
                    typ = column;
                }
                    break;
                case 12: {
                    typ = sixLine;
                }
                    break;
                case 13: {
                    typ = cornerBet;
                }
                    break;
                case 14: {
                    typ = line;
                }
                    break;
                case 15: {
                    typ = split;
                }
                    break;
                case 16: {
                    typ = straight;
                }
                    break;
            }
            f >> m;
            f >> nrFields;
            if (nrFields != 0) {
                int *tab = (int *) malloc(nrFields * sizeof(int));
                for (int i = 0; i < nrFields; i++) {
                    f >> tab[i];
                }
                players.getByIndex(playersNumber - 1)->addBet(m, typ, tab, nrFields);
                players.getByIndex(playersNumber - 1)->addMoney(m);
            } else {
                players.getByIndex(playersNumber - 1)->addBet(m, typ);
                players.getByIndex(playersNumber - 1)->addMoney(m);

            }
        }
    } else {
        cout << "Error, with file!" << endl;
    }
    f.close();
}

void Game::save(Player* player) {
        std::fstream f;
        f.open(player->getName() + ".txt", std::ios::out);
        if (f.good()) {
            f << player->getName() << "\n";
            f << player->getMoney() << "\n";
            for (int i = 0; i < player->getBetsSize(); i++) {
                player->getBet(i)->saveToFile(&f);
                if (i != player->getBetsSize() - 1)
                    f << "\n";
            }
        } else {
            cout << "Error, with file!" << endl;
        }

        f.close();
}

void Game::tests() {
    cout<<"Autonomic test or manual?"<<endl;
    cout<<"1. Autonomic\n2.Manual"<<endl;
    cout << "\t0. Exit" << endl;
    int choice;
    cin>>choice;
    if(choice != 0){
        Tests t;
        t=Tests();
        if(choice == 1){
            if(t.autonomicTest())
                cout<<"Program works well =)"<<endl;
            else
                cout<<"There are some errors!"<<endl;
        }else{

        }
    }
}

int Game::getPlayersNumber(){
    return playersNumber;
}

CyclicList<Player>* Game::getPlayersList(){
    return &players;
}
