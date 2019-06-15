/*
Reverse Each Word
Send Feedback
Given a string S, reverse each word of a string individually. For eg. if a string is "abc def", reversed string should be "cba fed".
Input Format :
String S
Output Format :
Updated string
Constraints :
1 <= Length of S <= 1000
Sample Input :
Welcome to Coding Ninjas
Sample Output:
emocleW ot gnidoC sajniN

 */

#include<bits/stdc++.h>

#include <iostream>

using namespace std;

void util(char input[], int start, int end){
      int i=start; 
    int j = end;
    
    while(i<j){
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        
        i++;
        j--;
    }
}
void reverseEachWord(char str[]) {
    // Write your code here
    
    int l = strlen(str) -1;
    int start = 0, end = 0;
    int i=0;
    for(i=0; str[i] != '\0'; i++){
        if(str[i] == ' '){
        end = i-1;
        util(str, start, end);
        start = i+1;
        }
    }
    end = i-1;
    util(str, start, end);
}



int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseEachWord(input);
    cout << input << endl;
}
