#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<vector<int>> M(n,vector<int> (n));
        int mx1  = -1,mx2 = -1;
        pair<int,int> ans1,ans2;
        vector<int> d1(2*n);
        vector<int> d2(2*n);
        for(int i= 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>M[i][j];
                d1[j+i] += M[i][j];
                d2[(n-(j+1))+i]+=M[i][j];
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int i1 = i+j,i2 = (n-(j+1))+i;
                if((i+j)&1){
                    if(d1[i1]+d2[i2]-M[i][j]>mx1){
                        mx1 = d1[i1]+d2[i2]-M[i][j];
                        ans1 = {i+1,j+1};
                    }
                }
                else{
                    if(d1[i1]+d2[i2]-M[i][j]>mx2){
                        mx2 = d1[i1]+d2[i2]-M[i][j];
                        ans2 = {i+1,j+1};
                    }
                }
            }
        }
        cout<<mx1+mx2<<endl;
        cout<<ans1.x<<" "<<ans1.y<<" "<<ans2.x<<" "<<ans2.y<<endl;

    }
    return 0;
}  

