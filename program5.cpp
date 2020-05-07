#include <bits/stdc++.h>

using namespace std;

int main(){
    int f, d, m, y;

    while (cin >> f >> d >> m >> y) {
        if(f == 0 && d == 0 && m == 0 && y == 0){
            return 0;
        }

        auto isLeapYear = [](int year)->bool{
            bool leap_year = false;

            if(year % 4 == 0){
                leap_year = true;
                if(year % 100 == 0){
                    leap_year = false;
                    if(year % 400 == 0){
                        leap_year = true;
                    }
                }
            }

            return leap_year;
        };

        auto daysOfYear = [&](int year)->int{
            bool leap_year = isLeapYear(year);
            return leap_year ? 366 : 365;
        };

        auto daysOfMonth = [&](int year,int month)->int{
            std::vector<int> mn = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if(month == 2){
                bool leap_year = isLeapYear(year);
                return leap_year ? mn[1] + 1 : mn[1];
            }
            return mn[month-1];
        };

        bool is_first_loop_year = true;
        while (1) {
            if(!is_first_loop_year && f > daysOfYear(y)){
                f = f - daysOfYear(y);
                ++y;
                continue;
            }else if((f+d) <= daysOfMonth(y,m)){
                d = d + f;
                break;
            }else{
                f = f - (daysOfMonth(y,m) - d);
                d = 0;
            }

            if(m == 12) {
                m = 1;
                ++y;
                is_first_loop_year = false;
            } else {
                ++m;
            }
        }

        f = f + daysOfMonth(y,m);

        cout << d << " " <<  m << " " << y << endl;

    }
}
