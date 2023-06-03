#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include "States.h"
#include "Diseases.h"
using namespace std;

class popVars {
public:
    int initialPopulation;
    long double birthRate;
    long double deathRate;
    long finalPopulation;

    long double getFinalPopulation()
    {   
        finalPopulation = initialPopulation + (initialPopulation * (birthRate - deathRate) / 1000);
        return initialPopulation + (initialPopulation * (birthRate - deathRate) / 1000); 
    }
    

bool isValidDate(const std::string dateStr) {
    int day, month, year;

    // Extract day, month, and year from the date string
    if (sscanf(dateStr.c_str(), "%d-%d-%d", &day, &month, &year) != 3){

        cout << day<<endl;
        cout << month<<endl;
        cout << year<<endl;
    
          return false;
    }

    if (year < 1 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;

    int daysInMonth = 31;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
        }
        
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }

    // Check if the day is valid
    if (day < 1 || day > daysInMonth) {
        return false;
    }

    return true;
}

double nthDay(){
        string date;
        bool isValid = false; // Initialize isValid to true
        while (!isValid) {
        cout << "Enter a date (DD/MM/YYYY): ";
        getline(cin, date);
        //cin.ignore(); // Clear the input buffer
        isValid = isValidDate(date);
        }   

        int day, month, year;
        sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);

        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth[1] = 29;

        int totalDays = 0;
        for (int i = 1; i < month; i++)
            totalDays += daysInMonth[i - 1];
        totalDays += day;
        return totalDays;
    }

double nthDay(string date){
        bool isValid = false; // Initialize isValid to true
        while (!isValid) {
        //cin.ignore(); // Clear the input buffer
        isValid = isValidDate(date);
        }   

        int day, month, year;
        sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);

        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth[1] = 29;

        int totalDays = 0;
        for (int i = 1; i < month; i++)
            totalDays += daysInMonth[i - 1];
        totalDays += day;
        return totalDays;
    }

double getPopulationOnValidDate() {
    string date;
    bool isValid = false; // Initialize isValid to true
    while (!isValid) {
    cout << "Enter a date (DD/MM/YYYY): ";
    getline(cin, date);
    //cin.ignore(); // Clear the input buffer
    isValid = isValidDate(date);
    }   

    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    int totalDays = 0;
    for (int i = 1; i < month; i++)
        totalDays += daysInMonth[i - 1];
    totalDays += day;

    double popRatio = getFinalPopulation() / (double)(popVars::initialPopulation);

    double ratePerDay = 365 * (pow(popRatio, 0.00273972603) - 1); // This float is 1.0/365
    return popVars::initialPopulation * pow((1 + ratePerDay / 365.0), totalDays);
}

double getPopulationOnValidDate(int nth) {
    double popRatio = getFinalPopulation() / (double)(popVars::initialPopulation);
    double ratePerDay = 365 * (pow(popRatio, 0.00273972603) - 1); // This float is 1.0/365
    return popVars::initialPopulation * pow((1 + ratePerDay / 365.0), nth);
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
    double recoveredPplAfterNVacDays(int no, int vac){
        // naturally-recovering
        return (infectedPeopleDay1 * pow(1 - transmissionRate, no * contactRate)) 
                // + vaccine
               + infectedPeopleDay1 * transmissionRate * recoveryRate * pow(1 + efficiency, no + vac - (iso + incubationPeriod) * contactRate) 
               // -both
               - (rateVac * vac * efficiency * pow(infectedPeopleDay1 * transmissionRate * (1 - recoveryRate), no + vac - (iso + incubationPeriod) * contactRate - 1));
    }
};

vacVars v;
double getFinalPopulation(){
        return v.initialPopulation + (v.initialPopulation * (v.birthRate - v.deathRate) / 1000);
    }

double getFinalPopulation(int x, float b, float d){
        return x + (x * (b - d) / 1000);
    }


unsigned long ValidateInitPop(){
    string input;
    unsigned long initPop;
    cout << "Enter initial population: ";
    getline(cin, input);    
    stringstream ss(input);

    if (ss >> initPop) {
        char remaining;
        if (!(ss >> remaining))
            return initPop ; // No remaining characters, valid input
        }
        // cout << "Invalid initial population. ";
    return ValidateInitPop();
    }


double ValidateBirthRate() {
    string input;
    double br;
    cout << "Enter birth rate: ";
    getline(cin, input);
    stringstream ss(input);
        if (ss >> br && br >= 0 && br <= 1000) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining))
                    return br; // No remaining characters, valid input
            }
            // cout << "Invalid birth rate. ";
        return ValidateBirthRate();
    }

double ValidateDeathRate() {
    string input;
    double dr;
    cout << "Enter death rate: ";
    getline(cin, input);
    stringstream ss(input);
        if (ss >> dr && dr >= 0 && dr <= 1000) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining))
                    return dr; // No remaining characters, valid input
            }
            // cout << "Invalid death rate. ";
        return ValidateDeathRate();
    }

int ValidateInfday1() {
    string input;
    int infday1;
    cout << "Enter no of ppl who are infected on day 1: ";
    getline(cin, input);
    stringstream ss(input);
        if (ss >> infday1 && infday1 >= 0 && infday1<=v.initialPopulation) { // Validate the birth rate range && >= pop
                char remaining;
                if (!(ss >> remaining))
                    return infday1; // No remaining characters, valid input
            }
        // cout << "Invalid no of infected people on day 1";
        return ValidateInfday1();
    }


double ValidateTransRate() {
    string input;
    double tr;

    cout << "Enter transmission rate: ";
    getline(cin, input);
    stringstream ss(input);

        if (ss >> tr && tr>=0 && tr<=1){ // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining))
                    return tr; // No remaining characters, valid input
            }
            //cout << "Invalid transmission rate. ";
        return ValidateTransRate();
    }

double ValidateRecRate() {
    string input;
    double rr;

    cout << "Enter recovery rate: ";
    getline(cin, input);
    stringstream ss(input);

        if (ss >> rr && rr>=0 && rr<=1) { // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining))
                    return rr; // No remaining characters, valid input
            }
            // cout << "Invalid recovery rate. ";
        return ValidateRecRate();
    }



int ValidateIncPrd() {
    string input;
    int incprd;

    cout << "Enter incubation period: ";
    getline(cin, input);
    stringstream ss(input);

    if (ss >> incprd && incprd >= 0 && incprd <= 100) { // Validate the birth rate range
            char remaining;
            if (!(ss >> remaining))
                return incprd; // No remaining characters, valid input
        }
        // cout << "Invalid incubation period. ";
    return ValidateIncPrd();
}

double ValidateContRate() {
    string input;
    double contactRate;

    cout << "Enter contact rate: ";
    getline(cin, input);
    stringstream ss(input);

    if (ss >> contactRate && contactRate >= 0) {
        char remaining;
        if (!(ss >> remaining))
            return contactRate; // Valid input, return the contact rate
    }
    // cout << "Invalid contact rate. ";
    return ValidateContRate(); // Recursively call the function for valid input
}

int ValidateIso() {
    string input;
    int iso;
        
    cout << "Enter no. of days after incubation period when the patients self isolate themselves: ";
    getline(cin, input);
    stringstream ss(input);

    if (ss >> iso && iso >= 0) { // Validate the birth rate range
        char remaining;
            if (!(ss >> remaining)) return iso;
    }        
    // cout << "Invalid isolation period."
    return ValidateIso();
}
                

int ValidateVac() {
    string input;
    int vac;

    cout << "Enter no. of days after onset, when vaccine is invented: ";
    getline(cin, input);
    stringstream ss(input);

    if (ss >> vac && vac>=0) { // Validate the birth rate range
            char remaining;
            if (!(ss >> remaining))
                return vac; // No remaining characters, valid input
        }
    // cout << "Invalid vaccine discovery day. "
    return ValidateVac();
}

float ValidateEff() {
    string input;
    float eff;

    cout << "Enter vaccine efficiency: ";
    getline(cin, input);
    stringstream ss(input);

    if (ss >> eff && eff >= 0 && eff<=1) { // Validate the birth rate range
            char remaining;
            if (!(ss >> remaining))
                return eff; // No remaining characters, valid input
        }
        // cout << "Invalid vaccine efficiency. "
    return ValidateEff();
}


float ValidateRateOfVac() {
    string input;
    float rateVac;

    cout << "Enter avg. no. of people vaccinated per day: ";
    getline(cin, input);
    stringstream ss(input);

        if (ss >> rateVac && rateVac >=0 && stoi(input)<=getFinalPopulation()){ // Validate the birth rate range
                char remaining;
                if (!(ss >> remaining))
                    return rateVac; // No remaining characters, valid input 
            }
            // cout << "Invalid no of ppl vaccinated per day. "
        return ValidateRateOfVac();
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
            States s[65];
            float br, dr;
            unsigned long ip;
            genData(s);
            cout << "Enter state name: ";            
            string stateinp;
            cin >> stateinp;
            for(int i=0;i<=62;i++){
                if(stateinp==s[i].Name){
                    br=s[i].birthRate;
                    dr = s[i].deathRate;
                    ip = s[i].initPop;
                }
                //else cout << "State not present in database"<<endl;
            }
            v.birthRate = br;
            v.deathRate = dr;
            v.initialPopulation = ip;

            Diseases d[105];
            genDiseases(d);
            double tr, recr;
            int inc;
            cout << "Enter disease name (or ICD ID): ";
            string diseaseName;
            cin >> diseaseName;
            for(int i=0;i<=101;i++){
                if(diseaseName==d[i].Disease){
                    tr = d[i].TransRate;
                    recr = d[i].RecRate;
                    inc = d[i].IncPeriod;
                }
            }
            v.transmissionRate = tr;
            v.recoveryRate = recr;
            v.incubationPeriod = inc;
            v.infectedPeopleDay1 = ValidateInfday1();
            break;
        }
        
        else cout << "Enter Y/N !"<<endl;

    } while(true);
}

string ask(){
    string dateinp;
    string userdateinp;
    while(true){
        // cout<< "Enter the date: ";
        // cin >> userdateinp;
        if (v.isValidDate(userdateinp)==true){
            dateinp = userdateinp;
            }
        else ask();
    }
    return dateinp;
}

double infectedPplAfterNDays(int no){   
        if(v.infectedPeopleDay1 * pow((1 + v.transmissionRate), (no * v.contactRate))>v.initialPopulation){
            return v.getPopulationOnValidDate(v.nthDay(ask()));
        }
        else
            return v.infectedPeopleDay1 * pow((1 + v.transmissionRate), (no * v.contactRate));
    }

double recoveredPplAfterNVacDays(int no)
    {
        // naturally-recovering
        return (v.infectedPeopleDay1 * pow(1 - v.transmissionRate, no * v.contactRate))                                                              // + vaccine
               + v.infectedPeopleDay1 * v.transmissionRate * v.recoveryRate * pow(1 + v.efficiency, no + v.vac - (v.iso + v.incubationPeriod) * v.contactRate) // -both
               - (v.rateVac * v.vac * v.efficiency * pow(v.infectedPeopleDay1 * v.transmissionRate * (1 - v.recoveryRate), no + v.vac - (v.iso + v.incubationPeriod) * v.contactRate - 1));
    }


int main() {
    prompt();
    v.contactRate = ValidateContRate();
    cout << fixed << infectedPplAfterNDays(v.nthDay()) << "\n";
    cout << fixed << recoveredPplAfterNVacDays(v.nthDay()) << "\n";
    return 0;
}