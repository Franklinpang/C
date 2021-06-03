//https://www.educative.io/blog/cracking-top-facebook-coding-interview-questions
//Strings: Reverse words in a sentence
#include<iostream>
using namespace std;

char word[] = "Franklin";
int head =0;
int tail = sizeof(word)/sizeof(char) -2;

void printW(){
    cout << word<<endl;
}
void revString (int head, int tail){
    if(head>=tail){return;}
    char temp = word[head];
    word[head] = word[tail];
    word[tail] = temp;
    printW();
    head++;
    tail--;
    revString(head, tail);
}

int main(){
    printW();
    cout<<head<<endl;
    cout<<tail<<endl;
    revString(head, tail);
    printW();

}