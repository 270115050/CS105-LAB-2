#pragma once
//Each class will have 300 points and this points are distributed according to there class.
class Warrior :public Player {
public:
    Warrior() {
        setHitPoints(200);
        setMagicPoints(100);
    }
    //This function prints out the attack message of character
    string attack() {
        return " I will destroy you with my sword!";
    }
};

class Priest :public Player {
public:
    Priest() {
        setHitPoints(150);
        setMagicPoints(150);
    }
    //This function prints out the attack message of character
    string attack() {
        return "I will assualt you with holy wrath";
    }
};

class Mage :public Player {
public:
    Mage() {
        setHitPoints(100);
        setMagicPoints(200);
    }
    //This function prints out the attack message of character
    string attack() {
        return "I will crush you with my arcane missiles!";
    }
};