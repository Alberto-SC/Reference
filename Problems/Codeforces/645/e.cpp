#include <bits/stdc++.h>
using namespace std;
vector<int> nums;

int n,x;
bool check(int k){
    int sum = 0;
    cout<<"K "<<k<<endl;
    for(int i = 0;i<k;i++)
        sum+=nums[i];
    if(sum<=0)return      9806false;
    for(int i = 0;i<(n-k);i++){
        sum-=nums[i];
        sum+=nums[i+k];
        cout<<sum<<endl;
        if(sum<=0)return false;
    }
    if(sum<=0)return false;
    cout<<k<<endl;
    return true;
}   
int main(){
    cin>>n;
    nums.resize(n);
    for(int i = 0;i<n-(n/2);i++)
        cin>>nums[i];
    cin>>x;
    for(int i = n-(n/2);i<n;i++)nums[i]= x;
    // for(auto c:nums)cout<<c<<" ";
    // cout<<endl; 
    int l = 0,r = n;
    bool flag = false;
    int m;
    while(l<r){
        m = (l+r+1)>>1;
        if(check(m)){flag = true;r = m;}
        else l = m; 
    }
    flag == true?cout<<m<<endl:cout<<-1<<endl;
    return 0;
}