#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


bool check(int x,vector<int> &a,vector<int> &b){
    int l = 0,int r = T+1;
    while(l+1<r){
          int m = (l+r)>>1;

    }
    
}

signed main(){__
	int t= 1,n,T,a,b,x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<int> a;
        vector<int> b;
        vector<int> type(n);
        for(auto &c:type)cin>>c;
        for(int i = 0;i<n;i++){
            cin>>x;
            if(type[i])
                b.push_back(x);
            else   
                a.push_back(x);
        }
        int l = 0,r = n+1;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,a,b))
                l = m;
            else 
                r = m;
        }
        cout<<l<<endl;
    }
    return 0;
}  
