#include "bits/stdc++.h"
using namespace std ;
#define int long long 
#define accuracy chrono::steady_clock::now().time_since_epoch().count()
mt19937 rng(accuracy);

int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

void sol(){
    int a = rand(-1000000000,1000000000);
    int b = rand(-1000000000,1000000000);
	int x,y,x1,y1,x2,y2;
    int queries = 64;
    int d = 1;
    cout<<1<<" "<<queries<<" "<<d<<endl<<flush; 
	while( queries-- ){
		int op;
		cin>>op;
		if(op == 1){
            cin>>x>>y;
            string ans = "NN";
            if(x== a)ans[0]= 'X';
            if(x<a)ans[0] = 'N';
            if(x>a)ans[0] = 'P';
            if(y == b)ans[1] = 'Y';
            if(y<b)ans[1] = 'N';
            if(y>b)ans[1] = 'P';
            if(x== a && y ==b)ans = "O";
            if(ans =="O"){
                cout<<ans<<endl<<flush;
                return ;
            }
            cout<<ans<<endl<<flush; 
        }
		else if(op==2){
            cin>>x1>>y1>>x2>>y2;
            if(((a == x1 || a== x2) &&(b>=y1 && b<=y2)) || ((b == y1 || b == y) && (a>=x1 && a<=x2))){
                cout<<"O"<<endl<<flush;
                return ;
            }
            else if(a>x1 && a<x2 && b>y1 && b<y2)cout<<"IN"<<endl<<flush;
            else cout<<"OUT"<<endl<<flush;
        }
        else break;
        int move = rand(0,3);
        if(move ==0)
            a+=d;
        if(move ==1)
            a-=d;
        if(move==2)
            a+=d;
        if(move==3)
            a-=d;
	}
	cout <<" WA " << endl<<flush ;
	cout << "The position is "<<a<<" "<<b<<endl<<flush;
}

signed main(){
	sol();
}