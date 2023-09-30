
#include <bits/stdc++.h>
using namespace std;
int main(){
    int conta = 0,contb = 0;
    string s;
    cin>>s;
    int n = s.size();
    for(int i = 0; i < n; i ++){
        if(s[i] == 'A') conta++;
        else contb++;
    }
    char s2[n*2];
    for(int i = 0;i<n;i++)
        s2[i] = s[i];
    for(int i = n; i < n * 2; i ++)
        s2[i] = s[i - n];
    if(conta  &1 || contb &1)
        cout<<"NO"<<endl;
    else{
        vector<pair<int,int>> AB(2*n,{0,0});
        int index1 = 0,index2= 0,A = 0,B = 0,suma = 0,sumb = 0;
        for(int i=0; i<2*n; i++)
            s2[i]== 'A'? suma++:sumb++,AB[i] = {suma,sumb};
        for(int i = n; i < n * 2; i ++){
            AB[i].first -= AB[i - n].first;
            AB[i].second -= AB[i - n].second;
        }
        int yes = 0,needA = conta/2,needB = contb/2;
        // cout<<needA<<" "<<needB<<endl;
        for(int i = n / 2; i < 2 * n; i ++){
            if(AB[i].first - AB[i - (n/2)].first == needA &&  AB[i].second - AB[i - (n/2)].second == needB){
                yes = 1;
                index1 = i;
                break;
            }
        }

        if(!yes) cout<<"NO"<<endl;
        else{
            index1 += 2;
            if(index1 > n) index1 = 1;
            index2 = index1 + n/ 2;
            if(index2 > n) {index2 = index2 - n;}
            cout<<"YES"<<endl;
            cout<<index1<<" "<<index2<<endl;
        }
    }

    return 0;
}