#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
vector<string> pos[10];
void getall(int num,string here){
    int number = stoi(here);
    if(here.size()>5)return;
    nums.push_back(number);
    for(auto c:pos[num]){
        getall(stoi(c),here+c);
    }
}
int main(){
    int t,n;
    pos[1].push_back("2");
    pos[1].push_back("1");
    pos[1].push_back("3");
    pos[1].push_back("4");
    pos[1].push_back("5");
    pos[1].push_back("6");
    pos[1].push_back("7");
    pos[1].push_back("8");
    pos[1].push_back("9");
    pos[1].push_back("0");
    pos[2].push_back("3");
    pos[2].push_back("2");
    pos[2].push_back("5");
    pos[2].push_back("6");
    pos[2].push_back("8");
    pos[2].push_back("9");
    pos[2].push_back("0");
    pos[3].push_back("6");
    pos[3].push_back("3");
    pos[3].push_back("9");
    pos[4].push_back("5");
    pos[4].push_back("6");
    pos[4].push_back("4");
    pos[4].push_back("7");
    pos[4].push_back("8");
    pos[4].push_back("9");
    pos[4].push_back("0");
    pos[5].push_back("6");
    pos[5].push_back("5");
    pos[5].push_back("8");
    pos[5].push_back("9");
    pos[5].push_back("0");
    pos[6].push_back("9");
    pos[6].push_back("6");
    pos[7].push_back("8");
    pos[7].push_back("7");
    pos[7].push_back("9");
    pos[7].push_back("0");
    pos[8].push_back("9");
    pos[8].push_back("8");
    pos[8].push_back("0");
    pos[9].push_back("9");
    pos[0].push_back("0");
    for(int i = 0;i<10;i++){
        getall(i,to_string(i));
    }
    // cout<<nums.size()<<endl;
    sort(nums.begin(),nums.end());
    cin>>t;
    while(t--){
        cin>>n;
        int index = lower_bound(nums.begin(),nums.end(),n)-nums.begin();
        if(nums[index]==n)cout<<n<<endl;
        else {
            int num1 = nums[index];
            int num2;
            index>0?num2= nums[index-1]:num2 =num1;
            // cout<<num1<<" "<<num2<<endl;
            if(abs(n-num1)<abs(n-num2))cout<<num1<<endl;
            else if(abs(n-num1)== abs(n-num2))cout<<num2<<endl;
            else cout<<num2<<endl;
        }
    }
    return 0;
}