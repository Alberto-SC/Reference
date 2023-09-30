#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        vector<int> copy(n);
        for(auto &c:nums)cin>>c;
        copy = nums;
        sort(copy.begin(),copy.end());
        if(k==1){
            if(copy[0]!= copy.back())cout<<-1<<endl;
            else cout<<1<<endl;
        }
        else {
            int diff= 1,last = copy[0];
            for(int i = 1;i<n;i++){
                if(copy[i]!= last){
                    last = copy[i];
                    diff++;
                }
            }
            if(k>=diff)cout<<1<<endl;
            else{  
                diff-=k;
                if(diff%(k-1)==0)
                    cout<<diff/(k-1)+1<<endl;
                else cout<<(diff/(k-1))+2<<endl;
            }
        }

    }
    return 0;
}

