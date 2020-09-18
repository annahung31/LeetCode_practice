

#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

// Driver function to sort the 2D vector 
// on basis of a particular column 
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 


int crossArea(vector< vector<int> > pointSet, int st_idx, int mid_idx, int ed_idx, int &totalArea){
    totalArea += 1;
}



int calArea(vector< vector<int> > pointSet, int st_idx, int ed_idx, int &totalArea){
    
    if (st_idx < ed_idx){
        int j;
        for (j=st_idx; j<=ed_idx; j++){
            cout << pointSet[j][0] << ":" << pointSet[j][1]<< endl;
        }

        // Divide
        int mid_idx = (st_idx + ed_idx)/2;
        calArea(pointSet, st_idx, mid_idx, totalArea);
        calArea(pointSet, mid_idx+1, ed_idx, totalArea);

        // conquer
        crossArea(pointSet, st_idx, mid_idx, ed_idx, totalArea);
        //totalArea = rightArea + leftArea + crossArea
    }
    
}


int main(){ 
    int n, i, j, value, deltaX, deltaY, totalArea=0;
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

    

    //sort the pointSet by x coordinate.
    sort(pointSet.begin(), pointSet.end(), sortcol); 

    cout << "after sorting: " << endl;
    for (i=0; i<n; i++){
        cout << pointSet[i][0] << " : " << pointSet[i][1] << endl;
    
    }



    calArea(pointSet, 0, n-1, totalArea);
    
    //cout << totalArea << endl;
    //return totalArea; 
    return 0;
}