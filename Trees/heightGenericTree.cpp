
int height(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    if(root==NULL)
        return 0;
    
    
    int maxDepth = 0;
    
    for(int i=0; i<root->children.size();i++){
        maxDepth = max(maxDepth, height(root->children[i]));
        
    }
    
    return maxDepth + 1;
}