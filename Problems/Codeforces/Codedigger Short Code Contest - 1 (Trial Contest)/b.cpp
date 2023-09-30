#include <bits/stdc++.h>
using namespace std;
int main(){int t,a,b,c;cin>>t;while(t--){cin>>a>>b;c=0;while(a&&b){a<b?swap(a,b):swap(a,a);c+=a/b,a-=b*(a/b);}cout<<c<<'\n';}return 0;}  

