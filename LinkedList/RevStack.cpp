#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
stack<int> s;
void ReverseStack(){
    if(s.empty()){
        return;
    }
    int a;
    stack<int> newStack;
    while(!s.empty()){
        a=s.top();
        s.pop();
        newStack.push(a);
    }
    s=newStack;
}
//bad implementation
void print(){
   while(!s.empty()){
       cout<<s.top()<<"->";
       s.pop();
   }
}

int main(){
   
    s.push(30);
    s.push(28);
    print();
    ReverseStack();
    print();
    return 0;
}