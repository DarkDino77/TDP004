class Race
{
public:
  virtual void eat() = 0;
  // ...
};

// Egenskapsklasser (mix-ins)
class Sun_Insensitive
{
public:
  void ignore_sun() { /* implementation */ }
};

class Strong
{
public:
  void be_strong() { /* implementation */ }
};

class Intelligent
{
public:
  void be_intelligent() { /* implementation */ }
};

class Repulsive
{
public:
  void be_repulsive() { /* implementation */ }
};

// Klasserna som använder egenskapsklasser för att få olika egenskaper
class Human : public Race, public Sun_Insensitive, public Intelligent
{
public:
  void eat() override;
  // ...
};

class Orc : public Race, public Strong, public Repulsive
{
public:
  void eat() override;
  // ...
};

class Uruk_Hai : public Race, public Sun_Insensitive, public Strong, public Repulsive
{
public:
  // ...
};

// Funktion för att avgöra om en gäst är motbjudande
int eat_dinner(Race* dinner_guest)
{
  if (dynamic_cast<Repulsive*>(dinner_guest) != nullptr)
  {
    // Det är en motbjudande gäst
    return 1;
  }
  else
  {
    // Det är inte en motbjudande gäst
    return 0;
  }
}
