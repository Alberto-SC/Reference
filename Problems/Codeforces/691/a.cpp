#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string R;
        string B;
        cin>>R>>B;
        int contB = 0,contR = 0;
        for(int i = 0;i<n;i++){
            if(B[i]>R[i])
                contB++;
            else if(R[i]>B[i])
                contR++;
        }
        if(contB>contR)cout<<"BLUE"<<endl;
        else if(contR>contB)cout<<"RED"<<endl;
        else cout<<"EQUAL"<<endl;
    }
    return 0;
}  

