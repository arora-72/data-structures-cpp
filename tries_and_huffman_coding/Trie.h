// #include "TrieNode.h"
#include <string>

/***************
 * Main function - 
 
int main() {
    int choice;
    cin >> choice;
    Trie t;
    
    //cout << "asasas";
    while(choice != -1){
        string word;
        bool ans;
        switch(choice) {
            case 1 : // insert
                // getline(cin, word);
                cin >> word;
                t.insertWord(word);
                break;
            case 2 : // search
                // getline(cin, word);
                cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            default :
                return 0;
        }
        cin >> choice;
    }
    return 0;
}
 **************/

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        // Recursive call
        insertWord(child, word.substr(1));
    }
    
    // For user
    void insertWord(string word) {
        insertWord(root, word);
    }
    
    
    bool search(TrieNode* root, string word) {
        // Write your code here
        
        //base case
        if(word.size()==0){
            if(root->isTerminal)
                return true;
            else
                return false;
        }
        
        int index = word[0] - 'a';
        bool ans;
        
      
        
        if(root->children[index] != NULL){
        ans = search(root->children[index], word.substr(1));      
            }
        else{
                return false;
            
        }
    
        
//         //recursive call
//         insertWord(child, word.substr(1));
        return ans;
    }
    
    bool search(string word){
        return search(root, word);
    }
    
    void removeWord(TrieNode *root, string word){

        //base case
        if(word.size()==0){
            root->isTerminal =false;
            return;
        }

        //small calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if(root->children[index]){
            child = root->children[index];
        }else{
            //word not found;
            return;
        }
        //remove child node if it is useless
        if(child->isTerminal == false){
            for(int i=0;i<26;i++){
                if(child->chilren[i] != NULL)
                return;
            }
        
        delete child;
        root->children[index] = NULL;
        }
    }

    void removeWord(string word){
        removedWord(root, word);
    }
};