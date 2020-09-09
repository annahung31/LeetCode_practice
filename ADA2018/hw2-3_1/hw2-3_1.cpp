#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define MOD 1000000007;
using namespace std;

int checkSave(int n){
    int i, k=1;
    int count[10] ={0};
    
    for (i=1; i<19; i++){
        count[n/k % 10]++;
        k *=10;
    }
    if (n % 33==0 && count[3]%3==0 && count[6]%3==0 && count[9]%3==0){
        return 0;
    }
    return 1;

    
}


int main(){
    int n, m, i, j, value;
    cin >> n >> m;

    vector<int> row;
    row.assign(m, 0);
    vector< vector<int> > map;
    map.assign(n, row);

    vector<int> dp_row;
    dp_row.assign(m, 1);
    vector< vector<int> > dp;
    dp.assign(n, dp_row);


    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            cin >> value;
            map[i][j] = value;
        }
    }

    for (i=1; i<n+1; i++){
        for (j=1; j<m+1; j++){
            int SAFETY = checkSave(map[i][j]);

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            
            if (SAFETY==0){
                dp[i][j] = 0;
            }
            
        }
    }
    
    cout << dp[m - 1][n - 1] << endl;
    return dp[m - 1][n - 1];


}