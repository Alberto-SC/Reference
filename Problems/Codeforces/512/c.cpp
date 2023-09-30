#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int sum = 0;
    for(int i = 0;i<n;i++)
        sum+=(int)s[i]-'0';
    // cout<<sum<<endl;
    if(sum == 0)return cout<<"YES"<<endl,0;
    set<int> divisors;
    for(int i =1;i<=sqrt(sum);i++){
        if(sum%i == 0)divisors.insert(i),divisors.insert(sum/i);
    }
    // for(auto c:divisors)cout<<c<<" ";
    // cout<<endl;
    divisors.erase(sum);
    for(auto c:divisors){
        int x = 0,count = 0;
        if(sum/c>n)continue;
        for(int i = 0;i<sum/c && x<n;i++){
            int sump = 0;
            while(sump <c&& x<n){
                sump+=s[x]-'0';
                x++;
            }
            if(sump == c)count++;
            else break;
        }
        if(count == sum/c)return cout<<"YES"<<endl,0;
    }
    cout<<"NO"<<endl;
    return 0;
}