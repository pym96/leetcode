class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        
      auto checkSquare = [&](int r, int c){
        int num_of_black = 0, num_of_white = 0;

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(grid[r + i][c + j] == 'B') num_of_black++;
                else num_of_white++;
            }
        }

        return num_of_black >= 3 || num_of_white >= 3;
      };
      

      for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            if(checkSquare(i, j)) 
                return true;
        }
      }

      return false;
        
    }
};