#include <iostream>
#include <cmath>
// #include "./states_data.h"
using namespace std;
int dayOfYear(int,int,int);
// extern
class popVars{
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
		double dthDayPop(int dd, int mm, int yy){
			int doy = dayOfYear(dd,mm,yy);
			return initPop*pow(1 + ratePerDay()/100.0,doy);
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

int main(){
	popVars pV;
	// access the state's name as input
	pV.initPop  = 142800000;
	pV.birthRate = 16.42;
	pV.deathRate = 9.64;
	cout << pV.ratePerDay() << endl;
	cout << pV.dthDayPop(2*365)<< endl;
	// cout << pV.dthDayPop(2*365) << endl;
	// receive a DATE input (as DD/MM/YYYY) and


}
