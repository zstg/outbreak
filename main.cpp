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

int welcome(){
    cout << "Welcome to our program - Predict, Prepare, Prevail!!!"<<endl<<"Predict and mitigate the spread of diseases using our epidemic simultaion tool."<<endl<<"This program has several functions for calculating the population data of various regions.The program has the option to use presets (if you want this option, select `y` in the prompt that follows.)" << endl << endl;
    return 0;
}

bool isInt(string e) {
    try {
        stoi(e);
        return true;
    } 
    catch (const exception&) {
        return false;
    }
}


char changeCase (char c) {
    // this function converts a character to lowercase
    return tolower(static_cast<unsigned char>(c)); 
}

string lower(string str) {
    // uses changeCase to convert to lowercase
    transform(str.begin(), str.end(), str.begin(), changeCase);
    return str;
}

int dateSplit(string& dateString,int& day, int& month, int& year) {
    // this function splits the date into day, month and year
    // Find the positions of the slashes
    size_t firstSlashPos = dateString.find('/');
    size_t secondSlashPos = dateString.find('/', firstSlashPos + 1);

    // Extract day, month, and year substrings
    string dayString = dateString.substr(0, firstSlashPos);
    string monthString = dateString.substr(firstSlashPos + 1, secondSlashPos - firstSlashPos - 1);
    string yearString = dateString.substr(secondSlashPos + 1);

    // Convert the substrings to integers
    day = stoi(dayString);
    month = stoi(monthString);
    year = stoi(yearString);
    return day << month << year;
    // this function is never called directly

    // when this function is called, call as ```int day, month, year;```
    // ```dateSplit(dateString, day, month, year);```
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

#include <string>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

std::string dateFromDays(int n) {
    // Takes nth day as an argument and returns the date in dd/mm/yyyy format
    int dd = 0;
    int mm = 0;
    int yyyy = 2023;
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    while (n > 365) {
        n-=365;
        yyyy++;
    }

    for(int i=0;i<13;i++){
        int sum=0;
        if(sum<n){
            sum+=daysInMonth[i];
            mm++;
            n-=daysInMonth[i];
        }
    }
    dd=n+31;
    std::string date = std::to_string(dd) + "/" + std::to_string(mm) + "/" + std::to_string(yyyy);
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

    int nthDay(int dd,int mm,int yyyy){
        // returns the nth day of the year
        int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int n_day = 0;
        for(int i=0;i<mm-1;i++){
            n_day+=daysInMonth[i];
        }
        n_day+=dd;
        return n_day;
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
    long res = ((n-noOfDaysAfterOnsetWhenVacWasDiscovered-isolationPeriod))* pow(n-noOfDaysAfterOnsetWhenVacWasDiscovered-isolationPeriod,recRate/transRate)*pow(rateOfVac,1.1+efficiency)/500;
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
    if (initialPopulation < 0 || initialPopulation > getFinalPopulation())
        return false;
    return true;
}

bool isValidInfDay1(int infDay1){
    // Validate initially infected citizens
    if (infDay1 < 0 || infDay1 > getFinalPopulation())
        return false;
    return true;
}


bool isValidBirthRate(double birthRate){
    // Validate birth/death rate
    if (birthRate < 0 || birthRate > 1000)
        return false;
    return true;
}


bool isValidTransRate(double transRate){
    // Validate transmission rate/ recovery rate
    if (transRate <0 || transRate > 1) // <=, >= ??
        return false;
    return true;
}
bool isValidEff(double eff){
    // Validate efficiency
    if (eff <0 || eff > 1) // <=, >= ??
        return false;
    return true;
}
bool isValidRateOfVac(float rateOfVac){
    // Validate rate of vaccination
    if (rateOfVac < 0) // verify that no of ppl vaccinated < final population
        return false;
    return true;
}


bool isValidContRate(double contRate){
    // Validate contact rate
    if (contRate < 0 || contRate > 2) // few people might be in contact with a large number of people, but the sample size brings the avg down
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
    cout << "\t\t -------------------------------------------------------------------------------------"<<endl;
    cout << "\t\t|                                       MAIN MENU                                     |"<<endl;
    cout << "\t\t| 1. Infected people on a given date                                                  |"<<endl;
    cout << "\t\t| 2. Infected percentage of ppl                                                       |"<<endl;
    cout << "\t\t| 3. Date when the entire city recovers                                               |"<<endl;
    cout << "\t\t| 4. New cases on a given date                                                        |"<<endl;
    cout << "\t\t| 5. Rate change on a given date                                                      |"<<endl;
    cout << "\t\t| 6. Number of affected, infected and recovered people from day 1                     |"<<endl; 
    cout << "\t\t| 7. Perform all operations                                                           |"<<endl;
    cout << "\t\t| 8. Print this menu                                                                  |"<<endl;
    cout << "\t\t| 9. Quit                                                                             |"<<endl; // or q,Q
    cout << "\t\t -------------------------------------------------------------------------------------"<<endl;
    cout<<endl;

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

        cout << "Enter the avg number of days after the incubation period when the people isolate themselves: ";
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

        cout << "Enter avg no of people vaccinated per day: ";
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
    cout << endl << "Enter your choice [1-8], 8/m for menu, 9/q to quit: ";
    cin >> choice;
    //cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (choice !="1" && choice !="2" && choice !="3" && choice !="4" && choice !="5" && choice !="6" && choice !="7" && choice !="8" && choice !="9" && choice!="m" && choice!="q"){
        cout << "Invalid choice. Enter again: ";
        cin >> choice;
        break;
    }

    if (choice == "1"){
        int dd, mm, yyyy;
        string ds;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> ds;
        dateSplit(ds,dd,mm,yyyy);
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> ds;
            dateSplit(ds,dd,mm,yyyy);
        }
        long flag = v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy));
                    // no of infected ppl on that date - no of recovered on that date
        //if(flag<0) cout << "Zero";
        cout << endl << "The number of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << fixed << (int)v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy)) << endl;
    }
    if (choice == "2"){
        int dd, mm, yyyy;
        string ds;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> ds;
        dateSplit(ds,dd,mm,yyyy);
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> ds;
            dateSplit(ds,dd,mm,yyyy);
        }
        long flag = v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy));
        cout << endl<< "The percentage of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy))) / getFinalPopulation() * 100 << "%" << endl;
    }
     if (choice == "3"){
        int k=0;
         for(unsigned long long  i=1;i<36525;i++){
             if(v.infectedAfterNDays(i) - v.recoveredAfterNDays(i) <= 0){
                 cout << "The city is expected to recover on " << dateFromDays(i) << endl;
                 k=1;
                 break;
            }
         }
         if(k==0)
            cout << "The efficiency of the vaccine/ rate of vaccination is too low - the city won't recover even after 100 years!!"<<endl;
    }
    if (choice == "4"){
        int dd, mm, yyyy;
        string ds;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> ds;
        dateSplit(ds,dd,mm,yyyy);
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> ds;
            dateSplit(ds,dd,mm,yyyy);
        }
        if((v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy)))>0)
            cout << endl<<"The number of new cases on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy))) << endl;
        else
            cout << endl<<"There have been no new cases on "<< dd << "/" << mm << "/" << yyyy << endl ;
        }
    if (choice == "5"){
        int dd, mm, yyyy;
        string ds;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> ds;
        dateSplit(ds,dd,mm,yyyy);
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> ds;
            dateSplit(ds,dd,mm,yyyy);
        }
        double flag = ((v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy))))/ ((v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) - v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy)))) * 100;
        if(flag>0)
            cout << endl << "The rate of change on " << dd << "/" << mm << "/" << yyyy << " is " <<flag << "% more than the previous day"<< endl;
        else
            cout << endl << "The rate of change on " << dd << "/" << mm << "/" << yyyy << " is " << -1*flag << "% less than the previous day" << endl;
    }

    if(choice=="6"){
        int nodays;
        cout << "Enter the number of days for which you want to get the data for: ";
        cin >> nodays;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        while(static_cast<int>(nodays) != nodays || cin.fail() || nodays<0 ){
            cout << "Enter valid no of days: ";
            cin.clear();  // Clear the fail state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
            cin >> nodays;
        }
        int nodaysInt = static_cast<int>(nodays);  // Convert nodays to an int
        cout << endl;
        for(int i=0;i<nodaysInt;i++)
            cout<< fixed << "Day " << i +1 << "- Infected:" << v.infectedAfterNDays(i) << ", recovered: "<< (int)v.recoveredAfterNDays(i) << ", currently infected people: " << diff(v.infectedAfterNDays(i),v.recoveredAfterNDays(i)) << endl;
        cout << endl;
    }

    if(choice=="7"){
        int dd, mm, yyyy;
        string ds;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> ds;
        dateSplit(ds,dd,mm,yyyy);
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> ds;
            dateSplit(ds,dd,mm,yyyy);
        }

        cout << endl;

        // 1. no of infected ppl on that date - no of recovered on that date
        cout << "➜ The number of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << fixed << v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy)) << endl;

        // 2. Infected percentage of ppl
        cout << "➜ " << fixed << (v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy))) / getFinalPopulation() * 100 << "% of the state has been affected on " << dd << "/" << mm << "/" << yyyy << endl;

        // 3. Date when the entire city recovers
        int k=0;
        for(unsigned long long  i=1;i<36525;i++){
             if(v.infectedAfterNDays(i) - v.recoveredAfterNDays(i) <= 0){
                 cout << "The city is expected to recover on " << dateFromDays(i) << endl;
                 k=1;
                 break;
            }
         }
         if(k==0)
            cout << "The efficiency of the vaccine/ rate of vaccination is too low - the city won't recover even after 100 years!!"<<endl;

        // 4. New cases on a given date
        if((v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy)))>0)
            cout << "The number of new cases on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy))) << endl;
        else
            cout << "There have been no new cases on "<< dd << "/" << mm << "/" << yyyy << endl ;

        // 5. Rate change on a given date
        double flag = ((v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy))))/ ((v.infectedAfterNDays(v.nthDay(dd-2,mm,yyyy)) - v.recoveredAfterNDays(v.nthDay(dd-2,mm,yyyy)))) * 100;
        if(flag>0)
            cout << "The rate of change on " << dd << "/" << mm << "/" << yyyy << " is " <<flag << "% more than the previous day"<< endl;
        else
            cout << "The rate of change on " << dd << "/" << mm << "/" << yyyy << " is " << -1*flag << "% less than the previous day" << endl;

      }

    if(choice=="8" || lower(choice)=="m") printmenu();

    if(choice == "9" || lower(choice) == "q"){ // weirdly quit and exit don't work
        cout << "Thank you for using the program!" << endl;
        cout << "PRs welcome at https://github.com/zstg/outbreak "<<"!!"<<endl;
        exit(0);
        }

    return 0;
    }
}

int main(){
    // welcome();
    // prompt1();
    // prompt2();
    // printmenu();
    while(true)
        ask();
 
    return 0;     
}
