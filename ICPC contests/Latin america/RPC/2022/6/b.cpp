#include <bits/stdc++.h>
using namespace std;

int main() {

  string s; cin>>s;
  int idx = 0;
  for(int i = s.size()-1; i >= 0; i--){
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
      idx = i; break;
    }
  }

  cout << s.substr(0, idx+1) + "ntry\n";

  return 0;
}