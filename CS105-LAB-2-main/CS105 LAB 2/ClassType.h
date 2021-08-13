#pragma once
//Each class will have 300 points and this points are distributed according to there class.
class Warrior :public Player {
private:
    string name;
public:
    Warrior() {
        setHitPoints(200);
        setMagicPoints(100);
    }
    //Creats the Warrior class
    Warrior createCharacter(Race r, Warrior w) {
        cout << "\n\t\tWould you like to name your character? ";
        cin >> name;
        w.setRace(r);
        w.setName(name);

        return w;
    }
    //This function prints out the attack message of character
    string attack() {
        return " I will destroy you with my sword!";
    }
};

class Priest :public Player {
private:
    string name;
public:
    Priest() {
        setHitPoints(150);
        setMagicPoints(150);
    }
    //Creates the Priest class
    Priest createCharacter(Race r, Priest p) {
        cout << "\n\t\tWould you like to name your character? ";
        cin >> name;
        p.setRace(r);
        p.setName(name);

        return p;
    }
    //This function prints out the attack message of character
    string attack() {
        return "I will assualt you with holy wrath";
    }
};

class Mage :public Player {
private:
    string name;
public:
    Mage() {
        setHitPoints(100);
        setMagicPoints(200);
    }
    //Creates the Mage class
    Mage createCharacter(Race r, Mage m) {
        cout << "\n\t\tWould you like to name your character? ";
        cin >> name;
        m.setRace(r);
        m.setName(name);

        return m;
    }
    //This function prints out the attack message of character
    string attack() {
        return "I will crush you with my arcane missiles!";
    }
};