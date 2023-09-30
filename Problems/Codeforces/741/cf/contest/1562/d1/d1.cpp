#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,q,l,r;
    cin>>t;
    while(t--){
        cin>>n>>q;
        string s;
        cin>>s;
        vector<int> pr(n),ir(n);
        for(int i = 0;i<n;i++){
            if(i&1){
                if(s[i]=='+')
                    ir[i]= 1;
                else 
                    ir[i] = -1;
                pr[i] = 0;
            }
            else{
                if(s[i]=='+')
                    pr[i]= 1;
                else 
                    pr[i] = -1;
                ir[i] = 0;
            }
        }
        for(int i = 1;i<n;i++){
            pr[i] =pr[i-1]+pr[i];
            ir[i] = ir[i-1]+ir[i];
        }
        while(q--){
            cin>>l>>r;
            l--,r--;
            int x = pr[r]-(l?pr[l-1]:0);
            int y = ir[r]-(l?ir[l-1]:0);
            // cout<<x<<" "<<-y<<endl;
            cout<<abs(x-y)<<endl;
        }
    }
    return 0;
}  
