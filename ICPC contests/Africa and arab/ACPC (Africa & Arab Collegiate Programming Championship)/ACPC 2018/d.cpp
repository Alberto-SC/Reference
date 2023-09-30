#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    freopen("dull.in", "r", stdin);  
	lli t= 1,n,m,k,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        map<int,vector<int>> rows;
        for(int i = 0;i<k;i++){
            cin>>x>>y;
            rows[x].push_back(y);
        }
        lli ans = 0;
        int cont = 0;
        map<int,vector<int>> columns;
        for(auto c:rows){
            int last = 0;
            for(int i = 0;i<c.second.size();i++){
                cont++;
                if(cont%2==0)continue;
                if(i+1<(int)c.second.size())
                    ans+=c.second[i+1]-c.second[i];                
                else{
                    ans+=(m-c.second[i])+1;
                }
            }
        }
        cout<<ans<<" "<<(n*m)-ans<<endl;
    }
    return 0;
}  

