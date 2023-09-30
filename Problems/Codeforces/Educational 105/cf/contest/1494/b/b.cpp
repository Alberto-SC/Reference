#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<pair<int,int>> corners = {{0,3},{0,1},{2,3},{2,1}};
signed main(){__
	int t= 1,n,U,R,D,L;
    cin>>t;
    while(t--){
        vector<int> x(4);
        cin>>n>>x[0]>>x[1]>>x[2]>>x[3];
        vector<int> order = {0,1,2,3};
        bool flag = false;
        do{ 
            vector<int> copy = x;
            for(int i = 0;i<4;i++){
                if(copy[corners[order[i]].first] && copy[corners[order[i]].second])
                    copy[corners[order[i]].first]--,copy[corners[order[i]].second]--;
            }
            if(copy[0]<= n-2 && copy[1]<=n-2 && copy[2]<=n-2 && copy[3]<=n-2)
                flag = true;
            
        }while(next_permutation(order.begin(),order.end()));
        if(!flag)
            cout<<"NO"<<endl;
        else 
            cout<<"YES"<<endl;
    }
    return 0;
} 