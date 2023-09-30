#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int msb(int a){
    int cont = 0;
    while(a){
        a>>=1;
        cont++;
    }
    return cont;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        int mx = -1;
        cin>>n;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i =1;i<n;i++){
            lli dif = nums[i-1]-nums[i];
            if(dif<0)continue;
            nums[i]+=dif;
            int k =0;
            while(dif>>=1)k++;
            mx = max(mx,k); 
        }
        if(mx == -1)cout<<0<<endl;
        else cout<<mx+1<<endl;
    }
    return 0;
    
}