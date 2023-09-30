#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mod = 1e9+7;
const int maxn = 100005;
int st[4*maxn],basura[4*maxn],pos[maxn];
set<int> nodos[maxn];
map<int,int> conv,rev;
int idx = 1;

void build(int i, int ini, int fin){
	if(ini == fin){
		pos[ini] = i;
		return;
	}

	int m = (ini+fin)/2;
	build(2*i,ini,m);
	build(2*i+1,m+1,fin);
}

void build(int n){
	nodos[0].insert(1);
	build(1,1,n);
}

int query(int x){
	int i = pos[x];
	int last = 0;
	while(i){
		if(st[i]) last = st[i];
		if(basura[i]) return -1;
		i/=2;
	}
	return last;
}

bool check(int i, int k){
	while(i){
		if(st[i] && st[i] != k){
			//debug(st[i],k,i);
			return false;
		}
		i/=2;
	}
	return true;
}

void trash(int k){
	//debug(k,nodos[k]);
	for(int x : nodos[k]){
		//debug(x);
		if(check(x,k)) basura[x] = 1;
	}
	nodos[k].clear();
}

void propagate(int i, int ini, int fin){
	if(st[i] != 0 && ini != fin){
		int p = st[i];
		nodos[p].erase(i);
		st[i] = 0;
		if(st[2*i]) nodos[st[2*i]].erase(2*i);
		if(st[2*i+1]) nodos[st[2*i+1]].erase(2*i+1);
		st[2*i] = st[2*i+1] = p;
		nodos[p].insert(2*i);
		nodos[p].insert(2*i+1);
		//debug(p,i,ini,fin,nodos[p]);
	}
}

void update(int i, int ini, int fin, int l, int r, int k){
	if(ini > r || fin < l) return;

	if(basura[i]) return;
	propagate(i,ini,fin);
	if(ini >= l && fin <= r){
		//poner
		if(st[i]) nodos[st[i]].erase(i);
		st[i] = k;
		nodos[st[i]].insert(i);
		propagate(i,ini,fin);
		return;
	}

	int m = (ini+fin)/2;
	update(2*i,ini,m,l,r,k);
	update(2*i+1,m+1,fin,l,r,k);
}

int main(){__
	int n,c;
	cin >> n >> c;
	build(n);
	int q;
	cin >> q;
	while(q--){
		int i,j,k;
		char opc;
		cin >> opc;
		if(opc == 'm'){
			cin >> i >> j >> k;
			if(conv.find(k) != conv.end()){
				k = conv[k];
			}
			else{
				conv[k] = idx;
				rev[idx] = k;
				k = idx;
				idx++;
			}
			update(1,1,n,i,j,k);
		}
		else if(opc == 'b'){
			cin >> k;
			if(conv.find(k) != conv.end()){
				k = conv[k];
			}
			else{
				conv[k] = idx;
				rev[idx] = k;
				k = idx;
				idx++;
			}
			trash(k);
		}
		else if(opc == 'd'){
			cin >> i;
			int ans = query(i);
			if(ans == 0){
				cout << "si lo encuentro que te hago\n";
			}
			else if(ans == -1){
				cout << "para que quieres saber eso\n";
			}
			else{
				cout << rev[ans] << endl;
			}
		}
		else{
			cin >> i >> j;
			if(query(i) == query(j)) cout << "si\n";
			else cout << "no\n";
		}
	}
	return 0;
}