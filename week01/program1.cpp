#include <bits/stdc++.h>

using namespace std;

int main(){
    std::map<int,int> t;
    t[1] = 1;

    function<int(int)> calc = [&](int in)->int{
        int mem = 0;
        if(t.find(in) != t.end()) return t[in];
        else if(in % 2) mem = calc(3*in+1);
        else mem = calc(in/2);
        t[in] = mem+1;
        return mem+1;
    };


    int r,l;
    while(cin >> r >> l){
        int maximum = 0;
        if(r > l) swap(r,l);

        for (int n = r; n <= l; ++n) {
            maximum = max(calc(n),maximum);
        }
        cout << r << " " << l << maximum << endl;
    }

}

