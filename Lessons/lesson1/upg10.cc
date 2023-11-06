I C++ kan du använda olika typer av variabler, inklusive vanliga variabler, medlemsvariabler och statiska medlemsvariabler. 
Här är en översikt över skillnaderna mellan dem, inklusive exempelkod för att belysa dessa skillnader:

1. Vanlig variabel:
   En vanlig variabel är en variabel som deklareras i en funktion eller i det globala omfånget och är inte associerad med en specifik klass eller objekt.
    Denna typ av variabel lagras i minnet på stacken (om den är lokal för en funktion) eller i datasektionen (om den är global).

   Exempel:
   int main() {
       int x = 5; // En vanlig variabel
       return 0;
   }

2. Medlemsvariabel:
   En medlemsvariabel är en variabel som är medlem av en klass. 
   Varje objekt av klassen innehåller en egen uppsättning medlemsvariabler. 
   Dessa variabler lagras i minnet när ett objekt av klassen skapas.

   Exempel:
   class MyClass {
   public:
       int memberVar; // En medlemsvariabel
   };

   int main() {
       MyClass obj1;
       obj1.memberVar = 10; // Åtkomst via objekt
       return 0;
   }

   Varje objekt av klassen `MyClass` har sin egen `memberVar`, och ändringar i den påverkar bara det specifika objektet.

3. Statisk medlemsvariabel:
   En statisk medlemsvariabel är också en medlemsvariabel, men den delas mellan alla objekt av klassen. 
   Den lagras i datasektionen och är oberoende av specifika objektinstanser.

   Exempel:
   class MyClass {
   public:
       static int staticMemberVar; // En statisk medlemsvariabel
   };

   int MyClass::staticMemberVar = 0; // Initialisering av den statiska medlemsvariabeln

   int main() {
       MyClass obj1, obj2;
       obj1.staticMemberVar = 10; // Åtkomst via objekt
       obj2.staticMemberVar = 20; // Åtkomst via ett annat objekt
       MyClass::staticMemberVar = 30; // Direkt åtkomst via klassen
       return 0;
   }

   I detta exempel delar `obj1` och `obj2` samma `staticMemberVar`, så ändringar i en påverkar den andra. 
   Du kan även komma åt den statiska medlemsvariabeln direkt genom att använda klassnamnet, 
   som i fallet med `MyClass::staticMemberVar`.

Sammanfattningsvis är huvudskillnaden mellan dessa tre typer av variabler hur de lagras och åtkomstmetoden. 
Vanliga variabler är självständiga och har lokal eller global räckvidd. 
Medlemsvariabler är kopplade till specifika objekt och delas inte mellan dem. 
Statiska medlemsvariabler delas mellan alla objekt av klassen alla instanser av objektet delar minne