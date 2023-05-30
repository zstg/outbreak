#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

class States{
  public:
    string Name;
    float birthRate, deathRate;
    unsigned long statePop;
};

int main(){
    States s[63];
    s[0].Name = "Andhra Pradesh";
    s[0].birthRate = 16.8;
    s[0].deathRate = 7.1;
    s[0].statePop = 53000000;

    s[1].Name = "AP";
    s[1].birthRate = 16.8;
    s[1].deathRate = 7.1;
    s[1].statePop = 53000000;

    s[2].Name = "Arunachal Pradesh";
    s[2].birthRate = 18.8;
    s[2].deathRate = 6.0;
    s[2].statePop = 1000000;

    s[3].Name = "AR";
    s[3].birthRate = 18.8;
    s[3].deathRate = 6.0;
    s[3].statePop = 1000000;

    s[4].Name = "Assam";
    s[4].birthRate = 22.0;
    s[4].deathRate = 7.1;
    s[4].statePop = 31000000;

    s[5].Name = "AS";
    s[5].birthRate = 22.0;
    s[5].deathRate = 7.1;
    s[5].statePop = 31000000;

    s[6].Name = "Bihar";
    s[6].birthRate = 26.3;
    s[6].deathRate = 6.2;
    s[6].statePop = 129000000;

    s[7].Name = "BR";
    s[7].birthRate = 26.3;
    s[7].deathRate = 6.2;
    s[7].statePop = 129000000;

    s[8].Name = "Chhattisgarh";
    s[8].birthRate = 23.2;
    s[8].deathRate = 7.5;
    s[8].statePop = 26000000;

    s[9].Name = "Chattisgarh";
    s[9].birthRate = 23.2;
    s[9].deathRate = 7.5;
    s[9].statePop = 26000000;

    s[10].Name = "CG";
    s[10].birthRate = 23.2;
    s[10].deathRate = 7.5;
    s[10].statePop = 26000000;

    s[11].Name = "Delhi";
    s[11].birthRate = 16.4;
    s[11].deathRate = 16.4;
    s[11].statePop = 20000000;

    s[12].Name = "New Delhi";
    s[12].birthRate = 16.4;
    s[12].deathRate = 16.4;
    s[12].statePop = 20000000;

    s[13].Name = "Goa";
    s[13].birthRate = 12.7;
    s[13].deathRate = 6.4;
    s[13].statePop = 1000000;

    s[14].Name = "GA";
    s[14].birthRate = 12.7;
    s[14].deathRate = 6.4;
    s[14].statePop = 1000000;

    s[15].Name = "Gujarat";
    s[15].birthRate = 20.4;
    s[15].deathRate = 6.1;
    s[15].statePop = 73000000;

    s[16].Name = "GJ";
    s[16].birthRate = 20.4;
    s[16].deathRate = 6.1;
    s[16].statePop = 73000000;

    s[17].Name = "Haryana";
    s[17].birthRate = 20.9;
    s[17].deathRate = 6.1;
    s[17].statePop = 30000000;

    s[18].Name = "HR";
    s[18].birthRate = 20.9;
    s[18].deathRate = 6.1;
    s[18].statePop = 30000000;

    s[19].Name = "Himachal Pradesh";
    s[19].birthRate = 16.3;
    s[19].deathRate = 6.6;
    s[19].statePop = 7000000;

    s[20].Name = "HP";
    s[20].birthRate = 16.3;
    s[20].deathRate = 6.6;
    s[20].statePop = 7000000;

    s[21].Name = "Jammu and Kashmir";
    s[21].birthRate = 16.2;
    s[21].deathRate = 4.9;
    s[21].statePop = 15000000;

    s[22].Name = "JK";
    s[22].birthRate = 16.2;
    s[22].deathRate = 4.9;
    s[22].statePop = 15000000;

    s[23].Name = "Jharkhand";
    s[23].birthRate = 23.5;
    s[23].deathRate = 5.8;
    s[23].statePop = 41000000;

    s[24].Name = "JH";
    s[24].birthRate = 23.5;
    s[24].deathRate = 5.8;
    s[24].statePop = 41000000;

    s[25].Name = "Karnataka";
    s[25].birthRate = 17.9;
    s[25].deathRate = 6.6;
    s[25].statePop = 70000000;

    s[26].Name = "KA";
    s[26].birthRate = 17.9;
    s[26].deathRate = 6.6;
    s[26].statePop = 70000000;

    s[27].Name = "Kerala";
    s[27].birthRate = 14.8;
    s[27].deathRate = 6.6;
    s[27].statePop = 35000000;

    s[28].Name = "KL";
    s[28].birthRate = 14.8;
    s[28].deathRate = 6.6;
    s[28].statePop = 35000000;

    s[29].Name = "Madhya Pradesh";
    s[29].birthRate = 25.5;
    s[29].deathRate = 7.5;
    s[29].statePop = 86000000;

    s[30].Name = "MP";
    s[30].birthRate = 25.5;
    s[30].deathRate = 7.5;
    s[30].statePop = 86000000;

    s[31].Name = "Maharashtra";
    s[31].birthRate = 16.3;
    s[31].deathRate = 5.8;
    s[31].statePop = 130000000;

    s[32].Name = "MH";
    s[32].birthRate = 16.3;
    s[32].deathRate = 5.8;
    s[32].statePop = 130000000;

    s[33].Name = "Manipur";
    s[33].birthRate = 14.4;
    s[33].deathRate = 4.0;
    s[33].statePop = 3000000;

    s[34].Name = "MN";
    s[34].birthRate = 14.4;
    s[34].deathRate = 4.0;
    s[34].statePop = 3000000;

    s[35].Name = "Meghalaya";
    s[35].birthRate = 23.7;
    s[35].deathRate = 7.4;
    s[35].statePop = 3000000;

    s[36].Name = "ML";
    s[36].birthRate = 23.7;
    s[36].deathRate = 7.4;
    s[36].statePop = 3000000;

    s[37].Name = "Mizoram";
    s[37].birthRate = 16.2;
    s[37].deathRate = 4.2;
    s[37].statePop = 1000000;

    s[38].Name = "MZ";
    s[38].birthRate = 16.2;
    s[38].deathRate = 4.2;
    s[38].statePop = 1000000;

    s[39].Name = "Nagaland";
    s[39].birthRate = 14.8;
    s[39].deathRate = 3.0;
    s[39].statePop = 2000000;

    s[40].Name = "NL";
    s[40].birthRate = 14.8;
    s[40].deathRate = 3.0;
    s[40].statePop = 2000000;

    s[41].Name = "Odisha";
    s[41].birthRate = 19.2;
    s[41].deathRate = 7.6;
    s[41].statePop = 48000000;

    s[42].Name = "Orissa";
    s[42].birthRate = 19.2;
    s[42].deathRate = 7.6;
    s[42].statePop = 48000000;

    s[43].Name = "OD";
    s[43].birthRate =19.2;
    s[43].deathRate = 7.6;
    s[43].statePop = 48000000;

    s[44].Name = "Punjab";
    s[44].birthRate = 15.2;
    s[44].deathRate = 6.2;
    s[44].statePop = 32000000;

    s[45].Name = "PB";
    s[45].birthRate = 15.2;
    s[45].deathRate = 6.2;
    s[45].statePop = 32000000;

    s[46].Name = "Rajasthan";
    s[46].birthRate = 24.8;
    s[46].deathRate =6.3;
    s[46].statePop = 81000000;

    s[47].Name = "RJ";
    s[47].birthRate = 24.8;
    s[47].deathRate =6.3;
    s[47].statePop = 81000000;

    s[48].Name = "Sikkim";
    s[48].birthRate = 17.0;
    s[48].deathRate =5.0;
    s[48].statePop = 700000;

    s[49].Name = "SK";
    s[49].birthRate = 17.0;
    s[49].deathRate = 5.0;
    s[49].statePop = 700000;

    s[50].Name = "Tamil Nadu";
    s[50].birthRate = 15.2;
    s[50].deathRate = 6.7;
    s[50].statePop = 83000000;

    s[51].Name = "TN";
    s[51].birthRate = 15.2;
    s[51].deathRate = 6.7;
    s[51].statePop = 83000000;

    s[52].Name = "Telangana";
    s[52].birthRate = 17.8;
    s[52].deathRate = 6.5;
    s[52].statePop = 41000000;

    s[53].Name = "Telangana State";
    s[53].birthRate = 17.8;
    s[53].deathRate = 6.5;
    s[53].statePop = 41000000;

    s[54].Name = "TS";
    s[54].birthRate = 17.8;
    s[54].deathRate = 6.5;
    s[54].statePop = 41000000;

    s[55].Name = "Tripura";
    s[55].birthRate = 14.7;
    s[55].deathRate =5.2;
    s[55].statePop = 4000000;

    s[56].Name = "TR";
    s[56].birthRate = 14.7;
    s[56].deathRate = 5.2;
    s[56].statePop = 4000000;

    s[57].Name = "Uttar Pradesh";
    s[57].birthRate = 26.7;
    s[57].deathRate = 7.2;
    s[57].statePop = 241000000;

    s[58].Name = "UP";
    s[58].birthRate =26.7;
    s[58].deathRate = 7.2;
    s[58].statePop = 241000000;

    s[59].Name = "Uttarakhand";
    s[59].birthRate = 17.8;
    s[59].deathRate = 6.4;
    s[59].statePop = 10000000;

    s[60].Name = "UK";
    s[60].birthRate = 17.8;
    s[60].deathRate = 6.4;
    s[60].statePop = 10000000;

    s[61].Name = "West Bengal";
    s[61].birthRate = 15.5;
    s[61].deathRate = 5.9;
    s[61].statePop = 104000000;

    s[62].Name = "WB";
    s[62].birthRate = 15.5;
    s[62].deathRate = 5.9;
    s[62].statePop = 104000000;

    string stateinp;
    cout<< "Enter state name: ";
    cin>> stateinp;
    float br, dr;
    unsigned long ip;
            for(int i=0;i<62;i++){
                if(stateinp==s[i].Name){
                    br= s[i].birthRate;
                    dr = s[i].deathRate;
                    ip = s[i].statePop;
                }
            }
            cout << br << endl;
}   