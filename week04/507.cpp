#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    for (int a = 0; a < N; ++a) {
        int r;
        cin >> r;

        vector<int> d;
        for (int i = 0; i < r-1; ++i) {
            int input;
            cin >> input;

            d.push_back(input);
        }

        int s = 0,max_s = 0,max_e = 0,max = -1145141919,sum = 0;
        for (int e = 0; e < d.size(); ++e) {
            sum += d[e];

            if(sum < 0){
                s = e+1;
                sum = 0;
            }

            if(max < sum){
                max = sum;
                max_s = s;
                max_e = e+1;
            }else if(max == sum && (e - s) > (max_e - max_s)){
                max = sum;
                max_s = s;
                max_e = e+1;
            }
        }

        if(max > 0){
            cout << "The nicest part of route " << a + 1 << " is between stops " << max_s + 1 << " and " << max_e + 1 << endl;
        }else{
            cout << "Route " << a + 1 << " has no nice parts" << endl;
        }

    }

    return 0;
}
