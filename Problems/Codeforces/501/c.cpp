#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,m,o,c;
    cin>>n>>m;
    lli minpos = 0,original = 0;
    vector<lli> gain(n);
    for(int i = 0;i<n;i++){
        cin>>o>>c;
        minpos+=c;
        gain[i] = o-c;
        original +=o;
    }
    if(minpos>m)return cout<<-1<<endl,0;
    sort(gain.rbegin(),gain.rend());
    for(int i = 0;i<n;i++){
        if(original<= m)return cout<<i<<endl,0;
        original-=gain[i];
    }
    cout<<n<<endl;
    return 0;
}