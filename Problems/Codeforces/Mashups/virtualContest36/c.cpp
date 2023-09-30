#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,l,r,k;
    while(t--){
        cin>>l>>r>>k;
        int aux = k;
        vector<int> ans;
        if(l<=1 &&r>=1)ans.push_back(1);
        for(int i = 1;i<64;i++){
            int mul;
            if(l<=k &&k<=r)ans.push_back(k);
            if(k>r)break;
            if (__builtin_smulll_overflow(k, aux, &mul))        
                break;
            else k= mul;
        }
        if(ans.size()==0)cout<<-1<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
