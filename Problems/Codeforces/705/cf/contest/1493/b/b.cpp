#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> rev(10);
int get_reverse(int x){
    string s;
    s.push_back(rev[x%10]+'0');
    s.push_back(rev[x/10]+'0');
    int y = stoi(s);
    return y;
}
signed main(){
	int t= 1,n,h,m,lh,lm;
    cin>>t;
    vector<bool> correct(10);
    correct[1] = true;
    correct[2] = true;
    correct[0] = true;
    correct[5] = true;
    correct[8] = true;
    rev[1] = 1;
    rev[2] = 5;
    rev[5] = 2;
    rev[8] = 8;
    while(t--){
        scanf("%d %d",&lh,&lm);
        scanf("%d:%d",&h,&m);
        while(1){
            bool flag = false;
            while(m<lm){
                if(correct[h%10] && correct[h/10] && correct[m%10] && correct[m/10] && get_reverse(h)<lm && get_reverse(m)<lh){
                    flag = true;
                    break;
                }
                m++;
            }
            if(flag)break;
            if(m == lm)m = 0;       
            h++;
            if(h == lh)h = 0;
        }
        string sh,sm;
        if(h/10 == 0){
            sh = "0"+to_string(h);
        }
        else sh = to_string(h);
        if(m/10 == 0){
            sm = "0"+to_string(m);
        }
        else sm = to_string(m);
        cout<<sh<<":"<<sm<<endl;
    }
    return 0;
}  
