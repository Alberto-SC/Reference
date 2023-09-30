#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli gauss(lli n){
    return (n*(n+1))/2;
}
int main(){__
	lli t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<vector<lli>> s(m);
        vector<vector<lli>> positions(m);
        for(lli i = 0;i<m;i++){
            s[i].resize(n);
            positions[i].resize(n+1);
            for(lli j = 0;j<n;j++){
                cin>>s[i][j];
                positions[i][s[i][j]] = j;
            }

        }
        lli l = 0,r = 0;
        lli ans = 0;
        vector<lli> last(m,-1);
        while(l<n && r<n){
            bool flag = true;
            last.assign(m,-1);
            while(r<n && flag){
                lli current_num = s[0][r];
                for(lli i = 0;i<m;i++){
                    if(last[i]== -1){
                        last[i] = positions[i][current_num];
                    }
                    else if(positions[i][current_num]!= last[i]+1){
                        flag = false;
                        break;
                    }
                    else if(positions[i][current_num] == last[i]+1){
                        last[i] = positions[i][current_num];
                    }
                }
                if(!flag)break;
                r++;
            }
            ans+=gauss((r-l)); 
            l= r;
        }
        cout<<ans<<endl;
    }
    return 0;
}  

