#include<bits/stdc++.h>  
using namespace std;  
int A[400][400];
int R,C;
int maxHist(int row[]){ 
    stack<int> result; 
    int top_val;
    int max_area = 0;
  
    int area = 0;  
    int i = 0; 
    while (i < C) { 
        if (result.empty() || row[result.top()] <= row[i]) 
            result.push(i++); 
        else { 
            top_val = row[result.top()]; 
            result.pop(); 
            area = top_val * i; 
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1); 
            max_area = max(area, max_area); 
        } 
    } 
    while (!result.empty()) { 
        top_val = row[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1); 
  
        max_area = max(area, max_area); 
    } 
    return max_area; 
} 

int minHist(int row[]){ 
    stack<int> result; 
    int top_val;
    int max_area = 100000000;  
    int area = 0;  
    int i = 0; 
    while (i < C) { 
        if (result.empty() || row[result.top()] <= row[i]) 
            result.push(i++); 
        else { 
            top_val = row[result.top()]; 
            result.pop(); 
            area = top_val * i; 
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1); 
            max_area = min(area, max_area); 
        } 
    } 
    while (!result.empty()) { 
        top_val = row[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1); 
  
        max_area = min(area, max_area); 
    } 
    return max_area; 
} 
 
  
int maxRectangle(){ 
    int result = maxHist(A[0]); 
    for (int i = 1; i < R; i++) {   
        for (int j = 0; j < C; j++) 
            if (A[i][j]) 
                A[i][j] += A[i - 1][j]; 
        result = max(result, maxHist(A[i])); 
    }   
    return result; 
} 
int minRectangle(){ 
    int result = minHist(A[0]); 
    for (int i = 1; i < R; i++) {   
        for (int j = 0; j < C; j++) 
            if (A[i][j]) 
                A[i][j] += A[i - 1][j]; 
        result = min(result, minHist(A[i])); 
    }   
    return result; 
} 
int main(){
    cin>>R>>C;
    char l;
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            cin>>l;
            if(l =='X')
                A[i][j] = 1;
            else A[i][j] = -1;
        }
    }  
    cout<<maxRectangle()<<endl;
    cout<<minRectangle()<<endl;
    // cout<<findMax(r,c)<<endl;
  
    return 0;  
}  