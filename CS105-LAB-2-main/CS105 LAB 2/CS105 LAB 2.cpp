//Programmers:			Jay Anino   
//Student ID:			270115050
//School:				Yoobee College
//Due Date:				14/08/2021
//Project Name:    	    CS105 Lab2
//Project Description:  Develop an RPG where user can create characters by choosing there race and classes.
//                      In this project I took some liberty to change some of the output of the program but it still follows the project guide lines.

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
#include "Player.h"
#include "ClassType.h"

int main()
{
    vector <Warrior> warrior;
    vector <Priest> priest;
    vector <Mage> mage;    
    Race r;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int choice, choice2;
    bool isTrue, isTrue2;
    
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);//Maximize window

    do {//choose class
        Warrior w;
        Priest p;
        Mage m;
        cout << "\n\t\t\t" << w.getHitPoints() << "\n\t\t\t";

        isTrue = true, isTrue2 = true;     
        choice = 0, choice2 = 0;
        cout << "\n\t\t|----------------------------------------------|"
             << "\n\t\t|            CHARACTER CREATION                |"
             << "\n\t\t|----------------------------------------------|"
             << "\n\t\t| Which of the following would you like?       |"
             << "\n\t\t| Press 1 Create a Warrior!                    |"
             << "\n\t\t| Press 2 Create a Priest!                     |"
             << "\n\t\t| Press 3 Create a Mage!                       |"
             << "\n\t\t| Press 4 Finish creating player characters!   |"
             << "\n\t\t|----------------------------------------------|"
             << "\n\t\t| Choose options: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) { //if user enters 4 dont ask for race
            do {//choose race               
                cout << "\n\t\t|--------------------------------|"
                     << "\n\t\t| Which race do you want?        |"
                     << "\n\t\t|--------------------------------|"
                     << "\n\t\t| Press 1 Human! (+30HP, +30HP)  |"
                     << "\n\t\t| Press 2 Elf!   (+20HP, +40HP)  |"
                     << "\n\t\t| Press 3 Dwarf! (+40HP, +20HP)  |"
                     << "\n\t\t| Press 4 Orc!   (+50HP, +10HP)  |"
                     << "\n\t\t| Press 5 Troll! (+60HP, +0HP)   |"
                     << "\n\t\t| Press 6 Go back                |"
                     << "\n\t\t|--------------------------------|"
                     << "\n\t\t| Choose options: ";
                cin >> choice2;

                switch (choice2) {
                case 1:
                    r = HUMAN;
                    isTrue2 = false;
                    break;
                case 2:
                    r = ELF;
                    isTrue2 = false;
                    break;
                case 3:
                    r = DWARF;
                    isTrue2 = false;
                    break;
                case 4:
                    r = ORC;
                    isTrue2 = false;
                    break;
                case 5:
                    r = TROLL;
                    isTrue2 = false;
                    break;
                case 6:
                    cout << "\n\t\t";
                    r = DEFAULT;
                    isTrue2 = false;
                    break;
                default:
                    cout << "\n\t\tInvalid Input, Please try again...\n";
                    break;
                }             
            } while (isTrue2);
        }

        if (choice2 != 6) { // if user didn't chooce race then dont create character
            switch (choice) {
            case 1:
                w = w.createCharacter(r, w);
                warrior.push_back(w);
                cout << "\n\n\t\tCharacter has been successfully created!!\n\t\t";
                break;
            case 2:
                p = p.createCharacter(r, p);
                priest.push_back(p);
                cout << "\n\n\t\tCharacter has been successfully created!!\n\t\t";
                break;
            case 3:
                m = m.createCharacter(r, m);
                mage.push_back(m);
                cout << "\n\n\t\tCharacter has been successfully created!!\n\t\t";
                break;
            case 4:
                cout << "\n\t\tExiting character creation...\n\t\t";
                isTrue = false;
                break;
            default:
                cout << "\n\t\tInvalid Input, Please try again..\n\t\t";
                break;
            }
        }     
        system("pause");
        system("cls");
    } while (isTrue);

    cout << "\n\t\t|--------------------|"
         << "\n\t\t|    WARRIOR LIST    |"
         << "\n\t\t|--------------------|\n\n";
    for (int i = 0; i < warrior.size(); i++) {
        cout << "\n\t\t<||>'''''''''''''''''''''''''''''''''''''''''''''''<||>"
             << "\n\t\t<||>Name: " << warrior[i].getName()
             << "\n\t\t<||>Race: " << warrior[i].whatRace() << "\n\t\t<||>";
        SetConsoleTextAttribute(h, 12);
        cout << "HP:  " << warrior[i].getHitPoints();
        SetConsoleTextAttribute(h, 7); //change text colour
        cout << "\n\t\t<||>";
        SetConsoleTextAttribute(h, 11);
        cout << "MP:  " << warrior[i].getMagicPoints();
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t<||> " << warrior[i].attack()
            << "\n\t\t<||>'''''''''''''''''''''''''''''''''''''''''''''''<||>";           
    }

    cout << "\n\n\t\t|--------------------|"
         << "\n\t\t|     PRIEST LIST    |"
         << "\n\t\t|--------------------|\n\n";
    for (int i = 0; i < priest.size(); i++) {
        cout << "\n\t\t<||>'''''''''''''''''''''''''''''''''''''''''''''''<||>"
            << "\n\t\t<||>Name: " << priest[i].getName()
            << "\n\t\t<||>Race: " << priest[i].whatRace() << "\n\t\t<||>";
        SetConsoleTextAttribute(h, 12);
        cout << "HP:  " << priest[i].getHitPoints();
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t<||>";
        SetConsoleTextAttribute(h, 11);
        cout << "MP:  " << priest[i].getMagicPoints();
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t<||> " << priest[i].attack()
            << "\n\t\t<||>'''''''''''''''''''''''''''''''''''''''''''''''<||>";
        SetConsoleTextAttribute(h, 7);
    }

    cout << "\n\n\t\t|--------------------|"
         << "\n\t\t|      MAGE LIST     |"
         << "\n\t\t|--------------------|\n\n";
    for (int i = 0; i < mage.size(); i++) {
        cout << "\n\t\t<||>'''''''''''''''''''''''''''''''''''''''''''''''<||>"
             << "\n\t\t<||>Name: " << mage[i].getName()
             << "\n\t\t<||>Race: " << mage[i].whatRace() << "\n\t\t<||>";
        SetConsoleTextAttribute(h, 12);
        cout << "HP:  " << mage[i].getHitPoints();
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t<||>";
        SetConsoleTextAttribute(h, 11);
        cout << "MP:  " << mage[i].getMagicPoints();
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t<||> " << mage[i].attack()
            << "\n\t\t<||>'''''''''''''''''''''''''''''''''''''''''''''''<||>";
        SetConsoleTextAttribute(h, 7);
    }

    return 0;
}