/*

Second Largest Element In Tree
Send Feedback
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Second Largest node data
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40

*/


void secondLargestUtil(TreeNode<int>* root, TreeNode<int>** first, TreeNode<int>** second)
{
    
    //base condition
    if(root==NULL)
        return;
    
    //other conditions
    if(!(*first))
        *first = root;
    
    else if (root->data > (*first)->data){
        *second = *first;
        *first = root;
    }
    
    else if(!(*second) || root->data>(*second)->data)
    {
        if(root->data!=(*first)->data)
            *second = root;
    }
        
    
    
    //recursion
    int numChild = root->children.size();
    
    for(int i=0;i<numChild;i++){
        secondLargestUtil(root->children[i],first,second);
    }
}



    
    
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    TreeNode<int>* second = NULL;
    TreeNode<int>* first = NULL;
    
    secondLargestUtil(root, &first, &second);
    
    if(second==NULL)
        return NULL;
    
    
    //if all elements are same
    if(first->data == second->data)
        return NULL;
    
    
    return second;
    
    
}
