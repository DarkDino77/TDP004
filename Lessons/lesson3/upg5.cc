#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Menu_Item
{
public:
    Menu_Item(string const& t) : title(t) {}
    virtual void execute() = 0;
private:
    string title;
};

class Menu : public Menu_Item
{
public:
    Menu(string const& t) : Menu_Item(t) {}
    ~Menu() { /* delete all items in list */ }
    void add_menu_item(Menu_Item* i) { item_list.push_back(i); }
    void execute() { /* user chose one menu item and execute i */ }
private:
    vector<Menu_Item*> item_list;
};

class Load_Game : public Menu_Item
{
public:
    Load_Game(string const& t) : Menu_Item(t) {}
    void execute() override
    {}
};

class Save_Game : public Menu_Item
{
public:
    Save_Game(string const& t) : Menu_Item(t) {}
    void execute() override
    {}
};

class Highscore : public Menu_Item
{
public:
    Highscore(string const& t) : Menu_Item(t) {}
    void execute() override
    {}
};

class Keyboard_Settings : public Menu_Item
{
public:
    Keyboard_Settings(string const& t) : Menu_Item(t) {}
    void execute() override
    {}
};

class Graphic_Settings : public Menu_Item
{
public:
    Graphic_Settings(string const& t) : Menu_Item(t) {}
    void execute() override
    {}
};

class Sound_Settings : public Menu_Item
{
public:
    Sound_Settings(string const& t) : Menu_Item(t) {}
    void execute() override
    {}
};




int main()
{
    Menu_Item* start { new Menu("Start") };
    start->add_menu_item(new Load_Game("Läs in sparat spel"));
    start->add_menu_item(new Save_Game("Spara spelet"));
    start->add_menu_item(new Highscore("Poängställning"));
    Menu_Item* options { new Menu("Alternativ...") };
    start->add_menu_item(options);
    options->add_menu_item(new Keyboard_Settings("Tangentbordsalternativ"));
    options->add_menu_item(new Graphic_Settings("Grafikalternativ"));
    options->add_menu_item(new Sound_Settings("Ljudalternativ"));
    start->execute();
    delete start;

    return 0;
}