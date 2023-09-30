#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    char c;
    char *p;
    int ans = 0;
    while(scanf("%d-%d %c: %s",&l,&r,&c,p)!=EOF){
        int n =0;
        int i = 0;
        while(p[i]!= EOF){
            n++;
            i++;
        }
        if((p[l-1]== c && (r-1<n && p[r-1]!= c)) || (p[l-1]!= c && (r-1<n && p[r-1]== c)) )ans++;
    }
    cout<<ans<<endl;
    return 0;
}