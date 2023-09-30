#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<bool> used(n,false);
        for(int i = 0;i<n;i++){
            int nr = (i+(((nums[i]%n)+n)%n))%n;
            used[nr] = true;
        }
        bool flag = true;
        for(int i = 0;i<n;i++)
            if(!used[i])flag = false;
        cout<<"NO\0YES\0"+3*flag<<endl;
    }
    return 0;
}  

