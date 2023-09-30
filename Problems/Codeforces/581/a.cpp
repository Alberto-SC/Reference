#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    string s;
    cin>>s;
    n = s.size();
    int idx;
    for(int i = 0;i<n;i++){
        if(s[i]=='1'){
            idx = i;
            break;
        }
    }
    bool flag = false;
    for(int i = idx+1;i<n;i++){
        if(s[i]== '1')flag = true;
    }
    int ans= ((n-idx)+1)/2;
    
    if(!flag && (n-idx)&1)
        ans--;
    cout<<ans<<endl;
    return 0;
}  

