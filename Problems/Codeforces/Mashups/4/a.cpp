#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,a,b,c;
    while(t--){
        vector<int> z(3);
        cin>>z[0]>>z[1]>>z[2];
        int ans = 0;

        while(z[0]){
            sort(z.begin(),z.end());
            int diff = z[2]-z[1];
            int moves = diff/2;
            moves = min(moves,z[0]);
            ans+=moves;
            if(moves ==0)break;
            z[2]-=moves*2;
            z[0]-=moves;
        }  
            
        z[1]-=z[0];
        z[2]-=z[0];
        while(abs(z[1]-z[2])>1 && z[1]&& z[2]){
            sort(z.begin(),z.end());
            int diff = z[2]-z[1];
            int moves = diff/2;
            moves = min(moves,z[1]);
            ans+=moves;
            z[2]-=moves*2;
            z[1]-=moves;
        } 
        if(z[1]>z[2])swap(z[1],z[2]);
        if(z[1]==0||z[2]==0){cout<<ans+z[0]<<endl;continue;}
        if(z[1]!=z[2] &&z[2]>=2)
            z[2]-=2,z[1]--,ans++;

        int mod = z[1]%3;
        int y = (z[1]/3)*2;
        if(mod ==2)y++;
        cout<<ans+y+z[0]<<endl;
    }
    return 0;
}  
