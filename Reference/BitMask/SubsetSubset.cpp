/**
 * Author: Alberto Silva
 * Description:  Computing some information $f$ from all the subsets of some subset 
 * Time:  $O(3^n)$
 */


#include <bits/stdc++.h>
using namespace std;

int main(){
    int N = 4;
    // If you just want to iterate over all the subsets of a mask
    for(int i=0; i<(1<<N); ++i){
        bitset<8> n(i);
        cout<<"MASK: "<<n<<endl;
        cout<<"SUBMASK:"<<endl;
        for(int j = i; j; j = (j-1) & i){
            bitset<8> p(j);
            cout<<p<<endl;
        }
        cout<<endl;
    }

    // If you want to compute some information like the sum from all the subsets of some mask

    for(int mask = 0; mask < (1<<N); ++mask){
      dp[mask][-1] = A[mask];	//handle base case separately (leaf states)
      for(int i = 0;i < N; ++i){
        if(mask & (1<<i))
          dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<i)][i-1];
        else
          dp[mask][i] = dp[mask][i-1];
      }
      F[mask] = dp[mask][N-1];
    }

    // Memory optimization
    for(int i = 0; i<(1<<N); ++i)
      F[i] = A[i];
    for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
      if(mask & (1<<i))
        F[mask] += F[mask^(1<<i)];
    }
    return 0;
}

