#include<iostream>
#include<bits/stdc++.h>
#include<string>


using namespace std;



bool isPermutation(char str1[], char str2[])
{
    int freq[256] = {0};
    
    for(int i=0;str1[i] != '\0';i++){
        int index = str1[i];
        freq[index]++;
        }
    
    for(int i=0; str2[i] != '\0';i++){
        int index = str2[i];
        freq[index]--;
    }
    
    
    for(int i=0;i<256;i++){
        if(freq[i] != 0)
            return false;
    }
    
    return true;
}