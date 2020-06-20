#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int junction, street;
        cin >> junction >> street;

        vector<vector<int>> streets(junction);
        for (int j = 0; j < street; ++j) {
            int right,left;
            cin >> right >> left;

            streets[right].push_back(left);
            streets[left].push_back(right);
        }

        vector<int> color(junction, 0);
        // not visited :0
        // black: 1
        // whilte: 2

        int answer = 0;
        bool is_bipatite_graph = true;

        for (int j = 0; j < junction; ++j) {
            if(color[j] == 1 | color[j] == 2){
                continue;
            }

            queue<int> queue;
            int white = 0,black = 0;

            // initialize
            queue.push(j);
            color[j] = 1;
            ++black;


            while(!queue.empty()){
                int q = queue.front();
                queue.pop();

                for (int k = 0; k < streets[q].size(); ++k) {
                    // check bipartite graph
                    if(color[streets[q][k]] == color[q]){
                        is_bipatite_graph = false;
                        break;
                    }

                    // paint color
                    if(color[streets[q][k]] == 0){
                        if(color[q] == 1){
                            //paint white
                            color[streets[q][k]] = 2;
                            white++;
                        }else{
                            //paint black
                            color[streets[q][k]] = 1;
                            black++;
                        }

                        queue.push(streets[q][k]);
                    }

                }

                if(!is_bipatite_graph){
                    break;
                }


            }

            if(!is_bipatite_graph){
                break;
            }

            int max = (black < white ? black : white);
            answer += (max == 0 ? 1 : max);
        }

        if(is_bipatite_graph){
            cout << answer << endl;
        }else{
            cout << -1 << endl;
        }
    }
    
    
    return 0;
}
