#include <bits/stdc++.h>
using namespace std;

typedef complex <double> CD;

const int N = 5e5;
const long double PI = acos(-1.0);

char s[N], t[N];
int p[10][N];
int sum[N], rev[N];
CD v1[N], v2[N];

int find(int x, int id){
	return x == p[x][id] ? x : p[x][id] = find(p[x][id], id);
}

bool same(int x, int y, int id){
	return find(x, id) == find(y, id);
}

void unite(int x, int y, int id){
	int fx = find(x, id), fy = find(y, id);
	p[fy][id] = fx;
}

void Fast_Fourier_Transform(CD *a, int n, bool inverse){
	for (int i = 0; i < n; i++){
		if (rev[i] > i) swap(a[i], a[rev[i]]);
	}
	double pi = inverse ? -PI : PI;
	for (int step = 1; step < n; step <<= 1){
		double alpha = pi / step;
		for (int k = 0; k < step; k++){
			CD omegak = exp(CD(0, alpha * k));
			for (int Ek = k; Ek < n; Ek += (step << 1)){
				int Ok = Ek + step;
				CD t = omegak * a[Ok];
				a[Ok] = a[Ek] - t;
				a[Ek] += t;
			}
		}
	}
	if (inverse){
		for (int i = 0; i < n; i++) a[i] /= n;
	}
}

int main(){
	int n, m, sz, ans;
	scanf("%s", s);
	n = strlen(s);
	scanf("%s", t);
	m = strlen(t);
	sz = 2;
	while (sz < n + m) sz <<= 1;
	for (int i = 0, j = 0; i < sz; i++){
		rev[i] = j;
		int k = sz;
		while (j & (k >>= 1)) j &= ~k;
		j |= k;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++){
			p[j][i] = j;
		}
	}
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (i == j) continue;
			for (int k = 0; k < sz; k++) v1[k] = v2[k] = (CD){0.0, 0.0};
			for (int k = 0; k < n; k++){
				if (s[k] == 'a' + i) v1[k] = (CD){1.0, 0.0};
			}
			for (int k = 0; k < m; k++){
				if (t[k] == 'a' + j) v2[m - k - 1] = (CD){1.0, 0.0};
			}
			Fast_Fourier_Transform(v1, sz, false);
			Fast_Fourier_Transform(v2, sz, false);
			for (int i = 0; i < sz; i++) v1[i] *= v2[i];
			Fast_Fourier_Transform(v1, sz, true);
			for (int k = 0; k < n; k++){
				if (v1[k].real() > 0.1){
					if (!same(i, j, k)){
						unite(i, j, k);
						sum[k]++;
					}
				}
			}
		}
	}
	for (int i = m - 1; i < n; i++) printf("%d ", sum[i]);
	printf("\n");
	return 0;
}