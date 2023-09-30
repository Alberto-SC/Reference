#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int n = s.size();
        vector<vector<int>> p(2,vector<int>(n,0));
        for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
            for(int i=0;i<n;i++)
            {
                if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
                int L=i-p[z][i], R=i+p[z][i]-!z;
                while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
                if(R>r) l=L,r=R;
            }
        int ans = -1;
        for(int i = 0;i<n;i++){
            ans = max(p[0][i]*2,ans);
            ans = max((p[1][i]*2)+1,ans);
        }
        int cont = 0;
        for(int i = 0;i<n;i++){
            if(p[0][i]*2 == ans)cont++;
            if((p[1][i]*2)+1 == ans)cont++;
        }
        cout<<ans<<" "<<cont<<endl;
    }
    return 0;
}