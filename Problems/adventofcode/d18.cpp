#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
// Sin precedencia, solo parentesis ()
lli evaluar(string s){
    int n = s.size();
    lli last = -1;
    for(int i = 0;i<n;){
        if(s[i] == ' ' || s[i]== 13)i++;
        else if(s[i]== '+'){
            int j = i+1,j2;
            lli next_num;
            while(j<n && s[j]== ' ')j++;
            bool P = false;
            if(s[j]== '('){
                j2 = j+1;
                int pc = 1;
                while(j2<n && pc){
                    if(s[j2]== '(')pc++;
                    else if(s[j2]== ')')pc--;
                    j2++;
                }
                next_num = evaluar(s.substr(j+1,(j2-(j+1))-1));
                P = true;
            }
            else{
                j2 = j;
                while(j2<n && s[j2]>='0' && s[j2]<='9'){j2++;}
                next_num = stoll(s.substr(j,(j2-j)+1));
            }
            i = j2;
            if(P)i++;
            last+=next_num;
        }
        else if(s[i]== '*'){
            int j = i+1,j2;
            lli next_num;
            while(j<n && s[j]== ' ')j++;
            bool P = false;
            if(s[j]== '('){
                j2 = j+1;
                int pc = 1;
                cout<<"Parentesis "<<endl;
                while(j2<n && pc){
                    if(s[j2]== '(')pc++;
                    else if(s[j2]== ')')pc--;
                    j2++;
                }
                next_num = evaluar(s.substr(j+1,(j2-(j+1))-1));
                P = true;
            }
            else{
                j2 = j;
                while(j2<n && s[j2]>='0' && s[j2]<='9'){j2++;}
                next_num = stoll(s.substr(j,(j2-j)+1));
            }
            last*=next_num;
            i = n;
            if(P)i++;
        }
        else if(s[i]<='9' && s[i]>='0'){
            int j = i;
            while(j<n && s[j]== ' ')j++;
            while(j<n && s[j]>='0' && s[j]<='9')j++;
            last = stoll(s.substr(i,(j-i)+1));
            i = j;
        }
        else if(s[i]== '('){
            int j2 = i+1;
            int pc = 1;
            while(j2<n && pc){
                if(s[j2]== '(')pc++;
                else if(s[j2]== ')')pc--;
                j2++;
            }
            last = evaluar(s.substr(i+1,(j2-(i+1))-1));
            i = j2+1;
            
        }
    }
    return last;
}

int main(){
    string s;
    vector<string> ex;
    while(getline(cin,s)){
        ex.push_back(s);
    }
    lli ans = 0;
    for(int i = 0;i<ex.size();i++){
        ans+=evaluar(ex[i]);
    }
    cout<<ans<<endl;
    return 0;
}