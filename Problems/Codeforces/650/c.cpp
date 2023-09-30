#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
const int inf = 1000000007;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t,n,k;
    cin>>t;
    string s;
    while(t--){
        cin>>n>>k;
        cin>>s;
        vector<int> pos;
        int ans = 0;
        for(int i= 0;i<n;i++)
            if(s[i]== '1')pos.push_back(i);
        if(pos.size()== 0)cout<<ceil((n*1.0)/(k+1))<<endl;
        else{
            int last = 0;
            for(int i = 0;i<pos.size();i++){
                int x;
                if(i == 0){
                    x = pos[i]-k;
                    // cout<<x<<endl;
                    if(x)
                        ans+=ceil((x*1.0)/(k+1));
                    last = pos[i];
                }
                else {

                    x = (pos[i]-last)-1;
                    if(x<0){
                        last = pos[i];
                        continue;
                    }
                    // cout<<x<<" ";
                    x-= (k*2);
                    // cout<<x<<endl;
                    ans+=ceil((x*1.0)/(k+1));

                    last = pos[i];
                }
            }
            int x =  pos.back()+k;
            x = (n-x)-1;
            // cout<<x<<endl;
            if(x)
                ans+=ceil((x*1.0)/(k+1));
            cout<<ans<<endl;
        }
    }
    return 0;
}