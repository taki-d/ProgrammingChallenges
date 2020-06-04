#include <bits/stdc++.h>

using namespace std;

int main(){
    int money, N;
    int dp[20000];

    while(cin >> money >> N){
        vector<pair<int,int>> d;
        for (int i = 0; i < N; ++i) {
            int price,n;
            cin >> price >> n;
            d.push_back(make_pair(price,n));
        }

        memset(dp, 0, sizeof (dp));

        for (int i = 0; i < d.size(); ++i) {
            for (int j = money+201; j >= d[i].first; --j) {
                if(j == d[i].first || dp[j-d[i].first] > 0){
                    dp[j] = max(dp[j], dp[j-d[i].first] + d[i].second);
                }
            }

        }

        int ans = 0;
        // over 2000;
        if(money <= 2000 && money > 1800){
            for (int i = 0; i < money; ++i) {
                ans = max(dp[i],ans);
            }

            for (int i = 2001; i < money + 201; ++i) {
                ans = max(dp[i],ans);
            }
        }else if(money > 2000){
            for (int i = 0; i < money + 201; ++i) {
                ans = max(dp[i],ans);
            }
        }else{
            for (int i = 0; i <= money; ++i) {
                ans = max(dp[i],ans);
            }
        }

        cout << ans << endl;

    }


    return 0;
}
