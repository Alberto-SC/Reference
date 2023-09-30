#include <bits/stdc++.h>
using namespace std;
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
int main(){
    int t = 200;
    cout<<t<<endl;
    while(t--){
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                int n = rand(1,2);
                string s;
                for(int k = 0;k<n;k++){
                    s+=char(rand(0,5)+'A');
                }
                cout<<s<<" ";
            }
            cout<<endl;
        }
        if(t)cout<<endl;
    }
    return 0;
}