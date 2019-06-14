#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/

    int m,n;
    cin>>m>>n;
    int arr[m][n];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    int i=0;
    int sum = 0;
    while(i<n){
        for(int j =0;j<m;j++){
            //cout<<j<<" , "<<i<<endl;
            //cout<<arr[j][i]<<endl;
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
        sum = 0;
        i++;
    }
}


