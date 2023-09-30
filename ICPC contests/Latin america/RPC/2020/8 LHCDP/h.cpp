#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int lli;

using namespace std;

int main(){
	fast_io
    int t;
    cin>>t;
    while(t--){
	    lli n;
        cin>>n;
        n--;
        lli x;
        lli s = (lli)sqrt(n);
        if(s&1){
            x = -s;
            x+= n-(s*s);
        }else {
            x = s;
            x-= n-(s*s);
        }

        lli y = 0;
        y-=(s/2);
        if(s&1){
            lli diff = n-(s*s);
			lli size = (s+1)*(s+1) - s*s;
			if(diff <= size/2){
				y += diff;
			}else{
				y += size/2;
				y -= (diff-size/2);
			}
        }
        cout<<x<<" "<<y<<endl;
    }
	return 0;
}