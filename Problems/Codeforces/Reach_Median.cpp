#include <bits/stdc++.h>
#define print(A)for(auto c: A)cout<<c<<" ";
using namespace std;
int main(){
    long long n,s,ai,cont = 0;
    vector<int> arr;
    cin>>n>>s;
    for(int i = 0;i<n;i++){
        cin>>ai;
        arr.push_back(ai);
    }
    sort(arr.begin(),arr.end());
    long long sm = 0,hm =0;
    for(int i = 0;i<n/2;i++){
        if(arr[i]>s) hm+= arr[i]-s;
        if(arr[n-i-1]<s) sm+= s-arr[n-i-1];
    }
    cout<<hm+sm+abs(arr[n/2]-s);
    return 0;
}