
int nodesGreaterThanX(TreeNode<int> *root, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    if(root==NULL)
        return 0;
    
    int count=0;
    
    if(root->data > x)
        count++;
    
    for(int i=0;i<root->children.size();i++){
        count += nodesGreaterThanX(root->children[i], x);
    }
    
    
    return count;
    
        
}

