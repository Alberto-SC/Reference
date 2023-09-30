#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        vector<string> s(n-k);
        for(auto &c:s)cin>>c;
        vector<string> ans(n);
        cout<<"a ";
        int who = 0;
        for(int i = 0;i<n-k;){
            int j = i;
            while(j<n-k && s[i]== s[j]){
                j++;
            }
            // cout<<j-i<<endl;
            if(s[i]== "NO"){
                for(int l = 0;l<(j-i);l++){
                    if(who>25)
                        cout<<"s"<<char((who%26)+'a')<<" ";
                    else
                        cout<<char(who+'a')<<" ";
                }
            }
            else{
                for(int l = 0;l<(k-1)+(j-i-1);l++){
                    who++;
                    if(who>25)
                        cout<<"s"<<char((who%26)+'a')<<" ";
                    else
                        cout<<char(who+'a')<<" ";
                }
            }
            i = j;
        }

    }
    return 0;
}  
