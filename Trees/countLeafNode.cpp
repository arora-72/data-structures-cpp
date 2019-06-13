int numLeafNodes(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    if (root==NULL)
        return 0;
    
    TreeNode<int>* temp = root;
    int answer = 0;
    if(root->children.size()==0)
        return 1;
    else
        for(int i=0;i<root->children.size();i++){
            answer = answer + numLeafNodes(root->children[i]);
        }
    
    return answer;
}

