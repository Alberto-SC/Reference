#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n,k,l,r,x;
    cin>>t;
    while(t--){
        cin>>k>>n>>l>>r;
        vector<multiset<int>> arrays(k);
        vector<int> ss;
        multiset<pair<int,int>> sums;
        for(int i = 0;i<k;i++){
            int sum = 0;
            for(int j = 0;j<n;j++){
                cin>>x;
                arrays[i].insert(x);
                sum+=x;
            }
            ss.push_back(sum);
            sums.insert({sum,i});
        }
        sort(ss.begin(),ss.end());
        int target;
        if(k%2==0){
            target = (ss[k/2]+ss[(k/2)-1])/2;
        }
        else 
            target = ss[k/2];
        int ans = 0;
        int cont = 0;
        while(1){
            int mx = (*(sums.rbegin()--)).first;
            int mn = (*(sums.begin())).first;
            // cout<<mn<<" "<<mx<<" "<<target<<endl;
            if(mn==mx && mn == target)break;
            multiset<pair<int,int>> ns; 
            for(auto d:sums){
                if(d.first<=target){
                    int mna = *arrays[d.second].begin();
                    arrays[d.second].erase(arrays[d.second].begin());
                    int change = min(mna+(target-d.first),r);
                    int diff = change-mna; 
                    // cout<<d.first<<" "<<d.second<<" "<<mxdiff<<" "<<change<<" "<<mna<<endl;
                    ns.insert({d.first+diff,d.second});
                    arrays[d.second].insert(change);
                }
                else{
                    int mxa = *(arrays[d.second].rbegin()--);
                    arrays[d.second].erase(arrays[d.second].find(mxa));
                    int change = max(mxa-(d.first-target),l);
                    int diff = change-mxa;
                    // cout<<d.first<<" "<<d.second<<" "<<mxdiff<<" "<<change<<" "<<mna<<endl;
                    ns.insert({d.first+diff,d.second});
                    arrays[d.second].insert(change);
                }
            }
            ans++;
            sums = ns;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
