#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string nums;
        cin>>nums;
        vector<lli> zeros;
        for(lli i = 0;i<n;i++)
            if(nums[i] == '0')zeros.push_back(i);
        for(lli i = 0;i<zeros.size();i++){
            if(zeros[i] == i)continue;
            if((k-(zeros[i]-i))>=0){
                nums[i] = '0';
                nums[zeros[i]] = '1';
                k-=zeros[i]-i;
            }
            else {
                if(k>0){
                    if((zeros[i]-k)>=0){
                        nums[zeros[i]-k]= '0';
                        nums[zeros[i]] = '1';
                    }
                }
                break;
            }
        }
        cout<<nums<<endl;
    }
}