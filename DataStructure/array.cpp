//https://www.educative.io/blog/cracking-top-facebook-coding-interview-questions
//Arrays: move zeros to the left

#include<iostream>
using namespace std;

int a[] = {1,10,20,0,59,63,0,88,0};
int lenth = sizeof(a)/sizeof(int);

void move_zero_left (int index){
   if(index ==0){
       return;
   }
   
   if(a[index] == 0){
       for(int i=index; i>0; i--){
           a[i] = a[i-1];
       }
       a[0]=0;
   }
    index = index -1;
    move_zero_left(index);
   }

void print_a(int* a){
    for (int i=0; i<lenth; i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

int main(){
    print_a(a);
    move_zero_left (lenth);
    print_a(a);
}