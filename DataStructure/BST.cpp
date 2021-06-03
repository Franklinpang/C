#include <iostream>
#include <queue>
using namespace std;

struct node{
    node(int value):data(value), left(NULL), right(NULL){}
    int data;
    node* left, *right;
};

class bst{
    private:
    node* _root;
    void insert(node* root, int data);
    bool search(node* root, int data);
    int findMin(node* root);
    int findHeight(node* root);
    //Breath first traversal with Queue
    void bTraversal(node* root);
    //Depth first traversal with recrusive, and possible with stack.
    void preOrder(node* root);
    void inOrder(node* root);
    void postOrder(node* root);
    bool isBST(node* root, int max, int min);
    //void deleteNode(node* root, int data);

    public:
    bst(){_root = NULL;}
    void insert(int data);
    bool search(int data){return search(_root, data);}
    int findMin(){return findMin(_root);}
    int findHeight(){return findHeight(_root);}
    void bTraversal(){bTraversal(_root);cout << endl;}
    void preOrder(){preOrder(_root);cout << endl;}
    void inOrder(){inOrder(_root);cout << endl;}
    void postOrder(){postOrder(_root);cout << endl;}
    bool isBST(){return isBST(_root, INT32_MAX, INT32_MIN );}
    //void deleteNode(int data){deleteNode(_root, data);}
    void bstPrint();
};

void bst::insert(node* root, int data){
    if(root ==NULL){
        root = new node(data);
    }else{
        if(data <= root->data){
            if (root -> left ==NULL){
                root -> left = new node(data);
            }else{
                insert (root -> left, data);
            }
        }else{
            if (root -> right ==NULL){
                root -> right = new node(data);
            }else{
                insert (root -> right, data);
            }
        }
    }
}

void bst::insert(int data){
    if (_root ==NULL){
        _root = new node(data);
        cout << "first node - address: " << _root << "; data: " << (_root -> data) << endl;
    }else{
        insert(_root, data);
    }
}

bool bst::search(node* root, int data){
    if(root == NULL){
        return false;
    }else if (data == root -> data){
        return true;
    }else if (data <= root -> data){
        return search(root -> left, data);
    }else{
        return search(root -> right, data);
    }
}

int bst::findMin(node* root){
    if (root == NULL){
        return -1;
    }else if (root -> left ==NULL){
        return root -> data;
    }else{
        return findMin(root -> left);
    }
}

int bst::findHeight(node* root){
    if (root == NULL){
        return -1;
    }else{
        return (max(findHeight(root -> left), findHeight(root -> right))+1);
    }
}

void bst::bTraversal(node* root){
    if(root ==NULL){cout << "empty bst" << endl;return;}
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        node* current = Q.front();
        if(current -> left != NULL){Q.push(current -> left);}
        if(current -> right != NULL){Q.push(current -> right);}
        cout << current->data << " ";
        Q.pop();
    }
}

void bst::preOrder(node* root){
        if(root ==NULL){
        cout << "empty bst" << endl;
    }else{
        cout << root -> data << " ";
        if(root -> left != NULL){preOrder(root -> left);}
        if(root -> right != NULL){preOrder(root -> right);}
    }
}

void bst::inOrder(node* root){
        if(root ==NULL){
        cout << "empty bst" << endl;
    }else{
        if(root -> left != NULL){inOrder(root -> left);}
        cout << root -> data << " ";
        if(root -> right != NULL){inOrder(root -> right);}
        
    }
}

void bst::postOrder(node* root){
        if(root ==NULL){
        cout << "empty bst" << endl;
    }else{
        if(root -> left != NULL){postOrder(root -> left);}
        if(root -> right != NULL){postOrder(root -> right);}
        cout << root -> data << " ";
    }
}

bool bst::isBST(node* root, int max, int min){
    if(root ==NULL){return true;}
    if(root -> data < max &&
       root -> data >= min &&
       isBST(root -> left, root-> data, min) &&
       isBST(root -> right, max, root -> data)){
           return true;
       }else{
           return false;
       }
}

void bst::bstPrint(){
    cout << "Root - address: " << _root << "; data: " << _root -> data << endl;
    cout << "Left - address: " << _root -> left << endl;
    cout << "Right - address: " << _root -> right << endl;
}

int main(){
    bst a;
    a.insert(4);
    a.insert(2);
    a.insert(6);
    a.insert(1);
    a.insert(3);
    a.insert(5);
    a.insert(7);
    cout << a.search(2) << endl;
    cout << a.search(3) << endl;
    cout << a.findMin() <<endl;
    cout << a.findHeight() << endl;
    a.preOrder();
    a.inOrder();
    a.postOrder();
    a.bTraversal();
    cout << a.isBST()<<endl;
    a.bstPrint();
}
