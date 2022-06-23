#include <iostream>
#include <string>

class Spell {
protected:
    std::string discr;
    Spell* next = NULL;

public:

    void use() {
        std::cout << getDiscription() << "BOOOM!!!";
    }

    void setPtr(Spell* spell) {
        next = spell;
    }

    void setDiscrition(std::string str) {
        discr = str;
    }

    std::string getDiscription() {
        if (next == NULL)
            return "It's ";

        return next->getDiscription() + discr + ", ";
    }
};

class Modify {
public:
    virtual Spell* modify(Spell* spell) = NULL;
};

class IncreaseVelacity : public Modify {
public:
    Spell* modify(Spell* spell) override {
        Spell* res = new Spell();
        res->setPtr(spell);

        res->setDiscrition("becomes faster");
        return res;
    }
};

class IncreaseSize : public Modify {
public:
    Spell* modify(Spell* spell) override {
        Spell* res = new Spell();
        res->setPtr(spell);

        res->setDiscrition("becomes bigger");
        return res;
    }
};

int main() {
    IncreaseSize size;
    IncreaseVelacity speed;

    Spell* spell = new Spell;

    spell = speed.modify(spell);
    spell = size.modify(spell);
    spell = speed.modify(spell);


    spell->use();
    int a;
    std::cin >> a;
}