#include <bits/stdc++.h>

using namespace std;

int main(){
    int B, S;

    vector<int> R;
    vector<int> L;

    while(1){
        cin >> B >> S;

        if(B == 0 && S == 0) return 0;

        R.clear();
        L.clear();

        // indexを揃える．
        R.push_back(-1);
        L.push_back(-1);

        for (int i = 0; i < B; ++i) {
            R.push_back(i+2);
            L.push_back(i);
        }

        R.push_back(-1);
        L.push_back(-1);

        L[1] = -1;
        R[B] = -1;

        for (int i = 0; i < S; ++i) {
            int l,r;
            cin >> l >> r;

            int r_l = L[l];
            int l_r = R[r];

            if(r_l == -1) {
                cout << "*";

            }else{
                cout << r_l;
                R[r_l] = R[r];
            }
            cout << " ";

            if(l_r == -1){
                cout << '*' << endl;
            }else{
                cout << l_r << endl;
                L[l_r] = L[l];
            }

        }

        cout << "-" << endl;
    }

    return 0;
}
