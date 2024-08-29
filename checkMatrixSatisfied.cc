#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int> >& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        int row, col;
        for(row = 0; row < m; row++){
            for(col = 0; col < n; col++){
                if(row < m - 1 && grid[row][col] != grid[row+1][col]) return false;
                if(col < n - 1 && grid[row][col] == grid[row][col+1]) return false;
            }
        }

        return true;
    }
};


int main(){

    std::ios::sync_with_stdio(false);

    

    return 0;
}