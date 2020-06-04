#include <bits/stdc++.h>

using namespace std;

int main(){
    array<array<int,3>,3> grid;

    auto update = [&](){
        array<array<int,3>,3> updated_grid;

        updated_grid[0][0] = (grid[0][1] + grid[1][0]) % 2;
        updated_grid[0][1] = (grid[0][0] + grid[1][1] + grid[0][2]) % 2;
        updated_grid[0][2] = (grid[0][1] + grid[1][2]) % 2;
        updated_grid[1][0] = (grid[0][0] + grid[1][1] + grid[2][0]) % 2;
        updated_grid[1][1] = (grid[0][1] + grid[1][0] + grid[1][2] + grid[2][1]) % 2;
        updated_grid[1][2] = (grid[0][2] + grid[1][1] + grid[2][2]) % 2;
        updated_grid[2][0] = (grid[2][1] + grid[1][0]) % 2;
        updated_grid[2][1] = (grid[2][0] + grid[1][1] + grid[2][2]) % 2;
        updated_grid[2][2] = (grid[2][1] + grid[1][2]) % 2;

        grid = updated_grid;
    };

    auto check_zero = [&](){
        for(const auto& a : grid){
            for(const auto& b : a){
                if(b != 0) return false;
            }
        }
        return true;
    };

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int l;
        cin.ignore();
        for (int a = 0; a < 3; ++a) {
            cin >> l;
            grid[a] = { l / 100, (l / 10) % 10, l % 10 };
        }

        l = -1;
        while(1){
            if(check_zero()){
                break;
            }
            update();
            ++l;
        }

        cout << l << endl;

    }

    return 0;
}
