/*
Code : Min Cost Path

Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
Input Format :
Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)
Output Format :
Minimum cost
Constraints :
1 <= m, n <= 20
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
 */


#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int min(int x, int y, int z) 
{ 
   if (x < y) 
      return (x < z)? x : z; 
   else
      return (y < z)? y : z; 
} 

int util(int **input, int m, int n){
    
    if(m<0 || n<0)
        return INT_MAX;
    else if (m==0 && n==0)
        return input[m][n];
    else
        return input[m][n] + min(util(input, m-1, n-1), util(input, m-1, n), util(input, m, n-1));

}




int minCostPathMem(int **str, int m, int n,int i, int j, int **output){
    if(i==m-1 && j==m-1){
        return input[i][j];
    }

    if(i>=m || j>=n){
        return INT_MAX;
    }

    //check if answer already exists
    if(output[i][j] != -1){
        return output[i][j];
    }

    //recursive calls
    int x = minCostPathMem(str, m, n, i, j+1);
    int y = minCostPathMem(str, m, n, i+1, j+1);
    int z = minCostPathMem(str, m, n, i, j+1);

    int a = min(x, min(y, z)) + str[i][j];

    output[i][j] = a;

    return a;
}

int minCostDp(int **input, int m, int n){
    int **output = new int*[m];
    for(int i=0;i<m;i++){
        output[i] = new int[n];
    }


    //fill last dest cell
    output[m-1][n-1] = input[m-1][n-1];

    //fill last row (right to left)
    for(int j=n-2; j>=0;j--){
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }


    //fill last column
    for(int i=m-2;i>=0;i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }

    //fill remaining cells
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j] = min(output[i][j+1] , min(output[i+1][j+1], output[i+1][j])) + input[i][j];
        }
    }

    return output[0][0];
}


int minCostPath_Mem(int **input, int m, int n, int i, int j){
    int **output = new int* [m];
    for(int i=0;i<m;i++){
        output[i] = new int[n];
        for (int j = 0; j < n; j++){
            output[i][j] = -1;
        } 
    }

    return minCostPath_Mem(input, m ,n, i, j, output);
}


int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
   
    
    
    int ans = util(input, m-1, n-1);
    
    return ans;
}


//main function

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}
