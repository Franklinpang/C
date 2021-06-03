#include <iostream>
 using namespace std;

struct node {
    int data;
    node* next;
};

class linked_list{
    private:
    node* head, *tail;
    public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }
    void add_node(int n){
        node* tmp = new node;
        tmp -> data = n;
        tmp -> next = NULL;

        if (head == NULL){
            head = tmp;
            tail = tmp;
        }else{
            tail-> next =tmp;
            tail=tmp;
        }

    }
    void swap(int x, int y){
        node* tempx = head;
        node* tempy = head;
        if (x==y){
            return;
        }else{
            while (tempx->data !=x){
                tempx = tempx -> next;
            }
            while (tempy->data !=y){
                tempy = tempy -> next;
            }
            tempx -> data = y;
            tempy -> data = x;
            return;
        }
    }
    void reverse(){
        node * post, *current, *pre;
        post = NULL;
        current = head;
        while(current !=NULL){
            pre = current-> next;
            current -> next = post;
            post = current;
            current = pre;
            //pre = current-> next;
        }
        head = post;
        return;
    }

    void reverse1(){
        node* temp = head;
        recursive(temp);
    }
    void recursive(node* current){
        if (current-> next == NULL){
            head = current;
            return;
        }
        recursive(current -> next);
        current -> next -> next = current;
        current -> next =NULL;
    }

    int getcount(){
        int count =0;
        node* temp = head;
        while (temp !=NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    }
    void printList(){
        node* temp = head;
        while (temp != NULL){
            cout << temp->data << ' ';
            temp=temp->next;
        }
        cout<<endl;
    }
    void sort(){
            cout << "Impletment Sort function" << endl;
            return;
    }
};

int main(){
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.add_node(5);
    a.swap (1,3);
    a.printList();
    cout << a.getcount() << endl;
    a.reverse();
    a.printList();
    a.reverse1();
    a.printList();
    return 0;
}