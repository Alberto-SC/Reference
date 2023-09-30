#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<int> a(n);
    for(int i = 0;i<n;i++)a[i] = t[i]-'0';
    sort(a.begin(),a.end());
    vector<bool> used(n,false);
    int ans = 0;
    for(int i = 0;i<n;i++){
        int x = s[i]-'0';
        int index = lower_bound(a.begin(),a.end(),x)-a.begin();
        int j;
        // cout<<index<<endl;
        for(j = index;j<n;j++)if(!used[j]){used[j] = true;break;};
        if(j == n){
            ans++;
            for(int j = 0;j<index;j++)
                if(!used[j]){used[j] = true;break;}
        }
    }
    cout<<ans<<endl;
    ans = 0;
    for(int i = 0;i<n;i++)used[i] = false;
    for(int i = 0;i<n;i++){
        int x = s[i]-'0';
        int index = lower_bound(a.begin(),a.end(),x+1)-a.begin();
        int j;
        for(j = index;j<n;j++)if(!used[j]){used[j] = true;ans++;break;};
        if(j == n){
            for(int j = 0;j<index;j++)
                if(!used[j]){used[j] = true;break;}
        }
    }
    cout<<ans<<endl;
    return 0;

}