#include <bits/stdc++.h>

using namespace std;

int main(){
    int V,E;

    while(1){

        cin >> V >> E;

        if(V == 0 && E == 0){
            return 0;
        }

        vector<vector<int>> G(V);
        vector<vector<int>> rG(V);

        auto add_edge = [&](int from, int to){
            G[from].push_back(to);
            rG[to].push_back(from);
        };

        for (int i = 0; i < E; ++i) {
            int from,to,type;
            cin >> from >> to >> type;
            // 0-index;
            --from; --to;

            add_edge(from,to);
            if(type == 2){
                add_edge(to,from);
            }
        }

        auto scc = [&](){
            bool used[1000];
            vector<int> cmp(V);
            vector<int> vs;

            function<void(int)> dfs = [&](int v){
                used[v] = true;
                for (int i = 0; i < G[v].size(); ++i) {
                    if(!used[G[v][i]]) dfs(G[v][i]);
                }
                vs.push_back(v);
            };

            function<void(int,int)> rdfs = [&](int v, int k){
                used[v] = true;
                cmp[v] = k;
                for (int i = 0; i < rG[v].size(); ++i) {
                    if(!used[rG[v][i]]) rdfs(rG[v][i], k++);
                }
            };

            memset(used, 0, sizeof(used));
            vs.clear();

            for (int v = 0; v < V; v++) {
                if(!used[v]) dfs(v);
            }

            memset(used, 0, sizeof(used));
            int k = 0;
            for (int i = vs.size() - 1; i >= 0; --i) {
                if(!used[vs[i]]) rdfs(vs[i], k++);
            }

            return k;
        };

        if(scc() == 1){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }


    }

}


