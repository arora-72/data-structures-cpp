#include <iostream>
#include<queue>

using namespace std;

void print(int** edges, int n, int vs, bool* visited){
    
    queue<int> q;
    visited[vs]=true;
    q.push(vs);
    
    while(!q.empty())
    {
        int t = q.front();
        cout<<t<<" ";
        q.pop();
        
        
        for(int i=0;i<n;i++)
        {
            //cout<<i;
            if(t==i)
            {
                continue;
            }
            //cout<<edges[t][i] <<endl;;
            if(edges[t][i]==1 || edges[i][t]==1){
                 if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }   
            }
            
        }
    }
    
    
}



int main() {
    int n,e;

    cin>>n>>e;
    int **edges = new int*[n];
    
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    //taking input
    
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    //visited array
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    print(edges, n, 0, visited);
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}
