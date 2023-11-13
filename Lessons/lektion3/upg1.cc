#include <iostream>

// Basenheten: fordon
class Fordon {
public:
    int antalHjul;
    int topphastighet;

    // Funktion för att köra fordonet från A till B
    void kora() {
        std::cout << "Kör fordonet från A till B." << std::endl;
    }
};

// Subklass 1: passagerarfordon (ärver från fordon)
class Passagerarfordon : public Fordon {
public:
    int antalSittplatser;

    // Funktion för passagerare att lämna fordonet
    void lamnaFordon() {
        std::cout << "Passagerarna lämnar fordonet." << std::endl;
    }
};

// Subklass 2: fraktfordon (ärver från fordon)
class Fraktfordon : public Fordon {
public:
    int maxLast;

    // Funktion för att lasta fraktfordonet
    void lasta() {
        std::cout << "Fordonet lastas." << std::endl;
    }

    // Funktion för att lasta av fraktfordonet
    void lastaAv() {
        std::cout << "Fordonet lastas av." << std::endl;
    }
};

int main() {
    // Skapa objekt av passagerarfordon och fraktfordon
    Passagerarfordon passagerarbil;
    Fraktfordon lastbil;

    // Använd funktioner från bas- och subklasser
    passagerarbil.kora();
    passagerarbil.lamnaFordon();

    lastbil.kora();
    lastbil.lasta();
    lastbil.lastaAv();

    return 0;
}
