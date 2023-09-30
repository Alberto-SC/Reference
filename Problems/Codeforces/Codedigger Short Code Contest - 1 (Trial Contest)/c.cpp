#include <bits/stdc++.h>
using namespace std;
int main(){long long n,s=0,m,i=0; cin>>n;vector<int> v(n),a;multiset<int>k;for(int &c:v)cin>>c,s+=c,k.insert(c);for(int c:v){i++;k.erase(k.find(c));m = *k.rbegin();s-=m+c;if(s==m)a.push_back(i);k.insert(c),s+=c+m;}cout<<a.size()<<endl;for(int c:a)cout<<c<<" ";return 0;}  

