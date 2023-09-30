// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli rand(lli a, lli b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); 
    lli t,n;
    t = rand(1,10);
    vector<char> pos(4);
    pos[0] = 'A';
    pos[1] = 'C';
    pos[2] = 'T';
    pos[3] = 'G';
    while(t--){
        int n = rand(10,100);
        int m = rand(10,100);
        for(int i= 0;i<n;i++)
            cout<<pos[rand(0,3)];
        cout<<endl;
        for(int i= 0;i<m;i++)
            cout<<pos[rand(0,3)];        
        cout<<endl<<endl;
    }
}
    
