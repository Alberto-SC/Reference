#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        int idx = n-1;
        for(int i = 0;i<n-1;i+=2){
            cout<<"? "<<2<<" "<<i+1<<" "<<i+2<<" "<<1<<endl;
            cin>>x;
            if(x ==1){
                idx = i;
                break;
            }
            else if(x==2){
                cout<<"? "<<2<<" "<<i+2<<" "<<i+1<<" "<<1<<endl;
                cin>>x;
                if(x==1){
                    idx = i+1;
                    break;
                }
            }
        }
        vector<int> ans(n);
        ans[idx] = 1;
        for(int i = 0;i<n;i++){
            if(i== idx)continue;
            cout<<"? "<<1<<" "<<idx+1<<" "<<i+1<<" "<<n-1<<endl;
            cin>>x;
            ans[i] = x;
        }
        cout<<"! ";
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  