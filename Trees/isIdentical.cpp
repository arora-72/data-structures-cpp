bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    if(root1==NULL || root2==NULL)
        return false;
    
    bool answer=true;
    
    TreeNode<int>* temp1 = root1;
    TreeNode<int>* temp2 = root2;
    
    if(temp1->children.size() != temp2->children.size())
        answer = false;
    else{
    for(int i=0;i<temp1->children.size();i++)
    {
        if(temp1->children[i]->data != temp2->children[i]->data)
            answer = false;
        
        answer = isIdentical(temp1->children[i],temp2->children[i]);
        
    }
    }
    
    return answer;
    

}