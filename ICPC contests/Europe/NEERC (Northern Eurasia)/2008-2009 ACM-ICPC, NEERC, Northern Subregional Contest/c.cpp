#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int a[107][107];
int main(){__
    freopen("class.in","r",stdin);
    freopen("class.out","w",stdout);
    int n,r,c;
    cin>>n>>r>>c;
    int mn=(n+1)/2;
    for(int i=1;i<=mn&&i<=r;i++)
        a[i][1]='#',n--;
    for(int i=2;i<=mn&&i<=c;i++)
        a[1][i]='#',n--;
    cout<<min(min(r,c),mn)<<endl;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]=='#')
                cout<<'#';
            else{
                if(n)cout<<'#',n--;
                else
                    cout<<'.';
            }
        }
        cout<<endl;
    }
 
    
    return 0;
}

  