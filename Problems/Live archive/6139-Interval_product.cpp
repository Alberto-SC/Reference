#include <stdio.h> 
#include <math.h> 
#include <iostream>
using namespace std;

int helper(int a){

    return a;
}
int getMid(int s, int e){  return s + (e -s)/2;  } 
long long int getSumUtil(long long int *st, int ss, int se, int qs, int qe, int si) { 
    if (qs <= ss && qe >= se) 
        return st[si]; 
    if (se < qs || ss > qe) 
        return 0;
    int mid = getMid(ss, se); 
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) * 
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2); 
} 
void updateValueUtil(long long int *st, int ss, int se, int i, int diff, int si) { 
    if (i < ss || i > se) 
        return; 
    if(diff)
    st[si] -= st[si] * diff;
    else 
    st[si] += st[si] * diff; 
    if (se != ss) 
    { 
        int mid = getMid(ss, se); 
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1); 
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2); 
    } 
} 
void updateValue(int arr[], long long int *st, int n, int i, int new_val) { 
    if (i < 0 || i > n-1) 
    { 
        printf("Invalid Input"); 
        return; 
    } 
    int diff = new_val - arr[i]; 
    arr[i] = new_val; 
    updateValueUtil(st, 0, n-1, i, diff, 0); 
} 
long long int getSum(long long int *st, int n, int qs, int qe) { 
    if (qs < 0 || qe > n-1 || qs > qe) { 
        return 1; 
    } 
    return getSumUtil(st, 0, n-1, qs, qe, 0); 
} 
long long int constructSTUtil(int arr[], int ss, int se, long long int *st, int si) { 
    if (ss == se) { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
    int mid = getMid(ss, se); 
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) * 
              constructSTUtil(arr, mid+1, se, st, si*2+2); 
    return st[si]; 
}
long long int *constructST(int arr[], int n) { 
    int x = (int) (ceil(log2(n)));  
    int max_size = 2*(int)pow(2, x) - 1;  
    long long int *st = new long long int[max_size]; 
    constructSTUtil(arr, 0, n-1, st, 0); 
    return st;
}
int main(){
    int n,k,a,b,x;
    char com;
    while(cin>>n>>k){

    int arr[n];
    long long int *st = constructST(arr, n); 
    for(int i = 0;i<n;i++){
        cin>>x;
        if(x) arr[i] = 1;
        else if(x<0) arr[i] = -1;
        else arr[i] = 0; 
    }
    for(int i = 0;i<k;i++){
        cin>> com;
        if(com == 'C'){
            cin>>a>>b;
            updateValue(arr,st, n , a-1, b-1);
        }
        if(com == 'P'){
            cin>>a>>b;
            int s = getSum(st,n,a-1,b-1);
            if(s> 0)cout<<"+"<<endl;
            if(s == 0)cout<<"0"<<endl;
            else cout<<"-"<<endl;
        }

    }
    }
    return 0; 
} 