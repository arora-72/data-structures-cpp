/*

Reverse Word Wise
Send Feedback
Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Sample Input:
Welcome to Coding Ninjas
Sample Output:
Ninjas Coding to Welcome


*/

#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

void reverseCompleteString(char str[]){
    int i=0, j = strlen(str) -1;

    while(i<j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void reverse(char str[], int start, int end){
    int i=start, j=end;
     while(i<j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}


void reverseWordWise(char str[]){
    reverseCompleteString(str);
    int start = 0, end = 0, i;

    for(i = 0; str[i] != '\0';i++){
        if(str[i] == ' '){
            end = i-1;
            reverse(str, start, end);
            start = i + 1;
        }
    }
    end = i-1;
    reverse(str, start, end);
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseWordWise(input);
    cout << input << endl;
}
