#include <bits/stdc++.h>

using namespace std;

vector<int> eratosthenes(int N){
    vector<bool> is_prime_number(N+1);

    for (int i = 0; i <= N; ++i) {
        is_prime_number[i] = true;
    }

    vector<int> prime_num;
    prime_num.push_back(1);
    for (int i = 2; i <= N; ++i) {
        if(is_prime_number[i]){
            for (int j = i*2; j <= N; j += i) {
                is_prime_number[j] = false;
            }
            prime_num.push_back(i);
        }
    }

    return prime_num;
}

int main(){
    const int MAX = 10001;

    vector<int> prime_num = eratosthenes(MAX);

    vector<long long int> range_sum;
    long long int sum = 0;
    for(const auto& p : prime_num){
        sum += p;
        range_sum.push_back(sum);
    }

    int input;
    while(cin >> input){
        if(input == 0){
            break;
        }

        int counter = 0;
        for (int i = 0; i < range_sum.size(); ++i) {
            for (int j = i+1; j < range_sum.size(); ++j) {
                long long int sum_of_range = range_sum[j] - range_sum[i];
                if(sum_of_range == input){
                    counter++;
                }
                if(sum_of_range > input){
                    break;
                }
            }
        }

        cout << counter << endl;
    }
}
