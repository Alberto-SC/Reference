#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,id = 1,A,B;
    cin>>t;
    while(t--){
        cin>>n>>A>>B;
        vector<int> nums(n+1);
        for(int i= 1;i<=n;i++)
            cin>>nums[i];
        int ans = 0;
        for(int i = 1;i<=402;i++){
            vector<int> b(403);
            vector<int> copy = nums;
            b[i]++;
            for(int j = i;j>=0;j--){
                if(!b[j])continue;
                int rest = 0;
                if((j-A)>0 && (j>n || b[j]>copy[j])){
                    if(j>n)
                        b[j-A]+=b[j],rest += b[j];
                    else    
                        b[j-A]+=b[j]-copy[j],rest+=b[j]-copy[j];

                }
                if((j-B)>0 && (j>n || b[j]>copy[j])){
                    rest = 0;
                    if(j>n)
                        b[j-B]+=b[j],rest+=b[j];
                    else 
                        b[j-B]+=b[j]-copy[j],rest+=b[j]-copy[j];
                }
                b[j]-=rest;
            }
            bool yes = true;
            for(int j = 0;j<=n;j++){
                if(b[j]<copy[j])yes = false;
            }
            if(yes){
                ans = i;
                break;
            }
        }
        if(ans)
            cout<<"Case #"<<id++<<": "<<ans<<endl;
        else
            cout<<"Case #"<<id++<<": IMPOSSIBLE"<<endl;
    }
    return 0;
}  
