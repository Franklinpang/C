#include <iostream>
using namespace std;

struct node{
    int data;
    node *prev, *next;
};

class dll{
    private:
    node *head;
    public:
    dll(){
        head = NULL;
    }
    void push(int n){
        node* temp = new node;
        temp -> data = n;
        if (head != NULL){
            temp -> prev = head -> prev;
            temp -> next = head;
            head -> prev = temp;
            head = temp;
        }else{
            temp -> prev = NULL;
            temp -> next = NULL;
            head = temp;
        }
        return;
    }
    void append(int n){
        node* temp = new node;
        temp -> data = n;
        if (head != NULL){
            node * p = head;
            while(p->next != NULL){
                p=p-> next;
            }
            p->next = temp;
            temp-> prev = p;
            temp-> next = NULL;
        }else{
            temp -> prev = NULL;
            temp -> next = NULL;
            head = temp;
        }
        return;

    }
    void reverse(){
        

    }
    void printDll(){
        node* temp = head;
        while(temp !=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        return;
    }
};

int main(){
    dll a;
    a.push(1);
    a.append(2);
    //a.push(3);
    a.append(4);
    a.push(3);
    a.printDll();
}