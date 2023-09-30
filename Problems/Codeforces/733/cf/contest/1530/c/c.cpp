#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        list<int> ls;
        int k = n-(n/4);
        int sa = 0,sb = 0;
        for(int i = 0;i<k;i++){
            sa+=a[i];
            sb+=b[i];
            ls.push_back(a[i]);
        }
        int ans = 0;
        int lastb = k;
        int N  = n;
        while(sa<sb){
            n++;
            if(n%4==0){
                sa-=ls.back();
                ls.pop_back();
                sa+=100;
                ls.push_front(100);
            }
            else {
                if(lastb<N)
                    sb+=b[lastb++];
                sa+=100;
                ls.push_front(100);
            }
            ans++;
        }   
        cout<<ans<<endl;
    }
    return 0;
}  
