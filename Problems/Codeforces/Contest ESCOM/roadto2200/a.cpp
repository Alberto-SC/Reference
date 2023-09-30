#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    int mx = INT_MIN, mxh = 0; 
    for (int i=0;i<n;i++) { 
        mxh = mxh + a[i]; 
        if (mx < mxh) 
            mx = mxh; 
        if (mxh < 0) 
            mxh = 0; 
    } 
    return 0;
}