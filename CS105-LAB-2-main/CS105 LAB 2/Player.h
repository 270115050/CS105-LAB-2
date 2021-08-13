#pragma once
//The type of race that the user can choose from
enum Race { DEFAULT, HUMAN, ELF, DWARF, ORC, TROLL };

//This class will hold the information of the created character(i.e., Name, Race, Class)
class Player {
private:
    string name;
    int hitPoints, magicPoints;
    enum Race race;

public:
    Player(string defStr = "default", int defNum = 0, Race r = DEFAULT) {
        name = defStr, race = r, hitPoints = defNum, magicPoints = defNum;
    }
    //This function ask user to enter character name
    void setName(string n) {
        name = n;      
    }
    //This function sets the race of the character. Each race will have bonus points in there stats(HP & MP)
    void setRace(Race r) {
        race = r; // assign race
        switch (getRace()) {
        case 1:
            setHitPoints(getHitPoints() + 30);
            setMagicPoints(getMagicPoints() + 30);
            break;
        case 2:
            setHitPoints(getHitPoints() + 20);
            setMagicPoints(getMagicPoints() + 40);
            break;
        case 3:
            setHitPoints(getHitPoints() + 40);
            setMagicPoints(getMagicPoints() + 20);
            break;
        case 4:
            setHitPoints(getHitPoints() + 50);
            setMagicPoints(getMagicPoints() + 10);
            break;
        case 5:
            setHitPoints(getHitPoints() + 60);
            setMagicPoints(getMagicPoints() + 0);
            break;
        default:
            setHitPoints(getHitPoints());
            setMagicPoints(getMagicPoints());
            break;
        }
    }
    //This function sets the amount of hp of character
    void setHitPoints(int hp) {
        hitPoints = hp;
    }
    //This function sets the amount of magic points of character
    void setMagicPoints(int mp) {
        magicPoints = mp;
    }
    //This function returns to the name of character
    string getName() {
        return name;
    }
    //This function returns the race of character
    Race getRace() {
        return race;
    }
    //This function returns the hp of character
    int getHitPoints() {
        return hitPoints;
    }
   //This function returns the mp of character
    int getMagicPoints() {
        return magicPoints;
    }
    //This function returns the type of race of character
    string whatRace() {
        string raceStr;

        switch (getRace()) {
        case 1:
            raceStr = "HUMAN";
            break;
        case 2:
            raceStr = "ELF";
            break;
        case 3:
            raceStr = "DWARF";
            break;
        case 4:
            raceStr = "ORC";
            break;
        case 5:
            raceStr = "TROLL";
            break;
        default:
            raceStr = "DEFAULT";
            break;
        }
        return raceStr;
    }
    //This function prints out the attack message of character
    string attack() {
        cout << "\n\t\tI will defeat you with my stick of truth!";
    }
};