#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(2*n);
        vector<int> im;
        vector<int> par;
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<2*n;i++){
            if(nums[i]&1)im.push_back(i+1);
            else par.push_back(i+1);
        }
        n--;
        for(int i =0;i<im.size();i+=2){
            if(n== 0)break;
            if(i+1<im.size()){
                n--;
                cout<<im[i]<<" "<<im[i+1]<<endl;
            }
        }
        for(int i = 0;i<par.size();i+=2){
            if(n== 0)break;
            cout<<par[i]<<" "<<par[i+1]<<endl;
            n--;
        }
    

    }
    return 0;
}

