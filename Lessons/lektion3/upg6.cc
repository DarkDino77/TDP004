Att använda multipelt arv på det här sättet, där Uruk_Hai ärver från både Human och Orc, 
kan leda till problem på grund av s.k. "diamond-problemet" eller "ambiguity problem" i C++. 
Detta uppstår när en klass ärver från två klasser som i sin tur ärver från en gemensam bas. 
I detta fall är både Human och Orc härledda från Race, och Uruk_Hai ärver från båda.

Här är ett förenklat klassdiagram för att illustrera problemet:

      Race
     /    \
 Human    Orc
     \    /
    Uruk_Hai

När du försöker använda eat()-funktionen på en Uruk_Hai-instans, 
kommer kompilatorn att vara osäker på vilken eat()-funktion den ska använda eftersom den är definierad i både Human och Orc. 
Detta skapar en tvetydighet som leder till kompileringsfel.

För att lösa detta problem kan du använda using-deklarationer för att specificera vilken funktion som ska användas. 
I C++11 kan du använda using för att lösa det här problemet:

class Uruk_Hai : public Human, public Orc
{
public:
  using Human::eat;  // Resolve ambiguity by specifying which eat() to use
};

Nu kan du skapa en Uruk_Hai-instans och anropa eat() på den utan problem:

Uruk_Hai* uruk = new Uruk_Hai;
uruk->eat();  // Calls Human::eat() because of the using declaration

Men som du påpekade kvarstår problemet när du försöker använda polymorfism med en pekare till Race. 
För att lösa detta behöver du virtuellt arv, men det är en mer komplex koncept och går bortom omfånget för detta svar. 
En lösning är att undvika multipelt arv i denna form och istället använda komposition eller 
någon annan designmetod för att uppnå det önskade beteendet utan att introducera oväntade problem från multipelt arv.