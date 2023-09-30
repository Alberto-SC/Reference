#include <bits/stdc++.h>
using namespace std ;
int main() {
   int n,c;
   cin>>n>>c;
   vector<int> v(n);
   for (int i=0;i<c;i++){
      int ci;
      cin>>ci ;
      int cc = min_element(v.begin(), v.end()) - v.begin() ;
      if(i)
         cout <<" ";
      cout << (1+cc);
      v[cc] += ci;
   }
   cout<<endl;
}