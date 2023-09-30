#include <bits/stdc++.h>

using namespace std;
#define MAX 100020
int KP[MAX];
void Ss(char *P){
    int i, j;
    KP[0] = -1;
    for(i=1,j=-1; P[i]; i++) {
        while(j >= 0 && P[j+1] != P[i])
            j = KP[j];
        if(P[j+1] == P[i])
            j++;
        KP[i] = j;
    }
}

int KMP(char *S, char *P)	{
    int i, j;
    Ss(P);
    for(i = 0, j = -1; S[i]; i++){
        while(j >= 0 && P[j+1] != S[i])
            j = KP[j];
        if(P[j+1] == S[i])
            j++;
    }
    return j;
}
 
int main(){
	char S[MAX];
    char SC[MAX];
    while(scanf("%s", S) == 1){
    	int len = strlen(S);
        for(int i=0,j=len-1; i<len;i++,j--) {
            SC[i] = S[j];
        }
        SC[len] = '\0';
    	int cut = KMP(S,SC);
        cout<<S;
        for(int i = cut + 1; i <= len - 1; i++)
            cout<<SC[i];
        cout<<endl;
    }
 
    return 0;
}