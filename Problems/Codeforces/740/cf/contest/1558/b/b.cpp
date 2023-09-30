#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 400007;
vector<int> dp(maxn);

void solve(int idx){
    
}

signed main(){__
	int t= 1,n,x;
    cin>>x;
    map<int,int> mp;
    int y = 0;
    for(int i = 2;i<x;i++){
        cout<<"I: "<<i<<" -> ";
        for(int j = 2;j<=i;j++){
            cout<<i/j<<" ";
            mp[i/j]++;
        }
        cout<<endl;
    }
    int last = 0;
    for(int i =2;(i+1)*2<=x;i++){
        int a = i*2,b = (i+1)*2;
        y+=b-a;
        last = i;
    }
    last++;
    cout<<x-(last*2); 
    cout<<mp[2]<<" "<<y<<endl;
    cout<<endl;
    return 0;
}  
