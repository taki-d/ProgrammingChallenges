#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;


    for (int i = 0; i < N; ++i) {
        int A,B,C;
        cin >> A >> B >> C;

        bool flag = false;

        for(int x = -100; x <= 100; ++x){
            for(int y = -100; y <= 100; ++y){

                int z = A - x - y;
                if(!(x == y || y == z || x == z)){
                    if(x*y*z == B){
                        if(x*x + y*y + z*z == C){
                            cout << x << " " << y << " " << z << endl;
                            flag = true;
                            break;
                        }
                    }
                }
            }

            if(flag) break;
        }

        if(!flag) cout << "No solution" << endl;
    }

    return 0;
}
