/*
Att ha en virtuell destruktor i basen av en hierarki av klasser, 
särskilt när man använder polymorfism (som du gör med Menu_Item och dess subklasser),
är viktigt för att säkerställa att korrekt destruktion sker när objekt av de här klasserna tas bort.

I det här fallet, om du inte har en virtuell destruktor i Menu_Item,
kan det leda till problem när du försöker ta bort objekt av en av dess subklasser via en pekare till Menu_Item.
När en klass har virtuella funktioner, inklusive en virtuell destruktor, 
skapas en så kallad vtable (virtual table) av kompilatorn. 
Denna tabell används för att länka varje virtuell funktion med rätt implementering vid körning, 
vilket är särskilt viktigt när du använder polymorfism.

Om du inte har en virtuell destruktor och försöker ta bort en subklassinstans via en pekare till basen, 
kommer endast de delarna av objektet som tillhör basen att raderas. 
Detta kan leda till minnesläckor eller andra problem eftersom eventuell resursallokering i subklassen 
inte kommer att rensas upp korrekt.

Här är hur du kan lägga till en virtuell destruktor i Menu_Item:
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Menu_Item
{
public:
  Menu_Item(string const& t) : title(t) {}
  virtual ~Menu_Item() {}  // Virtuell destruktor
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

int main()
{
    
    Menu_Item* start { new Menu("Start") };
    start->add_menu_item(new Load_Game("Läs in sparat spel"));
    start->add_menu_item(new Save_Game("Spara spelet"));
    start->add_menu_item(new Highscore("Poängställning"));
    Menu_Item* options { new Meny("Alternativ...") };
    start->add_menu_item(options);
    options->add_menu_item(new Keyboard_Settings("Tangentbordsalternativ"));
    options->add_menu_item(new Graphic_Settings("Grafikalternativ"));
    options->add_menu_item(new Sound_Settings("Ljudalternativ"));
    start->execute();
    delete start;
    return 0;
}

/*
Med en virtuell destruktor kommer korrekt destruktion att ske för instanser av Menu_Item och 
dess subklasser när de tas bort genom en pekare till basen. 
Detta garanterar att eventuell resursallokering i subklasserna hanteras korrekt.
*/