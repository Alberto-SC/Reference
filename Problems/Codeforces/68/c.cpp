#include <bits/stdc++.h>
using namespace std;
void getZarr(string str, int Z[]); 
int search(string text, string pattern){ 
    string concat = pattern + "$" + text; 
    int l = concat.length(); 
    int Z[l]; 
    getZarr(concat, Z); 
    int index = 0;
    for (int i = 0; i < l; ++i) { 
        if (Z[i] == pattern.length()) 
            index = i - pattern.length() -1 ; 
    } 
    return index;
} 

void getZarr(string str, int Z[]) { 
    int n = str.length(); 
    int L, R, k; 
    L = R = 0; 
    for (int i = 1; i < n; ++i){ 
        if (i > R) { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else{ 
            k = i-L; 
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
            else { 
                
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
} 
  

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t,p;
        cin>>s>>t>>p;
        if(s==t){cout<<"YES"<<endl;continue;}
        bool yes = true;
        vector<int> dis(27,0);
        vector<int> need(27,0);
        vector<int> diss(27,0);
        for(int i = 0;i<p.size();i++)
            dis[p[i]-'a']++;
        for(int i = 0;i<t.size();i++)
            need[t[i]-'a']++;
        for(int i = 0;i<s.size();i++){
            dis[s[i]-'a']++;
            diss[s[i]-'a']++;
        }
        for(int i = 0 ;i<27;i++)
            if(need[i]>dis[i])yes = false;
        for(int i = 0;i<27;i++)
            if(diss[i]>need[i])yes = false;
        int indf = 0;
        for(int i = 0;i<s.size();i++){
            string pattern = s.substr(i,1);
            int indh= search(t, pattern);
            if(indh<indf){yes = false;break;}
            indf = indh;
        }
        
        if(yes)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}