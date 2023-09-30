#include <bits/stdc++.h>
using namespace std;

const int maxn = 100007;

struct N {
    int t;    
    int n;    
};

vector<int> Vy(maxn+1);      
vector<N> otros(maxn);
int nT=0, nB=0;

int compareNode(const N a,const N b) {
  return a.t > b.t;
}

int sortAndCompressB(int n){
    if (n == 0)
        return 0;
    sort(otros.begin(),otros.end(),compareNode);
    int j = 0;
    for(int i=1; i<n; i++) {
        if (otros[i].t == otros[j].t)
            otros[j].n++;
        else {
            j++;
            otros[j] = otros[i];
        }
    }
    return j+1;
}

int main(){
    int s, n;
    cin >> s >> n;
    for(int i=0; i<n; i++) {
        int t;
        char ch;
        cin >> t >> ch;
        if (ch == 'y')
            Vy[nT++] = t;
        else {
            otros[nB].t = t;
            otros[nB].n = 1;
            nB++;
        }
    }
    sort(Vy.rbegin(),Vy.rend());
    bool flag = false;
    int t = Vy[0]-1;
    for(int i=1; i<nT; i++) {
        if(t == 0){
            flag = true;
            break;
        }
        else if(t>=Vy[i])
            t = Vy[i]-1;
        else{
            Vy[i] = t;
            t--;
        }
    }
    if(flag){
        cout<<"No"<<endl;
    }
    else {                                 
        nB = sortAndCompressB(nB);
        Vy[nT] = 0;
        int nextT = 0;
        int nextB = 0;
        int currT = otros[nextB].t;
        int nAvail = s;
        while (nextB < nB) {
            if (currT == 0) {
                flag = true;
                break;
            }
            if (currT > otros[nextB].t)
                currT = otros[nextB].t;
            while (Vy[nextT] > currT)
                nextT++;
            if (Vy[nextT] == currT) {   
                nAvail--;
                nextT++;
            }
            if (nAvail < otros[nextB].n) {
                otros[nextB].n -= nAvail;
            }
            else
                nextB++;
            currT--;
            nAvail = s;
        }
        if(flag)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
}
