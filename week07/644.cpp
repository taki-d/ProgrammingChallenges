#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    vector<string> inputs;

    auto chk_prefix = [](string a, string b){
        bool flag = true;
        int ite = 0;
        while(ite < a.length()){
            flag = flag && (a[ite] == b[ite]);
            ite++;
        }

        return flag;
    };

    int count = 0;
    while(cin >> input) {
        if(input != "9"){
            inputs.push_back(input);
        }else{

            sort(inputs.begin(), inputs.end(), [](string a, string b){
                return a.length() < b.length();
            });

            bool flag = false;

            for (int i = 0; i < inputs.size() && !flag; ++i) {
                for (int j = i + 1; j < inputs.size() && !flag; ++j) {
                    if(chk_prefix(inputs[i], inputs[j])){
                        flag = true;
                    }
                }
            }

            count++;


            if(!flag){
                cout << "Set " << count << " is immediately decodable" << endl;
            }else{
                cout << "Set " << count << " is not immediately decodable" << endl;
            }

            inputs.clear();
        }
    }
}


