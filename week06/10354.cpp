#include <bits/stdc++.h>

using namespace std;


int main() {

    int P,R,BH,OF,YH,M;
    while(cin >> P >> R >> BH >> OF >> YH >> M){
        // 0 index
        --BH; --OF; --YH; --M;

        vector<vector<int>> g_boss(P,vector<int>(P,2e8));
        vector<vector<int>> g_prog(P,vector<int>(P,2e8));

        for (int i = 0; i < P; ++i) {
            g_boss[i][i] = 0;
            g_prog[i][i] = 0;
        }

        for (int i = 0; i < R; ++i) {
            int from,to,cost;
            cin >> from >> to >> cost;
            --from;
            --to;

            g_boss[from][to] = cost;
            g_boss[to][from] = cost;

            g_prog[from][to] = cost;
            g_prog[to][from] = cost;
        }

        // floyed warshall
        for (int k = 0; k < P; ++k) {
            for (int i = 0; i < P; ++i) {
                for (int j = 0; j < P; ++j) {
                    g_boss[i][j] = min(g_boss[i][j], g_boss[i][k] + g_boss[k][j]);
                }
            }
        }

        bool used[100];
        memset(used, 0, sizeof(used));

        // find boss path
        for (int i = 0; i < P; ++i) {
            if(g_boss[BH][OF] == g_boss[BH][i] + g_boss[i][OF])
                used[i] = true;
        }

        for (int k = 0; k < P; ++k) {
            if(used[k]) continue;
            for (int i = 0; i < P; ++i) {
                if(used[i]) continue;
                for (int j = 0; j < P; ++j) {
                    if(used[j]) continue;

                    g_prog[i][j] = min(g_prog[i][j], g_prog[i][k] + g_prog[k][j]);
                }
            }
        }

        if(g_prog[YH][M] == 2e8 | used[YH] | used[M]){
            cout << "MISSION IMPOSSIBLE." << endl;
        }else{
            cout << g_prog[YH][M] << endl;
        }

    }
}

