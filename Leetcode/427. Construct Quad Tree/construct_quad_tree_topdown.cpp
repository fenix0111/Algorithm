// Leetcode 427. Construct Quad Tree
// https://leetcode.com/problems/construct-quad-tree/
// time complexity: O(n2)
// space complexity: O(n)

/*
// Definition for a QuadTree node.

// code is a quite rambling
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution 
{
public:
    void construct(Node* parent, vector<vector<int>>& grid, int w, int r, int c)
    {
        int width = w / 2;
        int num = grid[r][c];
        bool diff = false;
        
        // top left
        for (int i = r; i < r + width; i++)
        {
            for (int j = c; j < c + width; j++)
            {
                if (num != grid[i][j])
                {
                    diff = true;
                    break;
                }
            }
            
            if (diff)
            {
                break;
            }
        }
        
        if (!diff)
        {
            parent->topLeft = new Node(num, true, nullptr, nullptr, nullptr, nullptr);
        }
        else
        {
            parent->topLeft = new Node();
            construct(parent->topLeft, grid, w / 2, r, c);
        }
        
        // top right
        num = grid[r][c + width];
        diff = false;
        for (int i = r; i < r + width; i++)
        {
            for (int j = c + width; j < c + w; j++)
            {
                if (num != grid[i][j])
                {
                    diff = true;
                    break;
                }
            }
            
            if (diff)
            {
                break;
            }
        }
        
        if (!diff)
        {
            parent->topRight = new Node(num, true, nullptr, nullptr, nullptr, nullptr);
        }
        else
        {
            parent->topRight = new Node();
            construct(parent->topRight, grid, w / 2, r, c + width);
        }
        
        // bottom left
        num = grid[r + width][c];
        diff = false;
        for (int i = r + width; i < r + w; i++)
        {
            for (int j = c; j < c + width; j++)
            {
                if (num != grid[i][j])
                {
                    diff = true;
                    break;
                }
            }
            
            if (diff)
            {
                break;
            }
        }
        
        if (!diff)
        {
            parent->bottomLeft = new Node(num, true, nullptr, nullptr, nullptr, nullptr);
        }
        else
        {
            parent->bottomLeft = new Node();
            construct(parent->bottomLeft, grid, w / 2, r + width, c);
        }
        
        // bottom right
        num = grid[r + width][c + width];
        diff = false;
        for (int i = r + width; i < r + w; i++)
        {
            for (int j = c + width; j < c + w; j++)
            {
                if (num != grid[i][j])
                {
                    diff = true;
                    break;
                }
            }
            
            if (diff)
            {
                break;
            }
        }
        
        if (!diff)
        {
            parent->bottomRight = new Node(num, true, nullptr, nullptr, nullptr, nullptr);
        }
        else
        {
            parent->bottomRight = new Node();
            construct(parent->bottomRight, grid, w / 2, r + width, c + width);
        }
    }
    
    Node* construct(vector<vector<int>>& grid) 
    {
        int sz = grid.size();
        if (sz == 1)
        {
            return new Node(grid[0][0], true, nullptr, nullptr, nullptr, nullptr);
        }
        
        int num = grid[0][0];
        bool diff = false;
        for (int r = 0; r < sz; r++)
        {
            for (int c = 0; c < sz; c++)
            {
                if (grid[r][c] != num)
                {
                    diff = true;
                    break;
                }
            }
            if (diff)
            {
                break;
            }
        }
        
        if (!diff)
        {
            return new Node(grid[0][0], true, nullptr, nullptr, nullptr, nullptr);
        }
        
        Node* root = new Node(1, false, nullptr, nullptr, nullptr, nullptr);
        construct(root, grid, sz, 0, 0);
        
        return root;
    }
};
