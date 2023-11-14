#include <vector>
#include <iostream>

using namespace std;


class Character
{
public:
    virtual void update(int delta_time);
    virtual void draw(); // 'Virtual' Menar att subklaser kan överskrida basklassens funktion som är virtual.
    // Pure virtual, eller = 0 innebär att alla subklasser måste ha funktionen, men den finns inte i basklassen.

protected: // Protected ger subklasserna åtkomst till variabeln, men inte utanför klasserna.
    int health;
};

class Archer: public Character
{
public:
    void update(int delta_time) override;
    void draw() override; // = 0 gör klassen 'Abstrakt'. Det går inte längre att skapa bara en character.
private:
    int range;
};

class Fighter:public Character
{
public:
    void update(int delta_time) override;
    void draw() override;
private:
    int armor;
};

// Varför override är viktigt:
class A
{
public:
    virtual void f2(int test);
};

class B: public A
{
public:
    void f2(int test) override; // Efter const
    //void f2(int); Helt annan funktion
};

class Monster: public Character
{
public:
    virtual void do_damage(Character& c) = 0;
protected:
    int damage;
};

class Goblin: public Monster
{
public:
    void do_damage(Character& c) override;
};

int main()
{
    vector<int> empty_vector{};
    vector<int> my_vector{1,2,3,4,5};

    my_vector.push_back(6);
    //int my_int{ my_vector.pop_back() };


    cout << "The size is: "
    << my_vector.size()
    << ", the element on pos 3 is :"
    << my_vector.at(3) << endl;

    for( int i : my_vector )
    {
        cout << i << ", ";
    }
    cout << endl;

    /*
                     ios        <- c++: Basklass, annat: superklass
                    /   \
             ostream     istream        <- c++: Härledd klass / underklass, annat: Ärver / subklass
               /  |       |  \
    ostringstream |       | ifilestream
                 /         \
         ofilestream     istringstream
    
    
    */

    Archer my_archer{};
    Fighter my_fighter{};
    Goblin my_goblin{};
    vector<Character*> characters{};
    characters.push_back(&my_archer); // &my_archer skapar objekt och lagrar pekare.
    characters.push_back(&my_fighter); // adress of
    characters.push_back(&my_goblin);

    for (Character* character: characters)
    {
        // Monster* m{static_cast<Monster*>(character)}; Går inte då alla inte är monster.
        // m -> do_damage();
        character -> update(1);
        Monster* m{dynamic_cast<Monster*>(character)};
        if (m != nullptr)
        {
            m -> do_damage(my_archer);
        }
    }

}