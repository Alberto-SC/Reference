#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        vector<int> ans(n);
        int last = 0;
        for(int i = 0;i<n;i++)
            if(s[i]== 'a')last = i;
        for(int i = 0;i<n;){
            int j = i+1;
            while(j<n && s[j] == s[j-1]){j++;}
            ans[j-1] = 1;
            i = j;
        }
        for(int i = n-1;i>=0;i--){
            if(ans[i]== 1 &&s[i]== 'a')break;
            if(ans[i]== 1 &&s[i]== 'b'){ans[i] = 0;break;}
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

