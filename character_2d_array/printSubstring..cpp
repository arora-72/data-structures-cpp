#include<string>
#include<bits/stdc++.h>
void printSubstrings(char str[]){
  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   * Print output as specified in the question.
   */
    
    int n = strlen(str);
      for (int len = 1; len <= n; len++)  
    {     
         
        for (int i = 0; i <= n - len; i++)  
        { 
               
            int j = i + len - 1;             
            for (int k = i; k <= j; k++)  
                cout << str[k]; 
              
            cout << endl; 
        } 
    } 

}
