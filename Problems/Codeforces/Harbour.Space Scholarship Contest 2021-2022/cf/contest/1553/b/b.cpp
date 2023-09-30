#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        n = s.size();
        bool flag = false;
        for(int i = 0;i<n;i++){
            int j = i,idx = 0;
            while(idx<t.size() && j<n && s[j] ==t[idx]){
                j++;
                idx++;
            }
            if(idx==t.size()){
                flag = true;
                break;
            }
            j-=2;
            while(idx<t.size() && j>=0 && s[j]== t[idx]){
                idx++;
                j--;
            }
            if(idx== t.size()){
                flag = true;
                break;
            }
        }   
         cout << "NO\0YES\0" + 3 * flag << endl;
    }
    return 0;
}  
