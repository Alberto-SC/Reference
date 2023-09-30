#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t1,t2;
    cin>>t1>>t2;
    pair<int,int> ans; 
    int mn =3000;
    for(int i = 0;i<=1000;i++){
        for(int j = 0;j<=1000;j++){
            if(i+j== 0)continue;
            if(((t1*i)+(t2*j))%(i+j)== 0 && ((t1*i)+(t2*j))/(i+j) == 80){
                if(i+j<mn){
                    mn = i+j;
                    ans = {i,j};
                }
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}  

