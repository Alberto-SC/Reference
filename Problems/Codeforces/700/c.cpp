#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>n;
    cout.flush();
    int l = 0,r = n-1;
    int x,y;
    while(l<r){
        int mid = (l+r)>>1;
        cout<<"? "<<mid+1<<endl;
        cout.flush();
        cin>>x;
        cout<<"? "<<mid+2<<endl;
        cout.flush();
        cin>>y;
        if(x<y) 
            r = mid;
        else 
            l = mid+1;
    }
    cout<<"! "<<l+1<<endl;
    return 0;
}  

