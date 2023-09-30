#include <bits/stdc++.h>
using namespace std;
vector<int> pos;
int n;
bool check(int x){
    int pref = 0,cont = 0,index,last = -1;
    int mx  = -1;
    bool flag = true;
    while(flag){
        // cout<<pref<<" ";
        if(last == pos.size()-1)break;
        index = lower_bound(pos.begin(),pos.end(),x+pref)-pos.begin();
        // cout<<index<<endl;
        if(pos[index]== x+pref)pref=pos[index],mx = x;
        else{
            // cout<<"HELLO"<<endl;
            if(index == pos.size())flag = false;
            index--;
            if(index == last || index<0)return false;
            mx = max(x-((pref+x)-pos[index]),mx);
            pref=pos[index];
        }
        last = index;
        cont++;
    }
    // cout<<cont<<" "<<mx<<endl;
    if(cont> n || mx>x)return false;
    return true;
}
int main(){
    cin>>n;
    string s;
    cin.ignore();
    getline(cin,s);
    for(int i = 0;i<s.size();i++){
        if(s[i] ==' ' || s[i] == '-')pos.push_back(i+1);
    }
    pos.push_back(s.size());
    int l = 1,r = s.size();

    while(l+1<r){
        int m =(l+1+r)>>1;
        if(check(m))
            r = m;
        else l = m;
    }
    cout<<r<<endl;
    return 0;

}