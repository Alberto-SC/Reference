#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
	int t,h,n,p;
    string name;
    while(cin>>n){
        priority_queue<pair<int,pair<int,string>>> ps;
        for(int i = 0;i<n;i++){
            cin>>t>>h;
            if(t == 1){
                cin>>p>>name;
                ps.push({-p,{-h,name}});
            }
            else{
                auto x = ps.top();
                ps.pop();
                cout<<-x.second.first<<" "<<h<<" "<<h+x.second.first<<" "<<x.second.second<<endl;
            }
        }
    }
    return 0;
}  

