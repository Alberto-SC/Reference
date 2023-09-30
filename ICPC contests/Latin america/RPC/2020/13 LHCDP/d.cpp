#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int get_digital_root(string num){
    int sum = 0;
    for(int i = 0;i<num.size();i++){
        sum+=num[i]-'0';
    }
    while(to_string(sum).size()>1){
        string s = to_string(sum);
        sum = 0;
        for(int i = 0;i<s.size();i++)
            sum+=s[i]-'0';
    }
    return sum;
}

int main(){__
	int t= 1,n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<=n;j++){
            cout<<"NUM: "<<s.substr(i,j-i)<<endl;
            cout<<"Root: "<<get_digital_root(s.substr(i,j-i))<<endl;
        }
    }
    return 0;
}  

