class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            for(int r = 0; r < grid.size(); ++r)
                for(int c = 0; c < grid[0].size(); ++c)
                    if(grid[r][c] == 1) return perimeter(grid, r, c);
            return 0;
        }

    protected:
        int perimeter(vector<vector<int>>& grid, int r, int c)
        {
            if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
                return 1;
            if(grid[r][c] == 2) return 0;
            grid[r][c] = 2; // 'visited'
            return  perimeter(grid, r+1, c) +
                    perimeter(grid, r-1, c) +
                    perimeter(grid, r, c+1) +
                    perimeter(grid, r, c-1);
        }
};
Since we have only one 'island' - the solution below, of course, is a better one:

class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            int land = 0;
            int not_perimeter = 0;
            for(int r = 0; r < grid.size(); ++r)
                for(int c = 0; c < grid[0].size(); ++c)
                {
                    if(grid[r][c] == 0) continue;
                    ++land;
                    if(r != 0 && grid[r-1][c] == 1) ++not_perimeter;
                    if(c != 0 && grid[r][c-1] == 1) ++not_perimeter;
                }
            return 4*land - not_perimeter*2; // land has 4 sides; each 'non_perimeter' shared between 2 'land' cells
        }
};
