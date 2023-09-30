#include <bits/stdc++.h>
using namespace std;
vector<int> divisors;
void get_divisors(int n){
    for(int i = 1;i*i<=n;i++){
        if(n%i == 0)divisors.push_back(i);
        if(n/i != i)divisors.push_back(n/i);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    get_divisors(n);
    for(auto c:divisors){
        if(c == 2|| c == 1)continue;
        for(int i = 0;i<n/c;i++){
            bool flag = true;
            for(int j = 0;j<n;j+=n/c){
                if(nums[i+j] == 0)flag = false;
            }
            if(flag)return cout<<"YES"<<endl,0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}