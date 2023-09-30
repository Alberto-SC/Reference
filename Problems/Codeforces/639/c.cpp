#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<bool> used(n,false);
        for(int i = 0;i<n;i++){
            int x = (i+MOD(nums[i],n))%n;
            used[x] = true;
        } 
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(used[i] ==false){flag = false;break;}
        }
    	cout << "NO\0YES\0" + 3 * flag << endl;
    }
}