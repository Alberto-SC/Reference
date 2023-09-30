#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int N = 1e7;
vector<int> primes;
vector<int> lp(N+1);
void criba(){
  for(int i = 2;i<=N;i++){
    if(lp[i]==0){
      lp[i] =i;
      primes.push_back(i);
    }
    for(int j = 0;j<primes.size()  && primes[j]*i<=N && primes[j]<=lp[i];j++){
      lp[primes[j]*i] = primes[j];
    }
  }
}

signed main(){
  int n;
  primes.push_back(0);
  criba();
  cin>>n;
  vector<int> nums(2*n);
  for(auto &c:nums)cin>>c;
  sort(nums.rbegin(),nums.rend());
  multiset<int> deleted;
  vector<int> ans;
  int cont = n;
  for(int i = 0,cont=0;i<2*n && cont<n;i++){
    if(deleted.count(nums[i])){
      deleted.erase(deleted.find(nums[i]));
      continue;
    }
    if(lp[nums[i]]!=nums[i]){
      ans.push_back(nums[i]);
      deleted.insert(nums[i]/lp[nums[i]]);
    }  
    else{
      int idx = lower_bound(primes.begin(),primes.end(),nums[i])-primes.begin();
      deleted.insert(idx);
      ans.push_back(idx);
    }
    cont++;
  }
  for(auto c:ans)cout<<c<<" ";
  cout<<endl;
  return 0;
}
