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
    long finalPopulation;

    double getFinalPopulation()
    {
        finalPopulation = initialPopulation + (initialPopulation * (birthRate - deathRate) / 1000);
        return finalPopulation;
    }
    
/*
    double getPopulationOnDate()
    {

        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int totalDays = 0;
        for (int i = 1; i < month; i++)
            totalDays += daysInMonth[i - 1];
        totalDays += day;

        double popRatio = (double)(getFinalPopulation() / (double)initialPopulation);

        double ratePerDay = 365 * (pow((double)(getFinalPopulation() / (double)initialPopulation), 0.00273972603) - 1); // this float is 1.0/365
        return initialPopulation * pow((1 + ratePerDay / 365.0), totalDays);
    }

*/

    bool isValidDate(const std::string& dateStr){
    int day, month, year;

    // Extract day, month, and year from the date string
    if (sscanf(dateStr.c_str(), "%d/%d/%d", &day, &month, &year) != 3)
        return false;

    // Check if the year is valid
    if (year < 1 || year > 9999)
        return false;

    // Check if the month is valid
    if (month < 1 || month > 12)
        return false;

    // Get the maximum number of days in the month
    int daysInMonth = 31;   
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        daysInMonth = 30;
    }

    // Check if the day is valid
    if (day < 1 || day > daysInMonth)
        return false;

    return true;
    }

    double getPopulationOnValidDate(){
    string date;

    while (true){
        cout << "Enter a date (DD/MM/YYYY): ";
        getline(std::cin, date);

        if (isValidDate(date)){
            int day, month, year;
            sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);

            int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                daysInMonth[1] = 29;

            int totalDays = 0;
            for (int i = 1; i < month; i++)
                totalDays += daysInMonth[i - 1];
            totalDays += day;

            double popRatio = getFinalPopulation() / static_cast<double>(popVars::initialPopulation);

            double ratePerDay = 365 * (pow(popRatio, 0.00273972603) - 1); // This float is 1.0/365
            return popVars::initialPopulation * pow((1 + ratePerDay / 365.0), totalDays);
        }
        else cout << "Invalid date entered! Please enter a valid date." << endl;
    }
}

    popVars(){
        initialPopulation = 0;
        birthRate = 0;
        deathRate = 0;
    }
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

class vacVars : public diseaseVars
{
public:
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
unsigned long ValidateInitPop() {
    string input;
    unsigned long initPop;
    while (true) {
        cout << "Enter initial population: ";
        getline(cin, input);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        
        stringstream ss(input);
        if (ss >> initPop) {
            char remaining;
            if (!(ss >> remaining)) {
                break; // No remaining characters, valid input
            }
        }
        cout << "Enter valid initial population." << endl;
    }
     // v.initialPopulation = initPop;
    return initPop;
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
            if (infday1 >= 0 && infday1<=v.initialPopulation) { // Validate the birth rate range && >= pop
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

double ValidateContRate() {
    string input;
    double contactRate;
    while (true) {
        cout << "Enter contact rate: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> contactRate) {
            if (contactRate >= 0) { 
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid contact rate:" << endl;
    }
    return contactRate;
}

int ValidateIso() {
    string input;
    int iso;
    while (true) {
        cout << "Enter no. of days after incubation period when the patients self isolate themselves: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> iso) {
            if (iso >= 0) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid no of days before isolation:" << endl;
    }
    return iso;
}

int ValidateVac() {
    string input;
    int vac;
    while (true) {
        cout << "Enter no. of days after onset, when vaccine is invented: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> vac) {
            if (vac >= 0) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid no. of days when vaccine is invented: " << endl;
    }
    return vac;
}

float ValidateEff() {
    string input;
    float eff;
    while (true) {
        cout << "Enter vaccine efficiency: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> eff) {
            if (eff >= 0 && eff<=1) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter valid efficiency: " << endl;
    }
    return eff;
}

float ValidateRateOfVac() {
    string input;
    float rateVac;
    while (true) {
        cout << "Enter avg. no. of people vaccinated per day: ";
        getline(cin, input);
        stringstream ss(input);
        if (ss >> rateVac) {
            if (rateVac >= 0 && stoi(input) <= v.getFinalPopulation()) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining)) {
                    break; // No remaining characters, valid input
                }
            }
        }
        cout << "Enter proper rate of vaccination: " << endl;
    }
    return rateVac;
}
void prompt(){
    char userInput;
    do{
        cout << "Do you want to enter custom-input? ";
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(userInput=='y' || userInput=='Y'){
            // ask for initial pop... etc.
            v.initialPopulation =  ValidateInitPop();
            v.birthRate=ValidateBirthRate();
            v.deathRate=ValidateDeathRate();
            v.infectedPeopleDay1 = ValidateInfday1();
            v.transmissionRate = ValidateTransRate();
            v.recoveryRate =  ValidateRecRate();
            v.incubationPeriod =  ValidateIncPrd();       
            break;
        }
        else if(userInput=='n' || userInput=='N'){
            for(int i=0;i<62;i++){
                if(tolower(s[i].name) == tolower(userInput)){
                    // ask the user for inputs
                }
            }

        }
        
        else cout << "Enter Y/N "<<endl;

    } while(true);
}

void mandatory(){
     
}

int main() {
    prompt();
    v.contactRate = ValidateContRate();
    v.iso = ValidateIso();
    v.vac = ValidateVac();
    v.efficiency = ValidateEff();
    v.rateVac = ValidateRateOfVac();
    double deathRate = ValidateDeathRate();
    int infectedDay1 = ValidateInfday1();
    double transmissionRate = ValidateTransRate();
    cout << "Enter date: ";
    cout << v.getPopulationOnValidDate();
    return 0;
}