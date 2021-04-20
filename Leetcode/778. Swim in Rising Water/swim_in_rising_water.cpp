// Leetcode 778. Swim in Rising Water
// https://leetcode.com/problems/swim-in-rising-water/
// time complexity: 
// space complexity: O(n)

class Solution 
{
    struct Point{
        int v;
        int x;
        int y;
        Point(int height, int row, int col) : v(height), x(row), y(col) {}
    };
    
    struct compare{
        bool operator()(const Point& p1, const Point& p2) const { return p1.v > p2.v; }
    };
    
public:
    int swimInWater(vector<vector<int>>& grid) 
    {        
        priority_queue<Point, vector<Point>, compare> q;
        q.push(Point(grid[0][0], 0, 0));
        
        int size = grid.size();
        
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        visited[0][0] = true;
        int t = 0;
        while (true)
        {
            Point p = q.top();
            q.pop();
            
            if (grid[p.x][p.y] > t)
            {
                t = grid[p.x][p.y];
            }
            
            if (p.x == size - 1 && p.y == size - 1)
            {
                break;
            }
            
            int topRow = p.x - 1;
            int topCol = p.y;
            
            int rightRow = p.x;
            int rightCol = p.y + 1;
            
            int leftRow = p.x;
            int leftCol = p.y - 1;
            
            int bottomRow = p.x + 1;
            int bottomCol = p.y;
            
            if (topRow >= 0 && topRow < size && topCol >= 0 && topCol < size && !visited[topRow][topCol])
            {
                visited[topRow][topCol] = true;
                q.push(Point(grid[topRow][topCol], topRow, topCol));
            }
            
            if (rightRow >= 0 && rightRow < size && rightCol >= 0 && rightCol < size && !visited[rightRow][rightCol])
            {
                visited[rightRow][rightCol] = true;
                q.push(Point(grid[rightRow][rightCol], rightRow, rightCol));
            }
            
            if (leftRow >= 0 && leftRow < size && leftCol >= 0 && leftCol < size && !visited[leftRow][leftCol])
            {
                visited[leftRow][leftCol] = true;
                q.push(Point(grid[leftRow][leftCol], leftRow, leftCol));
            }
            
            if (bottomRow >= 0 && bottomRow < size && bottomCol >= 0 && bottomCol < size && !visited[bottomRow][bottomCol])
            {
                visited[bottomRow][bottomCol] = true;
                q.push(Point(grid[bottomRow][bottomCol], bottomRow, bottomCol));
            }
        }
        
        return t;
    }
};
