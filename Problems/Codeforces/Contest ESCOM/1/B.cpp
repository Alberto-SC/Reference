#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c.first<<" "<<c.second<<"\n";
uint64_t all = 1e18l;
int main(){
    int n,t,s,ht = 0,lk= 0;
    uint64_t ans = 0,ai;
    cin>>n;
    unordered_map<uint64_t,int> like;
    unordered_set<uint64_t> unlike;
    set<int> List;
    for(int i = 0;i<n;i++){
        cin>>t>>s;
        if(t == 1)lk++;else ht++;
        for(int i =0;i<s;i++){
            cin>>ai;
            if(t == 1){
                like[ai]++;
            }
            else if (t == 2) {
                like[ai]--;
                unlike.insert(ai);
            }
        }
    }
    // print(like)cout<<endl;
    // cout<<lk<<endl;
    // cout<<ht<<endl;
    if(ht == n)
        cout<<all-unlike.size()<<endl;
    else{
        for(auto c:like){
            int nm = c.second;
            if(nm == lk)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}