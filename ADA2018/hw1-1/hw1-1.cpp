#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    int n, i, value;
    int minPrice=0;
    int maxPro = 0;
    cin >> n;
    
    vector<int> price;
    for (i=0; i<n; i++){
        if (i ==0){
            cin >> value;
            price.push_back(value);
            }
        else{
            cin >> value;
            value += price[i-1];
            price.push_back(value);

        }
        
    }

    for (i=0; i<price.size(); i++){
        maxPro = max(maxPro, price[i]-minPrice);
        minPrice = min(minPrice, price[i]);
    }
    cout << maxPro << "\n";
    return maxPro;
}