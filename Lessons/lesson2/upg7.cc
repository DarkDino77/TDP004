/*
När du kör insert(first, 2);, 
skapas ett nytt element med värdet 2 och placeras före det nuvarande första elementet 
(som tidigare hade värdet 8) i den befintliga länkade listan. Här är stegen som beskriver vad som händer:

1. Ursprunglig länkad lista:

[first] --> [8] --> [5] --> [3] --> [nullptr]


2. När insert(first, 2); körs, kommer en ny element att skapas med värdet 2 och peka på nästa element i listan, 
som är det ursprungliga första elementet med värdet 8. Den befintliga "first"-pekaren ändras inte i funktionen, 
men den pekar fortfarande på det ursprungliga första elementet.

3. Den nya listan efter att insert körs:

[first] --> [2] --> [8] --> [5] --> [3] --> [nullptr]


Eftersom insert skapar ett nytt element med värdet 2 och 
pekar på nästa element som var det tidigare första elementet med värdet 8,
har listan nu elementet med värdet 2 som det nya första elementet.

Så, efter att koden har körts, ser den länkade listan ut som ovan, där "first" pekar på det nya första elementet med värdet 2. 
Det tidigare första elementet (8) har nu blivit det andra elementet i listan, och de andra elementen följer därefter.
*/