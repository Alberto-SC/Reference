#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
vector<lli> lucky;
void string_to_num(string n){
    lli num = stoll(n,nullptr,0);
    lucky.push_back(num);
}
void getallLucky(int d,string  num){
    if(d == 0){string_to_num(num);return;}
    getallLucky(d-1,num+"4");
    getallLucky(d-1,num+"7");
}

int main(){
    lli l,r;
    cin>>l>>r;
    for(int i = 1;i<11;i++){
        getallLucky(i,"");
    }
    int n = lucky.size();
    int j = 0;
    while(lucky[j]<l){
        j++;
    }
    lli ans = 0;
    for(int i = j;i<n ;i++){
        // cout<<lucky[i]<<"  ";
        if(l>r)break;
        else if(l==r){ans+=lucky[lower_bound(lucky.begin(),lucky.end(),(lli)l)-lucky.begin()];break;}
        if(lucky[i]>=r)ans+=lucky[i]*((r-l)+1);
        else
            ans+=lucky[i]*((lucky[i]-l)+1);
        // cout<<(lli)lucky[i]*((lucky[i]-l)+1)<<endl;
        l = lucky[i]+1;
    }
    
    cout<<ans<<endl;
    return 0;
}