#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    string x;
    string y;
    cin>>x>>y;
    int a =0,b = 0;
    for(int i = 0;i<x.size();i++)
        if(x[i]=='S')a++;
    for(int i = 0;i<y.size();i++)
        if(y[i]=='S')b++;
    
    int res = a*b;
    for(int i = 0;i<res;i++)
        cout<<"S(";
    cout<<0;
    for(int i = 0;i<res;i++)
        cout<<")";
    cout<<endl;
    return 0;
}  
