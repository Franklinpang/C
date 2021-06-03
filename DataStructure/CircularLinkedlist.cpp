#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class circular_ll{
    private:
    node* tail;
    public:
    circular_ll(){
        tail = NULL;
    }
    void addToEmpty(int n){
        if (tail != NULL){
            return;
        }
        node* temp = new node;
        temp -> data = n;
        temp -> next = temp;
        tail = temp;  
        return; 
    }
    void addToBegin(int n){
        if (tail == NULL){
            addToEmpty(n);
            return;
        }
        node* temp = new node;
        temp -> data = n;
        temp -> next = tail -> next;
        tail -> next = temp;
        return;   
    }
    void addToEnd(int n){
        if (tail == NULL){
            addToEmpty(n);
            return;
        }
        node* temp = new node;
        temp -> data = n;
        temp -> next = tail -> next;
        tail -> next = temp;
        tail = temp;
        return; 
    }
    void addAfter(int n, int item){
        if (tail == NULL){
            addToEmpty(n);
            return;
        }
        node* temp = new node;
        temp -> data = n;
        node* loc = tail -> next;
        while (loc -> data !=item){
            if (loc ==tail){
                addToEnd(n);
                return;
            }
            loc = loc -> next;
        }
        temp -> next = loc -> next;
        loc -> next = temp;
        return; 
    }
   
    void traversal(){
        node* p1, *p2;
        p1 = tail -> next;
        p2 = p1 -> next;
        p1 -> next = tail;

        



    }
    void sort(){
        //reverse the ll;
    }
    int count(){
        int count =1;
        node* temp = head -> next;
        while (temp !=head){
            count ++;
            temp = temp -> next;
        }
        return count;
    }

    void printCLL(){
        if (head == NULL){
            return;
        }else{
            node* temp = head -> next;
            cout << head-> data;
            temp = temp -> next;
            while (temp !=head){
                cout << temp -> data << endl;
                temp = temp -> next;
            }
            return;
        }
    }
};

int main(){
    circular_ll c;
    c.insert(1,1);
    c.insert(1,2);
    //c.insert(1,3);
    //c.insert(1,4);
    c.printCLL();
    return 0;

}