int sumOfNodes(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically. 
     */
    int ans = root->data;
    for(int i=0;i<root->children.size();i++)
    {
        ans += sumOfNodes(root->children[i]);
    }
    
    return ans;
    
    
}

