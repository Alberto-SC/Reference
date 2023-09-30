#include <bits/stdc++.h>
using namespace std;
int main(){int t,n,x;cin>>t;while(t--){cin>>n;int f=0,g=0;for(int i =1;i<=n;i++)cin>>x,x==i?g++:f++;cout<<(f&&g?2:(g==0?1:0))<<'\n';}return 0;}  

  