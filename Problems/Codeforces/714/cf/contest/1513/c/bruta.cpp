#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    t = 220;
    vector<int> x= {0};
    vector<int> ans(251);
    for(int turn = 1;turn<=t;turn++){
        vector<int> nw;
        for(int i = 0;i<x.size();i++){
            int y = x[i]+1;
            if(y==10){
                nw.push_back(1);
                nw.push_back(0);
            }
            else 
                nw.push_back(y);
        }
        x = nw;
        // for(auto c:x)cout<<c<<" ";
        ans[turn] = x.size();
    }
    for(int i = 1;i<=220;i++){
        if(i%10==0){
            int p2 = (1ll<<((i/10)));
            cout<<"I: "<<i<<"-> "<<ans[i]-p2<<endl;
        }
    }
    
    return 0;
}  
