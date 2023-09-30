#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    map<char,int> mm;
    vector<string> hand(5);
    for(int i = 0;i<5;i++){
        cin>>hand[i];
        mm[hand[i][0]]++;
    }
    int mx = -1;
    for(int i = 0;i<5;i++){
        mx = max(mx,mm[hand[i][0]]);

    }

    cout<<mx<<endl;
    return 0;
}