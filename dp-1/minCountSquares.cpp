#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//dp
int minCountDp(int n){
    int *ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for(int i=4;i<=n;i++){
        ans[i] = i;

        for(int j=1;j<=i;j++){
            int temp = j * j;
            if(temp>n)
                break;
            else
            {
                ans[i] = min(ans[i], minCountDp(i-temp) + 1);
            }
                        
        }
    }

    int result = ans[n];
    delete [] ans;
    return result;
}

//brute force method
int minCount(int n){
    if(n<=3)
        return n;

    int answer = n;

    for(int i=1;i<n;i++){

        int temp = i*i;

        if(temp>n)
            break;
        else
        {
            answer = min(answer, minCount(n - temp) + 1);
        }
        
    }

    return answer;
}

int main(){
    
    int num;
    cin >> num;
    cout << minCountDp(num);
    
}

