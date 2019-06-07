int ROW = 0;
int COL = 0;

bool isValid(int row, int col)
{
    return (row>=0) && (row<ROW) && (col>=0) && (col<COL);
}

int rowNum[] = {-1,-1,-1,0,0,1,1,1};
int colNum[] = {-1,0,1,-1,1,-1,0,1};

bool DFS(char Graph[][MAXN], int row, int col, char* word, string path, int index, int n, bool visited[100][100])
{
    if(index==n)
        return true;
    
    
    if(visited[row][col]==true)   
        return false;               // if the position is already visited then we should return false
    
    visited[row][col]=true;    //   , if the position is unvisited then we can explore this root , but first mark it visited
    
    
    
    if(index>n || Graph[row][col] != word[index])  // if this condition is true then we should return false , but before returning false we mu
        // st mark the current position of graph unvisited because it may contain a letter which is required in the later portion of the word
    {
        visited[row][col]=false;   //   
        
        return false;
    }
    
    
    
    for(int k=0;k<8;k++)
        if(isValid(row + rowNum[k], col + colNum[k]))
        {
            bool ans=DFS(Graph, row + rowNum[k], col + colNum[k], word, path, index + 1,n,visited);
         
         if(ans) return true;   //   , if we get true ans then we must not further explore more roots , so return true
         else continue;       // otherwise continue exploring more roots
        }
    
    
    visited[row][col]=false;   // 
   return false;      //     , before returning false we must mark the current position of graph unvisited because it may contain a letter which is required in the later portion of the word                                                                                    
    
}



int solve(char Graph[][MAXN],int N, int M)
{
    ROW = N;
    COL = M;
    char* word = "CODINGNINJA";
   bool ans = false;
	// Write your code here.
    
   
    bool visited[100][100];    
    for(int i=0;i<N;i++)              // it is necessary to maintain the track of elements of graph 
                                    //  which we have visited to avoid revisiting so a 2D array visited is created
        for(int j=0;j<M;j++)
            visited[i][j]=false;   //initially all positions marked unvisited
    
    
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(Graph[i][j] == word[0])          
            { ans = DFS(Graph,i,j,word,"",0,11,visited);    // visited array also passed .  
                                                        // INSTEAD of passing N , size of word must be passed , which is 11
             if(ans) return 1;     
            }
    
    
    
    if(ans)
        return 1;
    else
        return 0;
    
}