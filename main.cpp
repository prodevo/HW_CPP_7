#include <iostream>
#include <vector>
using namespace std;

class Herbivore {
public:
    int weight;
    bool life;

    Herbivore(int weight = 10) : weight(weight), life(true) {}
    
    void EatGrass() {
        weight += 10;
        cout << "weight: " << weight << "\n";
    }
};

class Carnivore {
public:
    int power;

    Carnivore(int power = 20) : power(power) {}

    void Eat(Herbivore& herbivore) {
        if (herbivore.life)
        {
            if (power > herbivore.weight)
            {
                power += 10;
                herbivore.life = false;
                cout << "power: " << power << "\n";
            }
            else
            {
                power -= 10;
                cout << "power: " << power << "\n";
            }
        }
        else
        {
            cout << "are you going to eat the dead one? ewwww\n";
        }
    }
};

class Continent
{
public:
    virtual Herbivore* CreateHerbivore() = 0;
    virtual  Carnivore* CreateCarnivore() = 0;
};

class Chicken : public Herbivore{
public:
    Chicken() : Herbivore(5) {}
};


class Horse : public Herbivore {
public:
    Horse() : Herbivore(120) {}
};

class Tiger : public Carnivore {
public:
    Tiger() : Carnivore(100) {}
};

class Puma : public Carnivore {
public:
    Puma() : Carnivore(90) {}
};

class Eutope : public Continent
{
public:
    Herbivore* CreateHerbivore() override { return new Chicken(); }
    Carnivore* CreateCarnivore() override { return new Puma(); }
};

class Asia : public Continent
{
public:
    Herbivore* CreateHerbivore() override { return new Horse(); }
    Carnivore* CreateCarnivore() override { return new Tiger(); }
};

class AnimalWorld {
    Herbivore* herbivore;
    Carnivore* carnivore;
public:
    AnimalWorld(Continent& continent) {
        herbivore = continent.CreateHerbivore();
        carnivore = continent.CreateCarnivore();
    }

    void MealsHerbivores() {
        herbivore->EatGrass();
    }

    void NutritionCarnivores() {
        carnivore->Eat(*herbivore);
    }
};

int main()
{
    Eutope europe;
    AnimalWorld wrl(europe);
    wrl.MealsHerbivores();
    wrl.NutritionCarnivores();

    Asia asia;
    AnimalWorld wrld(asia);
    wrld.MealsHerbivores();
    wrld.NutritionCarnivores();
}






//FINALLY IT FINISHED
