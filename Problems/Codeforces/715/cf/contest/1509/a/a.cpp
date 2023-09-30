#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> p;
        vector<int> im;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            if(x&1)im.push_back(x);
            else p.push_back(x);
        }
        for(int i = 0;i<p.size();i++)cout<<p[i]<<" ";
        for(int i = 0;i<im.size();i++)cout<<im[i]<<" ";
        cout<<endl;
    }
    return 0;
}  
