#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>


using namespace std;


class Cities{
    map<string, int> cities;
    int total_population;
public:
    Cities(){};
    void addCity(string name, int population) {
        if (cities.find(name) != cities.end())
            total_population -= cities[name];
        cities[name] = population;
        total_population +=population;
    }
    void removeCity(string name) {
        cities.erase(name);
    }

    string getRandomCity() {
        int offs = rand % cities.size();
        auto it = cities.begin() + offs;
        return it->first;
    }


};
