#include <bits/stdc++.h>

using namespace std;

int main(){

    auto split =  [](const string &s, char delim)->vector<string>{
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
        if (!item.empty()) {
                elems.push_back(item);
            }
        }
        return elems;
    };

    while(1){
        int leak_rate = 0;
        double tank_size = 0;
        double max_tank_size = 0;
        double fuel_consumption = 0;
        int last_check = 0;
        while(1){
            string input;
            getline(cin, input);
            if(input == "0 Fuel consumption 0") return 0;

            vector<string> elem = split(input, ' ');

            auto calc_fuel_amount = [&](){
                double fuel = (fuel_consumption + leak_rate) * (stoi(elem[0]) - last_check);
                last_check = stoi(elem[0]);
                return fuel;
            };

            if(elem[1] == "Goal" || elem[1] == "Gas"){

                tank_size += calc_fuel_amount();

                if(tank_size > max_tank_size){
                    max_tank_size = tank_size;
                }
                tank_size = 0;

                if(elem[1] == "Goal") break;

            }else if(elem[1] == "Mechanic"){

                tank_size += calc_fuel_amount();
                leak_rate = 0;

            }else if(elem[1] == "Fuel"){

                tank_size += calc_fuel_amount();
                fuel_consumption = double(stoi(elem[3])) / 100.0;

            }else if(elem[1] == "Leak"){
                tank_size += calc_fuel_amount();
                ++leak_rate;
            }
        }

        cout << fixed << setprecision(3) << max_tank_size << endl;

    }

    return 0;
}
