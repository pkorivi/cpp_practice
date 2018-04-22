
Works:::::::::::
    bool check_node(Node* base,int min,int max){
        if(base == NULL)
            return 1;
        
        if(base->data < min || base->data >max){
            return 0;
        }
        return (check_node(base->left,min,base->data-1) && check_node(base->right,base->data+1,max));    
    }



Does not work:::::::::::::::::
   bool check_node(Node* base,int min,int max){
        if(base!= NULL){
            if(base->data < min || base->data >max){
                return 0;
            }
            else{
             if((check_node(base->left,min,base->data-1)) && check_node(base->right,base->data+1,max))
                    return 1;   
            }
        }
        return 1;
   }
        


########Final COde

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
    bool check_node(Node* base,int min,int max){
        if(base == NULL)
            return 1;
        
        if(base->data < min || base->data >max){
            return 0;
        }
        return (check_node(base->left,min,base->data-1) && check_node(base->right,base->data+1,max));    
    }
   bool checkBST(Node* root) {
        return check_node(root,0,10000);   
   }
