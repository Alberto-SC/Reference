#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int tope = (n*(n+1))/2;
    int a;
    for(a = 1;a<tope;a++)
        if(__gcd(a,tope-a)>1)break;
    if(a == tope)return cout<<"No"<<endl,0;
    vector<int> sets(n);
    vector<int> ac(n);
    ac[0] = 1;
    for(int i = 1;i<n;i++)
        ac[i]= ac[i-1]+(i+1);
    cout<<"Yes"<<endl;
    int index = (lower_bound(ac.begin(),ac.end(),a)-ac.begin());
    for(int i = 0;i<=index;i++)sets[i]= 1;
    if(ac[index]%a!= 0)sets[(ac[index]%a)-1]= 0;
    int sizea = accumulate(sets.begin(),sets.end(),0);
    cout<<sizea<<" ";
    for(int i = 0;i<n;i++)if(sets[i] == 1)cout<<i+1<<" ";
    cout<<endl;
    cout<<n-sizea<<" ";
    for(int i = 0;i<n;i++)if(sets[i] == 0)cout<<i+1<<" ";
    cout<<endl;
    return 0;
}