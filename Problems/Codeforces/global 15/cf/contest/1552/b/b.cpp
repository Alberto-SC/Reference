#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums[n];
        for(int i = 0;i<n;i++){
            nums[i].resize(5);
            for(int j = 0;j<5;j++){
                cin>>nums[i][j];
            }
        }
        set<int> good;
        map<int,int> best;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<5;j++){
                if(nums[0][j]<nums[i][j])best[i]++;
            }
        }
        for(int i = 1;i<n;i++){
            if(best[i]<3)good.insert(i);
        }
        if(good.size()==0){
            cout<<1<<endl;
            continue;
        }
        while(good.size()>1){
            int x = *good.begin();
            set<int> ng;
            best.clear();
            for(auto c:good){
                if(x==c)continue;
                for(int j = 0;j<5;j++){
                    if(nums[x][j]<nums[c][j])best[c]++;
                }
            }
            for(auto c:good){
                if(x==c)continue;
                if(best[c]<3)ng.insert(c);
            
            }
            if(ng.size()==0){
                ng.insert(x);
                good = ng;
                break;
            }
            good = ng;
        }
        int x = *good.begin(),cont = 0;
        best.clear();
        for(int i = 0;i<n;i++){
            if(i == x)continue;
            for(int j = 0;j<5;j++){
                if(nums[x][j]<nums[i][j])best[i]++;
            }
        }
        for(int i = 0;i<n;i++){
            if(i==x)continue;
            if(best[i]>=3)cont++;
        }
        if(cont==n-1)cout<<x+1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}  
