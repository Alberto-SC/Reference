#include <bits/stdc++.h>
using namespace std;
#define MN 300000
#define MX 15000000
int a[MN+5],u[MX+5],p[MX+5],pn,s[MX+5];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	int n,i,j,g = 0,x,ans=0;
	for(i=2;i<=MX;++i){
		if(!u[i])
            u[i]=p[++pn]=i;
		for(j=1;i*p[j]<=MX;++j){
            u[i*p[j]]=p[j];
            if(i%p[j]==0)
            break;
        }
	}
    for(int i = 0;i<20;i++)
        cout<<u[i]<<" ";
    cout<<endl;
    cin>>n;
	for(i=0;i<n;++i)cin>>a[i],g=gcd(g,a[i]);
	for(i=0;i<n;++i)
        for(j=a[i]/g;j>1;)
            for(++s[x=u[j]];u[j]==x;)
                j/=u[j];
	for(i=1;i<=MX;++i)ans=max(ans,s[i]);
    ans?cout<<n-ans<<endl:cout<<-1<<endl;
}