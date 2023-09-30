#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> diff(n+1,0);
    map<int,int> s;
    int mxi = 0,mxj = 0,mx = 0;
    int i = 0,j = 0;
    int cont = 0;
    while(j<n ){
        s[nums[j]]++;
        while(s.size()>k){
            s[nums[i]]--;
            if(s[nums[i]] == 0){s.erase(nums[i]);i++;break;}
            i++;
        }
        if((j-i)+1> mx){mx= (j-i)+1;mxi = i;mxj = j;}
        cont++;
        j++;
    }
    if(mxj==n)mxj--;
    if(mxi==n)mxi--;
    cout<<mxi+1<<" "<<mxj+1<<endl;
    return 0;
}