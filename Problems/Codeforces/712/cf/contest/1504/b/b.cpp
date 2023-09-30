

#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int test= 1,n;
    cin>>test;
    while(test--){
        cin>>n;
        string s,x;
        cin>>s>>x;
        int z = 0,o = 0;
        vector<int> flips;
        for(int i = 0;i<n;i++){
            if(s[i]=='0')z++;
            else o++;
            if(o==z)flips.push_back(i);
        }
        int r = flips.size()-1;
        bool flag= true;
        int change =0;
        for(int i = n-1;i>=0;i--){
            if(s[i]!= x[i] &&!change){
                while(r>=0 && flips[r]!= i){r--;}
                if(r<0){
                    flag = false;
                    break;
                }
                change^=1;
            }
            if(s[i]== x[i] && change){
                while(r>=0 && flips[r]!= i){r--;}
                if(r<0){
                    flag = false;
                    break;
                }
                change^=1;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
