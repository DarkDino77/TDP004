// ==============================[ Databehållare ]==============================
/*
sequence containers
- Vector
- Array - snabbast(fast storlek)
- Deque
- List - Undvik
- Forward List

sequence adaptors
- stack
- queue
- prority_queue

Associative containers
⊢ map - som en dict. För varje nyckel kan enbart ett värde existera.
.   map<string, int> dict{};
.       nyckel  värde
.   dict["my key"] = 5;
.   dict["a"] = 3; Skapar ett nytt "entry" i tabellen som även är sorterad.
.
.   dict.count["b"] = 0; - returnerar 0 eller 1.
.   dict.contains["a"] (c++20)
.   dict.erase() för att ta bort.
.
. Krav för nyckel: 1. Ska ha operator< 2. Ska gå att kopiera.
⊢ set - Innehåller inte ett värde. men är sorterad.
⊢ multi* - Använd en map med vektor som key istället!
⊢ unordered_*
*/

// ==============================[ Iteratorer ]==============================
int main()
{
    vector<int> v {1, 2, 3};
    for (int e : v)
    {
        cout << e << endl;
    }
}

using iterator = std::vector<int>::iterator;
for (iterator it{v.begin()}; it != v.end(); ++it)
{
    cout << *it << endl;
}
/*
    [1|2|3: :

    Varje behållare har sin egen itterator. Som är implementerad på olika sätt beroende på behållare

    Ska ha: 1. Operator++(båda), 2. operator* 3. Operator!=, Operator==.
*/

// ==============================[ Standard bibliotek ]==============================
/*
- Tillgänglig för alla
- Löser vanliga problem
- Komponenter
- Effektiv

Standar Template Library - STL

- Komponenter
. Algorithms
. Containers
. Iterators
. Others

*/

// ==============================[ Algorithms ]==============================

// Icke-modifierande algorithmer
std::vector<int> v { 5, -2, 8, 4, 7 };
auto it {std::find(v.begin(), v.end(), 4)};
if (it == v.end())
{
    // found nothing
}

std::vector<int> v {1, 2, 3, 1, 4, 1};
int result {std::count(v.begin(), v.end(), 1)};

// Modifierande algorithmer
auto it {std::remove(v.begin(), v.end(), 1)}; // Lägger alla element som ska tas bort i slutet.
v.erase(it, v.end()); // Tar bort allt från iterator it till behållarens slut.

// Kopierande
std::vector<string> args {argv, argv + argc};

std::vector<string> v (args.size()); // Måste se till att det finns tillräckligt med element att kopiera till.

std::copy(args.begin(), args.end(), v.begin()); 

// Transform
int add_2(int n)
{
    return n + 2;
}

int main()
{
    std::vector<int> v {1, 2, 3};
    std::vector<int> result (v.size());
    std::transform(v.begin(), v.end(),
                   result.begin(), add_2); // Vi anropar inte, men transform gör det.
}

// ==============================[ Lambda functions ]==============================
[](int n) -> int { return n + 2; }
/*
[] - Capture
(int n) - inparametrar
-> int - return type
{ return n + 2; } - body
*/

// Behöver inte specifiera returtyp:
[](int n) { return n + 2; }

// Spara en lambda-funktion som en variabel.
auto add_2 = [](int n) { return n + 2; };
std::transform(v.begin(), v.end(),
               v.begin(), add_2);

// Fördel: Kan ligga lokalt.

// Funktionsobjekt!
struct My_Lambda
{
    auto operator()(int n)
    {
        return n + 2;
    }
};

// Ge tillgång till en lokal variabel.
int x {2};
std::vector<int> v {1, 2, 3};
std::transform(v.begin(), v.end(), v.begin(),
               [x](int n) { return n + x; }); // X läggs som en privat medlemsvariabel i klassen.

// Problem:
int x {2};
auto add_x = [x](int n) { return n + x; };
cout << add_x(5) << endl; // 7
x = 3;
cout << add_x(5) << endl; // 7

// Lösning: (&)
int x {2};
auto add_x = [&x](int n) { return n + x; };
cout << add_x(5) << endl; // 7
x = 3;
cout << add_x(5) << endl; // 8

// Fånga allt (Använd inte!):
int x{2};
int y{3};
auto f = [&](int n) { return y*n + x; }; // Kommer ha tillgång till f.
std::vector<int> v {1, 2, 3};
std::transform(v.begin(), v.end(),
               v.begin(), f);

// v == {5, 8, 11}

// STL Funktionsobjekt
std::vector<int> v {4, 6, 3, 7, 1};
std::sort(v.begin(), v.end(), greater<int>{}); // greater<int> är ett funktionsobjekt. Ersätter enligt nedan.

// v == {7, 6, 4, 3, 1}

//Ersätter 
[](int x, int y) { return x > y; });

// ==============================[ Mer om iteratorer ]==============================
std::vector<int> v {1, 2, 3, 4};
std::copy(v.begin(), v.end(),
          std::ostream_iterator<int>{cout, " "}); // " " separator.

// Kommer skriva ut 1 2 3 4 .

// Läsa från stream.
std::vector<int> v {};
int x;
while (std::cin >> x)
{
    v.push_back(x);
}

std::vector<int> v {
    std::istream_iterator<int>{cin}, // Begin iteratorn
    std::istream_iterator<int>{} // När det inte finns något mer att läsa. När en felflagga sätts i cin blir den ekvivalent med denna.
};

// Går att kombineras!
std::vector<int> v {}; // Men vet inte hur stor v kommer vara?!
std::transform(std::istream_iterator<int>{cin},
               std::istream_iterator<int>{},
               v.begin(),
               [](int e) { return 2 * e; });
               
// Lösningen är Output-iteratorer. <---------------------------------------------------------------------------------------
std::vector<int> v {};
std::transform(std::istream_iterator<int>{cin},
               std::istream_iterator<int>{},
               std::back_inserter(v),
               [](int e) { return 2 * e; });

// Läs in, sortera och skriv ut
std::vector<int> args {}; // <---------------------------------------------------------------------------------------
std::transform(argv + 1, argv + argc,
               std::back_inserter(args),
               [](char const* arg)
               {
                   return std::stoi(arg);
               });

std::sort(args.begin(), args.end(),
          std::greater<int>);

std::copy(args.begin(), args.end(),
          std::ostream_iterator<int>{cout, ", "});

// INFÖR LABBEN
// look at all member functions of std::string