#include <bits/stdc++.h>
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        
        int first = -1,last = -1;
        for(int i = 0;i<n;i++){
            if(a[i]!=b[i]){
                if(first ==-1)first = i;
                last = i;    
            }
        }

        for(int i = last+1;i<n;i++){
            if(b[i]>=b[i-1])last++;
            else break;
        }
        for(int i = first-1;i>=0;i--){
            if(b[i]<=b[i+1])first--;
            else break;
        }
        cout<<first+1<<" "<<last+1<<endl;
    }
    return 0;    
}
