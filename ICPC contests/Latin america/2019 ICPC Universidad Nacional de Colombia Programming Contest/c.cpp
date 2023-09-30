#include<bits/stdc++.h> 
using namespace std;

int lcs(string &X, string &Y) { 
    int n = Y.size(); 
    int L[2][n + 1]; 
    bool bi;   
    for (int i = 0; i <= n; i++) { 
        bi = i & 1;   
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                L[bi][j] = 0; 
            else if (X[i-1] == Y[j-1]) 
                 L[bi][j] = L[1 - bi][j - 1] + 1; 
            else
                L[bi][j] = max(L[1 - bi][j],  
                               L[bi][j - 1]); 
        } 
    } 
    return L[bi][n]; 
} 
   
int main() { 
    string x,y;
    cin>>x>>y;
    int n = x.size();
    int c = lcs(x,y);
    int min = ceil((double)n*0.99);
    // cout<<min<<"   "<<n<<" "<<c<<endl;
    if(c>=min)cout<<"Long lost brothers D:"<<endl;
    else cout<<"Not brothers :("<<endl;    
    return 0; 
} 