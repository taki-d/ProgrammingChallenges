#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 1;
    while(1){
        int P,R;
        cin >> P >> R;

        if(P == 0 && R == 0){
            return 0;
        }

        vector<vector<int>> g(P,vector<int>(P,2e8));

        for (int i = 0; i < P; ++i) {
            g[i][i] = 0;
        }

        map<string,int> name;
        int counter = 0;

        for (int i = 0; i < R; ++i) {
            string a,b;
            cin >> a >> b;

            int a_index,b_index;
            if(name.find(a) != name.end()){
                a_index = name[a];
            }else{
                name[a] = counter;
                a_index = counter;
                counter++;
            }

            if(name.find(b) != name.end()){
                b_index = name[b];
            }else{
                name[b] = counter;
                b_index = counter;
                counter++;
            }

            g[a_index][b_index] = 1;
            g[b_index][a_index] = 1;

        }

        for (int k = 0; k < P; ++k) {
            for (int i = 0; i < P; ++i) {
                for (int j = 0; j < P; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        int max = 0;
        for (int i = 0; i < P; ++i) {
            for (int j = 0; j < P; ++j) {
                if(max < g[i][j]){
                    max = g[i][j];
                }
            }
        }

        cout << "Network " << n << ": ";
        if(max == 2e8){
            cout << "DISCONNECTED" << endl;
        }else{
            cout << max << endl;
        }

        cout << endl;

        ++n;
    }
}

