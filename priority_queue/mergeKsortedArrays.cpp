#include <iostream>
using namespace std;
#include <vector>
#include "Solution.h"

int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}


#include<bits/stdc++.h>
#include<queue>

typedef pair <int, pair<int, int>> ppi;

vector<int> mergeKSortedArrays(vector<vector<int>*> arr){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
    
    vector<int> output;
    
        priority_queue<ppi, vector<ppi>, greater<ppi> > pq; 
    
    //inserting the first element
    for(int i=0;i<arr.size();i++)
        pq.push({ arr[i][0], { i, 0 } }); 

    
    //min heap used
    //calculation on elements one by one
    while(!pq.empty()){
        
        ppi curr = pq.top();
        pq.pop();
        
        int i = curr.second.first;
        int j = curr.second.second;
        
        output.push_back(curr.first);
        
        if(j+1 < arr[i].size())
            pq.push({arr[i][j+1], {i,j+1}});
        
    }
    
    
    return output;

}
