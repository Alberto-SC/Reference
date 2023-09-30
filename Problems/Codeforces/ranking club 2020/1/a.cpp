#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> d1(n);
    for (int i=0, l=0, r=-1; i<n; i++) {
        int k = (i>r)?1:min(d1[l+r-i],r-i+1);
        while (0<=i-k && i+k<n && s[i-k] == s[i+k]) {
            k++;
        }
        d1[i] = k--;
        if (i+k>r){
            l=i-k;
            r=i+k;
        }
    }

    vector<int> d2(n);
    for (int i=0,l=0,r=-1;i<n;i++) {
        int k = (i>r) ? 0:min(d2[l+r-i+1], r-i+1);
        while (0<=i-k-1 && i+k<n && s[i-k-1] == s[i+k]) {
            k++;
        }
        d2[i] = k--;
        if (i+k> r) {
            l= i-k- 1;
            r= i+k ;
        }
    }
    // for(int i = 0;i<n;i++)cout<<d1[i]<<" "<<d2[i]<<endl;
    int ans1 = *max_element(d1.begin(),d1.end());
    int ans2 = *max_element(d2.begin(),d2.end());    
    if(ans2>=ans1){
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(d2[i] == ans2)ans++;
        }
        return cout<<ans2*2<<endl<<ans<<endl,0; 
    }
    else {
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(d1[i] == ans1)ans++;
        }
        if(ans1 > 1)ans1=(ans1*2)-1;
        return cout<<ans1<<endl<<ans<<endl,0; 
    }
    return 0;
}