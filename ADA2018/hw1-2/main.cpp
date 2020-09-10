

#include <bits/stdc++.h>
using namespace std;


int main(){ 
    int n, i, j, value, deltaX, deltaY, totalArea;
    cin >> n;          


    vector<int> a_point;
    a_point.assign(2, 0);  

    vector< vector<int> > pointSet;
    pointSet.assign(n, a_point);  

    for (i=0; i<n; i++){
        for (j=0; j<2; j++){
            cin >> value;
            pointSet[i][j] = value;
        }
    }


    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){

            deltaX = abs(pointSet[i][0] - pointSet[j][0]);
            deltaY = abs(pointSet[i][1] - pointSet[j][1]);
            totalArea += deltaX * deltaY;

        }
    }

    cout << totalArea << endl;
    return totalArea; 
}