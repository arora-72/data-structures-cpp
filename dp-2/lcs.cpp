/*
    longest common subsequence
 */

#include<iostream>

using namespace std;

int lcs(string s, string t){

    //base case
    if(s.size()==0 || t.size() ==0)
        return 0;

    
    //recusrive calls
    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1), t.substr(1));
    }else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));

        return max(a, max(b,c));
    }
    
}


int main(){
    string s,t;
    cin>>s>>t;

    cout<<lcs(s, t)<<endl;
}