#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
//#include "States.h"
using namespace std;

class popVars {
public:
    int initialPopulation;
    double birthRate;
    double deathRate;
    popVars() : initialPopulation(0), birthRate(0), deathRate(0) {}
    popVars(int initialPop, double birthR, double deathR) {
        initialPopulation = initialPop;
        // birthRate = birthR;
        deathRate = deathR;

    }
};

class diseaseVars:public popVars{
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
    double infectedPplAfterNDays(int no)
    {
        return infectedPeopleDay1 * pow((1 + transmissionRate), (no * contactRate));
    }
};

class vacVars:public diseaseVars{
    public:
    vacVars() : diseaseVars(), efficiency(0), vac(0), iso(0), rateVac(0) {}
    float efficiency;
    int vac; // no of days after the disease's onset, when the vaccine was invented
    int iso; // no of days after incubation period, when personnel self-isolate
    float rateVac;
    double recoveredPplAfterNVacDays(int no, int vac)
    {
        // naturally-recovering
        return (infectedPeopleDay1 * pow(1 - transmissionRate, no * contactRate))                                                              // + vaccine
               + infectedPeopleDay1 * transmissionRate * recoveryRate * pow(1 + efficiency, no + vac - (iso + incubationPeriod) * contactRate) // -both
               - (rateVac * vac * efficiency * pow(infectedPeopleDay1 * transmissionRate * (1 - recoveryRate), no + vac - (iso + incubationPeriod) * contactRate - 1));
    }
};

vacVars v;

double getFinalPopulation()
    {
        return v.initialPopulation + (v.initialPopulation * (v.birthRate - v.deathRate) / 1000);
    }

double getFinalPopulation(int x, float b, float d)
    {
        return x + (x * (b - d) / 1000);
    }

double getPopulationOnDate(int day, int month, int year)
    {

        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDays = 0;
        for (int i = 1; i < month; i++)
            totalDays += daysInMonth[i - 1];
        totalDays += day;

        double popRatio = (double)(getFinalPopulation()) / (double)(v.initialPopulation);

        double ratePerDay = 365 * (pow((double)(getFinalPopulation() / (double)v.initialPopulation), 0.00273972603) - 1); // this float is 1.0/365
        return v.initialPopulation * pow((1 + ratePerDay / 365.0), totalDays);
    }

unsigned long ValidateInitPop() {
    string input;
    //unsigned long initPop;
    while (true) {
        cout << "Enter initial population: ";
        getline(cin, input);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        
        stringstream ss(input);
        if (ss >> v.initialPopulation) {
            char remaining;
            if (!(ss >> remaining)) {
                break; // No remaining characters, valid input
            }
        }
        cout << "Enter valid initial population." << endl;
    }
    //pv.initialPopulation = initPop;
    return v.initialPopulation;
}


double ValidateBirthRate() {
    string input;
    double br;
    while (true) {
        cout << "Enter birth rate: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> br) {
            if (br >= 0 && br <= 1000) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid birth rate." << endl;
    }
    return br;
}

double ValidateDeathRate() {
    string input;
    double dr;
    while (true) {
        cout << "Enter death rate: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> dr) {
            if (dr >= 0 && dr <= 1000) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid death rate." << endl;
    }
    return dr;
}

int ValidateInfday1() {
    string input;
    int infday1;
    while (true) {
        cout << "Enter no of ppl who are infected on day 1: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> infday1) {
            if (infday1 >= 0) { // Validate the birth rate range && >= pop
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter proper no of ppl who are infected on day 1:" << endl;
    }
    return infday1;
}

double ValidateTransRate() {
    string input;
    double tr;
    while (true) {
        cout << "Enter transmission rate: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> tr) {
            if (tr >= 0 && tr <= 1) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid transmission rate." << endl;
    }
    return tr;
}
double ValidateRecRate() {
    string input;
    double rr;
    while (true) {
        cout << "Enter recovery rate: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> rr) {
            if (rr >= 0 && rr <= 1) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid recovery rate." << endl;
    }
    return rr;
}


int ValidateIncPrd() {
    string input;
    int incprd;
    while (true) {
        cout << "Enter incubation period: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> incprd) {
            if (incprd >= 0 && incprd <= 100) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid incubation period:" << endl;
    }
    return incprd;
}

void prompt(){
    char userInput;
    do{
        cout << "Do you want to enter custom-input? ";
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(userInput=='y' || userInput=='Y'){
            // ask for initial pop... etc.
            ValidateInitPop();
            ValidateBirthRate();
            ValidateDeathRate();
            ValidateInfday1();
            ValidateTransRate();
            ValidateRecRate();
            ValidateIncPrd();        
            break;
        }
        else if(userInput=='n' || userInput=='N'){
            /*
            // get stateName and diseaseName

            float br, dr;
            unsigned long ip;
            string stateinp;
            for(int i=0;i<62;i++){
                if(stateinp==s[i].Name){
                    float br=s[i].birthRate;
                    float dr = s[i].deathRate;
                    unsigned long ip = s[i].initPop;
                }
            cout << br << dr << ip;
            }
            break;
            */
        }
        
        else cout << "Enter Y/N "<<endl;

    } while(true);
}

int main() {
    prompt();
     cout <<  ValidateInitPop();
    //getPopulationOnDate(12,12,2023);
    //double deathRate = ValidateDeathRate();
    //int infectedDay1 = ValidateInfday1();
    //double transmissionRate = ValidateTransRate();
    cout << v.initialPopulation;
    return 0;
}