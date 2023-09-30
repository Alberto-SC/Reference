#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    map<char,char> mp={{'O','0'},{'I','1'},{'Z','2'},{'E','3'},{'A','4'},{'S','5'},{'G','6'},{'T','7'},{'B','8'},
                    {'o','0'},{'i','1'},{'z','2'},{'e','3'},{'a','4'},{'s','5'},{'g','6'},{'t','7'},{'b','8'}};

    string s;
    cin>>s;
    n = s.size();
    for(int i = 0;i<n;i++){
        if(mp.count(s[i]))
            cout<<mp[s[i]];
        else 
            cout<<s[i];
    }
    cout<<endl;
    return 0;
}  
