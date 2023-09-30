#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
int n,k;
vector<int> nums;
bool check(int x,int w){
    int c = 0;
    for(int i = 0;i<n;i++){
        if(w){
            c++;
            w^=1;
        }
        else {
            if(nums[i]<=x){
                c++;
                w^=1;
            }
            
        }
    }
    return c>=k;

}
int main(){__
    cin>>n>>k;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    int l = 0,r = 1e9;
    while(l<r){
        int mid = (l+r)>>1;
        if(check(mid,0) || check(mid,1))
            r = mid;
        else l = mid+1;
    }
    cout<<l<<endl;
    return 0;
}

