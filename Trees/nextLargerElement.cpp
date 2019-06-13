/*

Next larger
Send Feedback
Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.
Return NULL if no node is present with the value greater than n.
Input Format :
Line 1 : Integer n
Line 2 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Node with value just greater than n.
Sample Input 1 :
18
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
20
Sample Input 2 :
21
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 2:
30


 */



void util(TreeNode<int>* root, TreeNode<int>**resNode, int n)
{
    if(root==NULL)
        return;
    
    if(root->data > n){
        if(!*resNode || (*resNode)->data > root->data)
            *resNode = root;
    }
    
    int numChild = root->children.size();
    
    for(int i=0;i<numChild;i++){
        util(root->children[i], resNode, n);
    }
}

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

   
    
    
    if(root==NULL)
        return NULL;
    
    TreeNode<int>* resNode = NULL;
    
    util(root, &resNode, n);

        return resNode;
    
    
}

