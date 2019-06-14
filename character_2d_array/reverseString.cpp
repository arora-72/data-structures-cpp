#include<iostream>
using namespace std;


void reverseString(char input[]){
    int i=0;
    int j = length(input) -1;

    while(i<j){
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }

}