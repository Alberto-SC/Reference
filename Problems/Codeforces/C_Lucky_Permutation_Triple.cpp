#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%2 == 0)return cout<<-1<<endl,0;
    if(n == 1)return cout<<0<<endl<<0<<endl<<0<<endl,0;
    for(int i = 0;i<n;i++)
        cout<<i<<" ";
    cout<<endl;
    for(int i = 1;i<=n;i++)
        i==n?cout<<0<<" ":cout<<i<<" ";
    cout<<endl;
    for(int i = 0;i<n;i++)
        i<(n/2)?cout<<(i*2)+1<<" ":cout<<(i-(n/2))*2<<" ";

    return 0;
}