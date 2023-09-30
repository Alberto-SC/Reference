#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<string> letters = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                         "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
vector<string> numbers = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};


signed main(){__
    string s;
    getline(cin,s);
    string x = "";
    for(auto c:s){
        if(c>='0' && c<='9'){
            x+=numbers[c-'0'];
        }
        else if(c>='a' && c<='z')
            x+=letters[c-'a'];
        else if(c>='A' && c<='Z')
            x+=letters[c-'A'];
    }
    if(x=="")return cout<<"NO"<<endl,0;
    int n = x.size();
    bool flag = true;
    for(int i = 0;i<n/2;i++){
        if(x[i]!=x[(n-1)-i]){
            flag = false;
            break;
        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}