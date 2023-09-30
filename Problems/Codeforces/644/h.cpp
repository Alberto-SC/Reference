#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long int lli;

lli bin_to_int(string s){
    int n = s.size();
    lli ans = 0;
    for(int i = n-1;i>=0;i--){
        if(s[i] == '1')ans|=1ll<<(n-1)-i;
    }
    return ans;
}
int main(){
    lli t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        string s ;
        lli median = ((1ll<<m)-1)/2;
        lli copy = median;
        set<lli> st;
        int N = 1<<m;
        for(int i = 0;i<n;i++){
            cin>>s;
            lli num = bin_to_int(s);
            st.insert(num);
            if(num<median){
                if(N&1){
                    median = median;
                }
                else{
                    median++;
                    while(st.find(median)!= st.end())median++;
                }
            }
            else if(num == median){
                if(N&1){
                    median--;
                    while(st.find(median)!= st.end())median--;
                }
                else {
                    median++;
                    while(st.find(median)!= st.end())median++;
                }
            }
            else{
                if(N&1){
                    median--;
                    while(st.find(median)!= st.end())median--;
                }
                else {
                    median = median;
                }
            }
            N--;
        // cout<<median<<endl;
        }
        string binary = bitset<60>(median).to_string();
        for(int i = 60-m;i<60;i++)cout<<binary[i];
        cout<<endl;
        // cout<<binary<<endl;
    }
    return 0;
}