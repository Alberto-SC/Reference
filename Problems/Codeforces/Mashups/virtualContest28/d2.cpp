#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int n;
    cin>>n;
    vector<long long> nums(n);
    for(auto &c:nums)cin>>c;
    set<pair<long long,int>> st;
    for(int i = 0;i<n;i++){
        st.insert({nums[i],i});
    }
    vector<int> used(n,true);
    while((int)st.size()>0){
        auto x = *st.begin();
        st.erase(st.begin());
        if((int)st.size()==0)break;
        auto y = *st.begin();
        if(x.first!= y.first)continue;
        else{
            st.erase(st.begin());
            used[x.second] = false;
            st.insert({2*(x.first),y.second});
            nums[y.second]*=2;
        }
        if((int)st.size()==0)break;
    }
    int cont = 0;
    for(int i = 0;i<n;i++)
        if(used[i])cont++;
    cout<<cont<<endl;
    for(int i = 0;i<n;i++)
        if(used[i])cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}  
