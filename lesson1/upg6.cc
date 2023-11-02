//Abstraction handlar om att skriva kod saker på ett sätt som gömmer hur det funkar.

// Ett dåligt exempel på abstraktion
bool check_less_than_5(float value)
{
    if (value < 5)
    {
        cout << "är sant" << endl;
        return true;
    }
    return false;
};

// Ett bättre exempel på detta hade kunnat sett ut på följande vis:
bool check_less(float value, float check_value, std::string massage)
{
    if (value < check_value)
    {
        cout<< massage << endl;
        return true;
    }
    return false;
};
