#include <iostream>
#include <vector>
#include<queue>
#include<bits/stdc++.h>


using namespace std;


template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};





TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    if(root == NULL)
        return;

    TreeNode<int> *currNode = root;
    queue<TreeNode<int>*> temp;

    temp.push(root);

    while(!temp.empty()){
        TreeNode<int> * currNode = temp.front();
        temp.pop();
        cout<<currNode->data<<":";

        for(int i=0;i<currNode->children.size();i++)
            cout<<currNode->children[i]->data;
        
        for( i < currNode->children.size()-1)
            cout<<",";
        
        temp.push(currNode->children[i]);
    }

    cout<<endl;
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}

