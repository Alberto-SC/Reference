#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli k,l,r,t,x,y;
    cin>>k>>l>>r>>t>>x>>y;
    if(k<l||k>r) return cout<<"No"<<endl,0;
    if(x==y){
        if(k-x<l && k+x>r)return cout<<"No"<<endl,0;
        return cout<<"Yes"<<endl,0;
    }
    else if(x>y){
        lli diff = x-y;
        if(k+x<=r)k+=x,k-=y,t--;
        else k-=x,t--;
        if((k-l)/diff>=t)return cout<<"Yes"<<endl,0;
        else return cout<<"No"<<endl,0;
    }
    vector<bool> ks(x+1);
    while(t){
        if(ks[k%x])return cout<<"Yes"<<endl,0;
        ks[k%x] = true;
        lli move = min(t,(k-l)/x);
        k-=move*x;
        t-=move;
        if(!t)return cout<<"Yes"<<endl,0;
        t--;
        if(k+y<=r)k+=y;
        k-=x;
        if(k<l || k>r)return cout<<"No"<<endl,0;
    }
    cout<<"Yes"<<endl;
    return 0;
}  

