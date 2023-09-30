#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
    int n;
    while(1){
        cin>>n;
        if(!n)break;
        queue<int> discarded;
        queue<int> current;
        for(int i = 1;i<=n;i++)
            current.push(i);

        while(current.size()>1){
            discarded.push(current.front());
            current.pop();
            int front = current.front();
            current.push(front);
            current.pop();
        }
        cout<<"Discarded cards: ";
        while(!discarded.empty()){
            cout<<discarded.front();
            discarded.pop();
            if(!discarded.empty())
                cout<<", ";
        }
        cout<<endl;
        cout<<"Remaining card: "<<current.front()<<endl;
    }
    return 0;
}