#include <bits/stdc++.h>

using namespace std;

int main(){



    int N;
    cin >> N;

    for (int i = 0; i < N; ++i){
        vector<vector<int>> graph;

        int edge;
        cin >> edge;
        for (int j = 0; j < edge; ++j) {
            vector<int> ar;

            for (int k = 0; k < edge; ++k) {
                int v;
                cin >> v;
                ar.push_back(v);
            }

            graph.push_back(ar);
        }

        bool visited[120];
        memset(visited, 0, sizeof (visited));

        function<void(int,int)> dfs2 = [&](int v, int avoid)->void{
            visited[v] = true;

            for(int j = 0; j < edge; ++j){
                if(j == avoid) continue;

                if(graph[v][j] == 1 && visited[j] != 1){
                    dfs2(j,avoid);
                }
            }
        };

        bool dominated[120][120];
        memset(dominated, 0, sizeof(dominated));

        dfs2(0,-1);
        for(int j = 0; j < edge; j++){
            if(visited[j]){
                dominated[0][j] = true;
            }
        }

        for (int j = 1; j < edge; ++j) {
            memset(visited, 0 , sizeof(visited));

            dfs2(0, j);

            for (int k = 0; k < edge; ++k) {
                if(dominated[0][k] && !visited[k]){
                    dominated[j][k] = 1;
                }
            }
        }

        auto line = [&](){
            cout << '+';
            for (int i = 0; i < edge*2 -1; ++i) {
                cout << '-';
            }
            cout << '+' << endl;
        };

        cout << "Case " << i << ":" << endl;

        for (int j = 0; j < edge; ++j) {
            line();

            for (int k = 0; k < edge; ++k) {
                cout << '|' << (dominated[j][k] ? 'Y' : 'N');
            }
            cout << '|' << endl;
        }

        line();

    }
    
    return 0;
}
