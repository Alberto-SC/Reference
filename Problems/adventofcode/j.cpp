#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    string s;
    vector<lli> nums;
    lli x;
    while(cin>>x){
        nums.push_back(x);
    }
    vector<bool> b(100000); 
    for(int i= 0;i<nums.size();i++){
        b[nums[i]] = true;
    }
    int cont1 = 0,cont2 =0 ,cont3 = 0;
    sort(nums.begin(),nums.end());
    for(int i = 1;i<nums.size();i++){
        cout<<nums[i]<<" ";
        if(nums[i-1]== nums[i]-1)cont1++;
        if(nums[i-1] ==nums[i]-2)cont2++;
        if(nums[i-1] == nums[i]-3)cont3++;
    }
    cout<<endl;
    cout<<cont1<<" "<<cont2<<" "<<cont3<<endl;
    return 0;
}