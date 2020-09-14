

#include <bits/stdc++.h>
#include<cmath>
using namespace std;


int solu(int target){
    int n=0, count=0, nLeft, leftCount;  //need n days to achieve target

    while (true){
        if (count + pow(2, n) < target){
            count += pow(2, n);
            n += 1;
        }
        else{
            break;
        }
    }

    nLeft = target - count;
    if (nLeft > 0){
        leftCount = __builtin_popcount(nLeft);
        n += leftCount;
    }

    return n;
}


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
        ans = solu(targets[i]);
        results[i] = ans;
        cout << results[i] << endl;

    }

    
    return 0;
}


