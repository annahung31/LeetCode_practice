#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f


typedef pair<int, int> iPair;

class Graph{
    int V;

    list< pair<int, int> > *adj;
    
}


int main(){
    int n, m, i, j, value;
    cin >> m >> n;

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

    
}