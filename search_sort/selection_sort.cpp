#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void selectionSort(int input[], int n){

    //find min
    for(int i=0;i<n-1;i++){

    int min = input[i], minIndex = i;
    for(int j=i+1;j<n;j++){
        if(input[j] < min){
        min = input[j];
        minIndex = j;
    }
    }

    int temp = input[i];
    input[i] = input[minIndex];
    input[minIndex] = temp;
    
}
}


int main()
{
int input[] = {3,1,6,9,0,4};

selectionSort(input, 6);

for(int i=0;i<6;i++)
    cout<<input[i]<<" ";

cout<<endl;
return 0;
}
