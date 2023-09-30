#include <bits/stdc++.h>
using namespace std;

#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const string t = "abacaba";

int count(const string& s) {
    int cnt = 0;
    for(int i = 0; i<s.size();i++){
        if(s.substr(i, t.size()) == t) 
            ++cnt
    }
    return cnt;
}

int main(){__
    int q;
    cin >>q;
    while(q--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool F = false;

        for (int i = 0; i + T.size() <= n; ++i) {
            string ss = s;
            bool ok = true;
            for (int j = 0; j < T.size(); j++) {
                if (ss[i + j] != '?' && ss[i + j] != T[j]) {
                    ok = false;
                    break;
                }
                ss[i + j] = T[j];
            }
            if (ok && count(ss) == 1) {
                for (int j = 0; j < n; j++) {
                    if (ss[j] == '?') {
                        ss[j] = 'd';
                    }
                }
                F = true;
                cout << "Yes\n";
                cout << ss << "\n";
                break;
            }
        }
        if (!F) {
            cout << "No\n";
        }
    }

    return 0;
}