#include <bits/stdc++.h> 
using namespace std;   
#define MAX 10000   
vector<int> UN;   
void ulam() { 
    unordered_set<int> s; 
    UN.push_back(1); 
    s.insert(1); 
    UN.push_back(2); 
    s.insert(2); 
    for (int i = 3; i < MAX; i++) {   
        int count = 0; 
        for (int j = 0; j < UN.size(); j++) { 
            if (s.find(i - UN[j]) != s.end() && UN[j] != (i - UN[j])) 
                count++; 
            if (count > 2) 
                break; 
        } 
        if (count < 2) { 
            UN.push_back(i); 
            s.insert(i); 
        } 
    } 
} 
int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    ulam(); 
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<UN[n-1]<<"\n";
    }  
    return 0; 
} 