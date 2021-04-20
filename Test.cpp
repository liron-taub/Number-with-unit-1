//
// Created by Liron on 08/04/2021.
//

#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <string>
#include <fstream>
#include <iostream>
using namespace doctest;
using namespace ariel;
using namespace std;
TEST_CASE ("Good code") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{20, "m"};
    NumberWithUnits b{2, "cm"};
    NumberWithUnits addAB = a + b;
    NumberWithUnits addBA = b + a;
            CHECK(addAB == NumberWithUnits{20.02, "m"});
            CHECK(addBA == NumberWithUnits{2002, "cm"});
    NumberWithUnits addAA = a + a;
    NumberWithUnits addBB = b + b;
            CHECK(addAA == NumberWithUnits{40, "m"});
            CHECK(addBB == NumberWithUnits{4, "cm"});
    NumberWithUnits minusAB = a - b;
    NumberWithUnits minusBA = b - a;
            CHECK(minusAB == NumberWithUnits{19.98, "m"});
            CHECK(minusBA == NumberWithUnits{-1998, "cm"});
    NumberWithUnits onriBAddB = minusBA + b;
            CHECK(onriBAddB == NumberWithUnits{-1996, "cm"});
    NumberWithUnits OnriBOnri = +b;
    NumberWithUnits OnriBOnriAddB = OnriBOnri + b;
            CHECK(OnriBOnriAddB == NumberWithUnits{4, "cm"});
            CHECK(a != b);
            CHECK(a > b);
    NumberWithUnits BPlos = b++;


    NumberWithUnits c{1, "km"};
    NumberWithUnits d{6000, "m"};
    NumberWithUnits addCD = d + c;
    NumberWithUnits addDC = d + c;
            CHECK(addCD == NumberWithUnits{7, "km"});
            CHECK(addDC == NumberWithUnits{7000, "m"});
    NumberWithUnits addDD = d + d;
    NumberWithUnits addCC = c + c;
            CHECK(addCC == NumberWithUnits{2, "km"});
            CHECK(addDD == NumberWithUnits{12000, "m"});
    NumberWithUnits minusCD = c - d;
    NumberWithUnits minusDC = d - c;
            CHECK(minusCD == NumberWithUnits{-5, "km"});
            CHECK(minusDC == NumberWithUnits{5000, "m"});
    NumberWithUnits OnriCD = -minusCD;
    NumberWithUnits OnricdAddOnriCD = OnriCD + minusCD;
            CHECK(OnricdAddOnriCD == NumberWithUnits{0, "km"});
    NumberWithUnits OnriCDPlos = OnriCD++;
            CHECK(OnriCDPlos == NumberWithUnits{5, "km"});
    NumberWithUnits molC = c * 20;
            CHECK(molC == NumberWithUnits{20, "km"});
            CHECK(+c == NumberWithUnits{1, "km"});
            CHECK(+d == NumberWithUnits{6000, "m"});
            CHECK(c != d);
            CHECK(c < d);
            CHECK(c <= d);


    NumberWithUnits x{1.2, "km"};
    NumberWithUnits y{7.21, "cm"};
    NumberWithUnits addXY = x + y;
    NumberWithUnits addYX = x + y;
            CHECK(addXY == NumberWithUnits{1.2000721, "km"});
            CHECK(addYX == NumberWithUnits{120007.21, "cm"});
    NumberWithUnits addXX = x + x;
    NumberWithUnits addYY = y + y;
            CHECK(addXX == NumberWithUnits{2.4, "km"});
            CHECK(addYY == NumberWithUnits{14.42, "cm"});
    NumberWithUnits minusXY = x - y;
    NumberWithUnits minusYX = y - x;
            CHECK(minusXY == NumberWithUnits{1.1999279, "km"});
            CHECK(minusYX == NumberWithUnits{-119992.79, "cm"});
    NumberWithUnits OnriXY = -minusXY;
            CHECK(OnriXY == NumberWithUnits{-1.1999279, "km"});
    NumberWithUnits OnriXYAddY = OnriXY + y;
            CHECK(OnriXYAddY == NumberWithUnits{-1.1998558, "km"});
    NumberWithUnits XPlos = x++;
            CHECK(XPlos == NumberWithUnits{1.2, "km"});
            CHECK(x == NumberWithUnits{2.2, "km"});
    NumberWithUnits molY = y * 32;
            CHECK(molY == NumberWithUnits{230.72, "cm"});
            CHECK(x != y);
            CHECK(x > y);
            CHECK(x >= y);

    NumberWithUnits t{0.50, "ton"};
    NumberWithUnits k{10000, "g"};
    NumberWithUnits addTK = t + k;
    NumberWithUnits addKT = k + t;
            CHECK(addTK == NumberWithUnits{0.51, "ton"});
            CHECK(addKT == NumberWithUnits{510000, "g"});
    NumberWithUnits addTT = t + t;
    NumberWithUnits addKK = k + k;
            CHECK(addTT == NumberWithUnits{1, "ton"});
            CHECK(addKK == NumberWithUnits{20000, "g"});
    NumberWithUnits minusTK = t - k;
    NumberWithUnits minusKT = k - t;
            CHECK(minusTK == NumberWithUnits{0.49, "ton"});
            CHECK(minusKT == NumberWithUnits{-490000, "g"});
    NumberWithUnits Kplos = k++;
            CHECK(Kplos == NumberWithUnits{10000, "g"});
    NumberWithUnits KplosOne = +k;
            CHECK(KplosOne == NumberWithUnits{10001, "g"});
    NumberWithUnits molT = t * 2;
            CHECK(molT == NumberWithUnits{1, "ton"});
    NumberWithUnits kOther{10, "g"};
            k+=kOther;
    CHECK(k==NumberWithUnits{10011,"g"});
            CHECK(t != k);
            CHECK(k < t);
            CHECK(t >= k);

    NumberWithUnits m{56, "min"};
    NumberWithUnits o{22, "hour"};
    NumberWithUnits addMO = m + o;
    NumberWithUnits addOM = o + m;
            CHECK(addOM == NumberWithUnits{22.9333, "hour"});
            CHECK(addMO == NumberWithUnits{1376, "min"});
    NumberWithUnits addMM = m + m;
    NumberWithUnits addOO = o + o;
            CHECK(addMM == NumberWithUnits{112, "min"});
            CHECK(addOO == NumberWithUnits{44, "hour"});
    NumberWithUnits minusOM = o - m;
            CHECK(minusOM == NumberWithUnits{21.0666667, "hour"});
    NumberWithUnits oMol=o*1.5;
            CHECK(oMol == NumberWithUnits{33, "hour"});

    NumberWithUnits USD{3.33, "USD"};
    NumberWithUnits LIS{1, "ILS"};
    NumberWithUnits addUL = USD + LIS;
    NumberWithUnits addLU = LIS + USD;
            CHECK(addUL == NumberWithUnits{ 3.6303, "USD"});
            CHECK(addLU == NumberWithUnits{12.0889, "ILS"});
    NumberWithUnits addUU = USD + USD;
    NumberWithUnits addLL = LIS + LIS;
            CHECK(addUU == NumberWithUnits{6.66, "USD"});
            CHECK(addLL == NumberWithUnits{2, "ILS"});
    NumberWithUnits minusUL = USD - LIS;
    NumberWithUnits minusLU = LIS - USD;
            CHECK(minusUL == NumberWithUnits{3.0297, "USD"});
            CHECK(minusLU == NumberWithUnits{-10.0889, "ILS"});
}
TEST_CASE ("read code") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    istringstream line1{"10 [ kg ]"};
    istringstream line2{"9 [ g ]"};
    istringstream line3{"100 [ cm ]"};
    istringstream line4{"2 [ m ]"};
    istringstream line5{"3.333 [ USD ]"};
    istringstream line6{"3 [ ILS ]"};
    istringstream line7{"60 [ hour ]"};
    istringstream line8{"120 [ min ]"};
    istringstream line9{"123 [ ton ]"};
    istringstream line10{"20 [ sec ]"};
    istringstream line11{"101 [ km ]"};
    NumberWithUnits chak {1, "g"};
    line1 >> chak;
            CHECK(chak == NumberWithUnits{10, "kg"});
    line2 >> chak;
            CHECK(chak == NumberWithUnits{9, "g"});
    line3 >> chak;
            CHECK(chak == NumberWithUnits{100 ,"cm"});
    line4 >> chak;
            CHECK(chak == NumberWithUnits{2 ,"m"});
    line5 >> chak;
            CHECK(chak == NumberWithUnits{3.333 ,"USD"});
    line6 >> chak;
            CHECK(chak == NumberWithUnits{3,"ILS"});
    line7 >> chak;
            CHECK(chak == NumberWithUnits{60 ,"hour"});
    line8 >> chak;
            CHECK(chak == NumberWithUnits{120 ,"min"});
    line9 >> chak;
            CHECK(chak == NumberWithUnits{123 ,"ton"});
    line10 >> chak;
            CHECK(chak == NumberWithUnits{20 ,"sec"});
    line11 >> chak;
            CHECK(chak == NumberWithUnits{101 ,"km"});

}

TEST_CASE ("Eror") {
    NumberWithUnits m{56, "min"};
    NumberWithUnits o{1, "ton"};
    NumberWithUnits x{1.2, "km"};
    NumberWithUnits y{7.21, "cm"};
    NumberWithUnits l{7.21, "ILS"};
            CHECK_THROWS(m + o);
            CHECK_THROWS(m + x);
            CHECK_THROWS(m + y);
            CHECK_THROWS(l + o);
            CHECK_THROWS(x + l);


    string units[] = {"ILS", "min", "m", "kg", "cm", "g", "hour", "ton", "sec", "USD", "km"};
    for (int i = 0; i < 10; ++i) {
        NumberWithUnits a{1, units[i]};
        NumberWithUnits b{1, units[i + 1]};
                CHECK_THROWS_AS(a + b, std::invalid_argument);
                CHECK_THROWS_AS(a - b, std::invalid_argument);

    }
    CHECK_THROWS_AS(NumberWithUnits(1, ""), std::invalid_argument);

}
