#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<vector<int>> d;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        std::vector<int> slary;
        for (int j = 0; j < 3; ++j) {
            int t;
            cin >> t;
            slary.push_back(t);
        }
        d.push_back(slary);
    }

    // sort array
    for(auto &di : d){
        sort(di.begin(),di.end());
    }

    for (int i = 0; i < n; ++i) {
        cout << "Case " << i << ": " << d[i][1] << endl;
    }

}

