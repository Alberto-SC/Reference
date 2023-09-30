#include <bits/stdc++.h>
using namespace std;
class TextEditor {
public:
    struct cursor{
        cursor *next;
        cursor *prev;
        char letter;
        cursor(char c,cursor *p){
            letter = c;
            next = NULL;
            prev = p;
        }
        cursor(char c,cursor *n,cursor *p){
            letter = c;
            next = n;
            prev = p;
        }
        cursor(){
            letter = '$';
            next = NULL;
            prev = NULL;
        }
    };
    
    cursor *root;
    cursor *currentCursor;
    TextEditor() {
        root = new cursor();
        currentCursor = root;   
    }
    
    void addText(string text) {
        int idx = 0;
        cursor *nextChar = currentCursor->next;
        while(idx <text.size()){
            currentCursor->next = new cursor(text[idx],currentCursor);
            currentCursor = currentCursor->next;
            idx++;
        }
        currentCursor->next = nextChar;
        if(nextChar!=NULL){
            nextChar->prev = currentCursor;
        }
    }
    
    int deleteText(int k) {
        cursor *nextChar = currentCursor->next;
        int deleted = 0;
        while(k-- && currentCursor->prev!=NULL){
            currentCursor = currentCursor->prev;
            deleted++;
        }
        currentCursor->next = nextChar;
        if(nextChar!=NULL){
            nextChar->prev = currentCursor;        
        }
        return deleted;
    }
    
    string cursorLeft(int k) {
        while(k-- && currentCursor->prev!=NULL){
            currentCursor = currentCursor->prev;
        }
        int mn = 10;
        string result = "";
        cursor *aux = currentCursor;
        while(mn-- && aux->letter !='$'){
            result+=aux->letter;
            aux = aux->prev;
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    string cursorRight(int k) {
        while(k-- && currentCursor->next!=NULL){
            currentCursor = currentCursor->next;
        }
        int mn = 10;
        string result = "";
        cursor *aux = currentCursor;
        while(mn-- && aux->letter !='$'){
            result+=aux->letter;
            aux = aux->prev;
        }
        reverse(result.begin(),result.end());
        return result;
    }
    void print(){
        cursor * aux = root->next;
        while(aux!=NULL){
            cout<<aux->letter;
            aux = aux->next;
        }
        cout<<endl;
    }
};

int main(){
    TextEditor obj;
    cout<<obj.deleteText(9)<<endl;
    cout<<obj.cursorLeft(14)<<endl;
    obj.addText("mjzxkemqyvfrg");
    obj.print();
    cout<<obj.cursorLeft(5)<<endl;
    obj.addText("svvyobqebssp");
    obj.print();
    obj.addText("xkoznsq");
    obj.print();
    cout<<obj.cursorRight(3)<<endl;
    return 0;
}
// mjzxkemqsvvyobqebsspxkoznsqyvfrg
// ["TextEditor","deleteText","cursorLeft","addText","cursorLeft","addText","addText","cursorRight","cursorLeft","addText","cursorLeft","addText","cursorLeft","deleteText","addText","addText","cursorRight","cursorLeft","cursorLeft","deleteText","deleteText","deleteText","deleteText","deleteText","cursorLeft","addText","cursorRight","cursorLeft","addText","addText","addText","addText","cursorRight","cursorRight","cursorLeft","cursorLeft","addText","cursorRight","addText","addText","addText","addText","addText","addText","addText","deleteText"]
// [[],[9],[14],["mjzxkemqyvfrg"],[5],["svvyobqebssp"],["xkoznsq"],[3],[15],["irgkilfitjuysfgu"],[18],["aanfokhwqqjf"],[18],[7],["kjekmkypfqvbsyigry"],["opkmggjoxng"],[17],[1],[9],[16],[17],[2],[10],[5],[15],["bskjfptrqpg"],[1],[16],["dpuzcwbqotoihn"],["an"],["pntm"],["eamnglbbdnencdunao"],[12],[6],[5],[14],["utcyzkianwahi"],[4],["wcojk"],["yrfmlfvzev"],["ncpjvbv"],["ie"],["megbbxribprrsojsiofd"],["witgxkjntmvfvqjxitf"],["ifvhcabjla"],[10]]