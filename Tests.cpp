//
// Created by Stasiek on 2018-12-18.
//

#include "Tests.h"

bool Tests::spinTest() {
    Roulette r;
    r = Roulette();
    Component *com;
    com = r.draw();
    if (com->getValue() >= 0 && com->getValue() <= 36 && (com->getColor() == "red" || com->getColor() == "black")) {
        std::cout << "spinTest - OK" << std::endl;
        return true;
    }
    std::cout << "spinTest - ERROR" << std::endl;
    return false;
}

bool Tests::addPlayerTest() {
    Game g;
    g = Game();
    g.addPlayer("TestAdd", 1);
    if (g.getPlayersList()->size() == 1) {
        std::cout << "addPlayerTest - OK" << std::endl;
        return true;
    }
    std::cout << "addPlayerTest - ERROR" << std::endl;
    return false;
}

bool Tests::deletePlayerTest() {
    Game g;
    g = Game();
    g.addPlayer("TestAdd", 1);
    CyclicList<Player> *list = g.getPlayersList();
    if (list->size() == 1) {
        list->deleteByIndex(0);
        if (list->size() == 0) {
            std::cout << "deletePlayerTest - OK" << std::endl;
            return true;
        }
        std::cout << "deletePlayerTest - ERROR" << std::endl;
        return false;
    }
    std::cout << "deletePlayerTest - ERROR" << std::endl;
    return false;
}

bool Tests::addBetTest() {
    Player p;
    p.addBet(20, red);
    int *tab = (int *) malloc(3 * sizeof(int));
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    p.addBet(12, line, tab, 3);
    if (p.getBetsSize() == 2) {
        std::cout << "addBetTest - OK" << std::endl;
        return true;
    }
    std::cout << "addBetTest - ERROR" << std::endl;
    return false;
}

bool Tests::deleteBetTest() {
    Player p;
    p.addBet(20, red);
    int *tab = (int *) malloc(3 * sizeof(int));
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    p.addBet(12, line, tab, 3);
    if (p.getBetsSize() == 2) {
        p.deleteBet(0);
        if (p.getBetsSize() == 1) {
            std::cout << "deletePlayerTest - OK" << std::endl;
            return true;
        }
        std::cout << "deleteBetTest - ERROR" << std::endl;
        return false;
    }
    std::cout << "deleteBetTest - ERROR" << std::endl;
    return false;
}

bool Tests::showMoneyTest() {
    Player p;
    p.addMoney(1111);
    p.setName("none");
    Game g;
    if (g.showMoney(&p) == "Player none has 1111 money\n") {
        std::cout << "showMoneyTest - OK" << std::endl;
        return true;
    }
    std::cout << "showMoneyTest - ERROR" << std::endl;
    return false;
}

bool Tests::saveAndLoadTest() {
    Game in;
    in.addPlayer("test", 100);
    in.save(in.getPlayersList()->getByIndex(0));
    Game out;
    out.load("test");
    if (out.getPlayersList()->getByIndex(0)->getMoney() == in.getPlayersList()->getByIndex(0)->getMoney() &&
        out.getPlayersList()->getByIndex(0)->getName() == in.getPlayersList()->getByIndex(0)->getName()) {
        std::cout << "saveAndLoadTest - OK" << std::endl;
        return true;
    }
    std::cout << "saveAndLoadTest - ERROR" << std::endl;
    return false;
}

bool Tests::autonomicTest() {
    bool output;
    output =
            spinTest() && addPlayerTest() && addBetTest() && showMoneyTest() && deletePlayerTest() && deleteBetTest() &&
            saveAndLoadTest();
    return output;
}