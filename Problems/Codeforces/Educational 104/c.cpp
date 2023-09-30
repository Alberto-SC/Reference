#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        int total = (n*(n-1))/2;
        int i;
        for(i = total;i>=1;i--){
            if(((i*3) +((total-i)*2))%n == 0){
                break;
            }
        }
        int points = ((i*3)+ ((total-i)*2))/n;
        vector<int> p(n,points);
        if(n&1){
            for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    if(p[i]>=3){
                        p[i]-=3;
                        cout<<1<<" ";
                    }
                    else if(p[j]>=3){
                        p[j]-=3;
                        cout<<-1<<" ";
                    }
                }
            }
            for(int i = 0;i<n;i++)
                assert(p[i]==0);
        }
        else{
            vector<vector<int>> ans(n,vector<int> (n,-9));
            for(int i = 0;i<n/2;i++){
                ans[i][i+(n/2)] = 0;
                ans[i+(n/2)][i] = 0;
            }
            for(int i=1;i<= (points-1)/3;i++){
                for(int j = 0;j<n;j++){
                    ans[j][(j+i)%n] = 1;
                    ans[(j+i)%n][j] = -1;
                }
            }
            
            for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    cout<<ans[i][j]<<" ";
                }
            }
        }   
        cout<<endl;
    }
    return 0;
}  
