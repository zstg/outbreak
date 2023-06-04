#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctype.h>

#include "/home/stig/Git/outbreak/States.h"
#include "/home/stig/Git/outbreak/Diseases.h"

using namespace std;
States s[65];
Diseases d[105];

bool isValidDate(int dd, int mm, int yyyy){
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

string datefromdays(int n){
   // take nth day as an arg, return the date in dd/mm/yyyy format
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int dd, mm, yyyy;
    if (n <= 31){
        dd = n;
        mm = 1;
        yyyy = 0;
    }
    else{
        int i = 0;
        while (n > daysInMonth[i]){
            n -= daysInMonth[i];
            i++;
        }
        dd = n;
        mm = i + 1;
        yyyy = 0;
    }
    cout << dd <<  mm << yyyy << endl;

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

    long double getFinalPopulation(){ // this func shdn't take any args
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

    double infectedAfterNDays(int n){
        if(infDay1 * pow(1+transRate,n*contRate) < getFinalPopulation())
            return infDay1 * pow(1+transRate,n*contRate);
        else
            return getFinalPopulation();
    }
};

class Vac:public Dis{
public:
    float efficiency;
    int noOfDaysAfterOnsetWhenVacWasDiscovered;
    int vac=noOfDaysAfterOnsetWhenVacWasDiscovered;
    int isolationPeriod;
    float rateOfVac;

    double recoveredAfterNDays(int n){ // INT VAC?
    if((infDay1 * pow(1-transRate, n*recRate)) + infDay1 * transRate * recRate * pow(1+efficiency, n+vac-(isolationPeriod+incubationPeriod)*contRate)- rateOfVac * vac * efficiency * pow(infDay1*transRate*(1-recRate) ,n+vac-(isolationPeriod+incubationPeriod)*contRate -1) > getFinalPopulation())
        return getFinalPopulation();
    else
        return (infDay1 * pow(1-transRate, n*recRate)) + infDay1 * transRate * recRate * pow(1+efficiency, n+vac-(isolationPeriod+incubationPeriod)*contRate) - rateOfVac * vac * efficiency * pow(infDay1*transRate*(1-recRate) ,n+vac-(isolationPeriod+incubationPeriod)*contRate -1); 
    }
};

Vac v;
double getFinalPopulation(){
        return v.initialPopulation + (v.initialPopulation * (v.birthRate - v.deathRate) / 1000);
    }

// Validate initial population
bool isValidInitialPopulation(int initialPopulation){
    if (initialPopulation < 0 && initialPopulation > getFinalPopulation())
        return false;
    return true;
}


// REUSE THIS FUNCTION FOR DEATH RATE CHECKING (even tho stupid name)
bool isValidBirthRate(double birthRate){
    if (birthRate < 0 && birthRate > 1000)
        return false;
    return true;
}

// reuse this for recovery rate checking and efficiency checking
bool isValidTransRate(double transRate){
    if (transRate <0 && transRate > 1) // <=, >= ??
        return false;
    return true;
}
bool isValidEff(double eff){
    if (eff <0 && eff > 100) // <=, >= ??
        return false;
    return true;
}
bool isValidRateOfVac(float rateOfVac){
    // vac has to also be lesser than no of days after onset -> taken care of
    if (rateOfVac < 0 && rateOfVac > 1) // verify that no of ppl vaccinated < final population
        return false;
    return true;
}

// REUSE this for isolation period checking and vaccination rate

bool isValidContRate(double contRate){
    if (contRate < 0 || contRate > 2) // 1 person can pass the disease to ANY no of ppl, but this has a practical limit
        return false;
    return true;
}


bool isState(string state){
    for(int i=0;i<65;i++){
        if(state==s[i].Name) // s has already been defined at the beginning of the program
            return true;
    }
    return false;
}

bool isDis(string dis){
    for(int i=0;i<105;i++){
        if(dis==d[i].Disease) // d has already been defined at the beginning of the program
            return true;
    }
    return false;
}

int printmenu(){
    cout << endl;
    cout << "1. Infected people on a given date: "<<endl; // inf-rec
    cout << "2. Infected percentage of ppl"<<endl;
    cout << "3. Date when the entire city recovers"<<endl;
    // cout << "4. Date when the entire city is infected"; // too negative
    cout << "4. New cases on a given date"<<endl;
    cout << "5. Rate change on a given date"<<endl;
    cout << "6. Graph of affected, infected and recovered people"<<endl; // include on 1 graph
    cout << "7. Print this menu"<<endl;
    cout << "8. Perform all operations"<<endl;
    cout << "9. Quit"<<endl; // or q,Q
    cout << endl;

return 0;    
}

void prompt2(){
    // this is a common prompt for all the functions

        cout << "Enter no of people infected on day 1: ";
        cin >> v.infDay1;
        while (v.infDay1 > v.initialPopulation){ // greater than final pop??
            cout << "Invalid no of people infected on day 1. Enter again: ";
            cin >> v.infDay1;
        }

        cout << "Enter isolation period: ";
        cin >> v.isolationPeriod;
        while (!isValidInitialPopulation(v.isolationPeriod)){
            cout << "Invalid isolation period. Enter again: ";
            cin >> v.isolationPeriod;
        }

        cout << "Enter efficiency of vaccine: ";
        cin >> v.efficiency;
        while (!isValidEff(v.efficiency)){
            cout << "Invalid efficiency of vaccine. Enter again: ";
            cin >> v.efficiency;
        }

        cout << "Enter rate of vaccination: ";
        cin >> v.rateOfVac;
        while (!isValidRateOfVac(v.rateOfVac)){
            cout << "Invalid rate of vaccination. Enter again: ";
            cin >> v.rateOfVac;
        }

        cout << "Enter no of days after onset when vaccine was discovered: ";
        cin >> v.noOfDaysAfterOnsetWhenVacWasDiscovered;
        while (!isValidInitialPopulation(v.noOfDaysAfterOnsetWhenVacWasDiscovered)){
            cout << "Invalid no of days after onset when vaccine was discovered. Enter again: ";
            cin >> v.noOfDaysAfterOnsetWhenVacWasDiscovered;
        }

        cout << "Enter contact rate: ";
        cin >> v.contRate;
        while (!isValidContRate(v.contRate)){
            cout << "Invalid contact rate. Enter again: ";
            cin >> v.contRate;
        }


}
void prompt(){
    char userInput;
    userInput = 'y';
    /*
    y or Y or RETURN -> enter custom input
    n or N -> use default values from States.h and Diseases.h
    */
   /* if the user enters y, 
    ask them for the initial population, birth rate, death rate, transmission rate, recovery rate, incubation period.
    In case even 1 of these is invalid, ask them to enter that value again till they enter a valid value.
   */
  
    cout << "Do you want to enter custom values? (y/n) ";
    cin >> userInput;
    while (userInput != 'y' && userInput != 'Y' && userInput != 'n' && userInput != 'N' && userInput != 'q' && userInput != 'Q'){
        cout << "Invalid input. Enter again: ";
        cin >> userInput;
    }



    if (userInput == 'y' || userInput == 'Y' || userInput == '\n'){
        cout << "Enter initial population: ";
        cin >> v.initialPopulation;
        while (!isValidInitialPopulation(v.initialPopulation)){
            cout << "Invalid initial population. Enter again: ";
            cin >> v.initialPopulation;
            break;
        }

        cout << "Enter birth rate: ";
        cin >> v.birthRate;
        while (!isValidBirthRate(v.birthRate)){
            cout << "Invalid birth rate. Enter again: ";
            cin >> v.birthRate;
            break;
        }

        cout << "Enter death rate: ";
        cin >> v.deathRate;
        while (!isValidBirthRate(v.deathRate)){
            cout << "Invalid death rate. Enter again: ";
            cin >> v.deathRate;
            break;
        }

         cout << "Enter transmission rate: ";
        cin >> v.transRate;
        while (!isValidTransRate(v.transRate)){
            cout << "Invalid transmission rate. Enter again: ";
            cin >> v.transRate;
            break;
        }

        cout << "Enter recovery rate: ";
        cin >> v.recRate;
        while (!isValidTransRate(v.recRate)){
            cout << "Invalid recovery rate. Enter again: ";
            cin >> v.recRate;
            break;
        }

        cout << "Enter incubation period: ";
        cin >> v.incubationPeriod;
        while (!isValidInitialPopulation(v.incubationPeriod)){
            cout << "Invalid incubation period. Enter again: ";
            cin >> v.incubationPeriod;
            break;
        }

        }

    else if(userInput=='n' || userInput=='N'){
        genData(s);
        genDiseases(d);
        string stateinp, disinp;
        double br, dr;
        unsigned long ip;

        cout << "Enter the state name: ";
        cin >> stateinp;
        while (!isState(stateinp)){
            cout << "State is not in database. Enter a different one: ";
            cin >> stateinp;
        }
        // if state is in database, get the birth rate, death rate and initial population and assign to the state
        for(int i=0;i<62;i++){
            if(stateinp==s[i].Name){
                v.birthRate = s[i].birthRate;
                v.deathRate = s[i].deathRate;
                v.initialPopulation = s[i].initPop;
                }
            }

        cout << "Enter the disease name: ";
        cin >> disinp;
        while (!isDis(disinp)){
            cout << "Disease is not in database. Enter a different one: ";
            cin >> disinp;
            }
        // if disease is in database, get the transmission rate, recovery rate and incubation period and assign to the disease
        for(int i=0;i<105;i++){
            if(disinp==d[i].Disease){
                v.transRate = d[i].TransRate;
                v.recRate = d[i].RecRate;
                v.incubationPeriod = d[i].IncPeriod;
                }
            }

        
        }
}

int ask(){
    int choice;
    cout << "Enter your choice [1-8], 9 to quit: ";
    cin >> choice;
    while (choice !='1' || choice !='2' || choice !='3' || choice !='4' || choice !='5' || choice !='6' || choice !='7' || choice !='8' || choice !='9'){
        cout << "Invalid choice. Enter again: ";
        cin >> choice;
    }

    if (choice == 1){
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
    if (choice == 2){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        long flag = v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy));
        cout << "The percentage of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy))) / getFinalPopulation() * 100 << endl;
    }
     if (choice == 3){
         // for loop from 1 to 1000000 (say). practically, infected(i) - recovered(i) cannot be zero. so when we do infected(i) - recovered(i) we'll get values for all integers beyond a certain point.
         // stop the loop at the exact point when it reaches zero or goes below it
         for(int i=1;i<1000000;i++){
             if(v.infectedAfterNDays(i) - v.recoveredAfterNDays(i) <= 0){
                 cout << "The city recovers on " << datefromdays(i) << endl;
                 break;
             }
         }
    }
    if (choice == 4){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        // if date 
        cout << "The number of new cases on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy))) << endl;
        // TODO: fix this for 1st dates -> rewrite the nth day function to start from 1/1/70, include years for calc.
    }
    if (choice == 5){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        cout << "The rate of change on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))/ ((v.infectedAfterNDays(v.nthDay(dd,mm,yyyy)) - v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))) * 100 << endl;
    }

    if(choice==7){
        printmenu();
    }
    if(choice==8){
        int dd, mm, yyyy;
        cout << "Enter the date in dd/mm/yyyy format: ";
        cin >> dd >> mm >> yyyy;
        while (!isValidDate(dd, mm, yyyy)){
            cout << "Invalid date. Enter again: ";
            cin >> dd >> mm >> yyyy;
        }
        // no of infected ppl on that date - no of recovered on that date
        cout << "The number of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy)) << endl;
        // 2. Infected percentage of ppl"<<endl;
        cout << "The percentage of infected people on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd, mm, yyyy)) - v.recoveredAfterNDays(v.nthDay(dd, mm, yyyy))) / getFinalPopulation() * 100 << endl;
        // 3. Date when the entire city recovers"<<endl;
        for(int i=1;i<1000000;i++){
             if(v.infectedAfterNDays(i) - v.recoveredAfterNDays(i) <= 0){
                 cout << "The city recovers on " << datefromdays(i) << endl;
                 break;
             }
         }
        // 4. New cases on a given date"<<endl;
        cout << "The number of new cases on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy))) << endl;
        // 5. Rate change on a given date"<<endl;
        cout << "The rate of change on " << dd << "/" << mm << "/" << yyyy << " is " << (v.infectedAfterNDays(v.nthDay(dd,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd,mm,yyyy)))-(v.infectedAfterNDays(v.nthDay(dd-1,mm,yyyy)) -v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))/ ((v.infectedAfterNDays(v.nthDay(dd,mm,yyyy)) - v.recoveredAfterNDays(v.nthDay(dd-1,mm,yyyy)))) * 100 << endl;
        // 6. Graph of affected, infected and recovered people"<<endl; // include on 1 graph
    }
    if(choice==9){
        cout << "Thank you for using our program!" << endl;
        //exit(0);
    }
return 0;
}

int main(){
    prompt();
    prompt2();
    printmenu();
    cout << fixed << v.infectedAfterNDays(0)<<endl;
    cout << fixed << v.recoveredAfterNDays(0)<<endl;
    cout << fixed << v.recoveredAfterNDays(1)<<endl;
    cout << fixed << v.recoveredAfterNDays(2)<<endl;
    ask();  


return 0;     
}
