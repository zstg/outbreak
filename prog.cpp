#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
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
        
        double popRatio = (double)(getFinalPopulation()/ (double)initialPopulation);

        double ratePerDay = 365 * (pow((double)(getFinalPopulation()/ (double)initialPopulation), 0.00273972603) -1); // this float is 1.0/365
        return initialPopulation *pow((1+ratePerDay/365.0), totalDays);
        
    }
};

class diseaseVars {
public:
    int infectedPeopleDay1;
    double transmissionRate;
    double recoveryRate;
    double contactRate;
    int incubationPeriod;
/*
    diseaseVars(int infected, double transmission, double recovery, double contact, int incubation) {
        infectedPeopleDay1 = infected;
        transmissionRate = transmission;
        recoveryRate = recovery;
        contactRate = contact;
        incubationPeriod = incubation;
    }
*/
    double infectedPplAfterNDays(int no){
        return infectedPeopleDay1 * pow((1+transmissionRate),(no*contactRate));
    }
    
};

class vacVars:public diseaseVars {
    public:
    float efficiency;
    int vac; // no of days after the disease's onset, when the vaccine was invented
    int iso; // no of days after incubation period, when personnel self-isolate 
    float rateVac;
    double recoveredPplAfterNVacDays(int no, int vac){
        // naturally-recovering 
        return (infectedPeopleDay1 * pow(1-transmissionRate,no*contactRate)) \
        // + vaccine
        + infectedPeopleDay1*transmissionRate*recoveryRate*pow(1+efficiency, no+vac-(iso+incubationPeriod)*contactRate)\
        // -both
        - (rateVac*vac*efficiency*pow(infectedPeopleDay1*transmissionRate*(1-recoveryRate),no+vac-(iso+incubationPeriod)*contactRate-1));
    }
};

int main() {
    //class diseaseVars d(4,0.87,0.98,1.2,3);
    class vacVars v; 
    // default args -> for stuff like population
    v.infectedPeopleDay1 = 5000; // large amt of ppl get infected in a single day
    v.transmissionRate = 0.3; // low transmission rate
    v.recoveryRate = 0.2;
    v.incubationPeriod = 3;
    // no as input
    v.efficiency = 50;
    v.vac = 21;
    v.iso = 1;
    v.rateVac = 100;
    v.contactRate = 5;
    cout << fixed << setprecision(10) << (double)v.infectedPplAfterNDays(15)<<endl;
    cout << v.recoveredPplAfterNVacDays(15,2)<<endl;


    cout << endl;    
}    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    // Example usage
    popVars population(1428000000,16.42,9.64);
    // receive these inputs separately and call the function
    cout << "Final Population: " << (int)population.getFinalPopulation() << endl;

    double populationOnDate = population.getPopulationOnDate(31, 12, 2023);
    cout << "Population on 31/12/2023: " << fixed  << (int)populationOnDate << endl;
    
    cout << endl;
    return 0;
    */