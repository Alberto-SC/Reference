#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int> nums(2007);

vector<int> preffix(2007);


int main(){__
	int t= 1,n,m,s,e;
    for(int i = 1;i<=n;i++){
        cin>>nums[i];
        preffix[i] = preffix[i-1]+nums[i];
    }
    for(int i = 0;i<n;i++){
        cin>>s>>e,u;
        int l=0,r = (e-s)+1;
        if(l+1<r){
            int m = (l+r)>>1;
            if(check(m))
        }

    }
    return 0;
}  

