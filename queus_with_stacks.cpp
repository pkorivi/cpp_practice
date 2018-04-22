#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
/*Poor performance -  brute force*/
class MyQueue_old {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            //reverse exit queue
            while(!stack_oldest_on_top.empty()){
                stack_newest_on_top.push(stack_oldest_on_top.top());
                stack_oldest_on_top.pop();
            }
            //add new element
           stack_newest_on_top.push(x);

            //re arrange to exit queue
            while(!stack_newest_on_top.empty()){
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
        }

        void pop() {
            stack_oldest_on_top.pop();
        }

        int front() {
            return stack_oldest_on_top.top();
        }
};

/*
Good one--
Once you have populated your dequeue stack for performing either a pop or front operation, your dequeue stack is still in the right state for subsequent pop or top operations, 
until it's empty: only when it's empty you dequeue again to perform further pop or front operations.

*/

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
           stack_newest_on_top.push(x);
        }

        void pop() {
            if(stack_oldest_on_top.empty()){
                /*restock the pop queue*/
                while(!stack_newest_on_top.empty()){
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
            stack_oldest_on_top.pop();
        }

        int front() {
            if(stack_oldest_on_top.empty()){
                /*restock the pop queue*/
                while(!stack_newest_on_top.empty()){
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

