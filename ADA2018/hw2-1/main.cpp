

#include <bits/stdc++.h>
#include<cmath>
using namespace std;



int main(){ 
    int n, i, value;
    double ans;
    cin >> n;          

    vector<int> targets;
    targets.assign(n, 0);  

    vector<int> results;
    results.assign(n, 0); 


    for (i=0; i<n; i++){
            cin >> value;
            targets[i]= value;
        }
    

    for (i=0; i<n; i++){
        ans = log(targets[i]+1)/log(2); 
        results[i] = ceil(ans);
        cout << results[i] << endl;

    }

    
    return 0;
}


