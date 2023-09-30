#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

set<vector<string>> s;
bool win(vector<string>& v) {
    if(v[0][0] == v[0][1] && v[0][1] == v[0][2] && v[0][0] != '_') 
        return true;
    if(v[1][0] == v[1][1] && v[1][1] == v[1][2] && v[1][0] != '_') 
        return true;
    if(v[2][0] == v[2][1] && v[2][1] == v[2][2] && v[2][0] != '_') 
        return true;
    if(v[0][0] == v[1][0] && v[1][0] == v[2][0] && v[0][0] != '_') 
        return true;
    if(v[0][1] == v[1][1] && v[1][1] == v[2][1] && v[0][1] != '_') 
        return true;
    if(v[0][2] == v[1][2] && v[1][2] == v[2][2] && v[0][2] != '_') 
        return true;
    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '_') 
        return true; 
    if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] != '_') 
        return true;
    return false;
}

vector<bool> pos(20000);

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}
int get_int(vector<string> &v){
    int n = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(v[i][j]== 'X')n+= bin_pow(3,(i*3)+j);
            else if(v[i][j]=='O'){
                n+= 2*bin_pow(3,(i*3)+j);
            }
        }
    }
    return n;
}

void process(vector<string>& v, char c) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v[i][j] == '_') {
                v[i][j] = c;
                int x =  get_int(v);
                pos[x] = true;
                if(!win(v)) {
                    if(c == 'X') {
                        process(v, 'O');
                    }
                    else {
                        process(v, 'X');
                    }
                }
                v[i][j] = '_';
            }

        }
    }
}
signed main(){__
    vector<string> v = {"___","___","___"};
    pos[0] = true;
    process(v, 'X');
    int t;
    cin>>t;
    while(t--){
        vector<string> game(3);
        for(auto &c:game) 
            cin>>c;
        int x = get_int(game);
        if(!pos[x]) 
            cout<<3<<endl;
        else{
            bool flag = false;
            for(int i = 0;i<3;i++)
                for(int j = 0;j<3;j++)
                    if(game[i][j]=='_')flag = true;
            if(win(game)|| !flag)cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}