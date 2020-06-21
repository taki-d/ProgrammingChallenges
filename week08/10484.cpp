#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,D;
    while(cin >> N >> D){
        if(N == 0 && D == 0){
            break;
        }


        const int SIZE = 100;
        vector<long long int> N_fact(SIZE, 0);
        vector<long long int> D_fact(SIZE, 0);

        // fact N!
        for (int i = 2; i <= N; ++i) {

            int temp = i;
            for (int j = 2; j <= i && temp != 1; ++j) {
                while(temp % j == 0){
                    temp = temp/j;
                    N_fact[j]++;
                }
            }
        }

        //fact D
        int fact = D;
        for (int i = 2; i <= N && fact != 1; ++i) {
            while(fact % i == 0){
                fact = fact/i;
                D_fact[i]++;
            }
        }

        long long int n = 1;
        for (int i = 0; i < SIZE; ++i) {
            int k = N_fact[i] - D_fact[i];

            if(k < 0 || fact != 1){
                n = 0;
                break;
            }

            if(k != 0){
                n = n * (k+1);
            }
        }

        cout << n << endl;

    }
}
