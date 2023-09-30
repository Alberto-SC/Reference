#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int l = -1,r = -1;

        n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]== 'a'){
                l = i;
                r = i;
                break;
            }
        }
        if(l==-1){
            cout<<"NO"<<endl;
            continue;
        }
        char last = 'a';
        bool flag = true;
        while(l-1>=0 || r+1<n){
            last++;
            if(l-1>=0 && s[l-1] == last){
                l--;
            }
            else if(r+1<n && s[r+1] ==last){
                r++;
            }
            else {
                flag = false;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
