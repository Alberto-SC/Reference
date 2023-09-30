#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(k>=n)cout<<1<<endl;
        else {
            vector<int> divs;
            for(int i = 1;i*i<=n;i++){
                if(n%i == 0){
                    divs.push_back(i);
                    if(n/i != i)
                        divs.push_back(n/i);
                }
            }
            sort(divs.begin(),divs.end());
            int index = lower_bound(divs.begin(),divs.end(),k)-divs.begin();
            if(divs[index]== k)cout<<n/k<<endl;
            else cout<<n/divs[index-1]<<endl;
        }
    }
    return 0;
}