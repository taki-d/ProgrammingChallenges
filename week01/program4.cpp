#include <bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin >> n;

    auto split =  [](const string &s, char delim)->vector<string>{
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
        if (!item.empty()) {
                elems.push_back(item);
            }
        }
        return elems;
    };

    for (int i = 0; i < n; ++i) {
        string l;
        cin.ignore();
        getline(cin, l);


        vector<int> v;
        for(auto &li : split(l, ' ')){
            v.push_back(stoi(li));
        }

        sort(v.begin(),v.end(), greater<int>());

        cout << "Case " << i+1 << ": " << v[0] << endl;

    }
}
