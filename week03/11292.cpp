#include <bits/stdc++.h>

using namespace std;

int main(){
    int dragon,kight;
    while (1) {
        cin >> dragon >> kight;
        if(dragon == 0 && kight == 0){
            return 0;
        }

        vector<int> dragons;
        for (int i = 0; i < dragon; ++i) {
            int a;
            cin >> a;
            dragons.push_back(a);
        }

        vector<int> kights;
        for (int i = 0; i < kight; ++i) {
            int a;
            cin >> a;
            kights.push_back(a);
        }

        sort(dragons.begin(), dragons.end());
        sort(kights.begin(), kights.end());

        int kights_index = 0;
        int cost = 0;
        bool flag = false;
        for (int n = 0; n < dragon; ++n) {
            while(kights[kights_index] < dragons[n] && kights_index != kight){
                ++kights_index;
            }

            if(kights_index == kight){
                flag = true;
                break;
            }

            cost += kights[kights_index];
            ++kights_index;
        }

        if(flag){
            cout << "Loowater is doomed!" << endl;
        }else{
            cout << cost << endl;
        }
    }

    return 0;
}
