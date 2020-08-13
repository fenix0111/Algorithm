// Leetcode 841. Keys and Rooms
// https://leetcode.com/problems/keys-and-rooms/
// time complexity: O(number of rooms)
// space complexity: O(number of rooms)

class Solution 
{
public:
    void openRoom(const vector<vector<int>>& rooms, vector<bool>& visited, int key, int& remaining)
    {
        if (visited[key])
        {
            return;
        }
        
        visited[key] = true;
        remaining--;
        
        const vector<int>& room = rooms[key];
        for (int cler : room)
        {
            openRoom(rooms, visited, cler, remaining);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        vector<bool> visited(rooms.size(), false);
        
        int remaining = rooms.size();  // number of rooms which have not been opened
        openRoom(rooms, visited, 0, remaining);
        
        return remaining == 0;
    }
};
