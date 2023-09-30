#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(4);
        while(n%2 == 0){
            v[2]++;
            n/=2;
        }
        while(n%3 == 0){
            v[3]++;
            n/=3;
        }
        if(n>1){cout<<-1<<endl;continue;}
        if(v[2]> v[3]){cout<<-1<<endl;continue;}
        int ans = v[2];
        ans += (v[3]-v[2])*2;
        cout<<ans<<endl;
    }
    return 0;
}