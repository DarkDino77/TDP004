int* data[3];
for (int i = 0; i < 3; ++i)
{
  data[i] = new int(i);
}
/*
data[0]   data[1]   data[2]
   |         |         |
   v         v         v
  +---+     +---+     +---+
  | 0 |     | 1 |     | 2 |
  +---+     +---+     +---+
Koden deklarerar en array av pekare till heltal (int* data[3]) 
och en loop skapar dynamiskt allokerade heltal och lagrar deras adresser i arrayen data. 
Efter loopen kommer data att innehålla pekare till tre heltal med värdena 0, 1 och 2. 
Den resulterande figuren visar detta, där data[0] pekar på heltal med värdet 0, 
data[1] pekar på heltal med värdet 1 och data[2] pekar på heltal med värdet 2.

*/