#include <bits/stdc++.h>

#define INF 2e9

using namespace std;

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {

        int price, coin;
        cin >> price;
        cin >> coin;

        vector<int> coins;

        for (int j = 0; j < coin; ++j) {
            int p;
            cin >> p;
            coins.push_back(p);
        }

        int dp[20050];
        for (int j = 0; j < 20050; ++j) {
            dp[j] = INF;
        }

        dp[0] = 1;
        for (int j = 0; j < coins.size(); ++j) {
            for (int k = 20000; k >= 0; --k) {
                if(dp[k] < INF && k + coins[j] < 20000){
                    dp[k + coins[j]] = min(dp[k+coins[j]], dp[k] + 1);
                }
            }
        }

        while(dp[price] == INF) price++;

        cout << price << " " << dp[price]-1 << endl;
    }

    return 0;
}
