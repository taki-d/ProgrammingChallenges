#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    for (int n = 0; n < N; ++n) {

        int money, k;
        cin >> money >> k;

        int dp[25][300];
        memset(dp, 0, sizeof (dp));

        dp[0][0] = 1;

        for (int i = 0; i < k; ++i) {
            int num;
            cin >> num;

            for (int j = 0; j < num; ++j) {
                int price;
                cin >> price;

                for (int l = 0; l <= money; ++l) {

                    if(dp[i][l] == 1 && l+price <= money){
                         dp[i+1][l+price] = 1;
                    }
                }
            }
        }

        bool flag = false;
        for (int j = money; j >= 0; --j) {
            if(dp[k][j] == 1){
                flag = true;
                cout << j << endl;
                break;
            }
        }

        if(!flag){
            cout << "no solution" << endl;
        }

    }

    return 0;
}
