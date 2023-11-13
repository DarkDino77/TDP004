//Här är ett exempel på hur du kan deklarera ett gränssnitt för en observatör i C++:



#include <iostream>
#include <vector>

using namespace std;

// Observer interface
class Observer
{
public:
  virtual void notify() = 0;
  virtual ~Observer() {}  // Virtual destructor for proper cleanup
};

//Nu kan du implementera en klass för stapeldiagram (bar chart) 
//som ärver från detta gränssnitt och läggs till i en instans av den övervakade Data-klassen:

// Concrete observer class for a bar chart
class BarChartObserver : public Observer
{
public:
  BarChartObserver(string name) : chartName(name) {}

  // Implementation of the notify function
  void notify() override
  {
    cout << "Updating " << chartName << " with new data." << endl;
    // Actual implementation for updating the bar chart with new data
  }

private:
  string chartName;
};

// Concrete observable class representing data
class Data : public Observable
{
public:
  // Function to update data and notify observers
  void updateData()
  {
    // Update data here...

    // Notify all observers
    notify_all();
  }
};

int main()
{
  // Create an instance of the observable data
  Data data;

  // Create an instance of the bar chart observer
  BarChartObserver* barChartObserver = new BarChartObserver("Bar Chart");

  // Add the bar chart observer to the list of observers for the data
  data.add_observer(barChartObserver);

  // Update data, which will notify the bar chart observer
  data.updateData();

  // Clean up: The responsibility for deleting the observer lies with the code that created it
  // (in this case, it should be the responsibility of the main function)
  // delete barChartObserver;

  return 0;
}
/*
Notera att jag har lagt till en virtuell destruktor i Observer-gränssnittet 
för att möjliggöra korrekt uppröjning av resurser när en observer-objekt instanseras med new. 
Det är viktigt att påpeka att det är upphovsmannen till en pekare som använder new 
som ansvarar för att använda delete för att undvika läckage av minne.
*/