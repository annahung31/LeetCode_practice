

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


int crossArea(vector< vector<int> > pointSet, int front_idx, int mid_idx, int end_idx, int &totalArea){
    
    vector< vector<int> > leftSet(pointSet.begin()+front_idx, pointSet.begin()+mid_idx+1);
    vector< vector<int> > rightSet(pointSet.begin()+mid_idx+1, pointSet.begin()+end_idx+1);
    
    int i, j;
    int sigma_x, sigma_y, sigma_xy, temp;
    //from left to right
    for (i=leftSet.size()-1; i >=0; i--){
        sigma_x=0; sigma_y=0; sigma_xy=0; temp=0;
        for (j=rightSet.size()-1; j >=0; j--){
            //cout << "left:(" << leftSet[i][0] << "," << leftSet[i][1] << ")" << endl;
            //cout << "right:(" << leftSet[j][0] << "," << leftSet[j][1] << ")" << endl;
            if (rightSet[j][0] > leftSet[i][0] && rightSet[j][1] < leftSet[i][1]){
                sigma_x+=rightSet[j][0];
                sigma_y+=rightSet[j][1];
                sigma_xy+=rightSet[j][0]*rightSet[j][1];
            }
        }


        temp = leftSet[i][1]*sigma_x - leftSet[i][0]*leftSet[i][1] - sigma_xy + leftSet[i][0]*sigma_y;

        totalArea += temp;
        cout << totalArea << endl;
    }
    

    //from right to left
    for (j=rightSet.size()-1; j >=0; j--){
        for (i=leftSet.size()-1; i >=0; i--){
        sigma_x=0; sigma_y=0; sigma_xy=0; temp=0;
        
            if (rightSet[j][0] > leftSet[i][0] && rightSet[j][1] > leftSet[i][1]){
                sigma_x+=rightSet[i][0];
                sigma_y+=rightSet[i][1];
                sigma_xy+=rightSet[i][0]*rightSet[i][1];
            }
        }

        
        temp = (leftSet[j][1]*sigma_x - leftSet[j][0]*leftSet[j][1] - sigma_xy + leftSet[j][0]*sigma_y)*(-1);
        
        totalArea += temp;
        cout << totalArea << endl;
    }
    

}



int calArea(vector< vector<int> > pointSet, int front_idx, int end_idx, int &totalArea){
    
    if (front_idx < end_idx){

        // Divide
        int mid_idx = (front_idx + end_idx)/2;
        
        calArea(pointSet, front_idx, mid_idx, totalArea);
        calArea(pointSet, mid_idx+1, end_idx, totalArea);
        // conquer
        crossArea(pointSet, front_idx, mid_idx, end_idx, totalArea);
        
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

    calArea(pointSet, 0, pointSet.size()-1, totalArea);
    
    cout << totalArea << endl;
    return totalArea; 
}