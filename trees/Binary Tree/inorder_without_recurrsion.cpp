// C++ program to print inorder traversal 
// using stack. 
#include<bits/stdc++.h> 
using namespace std; 
  
/* A binary tree Node has data, pointer to left child 
   and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
/* Iterative function for inorder tree 
   traversal */
void inOrder(struct Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right; 
  
    } /* end of while */
} 
/* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
  Note that right child is pushed first so that left is processed first */  

void iterativePreorder(Node *root) 
{ 
    if (root == NULL) return; 
  
    stack<Node *> nodeStack; 
    nodeStack.push(root); 
  
    while (nodeStack.empty() == false) 
    { 
        struct Node *node = nodeStack.top(); 
        printf ("%d ", node->data); 
        nodeStack.pop(); 
  
        if (node->right) 
            nodeStack.push(node->right); 
        if (node->left) 
            nodeStack.push(node->left); 
    } 
}   

/* Driver program to test above functions*/
int main() 
{ 
  
    /* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
  
    printf("inorder :");
    inOrder(root); 
    printf("preorder :");
    iterativePreorder(root); 

    return 0; 
} 