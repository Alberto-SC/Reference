#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,a,b,k;
    cin>>n>>k;
    vector<pair<lli,lli>> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i].second>>nums[i].first;
    }
    sort(nums.rbegin(),nums.rend());
    lli sum = 0;
    lli ans = 0;
    set<pair<lli,lli>> st;
    for(int i = 0;i<n;i++){
        st.insert({nums[i].second,i});
        sum+=nums[i].second;
        while(st.size()>k){
            sum-=st.begin()->first;
            st.erase(st.begin());
        }
        ans = max(sum*nums[i].first,ans);
    }
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int x = 0;
    for(int i = 0;i<n;i++){
        int x = 0;
        for(int j = 0;j<n;j++){
            x+=M[i][j];
        }
    }
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cout<<M[i][j]<<"\n[j==n-1];
    return 0;
}
