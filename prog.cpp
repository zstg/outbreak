#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class popVars {
protected:
    float initialPopulation;
    double birthRate;
    double deathRate;

public:
    popVars(float initialPop, double birthR, double deathR) {
        initialPopulation = initialPop;
        birthRate = birthR;
        deathRate = deathR;
    }

    double getFinalPopulation() {
        return initialPopulation + (initialPopulation * (birthRate - deathRate) / 1000);
    }

    double getPopulationOnDate(int day, int month, int year) {

        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((year%4==0 && year%100 !=0)|| (year%400==0))
            int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int totalDays = 0;
        for (int i = 1; i < month; i++)
            totalDays += daysInMonth[i - 1];
        totalDays += day;
        //return totalDays;
        double popRatio;
        popRatio = (double)(getFinalPopulation()/ (double)initialPopulation);
        //cout << popRatio << endl;
        double ratePerDay = 365 * (pow((double)(getFinalPopulation()/ (double)initialPopulation), 0.00273972603) -1); // this float is 1.0/365
        return initialPopulation *pow((1+ratePerDay/365.0), totalDays);
        //return popRatio;
    }
};

class diseaseVars {
private:
    int infectedPeopleDay1;
    double transmissionRate;
    double recoveryRate;
    double contactRate;
    int incubationPeriod;
    int isolationPeriod;

public:
    diseaseVars(int infected, double transmission, double recovery, double contact, int incubation, int isolation) {
        infectedPeopleDay1 = infected;
        transmissionRate = transmission;
        recoveryRate = recovery;
        contactRate = contact;
        incubationPeriod = incubation;
        isolationPeriod = isolation;
    }
};

class vacVars {
    // Add relevant variables and functions for vaccination
};

int main() {
    // Example usage
    popVars population(1428000000,16.42,9.64);
    // receive these inputs separately and call the function
    cout << "Final Population: " << (int)population.getFinalPopulation() << endl;

    double populationOnDate = population.getPopulationOnDate(31, 12, 2023);
    cout << "Population on 31/12/2023: " << fixed  << (int)populationOnDate << endl;

    return 0;
}
