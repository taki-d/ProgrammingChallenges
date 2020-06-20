#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {

        int forward_to[50001];
        bool visited[50001];
        int ans[50001];
        memset(visited, 0, sizeof(visited));
        memset(ans, -1, sizeof(ans));

        int n;
        cin >> n;

        for (int j = 0; j < n; ++j) {
            int from,to;
            cin >> from >> to;
            // 0-index
            --from;
            --to;
            forward_to[from] = to;
        }

        function<int(int)> dfs = [&](int v)->int{
            if(visited[v]) return 0;
            visited[v] = true;
            int q = dfs(forward_to[v]);
            visited[v] = false;
            ans[v] = q + 1;
            return q + 1;
        };

        // search
        for (int j = 0; j < n; ++j) {
            if(ans[j] == -1) dfs(j);
        }

        int max = -1;
        int answer = -1;
        for (int j = 0; j < n; ++j) {


        if(max < ans[j]){
            max = ans[j];
            answer = j;
        }
        }
        cout << "Case " << i + 1 << ": " << answer + 1 << endl;
    }
    
    return 0;
}
