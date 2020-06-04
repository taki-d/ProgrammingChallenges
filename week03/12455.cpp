#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int Bar;
        cin >> Bar;

        int n;
        cin >> n;

        vector<int> bars;
        for (int j = 0; j < n; ++j) {
            int bar;
            cin >> bar;
            bars.push_back(bar);
        }

        bool dp[30][2000];
        memset(dp, 0 ,sizeof (dp));

        dp[0][0] = 1;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k <= Bar; ++k) {
                dp[j+1][k] |= dp[j][k];
                if(k >= bars[j]) dp[j+1][k] |= dp[j][k-bars[j]];
            }
        }

        if(dp[n][Bar]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

    }

    return 0;
}
