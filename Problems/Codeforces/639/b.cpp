#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t,n;
    cin>>t;
    vector<lli> pre;
    pre.push_back(2);
    for(lli i = 2;i<1000000;i++){
        pre.push_back(pre[pre.size()-1]+(2*i)+(i-1));
    }
    while(t--){
        cin>>n;
        lli ans = 0;
        while(n){
            lli index = lower_bound(pre.begin(),pre.end(),n)-pre.begin();
            if(pre[index]== n){ans++;break;}
            index--;
            if(index<0)break;
            // cout<<pre[index]<<endl;
            // cout<<index<<endl;
            n-=pre[index];
            ans++;
        }
        cout<<ans<<endl;
        
    }
}