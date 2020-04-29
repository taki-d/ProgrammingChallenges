#include <bits/stdc++.h>

using namespace std;

int main(){
    while(1){
        int participants, budget, hotel, week;
        int cost = 1145141919;

        cin >> participants >> budget >> hotel >> week;

        for (int i = 0; i < hotel; ++i) {
            int hotel_cost;
            cin >> hotel_cost;

            for (int w = 0; w < week; ++w) {
                int bed;
                cin >> bed;
                if(bed >= participants && budget >= hotel_cost*participants){
                    cost = min(cost,hotel_cost*participants);
                }
            }
        }

        if(cost == 1145141919){
            cout << "stay home" << endl;
        }else{
            cout << cost << endl;
        }

    }
}
