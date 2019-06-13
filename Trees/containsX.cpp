#include<iostream>
using namespace std;

bool containsX(TreeNode<int>* root, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    
    if(root==NULL)
        return false;
    
    TreeNode<int> *temp = root;
    
    if(x == temp->data )
        return true;
    
        
        for(int i=0;i<root->children.size();i++)
        {
           bool ans =  containsX(root->children[i],x);
            if(ans)
                return true;
        }
        
        return false;
        

}

