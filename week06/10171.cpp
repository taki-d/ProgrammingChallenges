#include <bits/stdc++.h>

using namespace std;

struct edge{
    int to,cost;
};

int main() {

    while(1){
        int N;
        cin >> N;

        if(N == 0){
            return 0;
        }

        vector<vector<edge>> young_graph(100);
        vector<vector<edge>> old_graph(100);

        for (int i = 0; i < N; ++i) {
            char age,type;
            char from,to;
            int cost;

            cin >> age >> type >> from >> to >> cost;
            edge e1,e2;

            if(age == 'Y'){
                e1.to = to - 'A';
                e1.cost = cost;
                young_graph[from - 'A'].push_back(e1);
                if(type == 'U'){
                    e2.to = from - 'A';
                    e2.cost = cost;
                    young_graph[to - 'A'].push_back(e2);
                }
            } else {
                e1.to = to - 'A';
                e1.cost = cost;
                old_graph[from - 'A'].push_back(e1);
                if(type == 'U'){
                    e2.to = from - 'A';
                    e2.cost = cost;
                    old_graph[to - 'A'].push_back(e2);
                }
            }
        }

        auto dijkstra = [](int start, vector<vector<edge>> g)->vector<int>{
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> queue;
            vector<int> d(50,2e9);

            d[start] = 0;
            queue.push(make_pair(0, start));
            // pair first: cost, second: index of v

            while(!queue.empty()){
                pair<int,int> p = queue.top();
                queue.pop();

                int v = p.second;
//                if(d[v] < p.first) continue;

                for (const auto& e : g[v]) {
                    if(d[e.to] > d[v] + e.cost) {
                        d[e.to] = d[v] + e.cost;
                        queue.push(make_pair(d[e.to], e.to));
                    }
                }
            }

            return d;
        };

        char old_start, young_start;
        cin >> young_start >> old_start;

        vector<int> young_cost,old_cost;
        young_cost = dijkstra(int(young_start - 'A'), young_graph);
        old_cost = dijkstra(int(old_start - 'A'), old_graph);

        int min_cost = 2e9;

        vector<char> ans;

        for (int i = 0; i < 50; ++i) {
                if(young_cost[i] <= 500 && old_cost[i] <= 500){
                    if(min_cost > young_cost[i] + old_cost[i]){
                        min_cost = young_cost[i] + old_cost[i];
                        ans.clear();
                        ans.push_back(i + 'A');
                    }else if(min_cost == young_cost[i] + old_cost[i] && !ans.empty()){
                        ans.push_back(i + 'A');
                    }
                }
        }

        if(ans.empty()){
            cout << "You will never meet." << endl;
        }else{
            cout << min_cost;

            for(auto c : ans){
                cout << " " << c;
            }
            cout << endl;
        }

    }

}

