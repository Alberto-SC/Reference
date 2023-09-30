#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<int> x(m-1);
        vector<int> y(n-1);
        for(auto &x:x)cin>>x;
        for(auto &x:y)cin>>x;
        sort(x.rbegin(),x.rend());
        sort(y.rbegin(),y.rend());
        int h = 1;
        int v = 1;
        int i = 0,j = 0 ;
        long long int ans = 0;
        while(i<m-1 && j<n-1){ 
            if(x[i]>y[j]){
                ans+= x[i]*v;
                h++;
                i++;
            }
            else {
                ans+= y[j]*h;
                v++;
                j++;
            }

        }
        if(i<m-1){
            while(i<m-1){
                ans+=x[i]*v;
                i++;
            }
        }
        else {
            while(j<n-1){ 
                ans+=y[j]*h;
                j++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}