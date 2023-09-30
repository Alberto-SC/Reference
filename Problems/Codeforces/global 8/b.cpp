#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
map<lli,lli> fact;

int main(){
    lli k;
    cin>>k;
    string s = "codeforces";
    if(k==1)return cout<<s<<endl,0;
    lli idx = 0;
    lli x = 1;
    vector<lli> b(10,1);
    while(x<k){
        for(int i = 0;i<10;i++){
            x = (x/b[i])*(b[i]+1);
            b[i]++;
            if(x>=k)break;
        }
    }
    for(int i = 0;i<10;i++){
        for(int j = 0;j<b[i];j++){
            cout<<s[i];
        }
    }
    cout<<endl;
    return 0;
}