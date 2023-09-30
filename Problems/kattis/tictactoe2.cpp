#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}
set<vector<string>> s;
bool win(vector<string>& v) {
    if(v[0][0] == v[0][1] && v[0][1] == v[0][2] && v[0][0] != '.') 
        return true;
    if(v[1][0] == v[1][1] && v[1][1] == v[1][2] && v[1][0] != '.') 
        return true;
    if(v[2][0] == v[2][1] && v[2][1] == v[2][2] && v[2][0] != '.') 
        return true;
    if(v[0][0] == v[1][0] && v[1][0] == v[2][0] && v[0][0] != '.') 
        return true;
    if(v[0][1] == v[1][1] && v[1][1] == v[2][1] && v[0][1] != '.') 
        return true;
    if(v[0][2] == v[1][2] && v[1][2] == v[2][2] && v[0][2] != '.') 
        return true;
    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '.') 
        return true; 
    if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] != '.') 
        return true;
    return false;
}

void process(vector<string>& v, char c) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v[i][j] == '.') {
                v[i][j] = c;
                s.insert(v);
                if(!win(v)) {
                    if(c == 'X') {
                        process(v, 'O');
                    }
                    else {
                        process(v, 'X');
                    }
                }
                v[i][j] = '.';
            }

        }
    }
}
int main() {
    vector<string> v = {"...","...","..."};
    s.insert(v);
    process(v, 'X');
    int cases;
    cin >> cases;
    while(cases--){
        vector<string> v(3);
        for(auto& i : v) 
            cin >> i;
        if(s.count(v) > 0) 
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}