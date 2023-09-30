#include<bits/stdc++.h>

using namespace std;

typedef long long int ll; 


int main(){
  ll N,tam,x,y,xant,yant, totalper=0;
  cin>>N;
  vector<pair<int,int>> coo(N);
  for(int i=0; i<N; i++)
    cin>>coo[i].first>>coo[i].second;

  ll infizqx=coo[0].first, infizqy=coo[0].second;
  ll supderx=coo[0].first, supdery=coo[0].second;

  for(int i=1; i<=N; i++){
    xant=coo[i-1].first; yant=coo[i-1].second;
    x=coo[i%N].first; y=coo[i%N].second;
    totalper+= (x!=xant)? abs(x-xant) : abs(y-yant);

    infizqx= min(infizqx,x);
    infizqy= min(infizqy,y);

    supderx= max(supderx,x);
    supdery= max(supdery,y);
    
  }
  ll pervisible= 2*(supderx-infizqx) + 2*(supdery-infizqy);
  cout<< totalper-pervisible << "\n";

  return 0;
}