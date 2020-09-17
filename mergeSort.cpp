

#include <bits/stdc++.h>
#include<cmath>
#include<vector>
using namespace std;
#define MOD 1000000007
#define INF 1000000000

void Merge(vector<int> &a_vector, int front_idx, int mid_idx, int end_idx){

    vector<int> leftVector(a_vector.begin()+front_idx, a_vector.begin()+mid_idx+1);
    vector<int> rightVector(a_vector.begin()+mid_idx+1, a_vector.begin()+end_idx+1);
    int i, leftIdx=0, rightIdx=0;

    leftVector.push_back(INF);
    rightVector.push_back(INF);
    
    for (i=front_idx; i <=end_idx; i++){
        if (leftVector[leftIdx] <= rightVector[rightIdx]){
            a_vector[i] = leftVector[leftIdx]; 
            leftIdx++;
        }
        else{
            a_vector[i] = rightVector[rightIdx]; 
            rightIdx++;
        }

    }

}



void MergeSort(vector<int> &a_vector, int front_idx, int end_idx){
    if (front_idx < end_idx){
        int mid_idx = (front_idx+end_idx)/2;
        MergeSort(a_vector, front_idx, mid_idx);
        MergeSort(a_vector, mid_idx+1, end_idx);
        Merge(a_vector, front_idx, mid_idx, end_idx);
    }
}


int main(){ 
    int n, i, value;
    cin >> n;          

    vector<int> a_vector;
    a_vector.assign(n, 0);  

    for (i=0; i<n; i++){
            cin >> value;
            a_vector[i] = value;
        
    }
    MergeSort(a_vector, 0, n-1);

    for  (i=0; i<n; i++){
        cout << a_vector[i] << " ";
    }

    
    return 0; 
}