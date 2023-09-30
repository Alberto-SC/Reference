#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){ 
    lli t,n;
    cin>>t;
    while(t--){
        cin>>n; 
        vector<int> tr;
        int two = -1;
        lli copy = n;
		while (n > 0) {
			tr.push_back(n % 3);
			if (tr.back() == 2) two =int(tr.size()) - 1;
			n /= 3;
		}
		tr.push_back(0);
        if(two == -1)cout<<copy<<endl;
        else {
            int i;
            for(i = two;i<tr.size();i++)
                if(tr[i] == 0)break;
            tr[i] = 1;
            for(int j = i-1;j>=0;j--)tr[j] = 0;

            lli p = 1;
            lli ans = 0;
            for(int i = 0;i<tr.size();i++){
                ans+=tr[i]*p;
                p*=3;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}