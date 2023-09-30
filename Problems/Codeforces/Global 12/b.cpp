#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define x first 
#define y second
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>> P(n);
        for(auto &c:P)cin>>c.first>>c.second;
        bool flag = false;
        for(int i = 0;i<n;i++){
            int cont = 0;
            for(int j = 0;j<n;j++){
                if(abs(P[i].x-P[j].x)+abs(P[i].y-P[j].y)<=k)cont++;
            }
            if(cont== n)flag = true;
        }
        if(flag)cout<<1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}  

