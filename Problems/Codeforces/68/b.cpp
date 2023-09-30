#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        char ai;
        vector<int>r(n,0);
        vector<int>c(m,0);
        char matrix[n][m];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>ai;
                matrix[i][j] = ai;
                if(ai =='*'){r[i]++;c[j]++;}
            }
        }
        int mxr = -1000000000,mxc = -1000000000;
        vector<int> indr;
        vector<int> indc;
        for(int i = 0;i<n;i++)
            if(r[i]>mxr){mxr = r[i];}
        for(int i = 0;i<n;i++)
            if(r[i] == mxr)indr.push_back(i);
        for(int i = 0;i<m;i++)
            if(c[i]>mxc){mxc = c[i];}
        for(int i = 0;i<m;i++)
            if(c[i] == mxc)indc.push_back(i);
    
        int ans = 0;
        if(mxr== 0)cout<<m+(n-1)<<endl;
        else{

        for(int i = 0;i<indr.size();i++){
            for(int j = 0;j<indc.size();j++){
                if(indr[i]==indc[j] && (mxr<m&&mxc<n)&& matrix[indr[i]][indc[j]]=='.' && mxr>0 && mxc>0){ans++;mxr++;mxc++;break;};

            }
        }
        ans += (n-mxr)+(m-mxc);
        cout<<ans<<endl;
        }
    }
}