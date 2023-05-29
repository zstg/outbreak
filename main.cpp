#include <iostream>
#include <cmath>
#include <string>
#include "States.h"
#include "Diseases.h"
// suppose we want to use the States data, do statesObj.func()
using namespace std;
double dthPop(string);
class popVars{
	//friend class diseaseVars;
	public:
		float birthRate, deathRate; // measured per year
		long initPop; // population measured from the beginning (say Jan 1 2023).
		float popGrowth(){
			return (birthRate-deathRate)/10;
		}
		long finalPop(){
			// final population measured after 1 year
			return  initPop+ initPop*popGrowth()/100;
		}
		double ratePerDay(){
			return 100*(-1 + pow(finalPop()/initPop,1.0/365));
		}
		double dthDayPop(string date){
			// return initPop*dthPop(date);
			return initPop*pow(1+ratePerDay()/100,dthPop(date));
		}
};

class diseaseVars:public popVars{
	// friend class popVars;
	public:
		long no_inf;
		float transRate, contactRate, recoveryRate, eff;
		int incubPrd;
		float rateVac;
	// n -> no of days after which a person isolates (n days after)
		int n = n + incubPrd;
		double infPop(int d){
			return no_inf*pow((1+transRate),(d*contactRate));
		}

		double recvPop(int d,int n,int vac){
			long recPopDDays = (infPop(d)*pow(1-transRate,d*contactRate) + (infPop(d)*transRate*recoveryRate*pow(1+eff,d+vac-n*contactRate)) - (rateVac*vac*eff*pow(no_inf*transRate*(1-recoveryRate), d+vac-n*contactRate-1)));
			return recPopDDays;
		}
		int infectedPopAfterDPlusVacDays(int d, int vac){
			return infPop(d) - recvPop(d,n,vac);
		}
};

int dayOfYear(int day, int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;
    // Calculate days in months before the given month
    for (int i = 0; i < month - 1; i++) {
        totalDays += daysInMonth[i];
    }
    // Add days in the given month
    totalDays += day;
    // Add one day for leap years after February
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && month > 2) {
        totalDays++;
    }
    return totalDays;
}
double dthPop(string date){
			string day, month, year;
			size_t firstslash = date.find('/');
			size_t secondslash = date.find('/',firstslash+1);

			day = date.substr(0,firstslash);
			month = date.substr(firstslash+1,secondslash-firstslash-1);
			year = date.substr(secondslash+1);

			int dayInt = stoi(day);
			int monthInt = stoi(day);
			int yearInt = stoi(day);
			int doy = dayOfYear(dayInt,monthInt,yearInt);
			return doy;
			// return pow(1 + popVars::ratePerDay()/100.0,doy);
}

int main(){
	popVars pV;
	States s;
	string dat;
	// access the state's name as input
	pV.initPop  = 142800000;
	pV.birthRate = 16.42;
	pV.deathRate = 9.64;
	cout << pV.ratePerDay() << endl;
	// cout << pV.dthDayPop(2*365)<< endl;
	// cout << pV.dthDayPop(2*365) << endl;
	// receive a DATE input (as DD/MM/YYYY)
	cin >> dat;
}