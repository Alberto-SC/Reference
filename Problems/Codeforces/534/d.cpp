#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    string s;
    while(1){
        cin>>s;
        if(s == "end")break;
        int l = 1,r = 1e9;
        char ans;
        while(l+1<r){
            int m = (l+r)>>1;
            cout<<"?"<<m<<" "<<m-1<<endl;
            fflush(stdout);
            cin>>ans;
            if(ans =='x')l = m;
            else r = m;
        }
        int x = r-1;
        if(x ==1e9)cout<<"!"<<x<<endl;
        fflush(stdout);
        vector<int> divs;
        for(int i = 1;i*i<=x;i++){
            if(x%i == 0){
                divs.push_back(x/i;)
            }
        }
        sort(divs.begin(),divs.end());
        l = 0,r = divs.size()-1;
        while(l+1<r){
            int m = (l+r)>>1;
            cout<<"? "<<divs[0]<<" "<<divs[m];
            fflush(stdout);
            cin>>ans;
            if(ans == 'x')l = m;
            else r = m;
        }
        cout<<"!"<<l<<endl;
    }
    return 0;
}  

