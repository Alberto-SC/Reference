#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        int q;
        cin>>q;
        int minH = -1,maxH =1e18;
        while(q--){
            int t,a,b;
            cin>>t>>a>>b;

            if(t == 1){
                cin>>n;
                int last = (n-1)*(a-b);
                int nwMinH = last+(b)+1;
                int nwMaxH = last+a;

                if(n == 1){
                    nwMinH = 1;
                    nwMaxH = a;
                }

                /* cout<<"H: "<<minH<<" "<<maxH<<" "<<nwMinH<<" "<<nwMaxH<<endl; */
                int lH = max(minH,nwMinH);
                int rH = min(maxH,nwMaxH);
                /* cout<<lH<<" "<<rH<<endl; */
                if(lH<=rH){
                    cout<<1<<" ";
                    minH = lH;
                    maxH = rH;
                }
                else cout<<0<<" ";
            }
            else{
                if(minH == -1 ){
                    cout<<-1<<" ";
                    continue;
                }

                int n1 = ((minH-a+(a-b-1))/(a-b))+1;
                int n2 = ((maxH-a+(a-b-1))/(a-b))+1;

                if(minH<=a)n1 = 1;
                if(maxH<=a)n2 = 1;
                /* cout<<n1<<" "<<n2<<" "<<minH<<" "<<maxH; */
                if(n1 == n2){
                   cout<<n1<<" ";
                }
                else cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
}


