#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int im = 0,pr = 0;
        vector<int> nums(n);
        for(auto &c:nums){cin>>c;if(c&1)im++;else pr++;}
        sort(nums.begin(),nums.end());
        if(im % 2 == 0&& pr %2 == 0)cout<<"YES"<<endl;
        else {
            bool flag = false;
            for(int i = 1;i<n;i++){
                if(nums[i] == nums[i-1]+1){flag = true;break;}
            }
            cout << "NO\0YES\0" + 3 * flag << endl;
        }
    }
    return 0;
}