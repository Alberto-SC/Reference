#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int imp = 0;
        vector<int> nums(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            if(nums[i]&1)imp++;
        }
        if(imp&1)cout<<"YES"<<endl;
        else if(imp == 0)cout<<"NO"<<endl;
        else {
            if(imp!=n)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}