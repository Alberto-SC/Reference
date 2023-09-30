#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    int test = 1;
    while(t--){
        string s,t = "facebook";
        cin>>s;
        int n =s.size();
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(idx<t.size() && s[i]== t[idx])idx++;
        }
        if(idx== t.size())cout<<"Case #"<<test<<": YES"<<endl;
        else cout<<"Case #"<<test<<": NO"<<endl;
        test++;
    }
    return 0;
}  
