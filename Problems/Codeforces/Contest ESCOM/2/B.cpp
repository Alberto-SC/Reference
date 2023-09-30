#include <bits/stdc++.h>
using namespace std;
#define MAXN 1003
char input[MAXN][MAXN];
void sol(int ul, int si, int index) {
	if (si < ul) return;
	if (ul == si) 
		cout<<input[ul]+index<<endl;
	else{
		int last = ul;
		for(int i=ul; i<=si; i++) {
			if (input[i][index] != input[last][index] || (input[i][index] != '*' && input[i][index] != '#')){
				if (i > last) {
					if (index > 0) cout<<"<l        i>\n";
					if (input[last][index] == '*' && i-1>last) cout<<"<ul>\n";
					if (input[last][index] == '#' && i-1>last) cout<<"<ol>\n";
					sol(last, i-1, index+(i-1>last));
					if (input[last][index] == '*' && i-1>last) cout<<"</ul>\n";
					if (input[last][index] == '#' && i-1>last) cout<<"</ol>\n";
					if (index > 0) cout<<"</li>\n";
				}
				last = i;
			}
		}
		if (index > 0) cout<<"<li>\n";
		if (input[last][index] == '*' && si>last) cout<<"<ul>\n";
		if (input[last][index] == '#' && si>last) cout<<"<ol>\n";
		sol(last, si, index+(si>last));
		if (input[last][index] == '*' && si>last) cout<<"</ul>\n";
		if (input[last][index] == '#' && si>last) cout<<"</ol>\n";
		if (index > 0) cout<<"</li>\n";
	}
    return;
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n = 0;
	while(cin>>input[n++]);
	sol(0, n-1, 0); 
    fclose(stdin);
	fclose(stdout);
	return 0;
}