#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>n;
    string s;
    vector<bool> b(1000007);
    for(int i = 0;i<n;i++){
        cin>>s;
        if(s== "1000000"){
            b[1000000] = true;
        }
        if(s[0]== '-')continue;
        if(s.size()<=6){
            int num = stoi(s);
            b[num] = true;
        }
    }
    for(int i = 0;i<=n+10;i++){
        if(!b[i])return cout<<i<<endl,0;
    }
    return 0;
}

