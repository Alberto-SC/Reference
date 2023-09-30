#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int main(){
    int t,n,q,l,r;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<lli> nums(n+2);
        vector<pair<int,int>> op(n+2); 
        for(int i = 0;i<q;i++){
            cin>>l>>r;
            nums[l]++;
            nums[r+1] -= ((r+1)-l)+1;
            op[l].first++;
            op[r+1].second++;
        }
        lli sum = 0;
        int cont = 0;
        vector<lli> ans(n+1);
        for(int i = 0;i<=n;i++){
            sum+= cont;
            cont+=op[i].first;
            cont-=op[i].second;
            sum+= nums[i];
            ans[i] = sum;
        }
        for(int i =1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}