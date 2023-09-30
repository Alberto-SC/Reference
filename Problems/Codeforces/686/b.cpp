#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> b(n+1);
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            b[x] = {b[x].first+1,i+1};
        }
        bool flag = false;
        for(int i = 0;i<=n;i++)
            if(b[i].first== 1){flag = true;cout<<b[i].second<<endl;break;}
        if(!flag)cout<<-1<<endl;
    }
    return 0;
}  

