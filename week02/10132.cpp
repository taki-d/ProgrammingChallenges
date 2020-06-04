#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    cin.ignore();


    string gomi;
    getline(cin, gomi);

    for (int i = 0; i < N; ++i) {
        vector<string> fragments;
        string fragment;
        while(getline(cin ,fragment) && !fragment.empty()){
//            if(fragment == "") break;
            fragments.push_back(fragment);
        }

        map<string,int> d;
        // check all pattern
        for (int i = 0; i < fragments.size(); ++i) {
            for (int j = i+1; j < fragments.size(); ++j) {
                d[fragments[i] + fragments[j]]++;
                d[fragments[j] + fragments[i]]++;
            }
        }

        int max = 0;
        string ans = "";
        for(const auto& a : d){
            if(max < a.second){
                ans = a.first;
                max = a.second;
            }
        }

        cout << ans << endl;

        if(i != N-1) cout << endl;
    }

    return 0;
}
