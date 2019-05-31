#include <iostream>
#include<queue>
using namespace std;


bool hasPath(int** edges, int n, int v1,int v2, bool* visited){
    
    //base case
    if(v1==v2)
        return true;
    
    queue<int> q;
    
    visited[v1] = true;
    q.push(v1);
    
    while(!q.empty()){
        v1 = q.front();
        q.pop();
        
        for(int i=0;i<n;i++){
            
            if(i==v2 && edges[v1][i]==1)
                return true;
            if(edges[v1][i]==1){
                
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
            }
        }
    }
    
    return false;

}


int main() {
    int n, e;
    cin >> n >> e;

  int **edges = new int*[n];
    
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]==0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    //visited edges
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    int v1,v2;
    cin>>v1>>v2;
        
    bool ans = hasPath(edges,n,v1,v2,visited);
    
    
    if(ans){
        cout<<"true";
    }else{
        cout<<"false";
    }
    
    
  return 0;
}
