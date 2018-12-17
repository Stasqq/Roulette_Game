//
// Created by Stasiek on 2018-12-16.
//

#include "Game.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Game::Game() {
    playersNumber=0;
    roulette=Roulette();
    players=CyclicList<Player>();
}

int Game::printMenu() {
    int output;

    cout<< "====================================================" <<endl;
    cout<< "1. Spin roulette" <<endl;
    cout<< "2. Add player" <<endl;
    cout<< "3. Add bet" <<endl;
    cout<< "4. Show money" <<endl;
    cout<< "5. Delete player" <<endl;
    cout<< "6. Load game from file" <<endl;
    cout<< "7. Save game to file" <<endl;
    cout<< "8. Tests" <<endl;
    cout<< "\t 0. Exit" <<endl;
    cout<< "====================================================" <<endl;

    cin >> output;

    return output;
}

void Game::menuSwitch(int x) {
    switch(x){
        default:{
        }break;
        case 0:{
        }break;
        case 1:{
            Component* random;
            random=roulette.draw();
            cout<<"It's: "<< random->getColor() << " " << random->getValue() <<endl;

            //TODO::DONT KNOW WHY IT DONT CHECK BETS,DONT EVEN GO TO FUNCTION!!!!!!!!!!!!!!GRRRRRRRRRRRRRRRRRR
        }break;
        case 2:{
            string name;
            int money;
            cout<< "Enter name of new player: "<<endl;
            cin>>name;
            cout<< "How much money for start: "<<endl;
            cin>>money;
            Player nP;
            nP.addMoney(money);
            nP.setName(name);
            playersNumber++;
            players.pushBack(nP);
        }break;
        case 3:{
            int which;
            for(int i=0;i<playersNumber;i++){
                cout<<i+1<<". "<< players.getByIndex(i)->getName() <<endl;
            }
            cout<<"\t0. Exit"<<endl;
            cin>>which;
            if(which != 0){
                which=which-1;
                int money;
                int bt;
                cout<<"How much money would you like to bet?"<<endl;
                do{
                    cin >> money;
                }while(money > players.getByIndex(which)->getMoney());
                cout<<"What type of bet?"<<endl;
                cout<<"1. Red"<<endl;
                cout<<"2. Black"<<endl;
                cout<<"3. 1st 18"<<endl;
                cout<<"4. 2nd 18"<<endl;
                cout<<"5. Even"<<endl;
                cout<<"6. Odd"<<endl;
                cout<<"7. 1st dozen"<<endl;
                cout<<"8. 2nd dozen"<<endl;
                cout<<"9. 3rd dozen"<<endl;
                cout<<"10. 1st four numbers"<<endl;
                cout<<"11. Column"<<endl;
                cout<<"12. Six line"<<endl;
                cout<<"13. Corner bet"<<endl;
                cout<<"14. Line"<<endl;
                cout<<"15. Split"<<endl;
                cout<<"16. Straight"<<endl;
                cout<<"\t0. Exit"<<endl;
                cin>>bt;
                switch(bt){
                    default: {
                    }break;
                    case 0:{
                    }break;
                    case 1:{
                        players.getByIndex(which)->addBet(money,red);
                    }break;
                    case 2:{
                        players.getByIndex(which)->addBet(money,black);
                    }break;
                    case 3:{
                        players.getByIndex(which)->addBet(money,st18);
                    }break;
                    case 4:{
                        players.getByIndex(which)->addBet(money,nd18);
                    }break;
                    case 5:{
                        players.getByIndex(which)->addBet(money,even);
                    }break;
                    case 6:{
                        players.getByIndex(which)->addBet(money,odd);
                    }break;
                    case 7:{
                        players.getByIndex(which)->addBet(money,stDozen);
                    }break;
                    case 8:{
                        players.getByIndex(which)->addBet(money,ndDozen);
                    }break;
                    case 9:{
                        players.getByIndex(which)->addBet(money,rdDozen);
                    }break;
                    case 10:{
                        players.getByIndex(which)->addBet(money,stFour);
                    }break;
                    case 11:{

                    }break;
                    case 12:{

                    }break;
                    case 13:{

                    }break;
                    case 14:{

                    }break;
                    case 15:{

                    }break;
                    case 16:{
                        int number;
                        cout<<"What number would you like to bet? [0-36]"<<endl;
                        cin>>number;
                        int tab[1];
                        tab[0]=number;
                        players.getByIndex(which)->addBet(money,straight,tab,1);
                    }break;
                }
            }
        }break;
        case 4:{
            int which;
            for(int i=0;i<playersNumber;i++){
                cout<<i+1<<". "<< players.getByIndex(i)->getName() <<endl;
            }
            cout<<"\t0. Exit"<<endl;
            cin>>which;
            if(which != 0){
                which=which-1;
                cout<< "Player " <<players.getByIndex(which)->getName()<< " has " << players.getByIndex(which)->getMoney()<<" money"<<endl;
            }
        }break;
        case 5:{

        }break;
        case 6:{

        }break;
        case 7:{

        }break;
        case 8:{

        }break;
    }
}

void Game::run() {
    int end;
    cout << "Let's start the game!" << endl;
    do{
        end=printMenu();
        menuSwitch(end);
        cout << "\tPress enter" << endl;
        getchar();
        getchar();
    }while(end != 0);

}