

#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

// Driver function to sort the 2D vector 
// on basis of a particular column 
// return a vector set with vector[0] to have smallest x.
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 

// return a vector set with vector[0] to have smallest y.
bool sortY( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[1] < v2[1]; 
} 



int crossArea(vector< vector<int> > pointSet, int front_idx, int mid_idx, int end_idx, int &totalArea){
    /*
    For a given point A(x0,y0) from left-hand side with index i,
    update sigma_x, sigma_y, sigma_xy of all the points from right-hand side.
    Also update sigma_x0y0, which is x0*y0 from point A itself.
     */



    vector< vector<int> > leftSet(pointSet.begin()+front_idx, pointSet.begin()+mid_idx+1);
    vector< vector<int> > rightSet(pointSet.begin()+mid_idx+1, pointSet.begin()+end_idx+1);
    sort(leftSet.begin(), leftSet.end(), sortY); 
    sort(rightSet.begin(), rightSet.end(), sortY); 
    int i, j, j_st;
    int sigma_x, sigma_y, sigma_xy, temp;
    //from left to right
    sigma_x=0; sigma_y=0; sigma_xy=0;temp=0; j_st=0;
    for (i=0; i <leftSet.size(); i++){

        for (j=j_st; j<rightSet.size(); j++){
            //cout << "i:" << i << ",j:" << j << endl;
            //cout << "left: coord: (" << leftSet[i][0] << "," << leftSet[i][1] << ") to (" << rightSet[j][0] << "," << rightSet[j][1] << ")" << endl;
            if (rightSet[j][0] > leftSet[i][0] && rightSet[j][1] < leftSet[i][1]){
                //cout << "left ===Update===" << endl;
                sigma_x+=rightSet[j][0];
                sigma_y+=rightSet[j][1];
                sigma_xy+=rightSet[j][0]*rightSet[j][1];
                
                j_st +=1;
                //cout << sigma_x0y0 << ":" << leftSet[i][0] << "," << leftSet[i][1] << endl;
            }
        }
        //cout << "x:" << sigma_x << ",y:" << sigma_y << ", xy:" << sigma_xy << ",xy0:" << sigma_x0y0 << endl;
        if (sigma_x == 0 && sigma_y==0 && sigma_xy==0){
            temp = 0;
        }
        else{
            temp = leftSet[i][1]*sigma_x - j_st*leftSet[i][0]*leftSet[i][1] - sigma_xy + leftSet[i][0]*sigma_y;
        }
        //cout << "left:" << temp << endl;
        totalArea += temp;
        
    }
    

    //from right to left
    sigma_x=0; sigma_y=0; sigma_xy=0;temp=0; j_st=0;
    for (j=0; j<rightSet.size(); j++){

        for (i=j_st; i<leftSet.size(); i++){
            //cout << "i:" << i << ",j:" << j << endl;
            //cout << "right: coord: (" << leftSet[i][0] << "," << leftSet[i][1] << ") to (" << rightSet[j][0] << "," << rightSet[j][1] << ")" << endl;
            if (rightSet[j][0] > leftSet[i][0] && rightSet[j][1] > leftSet[i][1]){
                //cout << "right ===Update===" << endl;
                sigma_x+=leftSet[i][0];
                sigma_y+=leftSet[i][1];
                sigma_xy+=leftSet[i][0]*leftSet[i][1];
                
                j_st +=1;

            }
        }
        //cout << "x:" << sigma_x << ",y:" << sigma_y << ", xy:" << sigma_xy << ",xy0:" << sigma_x0y0 << endl;
        if (sigma_x == 0 && sigma_y==0 && sigma_xy==0){
            temp = 0;
        }
        else{
            temp = (rightSet[j][1]*sigma_x - j_st*rightSet[j][0]*rightSet[j][1] - sigma_xy + rightSet[j][0]*sigma_y)*(-1);
        }
        //cout << "right:" << temp << endl;
        totalArea += temp;
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