#include <bits/stdc++.h>

using namespace std;



int main(){

    int N;
    cin >> N;

    int dx[] = {-1, 0, 1, 1, 1, 0,-1,-1};
    int dy[] = {-1,-1,-1, 0, 1, 1, 1, 0};

    for (int i = 0; i < N; ++i) {

        int m,n;
        cin >> m >> n;

        vector<string> grid;

        for (int j = 0; j < m; ++j) {
            string grid_;
            cin >> grid_;
            grid.push_back(grid_);
        }

        int k;
        cin >> k;

        auto search = [&](string search_string){
            vector<pair<int,pair<int,int>>> ans_vec;

                for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                    for (int vec = 0; vec < 8; ++vec) {
                        int c_x = x,c_y = y;
                        bool flag = false;
                        for (int z = 0; z < search_string.size(); ++z) {
                            if(c_x < 0 || c_x >= n || c_y < 0 || c_y >= m){
                                break;
                            }else{
                                if(toupper(search_string[z]) != toupper(grid[c_y][c_x])){
                                    break;
                                }else if(z == (search_string.size() - 1)){
                                    return make_pair(y,x);
                                }
                            }

                            c_x += dx[vec];
                            c_y += dy[vec];
                        }
                    }
                }
            }
        };

        // number of searching words
        for (int j = 0; j < k; ++j) {
            string search_str;
            cin >> search_str;

            pair<int,int> ans = search(search_str);

            cout << ans.first + 1 << " " << ans.second + 1 << endl;

        }

        if(i != N-1){
            cout << endl;
        }
    }
}


