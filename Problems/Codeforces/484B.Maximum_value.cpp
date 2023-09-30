#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000007;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<bool> b(maxn);
    for(auto &x:nums)cin>>x,b[x]= true;;
    vector<int> last(maxn);
    last[0]=-1;
    for(int i=1;i<=maxn;i++)
        last[i]=b[i]?i:last[i-1];
    int ans=0;
    for(int i=1;i<=maxn;i++){
        if(b[i]){
            for(int j=2;i*(j-1)<=maxn;j++){
                int x=last[min(i*j-1,maxn)];
                if(x!=-1&&x>=i*(j-1))
                    ans=max(ans,x%i);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}