#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,w,h;
    while(t--){
        cin>>n;
        int last = 1e15;
        bool flag = true;
        for(int i = 0;i<n;i++){
            cin>>w>>h;
            if(min(w,h)>last)flag = false;
            else if(max(w,h)<=last)last = max(w,h);
            else last = min(w,h);
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
