#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,l,r,m;
    cin>>t;
    while(t--){
        cin>>l>>r>>m;
        vector<int> ans(3);
        if(l>m){
            ans[0] = l;
            ans[1] = l;
            ans[2] = l+(l-m);
        }
        else{
            for(int i = l;i<=r;i++){
                // cout<<m%(i*(m/i))<<endl;
                if(m%i==0){
                    ans[0] = i;
                    ans[1] = i;
                    ans[2] = i;
                    break;
                }
                else if(m%(i*(m/i))<=r-l){
                    ans[0] = i;
                    ans[2] = l;
                    ans[1] = l+(m%(i*(m/i)));
                    break;
                }
                else if(i-m%(i*(m/i))<=r-l){
                    ans[0] = i;
                    ans[2] = l+(i-(m%(i*(m/i))));
                    ans[1] = l;
                }
            }
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

