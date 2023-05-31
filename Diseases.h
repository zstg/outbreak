#include <iostream>
using namespace std;
class Diseases{
    public: 
    string Disease;
    double TransRate, RecRate;
    unsigned IncPeriod;
};

int genDiseases(Diseases d[]){
    d[0].Disease = "Influenza";
    d[0].TransRate = 0.29;
    d[0].RecRate = 0.32;
    d[0].IncPeriod = 3;

    d[1].Disease = "Flu";
    d[1].TransRate = 0.29;
    d[1].RecRate = 0.32;
    d[1].IncPeriod = 3;

    d[2].Disease = "Common flu";
    d[2].TransRate = 0.29;
    d[2].RecRate = 0.32;
    d[2].IncPeriod = 3;

    d[3].Disease = "Grippe";
    d[3].TransRate = 0.29;
    d[3].RecRate = 0.32;
    d[3].IncPeriod = 3;

    d[4].Disease = "J09";
    d[4].TransRate = 0.29;
    d[4].RecRate = 0.32;
    d[4].IncPeriod = 3;

    d[5].Disease = "Tuberculosis";
    d[5].TransRate = 0.15;
    d[5].RecRate = 0.293;
    d[5].IncPeriod = 18;

    d[6].Disease = "TB";
    d[6].TransRate = 0.15;
    d[6].RecRate = 0.293;
    d[6].IncPeriod = 18;

    d[7].Disease = "A15";
    d[7].TransRate = 0.15;
    d[7].RecRate = 0.293;
    d[7].IncPeriod = 18;

    d[8].Disease = "A16";
    d[8].TransRate = 0.15;
    d[8].RecRate = 0.293;
    d[8].IncPeriod = 18;

    d[9].Disease = "A17";
    d[9].TransRate = 0.15;
    d[9].RecRate = 0.293;
    d[9].IncPeriod = 18;

    d[10].Disease = "A18" ;
    d[10].TransRate = 0.15;
    d[10].RecRate = 0.293;
    d[10].IncPeriod = 18;

    d[11].Disease = "A19";
    d[11].TransRate = 0.15;
    d[11].RecRate = 0.293;
    d[11].IncPeriod = 18;

    d[12].Disease = "Hepatitis B";
    d[12].TransRate = 0.07;
    d[12].RecRate = 0.31;
    d[12].IncPeriod = 50;

    d[13].Disease = "Hep B";
    d[13].TransRate = 0.07;
    d[13].RecRate = 0.31;
    d[13].IncPeriod = 50;

    d[14].Disease = "HBV";
    d[14].TransRate = 0.07;
    d[14].RecRate = 0.31;
    d[14].IncPeriod = 50;

    d[15].Disease = "Hepatitis";
    d[15].TransRate = 0.07;
    d[15].RecRate = 0.31;
    d[15].IncPeriod = 50;

    d[16].Disease = "B16";
    d[16].TransRate = 0.07;
    d[16].RecRate = 0.31;
    d[16].IncPeriod = 50;

    d[17].Disease = "B17";
    d[17].TransRate = 0.07;
    d[17].RecRate = 0.31;
    d[17].IncPeriod = 50;

    d[18].Disease = "B18";
    d[18].TransRate = 0.07;
    d[18].RecRate = 0.31;
    d[18].IncPeriod = 50;

    d[19].Disease = "B19";
    d[19].TransRate = 0.07;
    d[19].RecRate = 0.31;
    d[19].IncPeriod = 50;

    d[20].Disease = "HIV/AIDS";
    d[20].TransRate = 0.0001;
    d[20].RecRate = 0;
    d[20].IncPeriod = 90;

    d[21].Disease = "HIV";
    d[21].TransRate = 0.0001;
    d[21].RecRate = 0;
    d[21].IncPeriod = 90;

    d[22].Disease = "AIDS";
    d[22].TransRate = 0.0001;
    d[22].RecRate = 0;
    d[22].IncPeriod = 90;

    d[23].Disease = "Human Immunodeficiency Virus";
    d[23].TransRate = 0.0001;
    d[23].RecRate = 0;
    d[23].IncPeriod = 90;

    d[24].Disease = "Acquired Immunodeficiency Syndrome";
    d[24].TransRate = 0.0001;
    d[24].RecRate = 0;
    d[24].IncPeriod = 90;

    d[25].Disease = "B20";
    d[25].TransRate = 0.0001;
    d[25].RecRate = 0;
    d[25].IncPeriod = 90;

    d[26].Disease = "B21";
    d[26].TransRate = 0.0001;
    d[26].RecRate = 0;
    d[26].IncPeriod = 90;

    d[27].Disease = "B22";
    d[27].TransRate = 0.0001;
    d[27].RecRate = 0;
    d[27].IncPeriod = 90;

    d[28].Disease = "B23";
    d[28].TransRate = 0.0001;
    d[28].RecRate = 0;
    d[28].IncPeriod = 90;

    d[29].Disease = "B24";
    d[29].TransRate = 0.0001;
    d[29].RecRate = 0;
    d[29].IncPeriod = 90;

    d[30].Disease = "Ebola";
    d[30].TransRate = 0.22;
    d[30].RecRate = 0.16;
    d[30].IncPeriod = 7;

    d[31].Disease = "Ebola virus";
    d[31].TransRate = 0.22;
    d[31].RecRate = 0.16;
    d[31].IncPeriod = 7;

    d[32].Disease = "Ebola hemorrhagic fever";
    d[32].TransRate = 0.22;
    d[32].RecRate = 0.16;
    d[32].IncPeriod = 7;

    d[33].Disease = "A98.4";
    d[33].TransRate = 0.22;
    d[33].RecRate = 0.16;
    d[33].IncPeriod = 7;

    d[34].Disease = "MERS";
    d[34].TransRate = 0.22;
    d[34].RecRate = 0.125;
    d[34].IncPeriod = 8;

    d[35].Disease = "Middle East Respiratory Syndrome";
    d[35].TransRate = 0.22;
    d[35].RecRate = 0.125;
    d[35].IncPeriod = 8;

    d[36].Disease = "MERS coronavirus";
    d[36].TransRate = 0.22;
    d[36].RecRate = 0.125;
    d[36].IncPeriod = 8;

    d[37].Disease = "B34.2";
    d[37].TransRate = 0.22;
    d[37].RecRate = 0.125;
    d[37].IncPeriod = 8;

    d[38].Disease = "Cholera";
    d[38].TransRate = 0.3;
    d[38].RecRate = 0.325;
    d[38].IncPeriod = 2;
    ;
    d[39].Disease = "A00";
    d[39].TransRate = 0.3;
    d[39].RecRate = 0.325;
    d[39].IncPeriod = 2;
    ;
    d[40].Disease = "Measles";
    d[40].TransRate = 0.31;
    d[40].RecRate = 0.316;
    d[40].IncPeriod = 10;

    d[41].Disease = "Measles virus";
    d[41].TransRate = 0.31;
    d[41].RecRate = 0.316;
    d[41].IncPeriod = 10;

    d[42].Disease = "B05";
    d[42].TransRate = 0.31;
    d[42].RecRate = 0.316;
    d[42].IncPeriod = 10;

    d[43].Disease = "Rubella";
    d[43].TransRate = 0.2;
    d[43].RecRate = 0.32;
    d[43].IncPeriod = 18;

    d[44].Disease = "German measles";
    d[44].TransRate = 0.2;
    d[44].RecRate = 0.32;
    d[44].IncPeriod = 18;

    d[45].Disease = "Three-day measles";
    d[45].TransRate = 0.2;
    d[45].RecRate = 0.32;
    d[45].IncPeriod = 18;

    d[46].Disease = "Three day measles";
    d[46].TransRate = 0.2;
    d[46].RecRate = 0.32;
    d[46].IncPeriod = 18;

    d[47].Disease = "B06";
    d[47].TransRate = 0.2;
    d[47].RecRate = 0.32;
    d[47].IncPeriod = 18;

    d[48].Disease = "Pertussis";
    d[48].TransRate = 0.28;
    d[48].RecRate = 0.32;
    d[48].IncPeriod = 7;

    d[49].Disease = "Bordetella pertussis";
    d[49].TransRate = 0.28;
    d[49].RecRate = 0.32;
    d[49].IncPeriod = 7;

    d[50].Disease = "Whooping cough";
    d[50].TransRate = 0.28;
    d[50].RecRate = 0.32;
    d[50].IncPeriod = 7;

    d[51].Disease = "A37";
    d[51].TransRate = 0.28;
    d[51].RecRate = 0.32;
    d[51].IncPeriod = 7;

    d[52].Disease = "Dengue fever";
    d[52].TransRate = 0.11;
    d[52].RecRate = 0.23;
    d[52].IncPeriod = 5;

    d[53].Disease = "Dengue";
    d[53].TransRate = 0.11;
    d[53].RecRate = 0.23;
    d[53].IncPeriod = 5;

    d[54].Disease = "A90";
    d[54].TransRate = 0.11;
    d[54].RecRate = 0.23;
    d[54].IncPeriod = 5;

    d[55].Disease = "Meningococcal meningitis";
    d[55].TransRate = 0.083;
    d[55].RecRate = 0.2;
    d[55].IncPeriod = 3.5;

    d[56].Disease = "Bacterial meningitis";
    d[56].TransRate = 0.083;
    d[56].RecRate = 0.2;
    d[56].IncPeriod = 3.5;

    d[57].Disease = "Meningitis";
    d[57].TransRate = 0.083;
    d[57].RecRate = 0.2;
    d[57].IncPeriod = 3.5;

    d[58].Disease = "A39";
    d[58].TransRate = 0.083;
    d[58].RecRate =0.2;
    d[58].IncPeriod =3.5;

    d[59].Disease = "Typhoid fever";
    d[59].TransRate = 0.25;
    d[59].RecRate = 0.32;
    d[59].IncPeriod = 10;

    d[60].Disease = "Typhoid";
    d[60].TransRate = 0.25;
    d[60].RecRate = 0.32;
    d[60].IncPeriod = 10;

    d[61].Disease = "A01";
    d[61].TransRate = 0.25;
    d[61].RecRate = 0.32;
    d[61].IncPeriod = 10;

    d[62].Disease = "Salmonella typhi";
    d[62].TransRate = 0.25;
    d[62].RecRate = 0.32;
    d[62].IncPeriod = 10;

    d[63].Disease = "Malaria";
    d[63].TransRate = 0.33;
    d[63].RecRate = 0.4;
    d[63].IncPeriod = 8;

    d[64].Disease = "Salmonella typhi";
    d[64].TransRate = 0.33;
    d[64].RecRate = 0.4;
    d[64].IncPeriod = 8;

    d[65].Disease = "Vivax";
    d[65].TransRate = 0.33;
    d[65].RecRate = 0.4;
    d[65].IncPeriod = 8;

    d[66].Disease = "B50";
    d[66].TransRate = 0.33;
    d[66].RecRate = 0.4;
    d[66].IncPeriod = 8;

    d[67].Disease = "B51";
    d[67].TransRate = 0.33;
    d[67].RecRate = 0.4;
    d[67].IncPeriod = 8;

    d[68].Disease = "B52";
    d[68].TransRate = 0.33;
    d[68].RecRate = 0.4;
    d[68].IncPeriod = 8;

    d[69].Disease = "B53";
    d[69].TransRate = 0.33;
    d[69].RecRate = 0.4;
    d[69].IncPeriod = 8;

    d[70].Disease = "B54";
    d[70].TransRate = 0.33;
    d[70].RecRate = 0.4;
    d[70].IncPeriod = 8;

    d[71].Disease = "COVID-19";
    d[71].TransRate = 0.4;
    d[71].RecRate = 0.32;
    d[71].IncPeriod = 5;

    d[72].Disease = "COVID 19";
    d[72].TransRate = 0.4;
    d[72].RecRate = 0.32;
    d[72].IncPeriod = 5;

    d[73].Disease = "Covid19";
    d[73].TransRate = 0.4;
    d[73].RecRate = 0.32;
    d[73].IncPeriod = 5;

    d[74].Disease = "Severe Acute Respiratory Syndrome Coronavirus 2";
    d[74].TransRate = 0.4;
    d[74].RecRate = 0.3;
    d[74].IncPeriod = 5;

    d[75].Disease = "SARS-CoV-2";
    d[75].TransRate = 0.4;
    d[75].RecRate = 0.3;
    d[75].IncPeriod = 5;

    d[76].Disease = "SARS CoV 2";
    d[76].TransRate = 0.4;
    d[76].RecRate = 0.3;
    d[76].IncPeriod = 5;

    d[77].Disease = "Spanish flu";
    d[77].TransRate = 0.4;
    d[77].RecRate = 0.13;
    d[77].IncPeriod = 5;

    d[78].Disease = "J10";
    d[78].TransRate = 0.4;
    d[78].RecRate = 0.13;
    d[78].IncPeriod = 5;

    d[79].Disease = "Monkeypox";
    d[79].TransRate = 0.16;
    d[79].RecRate = 0.29;
    d[79].IncPeriod = 7;

    d[80].Disease = "Mpox";
    d[80].TransRate = 0.16;
    d[80].RecRate = 0.29;
    d[80].IncPeriod = 7;

    d[81].Disease = "Mpxv";
    d[81].TransRate = 0.16;
    d[81].RecRate = 0.29;
    d[81].IncPeriod = 7;

    d[82].Disease = "B04";
    d[82].TransRate = 0.16;
    d[82].RecRate = 0.29;
    d[82].IncPeriod = 7;

    d[83].Disease = "Polio";
    d[83].TransRate = 0.26;
    d[83].RecRate = 0.32;
    d[83].IncPeriod = 10;

    d[84].Disease = "Poliomyelitis";
    d[84].TransRate = 0.26;
    d[84].RecRate = 0.32;
    d[84].IncPeriod = 10;

    d[85].Disease = "Poliovirus";
    d[85].TransRate = 0.26;
    d[85].RecRate = 0.32;
    d[85].IncPeriod = 10;

    d[86].Disease = "A80";
    d[86].TransRate = 0.26;
    d[86].RecRate = 0.32;
    d[86].IncPeriod = 10;

    d[87].Disease = "A81";
    d[87].TransRate = 0.26;
    d[87].RecRate = 0.32;
    d[87].IncPeriod = 10;

    d[88].Disease = "A82";
    d[88].TransRate = 0.26;
    d[88].RecRate = 0.32;
    d[88].IncPeriod = 10;

    d[89].Disease = "A83";
    d[89].TransRate = 0.26;
    d[89].RecRate = 0.32;
    d[89].IncPeriod = 10;

    d[90].Disease = "A84";
    d[90].TransRate = 0.26;
    d[90].RecRate = 0.32;
    d[90].IncPeriod = 10;

    d[91].Disease = "A85";
    d[91].TransRate = 0.26;
    d[91].RecRate = 0.32;
    d[91].IncPeriod = 10;

    d[92].Disease = "A86";
    d[92].TransRate = 0.26;
    d[92].RecRate = 0.32;
    d[92].IncPeriod = 10;

    d[93].Disease = "A87";
    d[93].TransRate = 0.26;
    d[93].RecRate = 0.32;
    d[93].IncPeriod = 10;

    d[94].Disease = "A88";
    d[94].TransRate = 0.26;
    d[94].RecRate = 0.32;
    d[94].IncPeriod = 10;

    d[95].Disease = "A89";
    d[95].TransRate = 0.26;
    d[95].RecRate = 0.32;
    d[95].IncPeriod = 10;

    d[96].Disease = "H1N1";
    d[96].TransRate = 0.45;
    d[96].RecRate = 0.28;
    d[96].IncPeriod = 1;

    d[97].Disease = "Swine flu";
    d[97].TransRate = 0.45;
    d[97].RecRate = 0.28;
    d[97].IncPeriod = 1;

    d[98].Disease = "J11";
    d[98].TransRate = 0.45;
    d[98].RecRate = 0.28;
    d[98].IncPeriod = 1;

    d[99].Disease = "Zika";
    d[99].TransRate = 0.38;
    d[99].RecRate = 0.26;
    d[99].IncPeriod = 9;

    d[100].Disease = "Zikavirus";
    d[100].TransRate = 0.38;
    d[100].RecRate = 0.26;
    d[100].IncPeriod = 9;

    d[101].Disease = "A92.8";
    d[101].TransRate = 0.38;
    d[101].RecRate = 0.26;
    d[101].IncPeriod = 9;

    return 0;
}