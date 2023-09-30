#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double ld;
#define x first 
#define y second
ld Grados_radianes(ld grd) {
  return (grd * M_PI) / 180.0;
}
pair<int,int> RotarCW(int x,int y,int g){
    ld t = Grados_radianes((ld)g);
    return {(int)round(x*cos(t) + y*sin(t)),(int)round(y*cos(t) - x*sin(t))};
}
pair<int,int> RotarCCW(int x,int y,int g){
    ld t = Grados_radianes((ld)g);
    return {(int)round(x*cos(t) - y*sin(t)),(int)round(y*cos(t) + x*sin(t))};
}
int main(){
    string s;
    vector<pair<char,int>> nums;
    char z;
    int num;
    while(cin>>z>>num){
        nums.push_back({z,num});
    }
    int a = 0,b = 0;
    int n = nums.size();
    int dir = 0;
    pair<int,int> waypoint = {1,10};
    for(int i = 0;i<n;i++){
        if(nums[i].x =='N')
            waypoint.x+=nums[i].y;
        if(nums[i].x =='S')
            waypoint.x-=nums[i].y;
        if(nums[i].x =='E')
            waypoint.y+=nums[i].y;
        if(nums[i].x =='W')
            waypoint.y-=nums[i].y;
        if(nums[i].x == 'L')
            tie(waypoint.x,waypoint.y) = RotarCW(waypoint.x,waypoint.y,nums[i].y);
        if(nums[i].x == 'R')
            tie(waypoint.x,waypoint.y) = RotarCCW(waypoint.x,waypoint.y,nums[i].y);
        if(nums[i].x == 'F')
            a+=nums[i].y*waypoint.x,
            b+=nums[i].y*waypoint.y;
    }
    cout<<abs(a)+abs(b)<<endl;
    return 0;
}