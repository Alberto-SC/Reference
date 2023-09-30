#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

ll binpow(ll x, ll y){
  ll res=1;
  while(y){
    if(y&1) res*=x;
    x*=x;
    y/=2;
  }
  return res;
}

int main(){__

    ll N;
    cin>>N;
    ll dos=0, cinco=0;
    while(N%2==0){
      N/=2;
      dos++;
    }
    while(N%5==0){
      N/=5;
      cinco++;
    }

    priority_queue<ll, vector<ll>, std::greater<ll> > q;
    for(int i=0; i<=dos; i++){
      for(int j=0; j<=cinco ; j++){
        ll respow= binpow(2,i) * binpow(5,j);
        q.push(respow);
      }
    }
    cout<<q.size()<<"\n";
    while(!q.empty()){
      cout<<q.top()<<"\n";
      q.pop();
    }  

    return 0;
}

