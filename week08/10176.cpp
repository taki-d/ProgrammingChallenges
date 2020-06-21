#include <bits/stdc++.h>

using namespace std;

int main(){

    string input;
    long long int n = 0;

    while(cin >> input){
        if(input[input.size() - 1] == '#'){
            for (int i = 0; i < input.size() - 1; ++i) {
                n = (n*2 + (input[i] == '0'? 0 : 1)) % 131071;
            }

            if(n == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }

            //prepare next input;
            n = 0;

        }else{
            for (int i = 0; i < input.size(); ++i) {
                n = (n*2 + (input[i] == '0'? 0 : 1)) % 131071;
            }
        }
    }
}


