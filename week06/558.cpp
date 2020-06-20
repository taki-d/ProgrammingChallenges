#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from,to,cost;
};

int main() {

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int V,E;
        cin >> V >> E;

        vector<edge> ev(E);

        for (int j = 0; j < E; ++j) {
            int from,to,cost;
            cin >> from >> to >> cost;
            edge e;
            e.from = from;
            e.to = to;
            e.cost = cost;

            ev.push_back(e);
        }

        auto find_neg_loop = [&](){
            vector<int> d(E,0);

            for (int j = 0; j < V; ++j) {
                for (const auto &e : ev) {
                    if(d[e.to] > d[e.from] + e.cost){
                        d[e.to] = d[e.from] + e.cost;

                        if(j == V - 1) return true;
                    }
                }
            }
            return false;
        };

        if(find_neg_loop()){
            cout << "possible" << endl;
        }else{
            cout << "not possible" << endl;
        }

    }
}
