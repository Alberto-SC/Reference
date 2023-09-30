#include <bits/stdc++.h>
using namespace std;
vector<int> div;
int n;
vector<int> getdivisors(int x){
    vector<int>divs;
    for(int i = 1;i*i<=x;i++){
        if(x%i==0 && i<=n)divs.push_back(i),div[i]++;
        if(x%i ==0 && i*i!= x && x/i <=n)divs.push_back(x/i),div[x/i]++;
    }
    sort(divs.begin(),divs.end());
    return divs;
}
int main(){
    cin>>n;
    div.resize(n+1);
    vector<int> nums(n);
    vector<vector<int>> divisors(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        divisors[i] = getdivisors(nums[i]);
    }
    vector<int> real(n+1);
    vector<int> acc(n+1);
    acc[i] = div[1];
    for(int i = 1;i<n;i++){
        if(div[i] != 0)
            acc[i] = div[i]*acc[i-1];
        else acc[i] = acc[i-1];
    }
    for(int i = 0;i<n;i++){
        int x= 1,z = 1;
        for(int j = 0;j<divisors[i].size();j++){
            x=(x*div[divisors[i]])%mod;
            z=(z*divisors[divisors[i]]-1)%mod;
        }
        real[i] = ((acc[n]/x)*z)%mod;
    } 
    int ans = 0;
    for(int i = 0;i<n;i++){
        
    }
    for(int i = 0;u)
    return 0;
}