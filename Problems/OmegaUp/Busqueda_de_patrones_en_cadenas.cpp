#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
void computeLPSarray(string pat, int M, int *lps){
    int len = 0;   
    int i ;
    lps[0] = 0 ;    
    i = 1;
    while(i <  M)   {
        if(pat[i] == pat[len])  {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0){
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    int *lps = (int*)malloc(M*sizeof(int));
    int j = 0;

    computeLPSarray(pat, M, lps);
    
    int i = 0;
    while(i < N)
    {
        if(pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if(j == M)
        {
            printf("%d\n",(i - j)+1);
            j = lps[j-1];
        }
        else if(pat[j] != txt[i])
        {
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    free(lps);
}

int main()
{
    string txt;
    string pat;
    cin>>txt;
    cin>>pat;
    KMPSearch(pat, txt);
    return 0;
}