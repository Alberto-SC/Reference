#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 10000007;
int sumdiv[maxn];
int main(){__
	int t= 1,n;
    for (int i = 1; i < maxn; ++i)
        for (int j = i; j < maxn; j += i)
            sumdiv[j] += i;
    vector<int> ans(10000001,-1);
    for(int i = 1;i<=10000000;i++){
        if(sumdiv[i]>10000000)continue;
        if(ans[sumdiv[i]]==-1)
            ans[sumdiv[i]]= i;
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}  
