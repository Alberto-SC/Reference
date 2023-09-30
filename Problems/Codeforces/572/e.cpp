#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p,k,mod;
    cin>>n>>p>>k;
    vector<int> nums(n);
    mod = k%p;
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(),nums.end());
    int cont = 0;
    for(int i = 0;i<n;i++){
        int s = mod-nums[i];
        long long pos = 0;
        for(int j = 0;pos<=nums[n-1];j++){
            pos = (p*j)+s;
            auto posi = lower_bound(nums.begin(),nums.end(),pos);
            cout<<posi-nums.begin()<<endl;
            cout<<nums[i]<<"posible    "<<pos<<endl;
            if(posi != nums.end()&&nums[posi-nums.begin()] ==pos &&posi-nums.begin() !=i){cont++;cout<<"cont"<<endl; }

        }
    }
    cout<<cont/2<<endl;
}