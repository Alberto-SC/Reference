#include <bits/stdc++.h>
using namespace std;
#define print(A)for(atuo c:A)cout<<c<<" ";cout<<endl;
int main(){
    long long int  t,x,y,n,r;
    cin>>t;
    while(t--){
        cin>>n>>r;
        vector<int> nums(n);
        for(auto &c: nums)cin>>c;
        sort(nums.begin(),nums.end());
        int ind = n-1;
        int max = -1000,k;
        for(int i = 0;i<n;i++){
            if(n/r>max){max = n/r;k=i;}
        }
        if(max>n-(k+1))cout<<n-(k+1)<<endl;
        else cout<<max<<endl; 
    }
    return 0;
}