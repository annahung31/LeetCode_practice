#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define MODULE 1000000007;
using namespace std;

int isLegal(int n){
    int i, k=1;
    int count[10] ={0};
    
    for (i=1; i<19; i++){
        count[n/k % 10]++;
        k *=10;
    }
    if (n % 33==0 && count[3]%3==0 && count[6]%3==0 && count[9]%3==0){
        return 1;
    }
    return 0;

    
}


int main(){
    int n, m, i, j, value;
    cin >> n >> m;

    vector<int> row;
    row.assign(m, 0);
    vector< vector<int> > map;
    map.assign(n, row);

    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            cin >> value;
            map[i][j] = value;
        }
    }


    return 0;
    //int LEGAL = isLegal(n);


}