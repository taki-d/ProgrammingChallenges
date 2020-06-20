#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    while(1){
        cin >> input;

        if(input == "."){
            break;
        }

        int ans = 1;
        for (int i = 1; i < input.size(); ++i) {
            if(input.size() % i == 0){
                string pat = input.substr(0,i);
                bool flag = true;
                for (int j = 0, k = i-1; k < input.size() && flag; j += i, k += i) {
                    flag = (pat == input.substr(j,i));
                }

                if(flag){
                    ans = input.size() / i;
                    break;
                }

            }
        }

        cout << ans << endl;

    }

}


