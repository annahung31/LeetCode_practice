

#include <bits/stdc++.h>
#include<cmath>
#include<vector>
using namespace std;
#define MOD 1000000007;
#define INF 1000000000;

void Merge(vector<int> *a_vector, int front_idx, int med_idx, int end_idx){

    vector<int> leftVector(a_vector.begin()+front_idx, a_vector.begin()+med_idx+1);
    vector<int> rightVector(a_vector.begin()+med_idx+1, a_vector.begin()+end_idx+1);

}





void MergeSort(vector<int> *a_vector, int front_idx, int end_idx){
    if (front_idx < end_idx){
        med_idx = (front_idx+end_idx)/2;
        MergeSort(a_vector, front_idx, med_idx);
        MergeSort(a_vector, med_idx+1, end_idx);
        Merge(a_vector, front_idx, med_idx, end_idx);
    }
}


int main(){ 
    int n, i, j, value;
    cin >> n;          

    vector<int> a_vector;
    a_vector.assign(n, 0);  

    for (i=0; i<n; i++){
            cin >> value;
            a_vector[i] = value;
        
    }
    

    
    return 0; 
}