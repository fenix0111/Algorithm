// Leetcode 1079. Letter Tile Possibilities
// https://leetcode.com/problems/letter-tile-possibilities/
// time complexity: ?
// space complexity: ?

// it works but in a very stupid way (it's easy to understand though)
class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        unordered_set<string> buf;
        
        // sorting is necessary before using std::next_permutation
        sort(tiles.begin(), tiles.end());
        do
        {
            buf.insert(tiles);
        } while (next_permutation(tiles.begin(), tiles.end()));
        
        unordered_set<string> buf2;
        for (auto it = buf.begin(); it != buf.end(); it++)
        {
            string str = *it;
            for (int i = 1; i <= tiles.size(); i++)
            {
                for (int j = 0; j + i - 1 < tiles.size(); j++)
                {
                    string tmp2 = str.substr(j, i);
                    buf2.insert(tmp2);
                }
            }
        }
        
        return buf2.size();
    }
};
