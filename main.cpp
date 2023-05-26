#include <iostream>
#include <cmath>
using namespace std;
class popVars{
	public:
		float birthRate, deathRate;
		long initPop;
		float popGrowth(){
			return (birthRate-deathRate)/10;
		}
		long finalPop(){return  initPop+ initPop*popGrowth()/100;}
		double ratePerDay(){return pow(100*(1 + popGrowth()/100),1.0/365) - 1;}
		double dthDayPop(int d){return initPop*pow(1 + ratePerDay()/100.0,d);}
};

int main(){
	popVars pV;
	pV.initPop  = 142800000;
	pV.birthRate = 16.42;
	pV.deathRate = 9.64;
	cout << pV.ratePerDay() << endl;
	cout << pV.dthDayPop(2*365)<< endl;
	// cout << pV.dthDayPop(2*365) << endl; // doesn't work??


}
