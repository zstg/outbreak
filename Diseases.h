#include <iostream>
using namespace std;
class Diseases{
    public: 
    string Disease;
    float TransRate, RecRate;
    unsigned IncPeriod;
};

int diseaseGen(){
    Diseases d[101];
    d[0].Disease = "Influenza";
    d[0].TransRate = 0.87;
    d[0].RecRate = 0.98;
    d[0].IncPeriod = 3;

    d[1].Disease = "Flu";
    d[1].TransRate = 
    d[1].RecRate = 
    d[1].IncPeriod = 

    d[2].Disease = "Common flu";
    d[2].TransRate = 
    d[2].RecRate = 
    d[2].IncPeriod = 

    d[3].Disease = "Grippe";
    d[3].TransRate = 
    d[3].RecRate = 
    d[3].IncPeriod = 

    d[4].Disease = "J09";
    d[4].TransRate = 
    d[4].RecRate = 
    d[4].IncPeriod = 

    d[5].Disease = "Tuberculosis";
    d[5].TransRate = 0.45;
    d[5].RecRate = 0.88;
    d[5].IncPeriod = 18;

    d[6].Disease = "TB";
    d[6].TransRate = 
    d[6].RecRate = 
    d[6].IncPeriod = 

    d[7].Disease = "A15";
    d[7].TransRate = 
    d[7].RecRate = 
    d[7].IncPeriod = 

    d[8].Disease = "A16";
    d[8].TransRate = 
    d[8].RecRate = 
    d[8].IncPeriod = 

    d[9].Disease = "A17";
    d[9].TransRate = 
    d[9].RecRate = 
    d[9].IncPeriod = 

    d[10].Disease = "A18"; 
    d[10].TransRate = 
    d[10].RecRate = 
    d[10].IncPeriod = 

    d[11].Disease = "A19";
    d[11].TransRate = 
    d[11].RecRate = 
    d[11].IncPeriod = 
    --
    d[12].Disease = "Hepatitis B";
    d[12].TransRate = 0.2;
    d[12].RecRate = 0.93;
    d[12].IncPeriod = 50;

    d[13].Disease = "Hep B";
    d[13].TransRate = 0.2;
    d[13].RecRate = 0.93;
    d[13].IncPeriod = 50;

    d[14].Disease = "HBV"
    d[14].TransRate = 
    d[14].RecRate = 
    d[14].IncPeriod = 

    d[15].Disease = "Hepatitis"
    d[15].TransRate = 
    d[15].RecRate = 
    d[15].IncPeriod = 

    d[16].Disease = "B16"
    d[16].TransRate = 
    d[16].RecRate = 
    d[16].IncPeriod = 

    d[17].Disease = "B17"
    d[17].TransRate = 
    d[17].RecRate = 
    d[17].IncPeriod = 

    d[18].Disease = "B18"
    d[18].TransRate = 
    d[18].RecRate = 
    d[18].IncPeriod = 

    d[19].Disease = "B19"
    d[19].TransRate = 
    d[19].RecRate = 
    d[19].IncPeriod = 
    --
    d[20].Disease = "HIV/AIDS";
    d[20].TransRate = 0.0001;
    d[20].RecRate = 0;
    d[20].IncPeriod = 90;

    d[21].Disease = "HIV";
    d[21].TransRate =
    d[21].RecRate =
    d[21].IncPeriod =

    d[22].Disease = "AIDS";
    d[22].TransRate =
    d[22].RecRate =
    d[22].IncPeriod =

    d[23].Disease = "Human Immunodeficiency Virus";
    d[23].TransRate =
    d[23].RecRate =
    d[23].IncPeriod =

    d[24].Disease = "Acquired Immunodeficiency Syndrome"
    d[24].TransRate =
    d[24].RecRate =
    d[24].IncPeriod =

    d[25].Disease = "B20"
    d[25].TransRate =
    d[25].RecRate =
    d[25].IncPeriod =

    d[26].Disease = "B21"
    d[26].TransRate =
    d[26].RecRate =
    d[26].IncPeriod =

    d[27].Disease = "B22"
    d[27].TransRate =
    d[27].RecRate =
    d[27].IncPeriod =

    d[28].Disease = "B23"
    d[28].TransRate =
    d[28].RecRate =
    d[28].IncPeriod =

    d[29].Disease = "B24"
    d[29].TransRate =
    d[29].RecRate =
    d[29].IncPeriod =
    --
    d[30].Disease = "Ebola"
    d[30].TransRate = 0.67
    d[30].RecRate = 0.5
    d[30].IncPeriod = 7

    d[31].Disease = "Ebola virus"
    d[31].TransRate =
    d[31].RecRate =
    d[31].IncPeriod =

    d[32].Disease = "Ebola hemorrhagic fever"
    d[32].TransRate =
    d[32].RecRate =
    d[32].IncPeriod =

    d[33].Disease = "A98.4"
    d[33].TransRate =
    d[33].RecRate =
    d[33].IncPeriod =
    --
    d[34].Disease = "MERS"
    d[34].TransRate = 0.67
    d[34].RecRate = 0.375
    d[34].IncPeriod = 8

    d[35].Disease = "Middle East Respiratory Syndrome"
    d[35].TransRate =
    d[35].RecRate =
    d[35].IncPeriod =

    d[36].Disease = "MERS coronavirus"
    d[36].TransRate =
    d[36].RecRate =
    d[36].IncPeriod =

    d[37].Disease = "B34.2"
    d[37].TransRate =
    d[37].RecRate =
    d[37].IncPeriod =
    --
    d[38].Disease = "Cholera"
    d[38].TransRate = 0.9
    d[38].RecRate = 0.975
    d[38].IncPeriod = 2

    d[39].Disease = "A00"
    d[39].TransRate =
    d[39].RecRate =
    d[39].IncPeriod =
    --
    d[40].Disease = "Measles"
    d[40].TransRate = 0.93
    d[40].RecRate = 0.95
    d[40].IncPeriod = 10

    d[41].Disease = "Measles virus"
    d[41].TransRate = 
    d[41].RecRate = 
    d[41].IncPeriod = 

    d[42].Disease = "B05"
    d[42].TransRate =
    d[42].RecRate =
    d[42].IncPeriod =
    --
    d[43].Disease = "Rubella"
    d[43].TransRate = 0.6
    d[43].RecRate = 0.95
    d[43].IncPeriod = 18

    d[44].Disease = "German measles"
    d[44].TransRate =
    d[44].RecRate =
    d[44].IncPeriod =

    d[45].Disease = "Three-day measles"
    d[45].TransRate =
    d[45].RecRate =
    d[45].IncPeriod =

    d[46].Disease = "Three day measles"
    d[46].TransRate =
    d[46].RecRate =
    d[46].IncPeriod =

    d[47].Disease = "B06"
    d[47].TransRate =
    d[47].RecRate =
    d[47].IncPeriod =
    --
    d[48].Disease = "Pertussis"
    d[48].TransRate = 0.85
    d[48].RecRate = 0.95
    d[48].IncPeriod = 7.5

    d[49].Disease = "Bordetella pertussis"
    d[49].TransRate =
    d[49].RecRate =
    d[49].IncPeriod =

    d[50].Disease = "Whooping cough"
    d[50].TransRate =
    d[50].RecRate =
    d[50].IncPeriod =

    d[51].Disease = "A37"
    d[51].TransRate =
    d[51].RecRate =
    d[51].IncPeriod =
    --
    d[52].Disease = "Dengue fever"
    d[52].TransRate = 0.33
    d[52].RecRate = 0.95
    d[52].IncPeriod = 5

    d[53].Disease = "Dengue"
    d[53].TransRate =
    d[53].RecRate =
    d[53].IncPeriod =

    d[54].Disease = "A90"
    d[54].TransRate =
    d[54].RecRate =
    d[54].IncPeriod =
    --
    d[55].Disease = "Meningococcal meningitis"
    d[55].TransRate = 0.25
    d[55].RecRate = 0.6
    d[55].IncPeriod = 3.5

    d[56].Disease = "Bacterial meningitis"
    d[56].TransRate =
    d[56].RecRate =
    d[56].IncPeriod =

    d[57].Disease = "Meningitis"
    d[57].TransRate =
    d[57].RecRate =
    d[57].IncPeriod =

    d[58].Disease = "A39"
    d[58].TransRate =
    d[58].RecRate =
    d[58].IncPeriod =
    --
    d[59].Disease = "Typhoid fever"
    d[59].TransRate = 0.25
    d[59].RecRate = 0.95
    d[59].IncPeriod = 10

    d[60].Disease = "Typhoid"
    d[60].TransRate =
    d[60].RecRate =
    d[60].IncPeriod =

    d[61].Disease = "A01"
    d[61].TransRate =
    d[61].RecRate =
    d[61].IncPeriod =

    d[62].Disease = "Salmonella typhi"
    d[62].TransRate =
    d[62].RecRate =
    d[62].IncPeriod =
    --
    d[63].Disease = "Malaria"
    d[63].TransRate = 0.33
    d[63].RecRate = 0.67
    d[63].IncPeriod = 8

    d[64].Disease = "Salmonella typhi"
    d[64].TransRate =
    d[64].RecRate =
    d[64].IncPeriod =

    d[65].Disease = "Vivax"
    d[65].TransRate =
    d[65].RecRate =
    d[65].IncPeriod =

    d[66].Disease = "B50"
    d[66].TransRate =
    d[66].RecRate =
    d[66].IncPeriod =

    d[67].Disease = "B51"
    d[67].TransRate =
    d[67].RecRate =
    d[67].IncPeriod =

    d[68].Disease = "B52"
    d[68].TransRate =
    d[68].RecRate =
    d[68].IncPeriod =

    d[69].Disease = "B53"
    d[69].TransRate =
    d[69].RecRate =
    d[69].IncPeriod =

    d[70].Disease = "B54"
    d[70].TransRate =
    d[70].RecRate =
    d[70].IncPeriod =
    --
    d[71].Disease = "COVID-19"
    d[71].TransRate = 0.96
    d[71].RecRate = 0.8
    d[71].IncPeriod = 5

    d[72].Disease = "COVID 19"
    d[72].TransRate =
    d[72].RecRate =
    d[72].IncPeriod =

    d[73].Disease = "Covid19"
    d[73].TransRate =
    d[73].RecRate =
    d[73].IncPeriod =

    d[74].Disease = "Severe Acute Respiratory Syndrome Coronavirus 2"
    d[74].TransRate =
    d[74].RecRate =
    d[74].IncPeriod =

    d[75].Disease = "SARS-CoV-2"
    d[75].TransRate =
    d[75].RecRate =
    d[75].IncPeriod =

    d[76].Disease = "SARS CoV 2"
    d[76].TransRate =
    d[76].RecRate =
    d[76].IncPeriod =
    --
    d[77].Disease = "Spanish flu"
    d[77].TransRate = 0.97
    d[77].RecRate = 0.4
    d[77].IncPeriod = 1.5

    d[78].Disease = "J10"
    d[78].TransRate =
    d[78].RecRate =
    d[78].IncPeriod =
    --
    d[79].Disease = "Monkeypox"
    d[79].TransRate = 0.16
    d[79].RecRate = 0.87
    d[79].IncPeriod = 7

    d[80].Disease = "Mpox"
    d[80].TransRate =
    d[80].RecRate =
    d[80].IncPeriod =

    d[81].Disease = "Mpxv"
    d[81].TransRate =
    d[81].RecRate =
    d[81].IncPeriod =

    d[82].Disease = "B04"
    d[82].TransRate =
    d[82].RecRate =
    d[82].IncPeriod =
    --
    d[83].Disease = "Polio"
    d[83].TransRate = 0.78
    d[83].RecRate = 0.94
    d[83].IncPeriod = 10

    d[84].Disease = "Poliomyelitis"
    d[84].TransRate =
    d[84].RecRate =
    d[84].IncPeriod =

    d[85].Disease = "Poliovirus"
    d[85].TransRate =
    d[85].RecRate =
    d[85].IncPeriod =

    d[86].Disease = "A80"
    d[86].TransRate =
    d[86].RecRate =
    d[86].IncPeriod =

    d[87].Disease = "A81"
    d[87].TransRate =
    d[87].RecRate =
    d[87].IncPeriod =

    d[88].Disease = "A82"
    d[88].TransRate =
    d[88].RecRate =
    d[88].IncPeriod =

    d[89].Disease = "A83"
    d[89].TransRate =
    d[89].RecRate =
    d[89].IncPeriod =

    d[90].Disease = "A84"
    d[90].TransRate =
    d[90].RecRate =
    d[90].IncPeriod =

    d[91].Disease = "A85"
    d[91].TransRate =
    d[91].RecRate =
    d[91].IncPeriod =

    d[92].Disease = "A86"
    d[92].TransRate =
    d[92].RecRate =
    d[92].IncPeriod =

    d[93].Disease = "A87"
    d[93].TransRate =
    d[93].RecRate =
    d[93].IncPeriod =

    d[94].Disease = "A88"
    d[94].TransRate =
    d[94].RecRate =
    d[94].IncPeriod =

    d[95].Disease = "A89"
    d[95].TransRate =
    d[95].RecRate =
    d[95].IncPeriod =
    --
    d[96].Disease = "H1N1"
    d[96].TransRate = 0.987
    d[96].RecRate = 0.84
    d[96].IncPeriod = 1.25

    d[97].Disease = "Swine flu"
    d[97].TransRate =
    d[97].RecRate =
    d[97].IncPeriod =

    d[98].Disease = "J11"
    d[98].TransRate =
    d[98].RecRate =
    d[98].IncPeriod =
    --
    d[99].Disease = "Zika"
    d[99].TransRate = 0.38
    d[99].RecRate = 0.8
    d[99].IncPeriod = 9

    d[100].Disease = "Zikavirus"
    d[100].TransRate =
    d[100].RecRate =
    d[100].IncPeriod =

    d[101].Disease = "A92.8"
    d[101].TransRate =
    d[101].RecRate =
    d[101].IncPeriod =
}