#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> nums(n);
    vector<int> b(32);
    int f = 0;
    for(auto &c:nums){
        cin>>c,f|=c;
        for(int i= 0;i<32;i++){
            if(c>>i&1)b[i]++;
        }
    }
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        int z = nums[i]*x;
        int plus = 0;
        int less = 0;
        for(int j = 0;j<32;j++)
            if(z>>j&1 && b[j] == 0)plus++;
        for(int j = 0;j<32;j++)
            if(!z>>j&1 && nums[j]>>j&1 && b[j]== 1)less++;
        
        v.push_back({{plus,less},nums[i]});
    }
    sort(v.begin(),v.end(),comp);
    for(int i = 0;i<k;i++){
        int z = f;
        for(int j = 0;j<32;j++){
            
        }
    }   
    return 0;
}