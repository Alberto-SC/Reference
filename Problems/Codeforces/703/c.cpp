#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,rigth,left;
    cin>>n;
    int sm;
    cout<<"? "<<1<<" "<<n<<endl;
    cout.flush();
    cin>>sm;
    if(sm == 1){
        int l = sm,r = n;
        while(l+1<r){
            int m = (l+r)>>1;
            cout<<"? "<<sm<<" "<<m<<endl;
            cout.flush();
            cin>>x;
            if(x == sm)
                r = m;
            else 
                l = m;
        }
        cout<<"! "<<r<<endl;
        cout.flush();
        return 0;
    }
    if(sm == n){
        int l = 1,r = sm;
        while(l+1<r){
            int m = (l+r)>>1;
            cout<<"? "<<m<<" "<<sm<<endl;
            cout.flush();
            cin>>x;
            if(x == sm)
                l = m;
            else 
                r = m;
        }
        cout<<"! "<<l<<endl;
        cout.flush();
        return 0;
    }
    cout<<"? "<<sm<<" "<<n<<endl;
    cout.flush();
    cin>>rigth;
    cout<<"? "<<1<<" "<<sm<<endl;
    cout.flush();
    cin>>left;
    if(left == sm){
        // cout<<"LEFT"<<endl;
        int l = 1,r = sm;
        while(l+1<r){
            int m = (l+r)>>1; 
            cout<<"? "<<m<<" "<<sm<<endl;
            cout.flush();
            cin>>x;
            if(x == sm)
                l = m;
            else 
                r = m;
        }
        cout<<"! "<<l<<endl;
    }
    else{
        // cout<<"RIGTH"<<endl;
        int l = sm,r = n;
        while(l+1<r){
            int m = (l+r)>>1;
            cout<<"? "<<sm<<" "<<m<<endl;
            cout.flush();
            cin>>x;
            if(x == sm)
                r = m;
            else 
                l = m;
        }
        cout<<"! "<<r<<endl;
    }
    
    return 0;
}  
