#include<iostream>
using namespace std;

void print(int** edges,int n, int sv, bool* visited){
    
    cout<<sv<<endl; //starting vertex;
    //marking as visited
    visited[sv]==true;

    for(int i=0;i<n;i++)
    {
        if(i==sv){
            continue;
        }
        //checking for adjacency
        if(edges[sv][i] == 1){
            if(visited[i])
            {
                continue;
            }
            print(edges,n,i, visited);
        }
    }
}


int main(){
    int n; //no of vertices
    int e; //no of edges
    cin>>n>>e;

    int **edges = new int*[n];

    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0; //to remove garbage values
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }


    //to keep track of visited edges
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    //for printing 
    print(edges,n, 0, visited);

}

