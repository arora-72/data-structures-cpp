void maxSum(TreeNode<int>* a, TreeNode<int>** b, int* c);

void maxSum(TreeNode<int>* root, TreeNode<int>** resNode, int* maxSumInt)
{
    if(root==NULL)
        return;
    
    int currSum=root->data;
    
    for(int i=0;i<root->children.size();i++)
    {
        currSum+=root->children[i]->data;
        maxSum(root->children[i],resNode,maxSumInt);
    }
    
    
    if(currSum>*maxSumInt)
    {
        *resNode = root;
        *maxSumInt = currSum;
    }
    
    return;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){

    if (root==NULL)
        return NULL;
    
    TreeNode<int>* resNode;
    int maxSumInt = 0;
    
    maxSum(root,&resNode,&maxSumInt);
    
    return resNode;
    
    
}