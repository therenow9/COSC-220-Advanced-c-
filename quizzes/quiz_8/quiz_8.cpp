#include <iostream>
using namespace std;
class enemy
{
private:
    int health;
    int attack;
    //private data members of all enemies health and attack
public:
    enemy(int h,int a);
    //constructor
    void displayStats();
    void displayHealth();
};
enemy::enemy(int h,int a)
{
    //base enemy constructor
    health=h;
    attack=a;
}
void enemy::displayHealth()
{
    //non overwritten member function
    cout<<health<<endl;
}
void enemy::displayStats()
{
    //enemy display stats
    cout<<health<<endl;
    cout<<attack<<endl;
}
class Goblin:public enemy
{
private:
    int armor;
    //in addition to health and attack inherited from enemy, goblins have armor as well
public:
    Goblin(int h,int a,int arm);
    void displayStats();
};
Goblin::Goblin(int h,int a,int arm):enemy(h,a)
{
    //overload constructor with enemy constructor
    armor=arm;

}

void Goblin::displayStats()
{
    //overwritten member function
    enemy::displayStats();
    //calls enemy display stats then outputs armor
    cout<<armor<<endl;
}


int main()
{
    enemy skeleton(10,3);
    //create skeleton that has 10 health and 3 attack
    Goblin orc(15,10,5);
    //orc has 15 health 10 attack and 5 armor
    skeleton.displayStats();
    orc.displayStats();
    /*this is where the dynamic binding comes into play
    since display stats is a method of both enemy and goblin
    it is determined at runtime which code is ran depending
    on the type of object that calls ex: enemy display stats
    prints health and attack, goblin display stats prints those 2 and armor
    This is an example of Dynamic Binding in C++ derived classes
    */
    skeleton.displayHealth();
    orc.displayHealth();
    /*also here we see i call the display health function on both objects
    despite the fact that it is only defined for enemy types
    this is because it is inherited and did not need to be changed therefore
    it shall work for this type as well
    */
    return 0;
    }
