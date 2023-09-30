#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    vector<int> A(n);
    for(int i = 0;i<n;i++)
        cin>>A[i];
    sort(A.begin(),A.end());
    cin>>m;
    vector<int> B(m);
    for(int i = 0;i<m;i++)
        cin>>B[i];
    sort(B.begin(),B.end());
    cout<<A[n-1]<<" "<<B[m-1]<<endl;
    return 0;
}