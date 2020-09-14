

#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

struct a_point{
    int x_coor;
    int y_coor;
};


bool comp(const a_point &a, const a_point &b){
    return a.x_coor < b.x_coor;
}


int solu(int n, vector< a_point > pointSet){


    return totalArea;
}




int main(){ 
    int n, i, j, deltaX, deltaY, totalArea;
    cin >> n;          

    vector< a_point > pointSet;
    
    while (n--){
        a_point onePoint;
        int x_coor;
        int y_coor;
        cin >> x_coor >> y_coor;
        onePoint.x_coor = x_coor;
        onePoint.y_coor = y_coor;
        pointSet.push_back(onePoint);
    }

    //sort the pointSet by x coordinate.
    sort(pointSet.begin(),pointSet.end(),comp);




    //totalArea = solu(n, pointSet);
    //cout << totalArea << endl;
    //return totalArea; 
    return 0;
}