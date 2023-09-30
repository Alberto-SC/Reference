#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        string ans(n,'?');
        vector<char> last(26,'a');
        ans[0] ='a';
        char limit = char(k+'a');
        int sz =0;
        for(int i = 1;i<n;i++){
            if(last[last[ans[i-1]-'a']-'a']==limit){
                last[ans[i-1]-'a']++;
            }
            if(last[ans[i-1]-'a']==limit)break;
            ans[i] = last[ans[i-1]-'a'];
            sz++;
            last[ans[i-1]-'a']++;
        }
        sz++;
        for(int i = 0;i<n;i++){
            cout<<ans[i%sz];
        }
        cout<<endl;
    }
    return 0;
}  
