#include <bits/stdc++.h>

using namespace std;

int main(){

    string input;
    map<string,int> dict;
    while(cin >> input){
        if(input == "#"){
            break;
        }

        dict[input] = 1;
    }

    auto split =  [](const string &s, char delim)->vector<string>{
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            if (!item.empty()) {
                elems.push_back(item);
            }
        }
        return elems;
    };

    auto caesar_encryption = [](string ss, int v){
        string dec;
        for(const auto& s: ss){
            int i = s - 'A';
            if(s == ' ') i = 26;
            i += v;
            i = i % 27;
            dec.push_back((i == 26 ? ' ' : char(i + 'A')));
        }

        return dec;
    };

    cin.ignore();
    string encrypted_string;

//    while (1) {

        getline(cin, encrypted_string);

        /*
        if(cin.eof()){
            break;
        }*/

        string ans = "";
        int count = 0;
        for (int i = 0; i < 27; ++i) {
            string chk_string = caesar_encryption(encrypted_string, i);

            int c_count = 0;
            for(const auto& s : split(chk_string, ' ')){
                if(dict.find(s) != dict.end()){
                    c_count++;
                }
            }

            if(count <= c_count){
                count = c_count;
                ans = chk_string;
            }
        }

        vector<string> output_strings = split(ans, ' ');

        int current_i = 0;
        while(true){
            int count = 0;
            int index = current_i;

            while(index != (output_strings.size() - 1)){
                count += (output_strings[index].size() + 1);

                if(count > 61){
                    index--;
                    break;
                }
                if(count == 61){
                    break;
                }

                index++;
            }

            cout << output_strings[current_i];
            for (int i = current_i+1; i <= index; ++i) {
                cout << " " << output_strings[i];
            }
            cout << endl;

            if(index == output_strings.size() - 1){
                break;
            }

            current_i = index + 1;
        }
//    }
}


