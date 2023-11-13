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

    // Virtuell funktion för att returnera en kort beskrivning av fordonstypen
    virtual std::string beskrivning() const {
        return "Ett generiskt fordon.";
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

    // Överskrid den virtuella funktionen för att returnera en kort beskrivning av fordonstypen
    std::string beskrivning() const override {
        return "Ett passagerarfordon med " + std::to_string(antalSittplatser) + " sittplatser.";
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

    // Överskrid den virtuella funktionen för att returnera en kort beskrivning av fordonstypen
    std::string beskrivning() const override {
        return "Ett fraktfordon med maxlast " + std::to_string(maxLast) + " kg.";
    }
};

int main() {
    // Skapa objekt av passagerarfordon och fraktfordon med konstruktorer
    Passagerarfordon passagerarbil(4, 120, 5);
    Fraktfordon lastbil(8, 130, 5000);

    // Använd funktioner från bas- och subklasser samt polymorfa funktionen för att returnera beskrivning
    std::cout << passagerarbil.beskrivning() << std::endl;
    std::cout << lastbil.beskrivning() << std::endl;

    return 0;
}
