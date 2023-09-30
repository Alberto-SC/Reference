#include <bits/stdc++.h>
using namespace std;

int main(){


    int n; cin>>n;

    for(int i = n, j = n; ; i++, j--){

        string s1 = to_string(i);
        string s2 = to_string(j);

        if(s1.size() >= 2){
            string num = "";
            num += s1[s1.size()-2];
            num += s1[s1.size()-1];
            if(num == "99"){
                cout << s1 << endl; break;
            }
        }

        if(s2.size() >= 2){
            string num = "";
            num += s2[s2.size()-2];
            num += s2[s2.size()-1];
            if(num == "99"){
                cout << s2 << endl; break;
            }
        }

    }

    return 0;
}