#include<iostream>
#include<bits/stdc++.h>
using namespace std;


long ways(int n){
    
    long ans[n+1];
    
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    
    for(int i=3;i<=n;i++)
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    
    return ans[n];
}

long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    return ways(n);
    
}


int main(){

  int n; 
  cin >> n ;
  cout << staircase(n) << endl;

}


