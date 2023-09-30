#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> a(n+1);
        for(int i = 1;i<=n;i++)
            cin>>a[i];
        vector<int> ans;
        vector<int> x(n+1);
        for(int i = 1;i<=n;i++){
            bool flag = true;
            for(int j = 1;j<=n;j++){
                if(j-1<i){
                    x[j-1] = a[j]-a[j-1];
                }
                else if(a[j]!= x[(j-1)%i]+ a[j-1])
                    flag = false;
                
            }
            if(flag)ans.push_back(i);
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

