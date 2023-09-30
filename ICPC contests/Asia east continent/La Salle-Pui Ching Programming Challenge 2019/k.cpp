#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long

int get_posbibles(int x){
    int ans = 1;
    if(x==0)return 10;
    if(x==-1)return 1;
    for(int i = 0;i<x;i++)
        ans*=10;
    ans*=9;
    return ans;
}

signed main(){
    int k;
    cin>>k;
    int digits = 1;
    int sum = 10;
    if(k<=10)return cout<<k-1<<endl,0;
    while(sum<k){
        sum += get_posbibles(digits);
        digits++;
    }
    int z = digits;
    digits = ((digits-1)*2)+1;
    string ans = "";
    sum/=9;
    for(int i = 0;i<z-1;i++)
        k-=get_posbibles(i);
    k--;
    int aux = z;
    while(z--){
        int x;
        if(z>=1)x = k/(pow(10,z));
        else x = k;
        if(z+1==aux)
            ans+=char(x+'1');
        else ans+=char(x+'0');
        
        k-=x*(pow(10,z));
    }
    int idx = ans.size()-2;
    for(int i = 0;i<digits/2;i++)
        ans+=ans[idx--];
    cout<<ans<<endl;
    return 0;
}
