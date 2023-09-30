#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int mn = n+1,x = 0,y = 0;
        for(int i = 1;i*i<=k;i++){
            if(k%i == 0){
                if(i+ (k/i)+2 <mn){
                    x = i;
                    y = k/i;
                    mn = i+(k/i)+2;
                }
            }
        }
        // cout<<x<<" "<<y<<endl;
        if(x == 0)
            x = 1,y = k;
        // cout<<x<<" "<<y<<endl;
        if(x == 1){
            // cout<<"HI"<<endl;
            mn = y+2;
            int e = y +(n-mn)-1+2;
            cout<<e<<endl;
            if(mn >=n+1){cout<<-1<<endl;continue;}
            for(int i = 1;i<=y;i++)
                cout<<i<<" "<<n-1<<endl;    
            if(n-mn == 0){
                cout<<n<<" "<<n-1<<endl;
            }
            else{
                for(int i = x+y;i<=n-2;i++){
                    cout<<i<<" "<<i+1<<endl;
                }
                cout<<n<<" "<<y+1<<endl;
            }
            continue;
        }

        if(mn >=n+1){cout<<-1<<endl;continue;}
        int e = x+y +(n-mn)-1+2;
        cout<<e<<endl;
        for(int i = 1;i<=x;i++)
            cout<<i<<" "<<n<<endl;
        for(int i = x+1;i<=y+x;i++)
            cout<<i<<" "<<n-1<<endl;
        if(n-mn == 0){
            cout<<n<<" "<<n-1<<endl;
        }
        else{
            for(int i = x+y+1;i<=n-2;i++){
                cout<<i<<" "<<i+1<<endl;
            }
            cout<<n<<" "<<x+y+1<<endl;
        }
    }
    return 0;
}  

