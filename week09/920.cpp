#include <bits/stdc++.h>

using namespace std;

struct point { int x,y; };

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int point_num;
        cin >> point_num;

        vector<point> points;
        for (int j = 0; j < point_num; ++j) {
            int x,y;
            cin >> x >> y;
            point p;
            p.x = x;
            p.y = y;

            points.push_back(p);
        }

        sort(points.begin(), points.end(), [](point a, point b){
            return a.x > b.x;
        });

        double length = 0;
        int max_y = 0;

        auto distance = [](point a, point b){
              return sqrt(double(a.x - b.x)*double(a.x - b.x) + double(a.y - b.y)*double(a.y - b.y));
        };

        for (int j = 1; j < point_num; ++j) {
            if(max_y < points[j].y){
                length += distance(points[j], points[j-1]) * (points[j].y - max_y) / (points[j].y - points[j-1].y);
                max_y = points[j].y;
            }
        }


        cout << setprecision(2) << setiosflags(ios::fixed) << length << endl;

    }
    
    return 0;
}
