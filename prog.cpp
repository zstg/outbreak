#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctype.h>

#include "States.h"
#include "Diseases.h"

using namespace std;
States s[65];
Diseases d[105];

char changeCase (char c) {
    // this function converts a character to lowercase
    return std::tolower(c); 
}

string lower(string str) {
    // uses changeCase to convert to lowercase
    transform(str.begin(), str.end(), str.begin(), changeCase);
    return str;
}

bool isValidDate(int dd, int mm, int yyyy){
    // returns True if a date is valid; performs date checks
    if (mm < 1 || mm > 12 || yyyy < 0 || yyyy>9999 ||  dd < 1 || dd > 31)
        return false;
    int daysInMonth = 31;
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        daysInMonth = 30;
    else if (mm == 2){
        if (yyyy % 4 == 0 && yyyy % 100 != 0 || yyyy % 400 == 0)
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    return (dd >= 1 && dd <= daysInMonth);
    }

string dateFromDays(int n){
   // take nth day as an arg, return the date in dd/mm/yyyy format
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int dd, mm, yyyy;
    if (n <= 31){
        dd = n;
        mm = 1;
        yyyy = 2023;
    }
    else{
        int i = 0;
        while (n > daysInMonth[i]){
            n -= daysInMonth[i];
            i++;
        }
        dd = n;
        mm = i + 1;
        yyyy = 2023;
    }
    // make it return a string
    string date = to_string(dd) + "/" + to_string(mm) + "/" + to_string(yyyy);
    return date;
}

class Pop {
public:
    int initialPopulation;
    long double birthRate;
    long double deathRate;
    long finalPopulation;


    Pop(){
        initialPopulation = 0;
        birthRate = 0;
        deathRate = 0;
    }
    Pop(int initialPop, double birthR, double deathR) {
        initialPopulation = initialPop;
        // birthRate = birthR;
        deathRate = deathR;

    }

    long getFinalPopulation(){ // this func shdn't take any args
        return initialPopulation + (initialPopulation * (birthRate - deathRate) / 1000);
        finalPopulation = initialPopulation + (initialPopulation * (birthRate - deathRate) / 1000);
    }



    double nthDay(int dd, int mm, int yyyy){
        // return which day of the year "date" is
        int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(yyyy % 4 == 0 && yyyy % 100 != 0 || yyyy % 400 == 0)
            daysInMonth[1] = 29; // account for leap Febs
        int dayOfYear = 0;
        for(int i = 0; i < mm - 1; i++)
            dayOfYear += daysInMonth[i];
        dayOfYear += dd;
        return dayOfYear;
        
    }
    
    double PopOnDate(int n_day){
        // return the population on the nth day of the year
        return initialPopulation  * pow(getFinalPopulation()/initialPopulation,n_day/365.0);
    }
// either take the 'n'th day of the year or the date in dd/mm/yyyy format

    double PopOnDate(int dd, int mm, int yyyy){
        // return the population on the date dd/mm/yyyy
        int n_day = nthDay(dd, mm, yyyy);
        return initialPopulation  * pow(getFinalPopulation()/initialPopulation,n_day/365.0);
    }
    
};    

class Dis:public Pop{
public:
    int infDay1;
    double transRate, recRate, contRate;
    int incubationPeriod;

    long infectedAfterNDays(int n){
        if(infDay1 + pow(1+contRate,n*1.1*transRate/recRate) < initialPopulation)
            return infDay1 + pow(1+contRate,n*1.1*transRate/recRate);
        else
            return getFinalPopulation();
        }
};

class Vac:public Dis{
public:
    float efficiency;
    int noOfDaysAfterOnsetWhenVacWasDiscovered;
    int isolationPeriod;
    float rateOfVac;

    double recoveredAfterNDays(int n){ // INT VAC?
    long res = ((n-noOfDaysAfterOnsetWhenVacWasDiscovered-isolationPeriod))* pow(n-noOfDaysAfterOnsetWhenVacWasDiscovered-isolationPeriod,recRate/transRate)*pow(rateOfVac,1.1+efficiency)/100;
    if(n<noOfDaysAfterOnsetWhenVacWasDiscovered+isolationPeriod)
        return 0;
    else if(res > getFinalPopulation())
        return getFinalPopulation();
    else
        return res;
    }
};

Vac v;
double getFinalPopulation(){
        return v.initialPopulation + (v.initialPopulation * (v.birthRate - v.deathRate) / 1000);
    }


bool isValidInitialPopulation(int initialPopulation){
    // Validate initial population
    if (initialPopulation < 0 && initialPopulation > getFinalPopulation())
        return false;
    return true;
}

bool isValidInfDay1(int infDay1){
    // Validate initially infected citizens
    if (infDay1 < 0 && infDay1 > getFinalPopulation())
        return false;
    return true;
}


bool isValidBirthRate(double birthRate){
    // Validate birth/death rate
    if (birthRate < 0 && birthRate > 1000)
        return false;
    return true;
}


bool isValidTransRate(double transRate){
    // Validate transmission rate/ recovery rate
    if (transRate <0 && transRate > 1) // <=, >= ??
        return false;
    return true;
}
bool isValidEff(double eff){
    // Validate efficiency
    if (eff <0 && eff > 100) // <=, >= ??
        return false;
    return true;
}
bool isValidRateOfVac(float rateOfVac){
    // Validate rate of vaccination
    if (rateOfVac < 0 && rateOfVac > 1) // verify that no of ppl vaccinated < final population
        return false;
    return true;
}


bool isValidContRate(double contRate){
    // Validate contact rate
    if (contRate < 0 || contRate > 2) // 1 person can pass the disease to ANY no of ppl, but this has a practical limit
        return false;
    return true;
}

bool isState(string state){
    // returns true if state is pres in header
    for(int i=0;i<65;i++){
        if(lower(state)==lower(s[i].Name)) // s has already been defined at the beginning of the program
            return true;
    }
    return false;
}

bool isDis(string dis){
    // returns true if disease is present in header
    for(int i=0;i<105;i++){
        if(lower(dis)==lower(d[i].Disease)) // d has already been defined at the beginning of the program
            return true;
    }
    return false;
}

int diff(int a, int b){
    // function created for a purpose
    if(a>b){
        return a-b;
    }
    else{
        return 0;
    }
}

int printmenu(){
    // simple function to print interactive menu
    cout << endl;
    cout << "1. Infected people on a given date: "<<endl;
    cout << "2. Infected percentage of ppl"<<endl;
    cout << "3. Date when the entire city recovers"<<endl;
    // cout << "4. Date when the entire city is infected"; // too negative
    cout << "4. New cases on a given date"<<endl;
    cout << "5. Rate change on a given date"<<endl;
    cout << "6. Number of affected, infected and recovered people from day 1"<<endl; 
    cout << "7. Print this menu"<<endl;
    cout << "8. Perform all operations"<<endl;
    cout << "9. Quit"<<endl; // or q,Q

    return 0;    
  }

void prompt2(){
    // this is a common prompt for all the functions

        cout << "Enter no of people infected on day 1: ";
        cin >> v.infDay1;
        while (cin.fail() || !isValidInitialPopulation(v.initialPopulation) || v.infDay1<0){
            cout << "Invalid no of people infected on day 1. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.infDay1;
        }

        cout << "Enter isolation period: ";
        cin >> v.isolationPeriod;
        while (cin.fail()||!isValidInitialPopulation(v.isolationPeriod)){
            cout << "Invalid isolation period. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.isolationPeriod;
        }

        cout << "Enter efficiency of vaccine: ";
        cin >> v.efficiency;
        while (cin.fail()||!isValidEff(v.efficiency)){
            cout << "Invalid efficiency of vaccine. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.efficiency;
        }

        cout << "Enter rate of vaccination: ";
        cin >> v.rateOfVac;
        while (cin.fail()||!isValidRateOfVac(v.rateOfVac)){
            cout << "Invalid rate of vaccination. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.rateOfVac;
        }

        cout << "Enter no of days after onset when vaccine was discovered: ";
        cin >> v.noOfDaysAfterOnsetWhenVacWasDiscovered;
        while (cin.fail()||!isValidInitialPopulation(v.noOfDaysAfterOnsetWhenVacWasDiscovered)){
            cout << "Invalid no of days after onset when vaccine was discovered. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.noOfDaysAfterOnsetWhenVacWasDiscovered;
        }

        cout << "Enter contact rate: ";
        cin >> v.contRate;
        while (cin.fail()||!isValidContRate(v.contRate)){
            cout << "Invalid contact rate. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.contRate;
        }


}
void prompt1(){
    string userInput;
    cout << "Do you want to enter custom values? (n uses inputs) ";
    cin >> userInput;
    while (lower(userInput)!="yes" && lower(userInput)!="no" && lower(userInput)!="y" && lower(userInput)!="n"){
        cout << "Invalid input. Enter again: ";
        cin >> userInput;
    }

    if (lower(userInput) == "y" || lower(userInput) == "yes" || userInput == "\n"){
        cout << "Enter initial population: ";
        cin >> v.initialPopulation;
        while (!isValidInitialPopulation(v.initialPopulation)){
            cout << "Invalid initial population. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.initialPopulation;
        }

        cout << "Enter birth rate: ";
        cin >> v.birthRate;
        while (cin.fail() || !isValidBirthRate(v.birthRate)){
            cout << "Invalid birth rate. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.birthRate;
        }

        cout << "Enter death rate: ";
        cin >> v.deathRate;
        while (cin.fail() || isValidBirthRate(v.deathRate)){
            cout << "Invalid death rate. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.deathRate;
        }

         cout << "Enter transmission rate: ";
        cin >> v.transRate;
        while (cin.fail() || !isValidTransRate(v.transRate)){
            cout << "Invalid transmission rate. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.transRate;
        }

        cout << "Enter recovery rate: ";
        cin >> v.recRate;
        while (cin.fail() || !isValidTransRate(v.recRate)){
            cout << "Invalid recovery rate. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.recRate;
        }

        cout << "Enter incubation period: ";
        cin >> v.incubationPeriod;
        while (cin.fail() || !isValidInitialPopulation(v.incubationPeriod)){
            cout << "Invalid incubation period. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> v.incubationPeriod;
        }

    }

    else if(lower(userInput)=="no" || lower(userInput)=="n"){
        genData(s);
        genDiseases(d);
        string stateinp, disinp;
        double br, dr;
        unsigned long ip;

        cout << "Enter the state name (eg: Tamil_Nadu): ";
        cin >> stateinp;
        while (!isState(stateinp)){
            cout << "State is not in database. Enter a different one: ";
            cin >> stateinp;
        }
        // if state is in database, get the birth rate, death rate and initial population and assign to the state
        for(int i=0;i<62;i++){
            if(lower(stateinp)==lower(s[i].Name)){
                v.birthRate = s[i].birthRate;
                v.deathRate = s[i].deathRate;
                v.initialPopulation = s[i].initPop;
                }
            }

        cout << "Enter the disease name: "; // _ works here too
        cin >> disinp;
        while (!isDis(disinp)){
            cout << "Disease is not in database. Enter a different one: ";
            cin >> disinp;
            }
        // if disease is in database, get the transmission rate, recovery rate and incubation period and assign to the disease
        for(int i=0;i<105;i++){
            if(lower(disinp)==lower(d[i].Disease)){
                v.transRate = d[i].TransRate;
                v.recRate = d[i].RecRate;
                v.incubationPeriod = d[i].IncPeriod;
                }
            }
        }
}

int ask(){
    string choice;
    while(true){
    cout << "Enter your choice [1-8], 8 for menu, 9 to quit: ";
    cin >> choice;
    while (choice !="1" && choice !="2" && choice !="3" && choice !="4" && choice !="5" && choice !="6" && choice !="7" && choice !="8" && choice !="9" && choice!="m" && choice!="q"){
        cout << "Invalid choice. Enter again: ";
        cin >> choice;
        break;
    }

    if (choice == "1"){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        long flag = v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy));
                    // no of infected ppl on that date - no of recovered on that date
        if(flag<0) cout << "Zero";
        else cout << "The number of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << fixed << v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy)) << endl;
    }
    if (choice == "2"){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        long flag = v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy));
        cout << "The percentage of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy))) / getFinalPopulation() * 100 << "%" << endl;
    }
     if (choice == "3"){
         for(int i=1;i<1000000;i++){
             if(v.infectedAfterNDays(i) - v.recoveredAfterNDays(i) <= 0){
                 cout << "The city recovers on " << dateFromDays(i) << endl;
                 break;
             }
         }
    }
    if (choice == "4"){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        cout << "The number of new cases on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy))) << endl;
    }
    if (choice == "5"){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        cout << "The rate of change on " << dd << "/" << mm << "/" << yyyy << " is " << ((v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy))))/ ((v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) - v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy)))) * 100 << "% more than the previous day"<< endl;
    }

    if(choice=="6"){
        int nodays;
        cout << "Enter the number of days for which you want to get the data for: ";
        cin >> nodays;
        while(cin.fail() || nodays<0){
            cout << "Enter valid no of days: ";
            cin >> nodays;
        }
        for(int i=0;i<nodays;i++){
            cout<< fixed << "Day " << i +1 << "- Infected:" << v.infectedAfterNDays(i) << ", recovered: "<< (int)v.recoveredAfterNDays(i) << ", currently infected people: " << diff(v.infectedAfterNDays(i),v.recoveredAfterNDays(i)) << endl;
        }
    }

    if(choice=="7")
        printmenu();

    if(choice=="8" || choice == "m"){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        // 1. no of infected ppl on that date - no of recovered on that date
        cout << "The number of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy)) << endl;

        // 2. Infected percentage of ppl
        cout << "The percentage of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy))) / getFinalPopulation() * 100 << "%" << endl;

        // 3. Date when the entire city recovers
        for(int i=1;i<1000000;i++){
             if(v.infectedAfterNDays(i) - v.recoveredAfterNDays(i) <= 0){
                 cout << "The city recovers on " << dateFromDays(i) << endl;
                 break;
            }
         }

        // 4. New cases on a given date
        cout << "The number of new cases on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy))) << endl;

        // 5. Rate change on a given date
        cout << "The rate of change on " << dd << "/" << mm << "/" << yyyy << " is " << ((v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy))))/ ((v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) - v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy)))) * 100 << "% more than the previous day"<< endl;

      }

    if(choice=="9" || choice=="q"){
        cout << "Thank you for using our program!" << endl;
        exit(0);
        }
    }
return 0;
}

int main(){
    prompt1();
    prompt2();
    printmenu();
    ask();  

return 0;     
}
