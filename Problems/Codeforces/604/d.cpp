#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    vector<int> nums(4);
    for(auto &c:nums)cin>>c;
    int total = accumulate(nums.begin(),nums.end(),0);
    for(int i = 0;i<4;i++){
        vector<int> res;
        auto a = nums;
        a[i]--;
        res.push_back(i);
        int last = i;
        for(int i = 0;i<total-1;i++){
            if(i-1>=0 && a[last-1]){
                a[last-1]--;
                res.push_back(last-1);
                last--;
            }
            else if(i+1<4 &&a[last+1]){
                a[last+1]--;
                res.push_back(last+1);
                last++; 
            }
            else
                break;
            
        }
        if(res.size()== total){
            cout<<"YES"<<endl;
            for(auto c:res)cout<<c<<" ";
            cout<<endl;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}  

