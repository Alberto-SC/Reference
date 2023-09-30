#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

map<int,int> fact;

void factorize(int n){
    while(n%2==0){
        fact[2]++;
        n/=2;
    }

    for(int i = 3;i*i<=n;i+=2){
        while(n%i ==0){
            fact[i]++;
            n/=i;
        }
    }
    if(n>1)
        fact[n]++;
}

signed main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        iota(nums.begin(),nums.end(),1);
        map<int,int> F;
        for(int i = 0;i<n;i++){
            fact.clear();
            factorize(nums[i]);
            for(auto c:fact){
                F[c.first] = max(F[c.first],c.second);
            }
        }
        int ans = 1;
        for(auto c:F){
            ans*=pow(c.first,c.second);
        }
        cout<<ans<<endl;
    }
    return 0;
}
