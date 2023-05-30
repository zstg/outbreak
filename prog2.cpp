#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;



class popVars
{
protected:
    int initialPopulation;
    double birthRate;
    double deathRate;

public:
/*
    popVars()
    {
        int initialPopulation;
        double birthRate;
        double deathRate;
    }
    */

    popVars(int initialPop, double birthR, double deathR)
    {
        initialPopulation = initialPop;
        birthRate = birthR;
        deathRate = deathR;
    }

    double getFinalPopulation()
    {
        return initialPopulation + (initialPopulation * (birthRate - deathRate) / 1000);
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

        double popRatio = (double)(getFinalPopulation() / (double)initialPopulation);

        double ratePerDay = 365 * (pow((double)(getFinalPopulation() / (double)initialPopulation), 0.00273972603) - 1); // this float is 1.0/365
        return initialPopulation * pow((1 + ratePerDay / 365.0), totalDays);
    }
};

class diseaseVars
{
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

/*
INPUTS:
- initial pop
- birth rate
- death rate

- inf ppl on day 1
- trans rate
- contact rate
- recovery rate
- incubation period

- date of first attack
- current date (split)
- days after 1st att, when vaccine was created

OUTPUTS:


*/

/*
TODO:
- debug recovered pop function
*/

int main()
{
    int initPop;
    double br, dr;
    int inf, incprd;
    string date;
    double transrate, contrate, recrate;
    // popVars p;


    cout << "Enter date as DD/MM/YYYY: ";
    cin >> date;
    // split(date);

    cout << "Enter initial population: ";
    cin >> initPop;

    cout << "Enter birth rate: ";
    cin >> br;
    cout << "Enter death rate: ";
    cin >> dr;

    popVars p(initPop, br, dr);

    cout << "No of infected people on day 1";
    cin >> inf;
    cout << "Enter transmission rate: ";
    cin>> transrate;
    cout << "Enter contact rate: ";
    cin>> contrate;
    cout << "Enter recovery rate: ";
    cin >> recrate;

    


}