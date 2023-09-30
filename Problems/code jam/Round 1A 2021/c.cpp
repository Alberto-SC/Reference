#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,q;
    int caso = 1;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<string> answers(n);
        vector<int> s(n);
        for(int i = 0;i<n;i++)
            cin>>answers[i]>>s[i];
        vector<pair<int,int>> o(q);
        for(int mask = 0;mask<(1<<q);mask++){
            bool flag = true;
            for(int i = 0;i<n;i++){
                int cont = 0;
                for(int j = 0;j<q;j++){
                    if((mask>>j)&1 && answers[i][j]=='T')cont++;
                    else if(!((mask>>j)&1) && answers[i][j]== 'F')cont++;
                }
                if(cont !=s[i])flag = false;
            }
            if(flag){
                for(int j = 0;j<q;j++){
                    if((mask>>j)&1){
                        o[j].first++;
                    }
                    else 
                        o[j].second++;
                }
            }
        }   
        int z = 0,w;
        string ans(q,'F');
        for(int i = 0;i<q;i++){
            if(o[i].first>=o[i].second)ans[i] = 'T';
            z+=max(o[i].first,o[i].second);
            w= o[i].first+o[i].second;
        }
        int gcd = __gcd(z,w);
        z/=gcd;
        w/=gcd;
        cout<<"Case #"<<caso<<": "<<ans<<" "<<z<<"/"<<w<<endl;
        caso++;

    }
    return 0;
}  
