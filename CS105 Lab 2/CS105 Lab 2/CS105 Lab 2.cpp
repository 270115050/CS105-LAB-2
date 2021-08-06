// CS105 Lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Player.h"
#include "ClassHeroes.h"

int main()
{
    vector <Warrior> warrior;
    vector <Priest> priest;
    vector <Mage> mage;
    Warrior w;
    Priest p;
    Mage m;
    int choice, choice2;
    Race r;

    do {
        cout << "\tCHARACTER CREATION"
            << "\n\nWhich of the following would you like?"
            << "\n\n\t1. Create a Warrior!"
            << "\n\t2. Create a Priest!"
            << "\n\t3. Create a Mage!"
            << "\n\t4. Finish creating player characters!"
            << "\n\tChoose options: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "\n\n\nWhich race do you want?"
                << "\n\n\t1. Human!"
                << "\n\t2. Elf!"
                << "\n\t3. Dwarf!"
                << "\n\t4. Orc!"
                << "\n\t5. Troll!"
                << "\n\tChoose options: ";
            cin >> choice2;

            switch (choice2) {
            case 1:
                r = HUMAN;
                break;
            case 2:
                r = ELF;
                break;
            case 3:
                r = DWARF;
                break;
            case 4:
                r = ORC;
                break;
            case 5:
                r = TROLL;
                break;
            default:
                r = DEFAULT;
                break;
            }
        }        
      
        switch (choice) {
        case 1:
            w.setRace(r);
            w.setName();
            warrior.push_back(w);
            cout << "\n\n\tCharacter has been successfully created!!\n";
            break;
        case 2:
            p.setRace(r);
            p.setName();
            priest.push_back(p);
            cout << "\n\n\tCharacter has been successfully created!!\n";
            break;
        case 3:
            m.setRace(r);
            m.setName();
            mage.push_back(m);
            cout << "\n\n\tCharacter has been successfully created!!\n";
            break;
        case 4:
            cout << "\n\tExiting character creation... ";
            break;
        default:
            cout << "\n\tInvalid Input, Please try again..";
            break;
        }
        
        system("pause");
        system("cls");
    } while (choice != 4);

    cout << "\n-------------"
        << "\nWARRIOR LIST:"
        << "\n-------------";
    for (int i = 0; i < warrior.size(); i++) {
        cout << "\nIm a warrior with name " << warrior[i].getName() << " and with race " << warrior[i].whatRace() << warrior[i].attack();
    }
    cout << "\n-------------"
        << "\nPRIEST LIST:"
        << "\n-------------";
    for (int i = 0; i < priest.size(); i++) {
        cout << "\nIm a priest with name " << priest[i].getName() << " and with race " << priest[i].whatRace() << priest[i].attack();
    }
    cout << "\n-------------"
        << "\nMage LIST:"
        << "\n-------------";
    for (int i = 0; i < mage.size(); i++) {
        cout << "\nIm a mage with name " << mage[i].getName() << " and with race " << mage[i].whatRace() << mage[i].attack();
    }
    return 0;
}

