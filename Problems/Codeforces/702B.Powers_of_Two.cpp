#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    map<int,int>mp;
    for(int i = 0;i<n;i++){
        mp[nums[i]]++;
    }
    long long int  cont = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<31;j++){
            int aux = 1<<j;
            if(aux-nums[i] == nums[i]){
                cont+=mp[aux-nums[i]]-1;
            }
            else {
                if(mp.count(aux-nums[i]))cont+=mp[aux-nums[i]];  
            }
        }
    }
    cout<<cont/2<<endl;
    return 0;
}