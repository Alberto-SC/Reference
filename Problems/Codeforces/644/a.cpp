#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a<b)swap(a,b);
        if(b*2>=a)cout<<(b*2)*(b*2)<<endl;
        else cout<<a*a<<endl;
    }
    return 0;
}