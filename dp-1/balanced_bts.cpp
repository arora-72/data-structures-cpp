#include <iostream>

using namespace std;
#include <cmath>
#include<bits/stdc++.h>



int balancedBTs(int h) {   
    if(h==0 || h==1)
        return 1;
    
    /*
    
    mathematical formulation
    
    all combinations possible
    (h-1), (h-2)
    (h-2), (h-1)
    (h-1), (h-1)
    count(h) = count(h-1) * count(h-2) + 
               count(h-2) * count(h-1) + 
               count(h-1) * count(h-1)
            = 2 * count(h-1) * count(h-2) +  
              count(h-1) * count(h-1)
           = count(h-1) * (2*count(h - 2) + 
                              count(h - 1))
    
    */
    return balancedBTs(h-1) * (2*balancedBTs(h-2) + balancedBTs(h-1));
    
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
