#include <bits/stdc++.h>
using namespace std;

int main(){
  int n=0, p=0, aux=n;
  cin >> n >> p;
  vector<int>time(n);
  vector<int>accepted(n);

  for(auto &x:time) cin >> x;

  for(int i=(n-1); i>=0; i--){
    if(time[i]!=0){
      aux=i;
      break;
    }
  }

  // Caso: Si todos son ceros no es ambiguo
  if(aux==0){
    for(int i=0; i<n; i++){
      cout << accepted[i] << "\n";
    }
    return 0;
  }

  // Continuaaaaamooooooos...
  int pos=1;
  accepted[aux]=pos;

  for(int i=(aux-1); i>=0; i--){
    if(time[i]>time[i+1]){
      pos++;
    }
    accepted[i]=pos;
  }

  // Vamooooos bieeeeeeen, correcto, lo entiendo :v
  if(accepted[0]==p){
    for(int i=0; i<n; i++){ 
      cout << accepted[i] << "\n"; 
    }
  }else{
    // Oh, no... oh, no... ambiguoooooos
    cout << "ambiguous" << "\n";
  }

  return 0;
}
