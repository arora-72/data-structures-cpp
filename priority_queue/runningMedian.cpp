//problem 
/*


Running median
Send Feedback
You are given a stream of n integers. For every ith integer, add it to the running list of integers and print the resulting median (of the list till now).
Print the only integer part of median.
Input Format :
Line 1 : An integer N denoting the number of integers in the stream
Line 2 : N integers which are separated by spaces
Output Format :
After each new integer is added to the list print the updated median on a new line
Input Constraints
1 <= n <= 10^5
1 <= Ai <= 10^5
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6
4
2
2
3
4
Sample Output explanation :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Download Test Cases

*/



#include <iostream>
#include<bits/stdc++.h>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);
    
    delete [] arr;
    
}


//using namespace std;

void findMedian(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    
    //max heap = smaller half elements 
    priority_queue<int> s;
    
    //min heap = larger half elements
    priority_queue<int, vector<int>, greater<int>> g;
    
    int med = arr[0];
    s.push(arr[0]);
    
    cout<<med<<endl;
    
    for(int i=1;i<n;i++)
    {
        int x = arr[i];
        
        //case 1 - left side has more elements
        if(s.size() > g.size())
        {
            if(x<med){
                g.push(s.top());
                s.pop();
                s.push(x);
            }else
                g.push(x);
            
            med = (s.top() + g.top())/2.0;
        }
        
        //case 2 (both heaps are balanced)
        else if (s.size() == g.size())
        {
            if(x<med){
                s.push(x);
                med = s.top();
            }else{
                g.push(x);
                med = g.top();
            }
        }
        
        
        //case3 (right side has more elements)
        else{
            if(x>med){
                s.push(g.top());
                g.pop();
                g.push(x);
            }else
                s.push(x);
            
            med = (s.top() + g.top())/2.0; 
        }
        
        cout << med <<endl;
    }
    

}


