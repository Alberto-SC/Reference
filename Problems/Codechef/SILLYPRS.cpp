#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int A,B,sumA = 0,sumB = 0;
        for(int i = 0;i<n;i++){
            cin>>A;
            sumA+=A;
        }
        for(int i = 0;i<n;i++){
            cin>>B;
            sumB+=B;
        }
        if((sumA%2 == 0 && sumB%2 == 0 )||(sumA%2 == 1 && sumB%2 ==1))
            cout<<floor((sumA+sumB)/2)-1<<endl;
        else cout<<floor((sumA+sumB)/2)<<endl;
    }
    return 0;
}