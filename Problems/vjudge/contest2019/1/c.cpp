#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c:A) cout<<c<<" ";
#define printM(A) for(auto c:A) print(c);cout<<endl;
int main(){
    long long n,m,ans = 0;
    cin>>n>>m;
    long long minn = min(n,m),countc  = 0,countr = 0;
    for(int i = 1;i<=minn;i++){
        countc = 0;
        for(int j = 1;j<=minn ;j++){
            if( ((i*i) + (j*j))%m == 0){
                countc += n/m;
                if(n%m >0 && j<=n%m )countc++;
            }
        }
        countr = n/m;
        if(n%m >0 && i<=n%m )countr++;
        ans += countc*countr;
    }   
    cout<<ans<<endl;
    return 0;
}