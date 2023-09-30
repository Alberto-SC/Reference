#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;  
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> x(n);
        vector<int> y(n);
        for(auto &c:x)cin>>c;
        for(auto &c:y)cin>>c;
        vector<int> l(n);
        vector<int> r(n);
        sort(x.begin(),x.end());
        int j = n-1;
        for(int i = n-1;i>=0;i--){   m   
            while(j>=0 && x[j]-x[i]>k)j--;      
            r[i]= (j-i)+1;
            if(i+1<n)l[i] = max(r[i],r[i+1]); 
        }
        j = 0;
        for(int i = 0;i<n;i++){
            while(j<n&& x[i]-x[j]>k)j++;
            l[i] = (i-j)+1;
            if(i-1>=0)l[i] = max(l[i],l[i-1]);
        }
  
        int ans = 1;
        for(int i = 0;i<n-1;i++)  
            ans = max(ans,l[i]+r[i+1]);
        cout<<ans<<endl;
    }
    return 0;
} 