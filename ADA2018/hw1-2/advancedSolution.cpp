

#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

// Driver function to sort the 2D vector 
// on basis of a particular column 
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] > v2[0]; 
} 


int crossArea(vector< vector<int> > pointSet, int front_idx, int mid_idx, int end_idx, int &totalArea,
                int &sigma_x, int &sigma_y, int &sigma_xy){
    
    vector< vector<int> > leftSet(pointSet.begin()+front_idx, pointSet.begin()+mid_idx+1);
    vector< vector<int> > rightSet(pointSet.begin()+mid_idx+1, pointSet.begin()+end_idx+1);
    int i, leftIdx=0, rightIdx=0;

    



}



int calArea(vector< vector<int> > pointSet, int front_idx, int end_idx, int &totalArea, 
            int &sigma_x, int &sigma_y, int &sigma_xy){
    
    if (front_idx < end_idx){


        // Divide
        int mid_idx = (front_idx + end_idx)/2;
        calArea(pointSet, front_idx, mid_idx, totalArea, sigma_x, sigma_y, sigma_xy);
        calArea(pointSet, mid_idx+1, end_idx, totalArea, sigma_x, sigma_y, sigma_xy);

        // conquer
        crossArea(pointSet, front_idx, mid_idx, end_idx, totalArea,sigma_x, sigma_y, sigma_xy);
        //totalArea = rightArea + leftArea + crossArea
    }
    
}


int main(){ 
    int n, i, j, value, deltaX, deltaY, totalArea=0, sigma_x=0, sigma_y=0, sigma_xy=0;
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



    //calArea(pointSet, 0, n-1, totalArea, sigma_x, sigma_y, sigma_xy);
    
    //cout << totalArea << endl;
    //return totalArea; 
    return 0;
}