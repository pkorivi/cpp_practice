/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head == NULL)
        return 0;
    
    Node* sp = head; 
    Node* fp = head->next;
    while(sp != fp){
        if(sp==NULL || fp==NULL || fp->next == NULL){
            return 0;
        }
        sp = sp->next;
        fp = fp->next->next;
    }
        
    return 1;
}


/*
Maximum loop will be rotated twice
as fp moves twice faster than sp, lets say there is loop from 6->1 then by the time sp reaches 6 lp will also reach 6. 
sp 0,1,2,3,4,5,6
lp 1,3,5,0,2,4,6
*/
