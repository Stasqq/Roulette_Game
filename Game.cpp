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
    cout<< "5. Show bets" <<endl;
    cout<< "6. Delete player" <<endl;
    cout<< "7. Delete bet" <<endl;
    cout<< "8. Load player from file" <<endl;
    cout<< "9. Save player to file" <<endl;
    cout<< "10. Tests" <<endl;
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
            for(int i=0;i<playersNumber;i++){
                players.getByIndex(i)->checkBets(random);
                players.getByIndex(i)->clearBets();
            }
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
                cout<<"How much money would you like to bet? (You have: "<<players.getByIndex(which)->getMoney()<<")"<<endl;
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
                        int c;
                        cout<< "Which column would you like to bet: [1-3]" <<endl;
                        cin>>c;
                        int *tab=(int*)malloc(12* sizeof(int));
                        tab[0]=1+(c-1);
                        tab[1]=4+(c-1);
                        tab[2]=7+(c-1);
                        tab[3]=10+(c-1);
                        tab[4]=13+(c-1);
                        tab[5]=16+(c-1);
                        tab[6]=19+(c-1);
                        tab[7]=22+(c-1);
                        tab[8]=25+(c-1);
                        tab[9]=28+(c-1);
                        tab[10]=31+(c-1);
                        tab[11]=34+(c-1);
                        players.getByIndex(which)->addBet(money,column,tab,12);
                    }break;
                    case 12:{
                        int c;
                        cout<< "Which sixline would you like to bet: [1-11]" <<endl;
                        cin>>c;
                        int *tab=(int*)malloc(6* sizeof(int));
                        tab[0]=1+3*(c-1);
                        tab[1]=2+3*(c-1);
                        tab[2]=3+3*(c-1);
                        tab[3]=4+3*(c-1);
                        tab[4]=5+3*(c-1);
                        tab[5]=6+3*(c-1);
                        players.getByIndex(which)->addBet(money,sixLine,tab,6);
                    }break;
                    case 13:{
                        int c;
                        cout<< "Which corner would you like to bet: [1-22]" <<endl;
                        cin>>c;
                        int *tab=(int*)malloc(4* sizeof(int));
                        if(c%2 == 1){
                            tab[0]=1+3*(c-1)/2;
                            tab[1]=2+3*(c-1)/2;
                            tab[2]=4+3*(c-1)/2;
                            tab[3]=5+3*(c-1)/2;
                            players.getByIndex(which)->addBet(money,cornerBet,tab,4);
                        }else{
                            tab[0]=2+3*(c-1)/2;
                            tab[1]=3+3*(c-1)/2;
                            tab[2]=5+3*(c-1)/2;
                            tab[3]=6+3*(c-1)/2;
                            players.getByIndex(which)->addBet(money,cornerBet,tab,4);
                        }
                    }break;
                    case 14:{
                        int c;
                        cout<< "Which line would you like to bet: [1-12]" <<endl;
                        cin>>c;
                        int *tab=(int*)malloc(3* sizeof(int));
                        tab[0]=1+3*(c-1);
                        tab[1]=2+3*(c-1);
                        tab[2]=3+3*(c-1);
                        players.getByIndex(which)->addBet(money,line,tab,3);
                    }break;
                    case 15:{
                        int c1,c2;
                        cout<< "Which numbers to split would you like to bet: " <<endl;
                        cin>>c1;
                        cin>>c2;
                        int *tab=(int*)malloc(2* sizeof(int));
                        tab[0]=c1;
                        tab[1]=c2;
                        players.getByIndex(which)->addBet(money,split,tab,2);
                    }break;
                    case 16:{
                        int number;
                        cout<<"What number would you like to bet? [0-36]"<<endl;
                        cin>>number;
                        int *tab=(int*)malloc(1* sizeof(int));
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
            int which;
            for(int i=0;i<playersNumber;i++){
                cout<<i+1<<". "<< players.getByIndex(i)->getName() <<endl;
            }
            cout<<"\t0. Exit"<<endl;
            cin>>which;
            if(which != 0){
                which=which-1;
                cout<< players.getByIndex(which)->showBets();
            }
        }break;
        case 6:{
            int which;
            for(int i=0;i<playersNumber;i++){
                cout<<i+1<<". "<< players.getByIndex(i)->getName() <<endl;
            }
            cout<<"\t0. Exit"<<endl;
            cin>>which;
            if(which != 0){
                which--;
                players.deleteByIndex(which);
                playersNumber--;
            }
        }break;
        case 7:{
            int which;
            for(int i=0;i<playersNumber;i++){
                cout<<i+1<<". "<< players.getByIndex(i)->getName() <<endl;
            }
            cout<<"\t0. Exit"<<endl;
            cin>>which;
            if(which != 0){
                which--;
                int betNr;
                cout<<"Which bet would you like to delete?"<<endl;
                cout<< players.getByIndex(which)->showBets();
                cout<<"\t0. Exit"<<endl;
                cin>>betNr;
                if(betNr != 0){
                    betNr--;
                    players.getByIndex(which)->deleteBet(betNr);
                }
            }
        }break;
        case 8:{
            string name;
            cout<<"Whats the name of new player?\n";
            cin>>name;
            std::fstream f;
            name+=".txt";
            f.open(name,std::ios::in);
            if(f.good()){
                string pName;
                int money;
                f>>pName;
                f>>money;
                Player nP;
                nP=Player();
                nP.setName(pName);
                nP.addMoney(money);
                playersNumber++;
                players.pushBack(nP);
                while(!f.eof()){
                    int bt;
                    enum betType typ;
                    int nrFields,m;
                    f>>bt;
                    switch(bt){
                        default:{}break;
                        case 1:{typ=red;}break;
                        case 2:{typ=black;}break;
                        case 3:{typ=st18;}break;
                        case 4:{typ=nd18;}break;
                        case 5:{typ=even;}break;
                        case 6:{typ=odd;}break;
                        case 7:{typ=stDozen;}break;
                        case 8:{typ=ndDozen;}break;
                        case 9:{typ=rdDozen;}break;
                        case 10:{typ=stFour;}break;
                        case 11:{typ=column;}break;
                        case 12:{typ=sixLine;}break;
                        case 13:{typ=cornerBet;}break;
                        case 14:{typ=line;}break;
                        case 15:{typ=split;}break;
                        case 16:{typ=straight;}break;
                    }
                    f>>m;
                    f>>nrFields;
                    if(nrFields != 0){
                        int *tab=(int*)malloc(nrFields* sizeof(int));
                        for(int i=0;i<nrFields;i++){
                            f>>tab[i];
                        }
                        players.getByIndex(playersNumber-1)->addBet(m,typ,tab,nrFields);
                        players.getByIndex(playersNumber-1)->addMoney(m);
                    }else{
                        players.getByIndex(playersNumber-1)->addBet(m,typ);
                        players.getByIndex(playersNumber-1)->addMoney(m);

                    }
                }
            }else{
                cout<<"Error, with file!"<<endl;
            }
            f.close();
        }break;
        case 9:{
            int which;
            for(int i=0;i<playersNumber;i++){
                cout<<i+1<<". "<< players.getByIndex(i)->getName() <<endl;
            }
            cout<<"\t0. Exit"<<endl;
            cin>>which;
            if(which != 0){
                which--;
                std::fstream f;
                f.open(players.getByIndex(which)->getName()+".txt",std::ios::out);
                if(f.good()){
                    f<<players.getByIndex(which)->getName()<<"\n";
                    f<<players.getByIndex(which)->getMoney()<<"\n";
                    for(int i=0;i<players.getByIndex(which)->getBetsSize();i++){
                        players.getByIndex(which)->getBet(i)->saveToFile(&f);
                        if(i != players.getByIndex(which)->getBetsSize()-1)
                            f<<"\n";
                    }
                    cout<<"Player is saved in file: "<<players.getByIndex(which)->getName()<<".txt\n";
                    int x;
                    cout<<"Would you like to delete him from this game?\n1.Yes\n2.No\n";
                    cin>>x;
                    if(x==1){
                        players.deleteByIndex(which);
                        playersNumber--;
                    }
                }else{
                    cout<<"Error, with file!"<<endl;
                }

                f.close();
            }
        }break;
        case 10:{

        }break;
    }
}

void Game::run() {
    int end;
    cout << "Let's start the game!" << endl;
    while(true){
        end=printMenu();
        menuSwitch(end);
        if(end == 0)
            return;
        cout << "\tPress enter" << endl;
        getchar();
        getchar();
    }
}