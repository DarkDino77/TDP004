#include <iostream>

// Basenheten: fordon
class Fordon {
public:
    int antalHjul;
    int topphastighet;

    // Konstruktor för fordon
    Fordon(int hjul, int hastighet) : antalHjul(hjul), topphastighet(hastighet) {
        begransaToppHastighet();
    }

    // Funktion för att köra fordonet från A till B
    void kora() {
        std::cout << "Kör fordonet från A till B." << std::endl;
    }

private:
    // Privat medlemsfunktion för att begränsa topphastigheten
    void begransaToppHastighet() {
        if (antalHjul > 6 && topphastighet > 100) {
            topphastighet = 100;
        }
    }
};

// Subklass 1: passagerarfordon (ärver från fordon)
class Passagerarfordon : public Fordon {
public:
    int antalSittplatser;

    // Konstruktor för passagerarfordon
    Passagerarfordon(int hjul, int hastighet, int platser) : Fordon(hjul, hastighet), antalSittplatser(platser) {}

    // Funktion för passagerare att lämna fordonet
    void lamnaFordon() {
        std::cout << "Passagerarna lämnar fordonet." << std::endl;
    }
};

// Subklass 2: fraktfordon (ärver från fordon)
class Fraktfordon : public Fordon {
public:
    int maxLast;

    // Konstruktor för fraktfordon
    Fraktfordon(int hjul, int hastighet, int last) : Fordon(hjul, hastighet), maxLast(last) {}

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
    // Skapa objekt av passagerarfordon och fraktfordon med konstruktorer
    Passagerarfordon passagerarbil(4, 120, 5);
    Fraktfordon lastbil(8, 130, 5000);

    // Använd funktioner från bas- och subklasser
    passagerarbil.kora();
    passagerarbil.lamnaFordon();

    lastbil.kora();
    lastbil.lasta();
    lastbil.lastaAv();

    return 0;
}
