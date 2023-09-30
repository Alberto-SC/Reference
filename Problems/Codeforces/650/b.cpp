#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int cont = 0,p= 0,im = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]%2 == 0)p++;
            else im++;
            if(i%2 != nums[i]%2)cont++;
        }
        if(cont&1)cout<<-1<<endl;
        else if(n&1 && im == n/2 && p == n-(n/2)){
            cout<<cont/2<<endl;
        }  
        else if(n%2 == 0 && im == n/2 && p == n/2)cout<<cont/2<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}