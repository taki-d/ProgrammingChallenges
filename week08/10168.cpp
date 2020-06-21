#include <bits/stdc++.h>

using namespace std;

vector<bool> eratosthenes(long long int N){
    vector<bool> is_prime_number(N+1);

    for (int i = 0; i <= N; ++i) {
        is_prime_number[i] = true;
    }

    for (int i = 2; i <= N; ++i) {
        if(is_prime_number[i]){
            for (int j = i*2; j <= N; j += i) {
                is_prime_number[j] = false;
            }
        }
    }

    return is_prime_number;
}

int main(){
    const int MAX = 10000000;

    vector<bool> is_prime_num = eratosthenes(MAX);

    int N;
    while(cin >> N){
        if(N < 8){
            cout << "Impossible." << endl;
        }else{
            // even num
            if(N % 2 == 0){
                cout << "2 2 ";
                N = N - 4;
            // odd num
            }else{
                cout << "2 3 ";
                N = N - 5;
            }

            for (int i = 2; i <= N-2; ++i) {
                if(is_prime_num[i] && is_prime_num[N-i]){
                    cout << i << " " << N - i << endl;
                    break;
                }
            }
        }
    }
}
