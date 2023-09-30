#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        
        vector<int> ans(n);
        int ac = 0,last  = n;
        for(int i =1;i<=n;i++){
            ac+=i;
            if(ac>k){
                ac-=i;
                last = i-1;
                break;
            }
            ans[i-1] = i;
        }
        for(int i = 0;i<last;i++)ans[i] = (40-ans[i])+1;
        int sum = 0;
        for(int i = last-1;i>=k-ac;i--){
            sum+=ans[i];
        }
        sum++;

        if(last<n)
            ans[last] = -sum;
        for(int i = last+1;i<n;i++)ans[i] = -1000;

        int cont = 0;
        for(int i = 0;i<n;i++){
            int x = 0;
            for(int j = i;j<n;j++){
                x+=ans[j];
                if(x>0)cont++;
            } 
        }

        assert(cont == k);
        
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
 
