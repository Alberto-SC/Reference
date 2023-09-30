#include <bits/stdc++.h>
using namespace std;
#define print(a)for(auto c:a)cout<<c<<" ";
int main(){ 
    int n,k;
    cin>>n>>k;
    vector<int> nums(n,0);
    vector<int> b(k+1,0);
    for(int i = 0;i<n;i++){cin>>nums[i];b[nums[i]]++;};
    int p= 0;
    for(int i = 0;i<=k;i++)p+=b[i]&1;
    int cont = 0,pos = ceil(n/2.0);
    for(int i = 0;i<=k;i++)cont+=b[i]/2;
    // cout<<"  "<<cont<<"   "<<pos<<"   "<<p<<endl;
    if(cont == pos)cout<<n<<endl;
    else cout<<n-(p-(pos-cont))<<endl;
    return 0;
}