#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(int i = 0;i<n;i++){
            char x;
            cin>>x;
            nums[i] = x-'0';
        }
        vector<int> copy(nums);
        for(int i = 0;i<k;i++){
            int mn = 1e16,mx = -1;
            int j = i;
            while(j<n){
                copy[j] = nums[i];
                j+=k;
            }
        }
        for(int i = 0;i<n;i++){
            if(copy[i]>nums[i])break;
            else if(copy[i]<nums[i]){
                int j = k-1;
                while(copy[j]==9){ 
                    int l = j;
                    while(l<n){
                        copy[l] = 0;
                        l+=k;
                    }
                    j--;
                }
            
                int aux = copy[j];
                while(j<n){
                    copy[j] = aux+1;
                    j+=k;
                }
                break;
            }
        }
    
        cout<<n<<endl;
        for(auto c:copy)cout<<c;
        cout<<endl;
    }
    return 0;
}  
