#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli ac[2000007];
int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
	for (int i=A;i<=B;i++){
		ac[i+B]++;
		ac[i+C+1]--;
	}
	for (int i=1;i<=1000007;i++)
		ac[i]+=ac[i-1];
	for (int i=1;i<=1000007;i++)
		ac[i]+=ac[i-1];
	lli ans = 0;
	for (int i = C; i <= D; i++)
		ans += ac[1000007]-ac[i];
    cout<<ans<<endl;
 	return 0;
}
