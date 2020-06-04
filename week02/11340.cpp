#include <bits/stdc++.h>

using namespace std;

int main(){

    int news;
    cin >> news;

    for (int i = 0; i < news; ++i) {
        int n;
        cin >> n;
        std::map<char,int> price;

        for (int j = 0; j < n; ++j) {
            char s;
            int cent;

            cin >> s >> cent;

            price[s] = cent;
        }

        int cost = 0;

        int n_line;
        cin >> n_line;

        cin.ignore();
        for (int j = 0; j < n_line; ++j) {
            std::string line;
            getline(cin, line);

            for(const auto &c : line){
                auto p = price.find(c);
                if(p != price.end()){
                    cost += p->second;
                }
            }
        }

        auto current_flag = cout.flags();

        cout << (cost - cost % 100) / 100 << ".";

        cout << setw(2) << setfill('0') << cost % 100;
        cout.flags(current_flag);

        cout << "$" << endl;

    }

    return 0;
}
