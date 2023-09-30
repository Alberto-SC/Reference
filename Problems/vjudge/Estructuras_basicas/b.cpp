#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,ans= 0;
    cin>>n>>k;
    vector<char> sets(5);
    sets[0] = sets[4] = 'S';
    sets[1] = sets[3] = 'E';
    sets[2] = 'T';
    map<char,int> m;
    m['S']= 1;
    m['E']= 2;
    m['T'] = 3;
    vector<string> cards(n);
    for(auto &c:cards)cin>>c;
    sort(cards.begin(),cards.end());
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            string search = "",s;
            for(int z = 0;z<k;z++){
                if(cards[i][z]!= cards[j][z]){search+= sets[(m[cards[j][z]]+m[cards[i][z]])-1];}
                else {search+= cards[i][z];}
            }
            int index = lower_bound(cards.begin(),cards.end(),search)-cards.begin();
            if(index != i && index!= j && cards[index]== search)ans++;
        }
    }
    return cout<<ans/3<<endl,0;

}