#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
  int a[200000];
    int v[200000];
    int b[200000];
int main(){
    int n,q,l,r;
    scanf("%d %d",&n,&q);
  
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i = 0;i<q;i++){
        scanf("%d %d",&l,&r);
        l--;
        r--;
        v[l]++;
        if (r<n-1)
             v[r+1]--;
    }
    int s=0;
    for(int i = 0;i<n;i++){
        s+=v[i];
        b[i]=s;
    }
    sort(b,b+n);
    long long int res=0;
    for(int i = 0;i<n;i++)
        res+=(b[i]*1ll*a[i]*1ll);
    cout<<res<<endl;
    return 0;
}