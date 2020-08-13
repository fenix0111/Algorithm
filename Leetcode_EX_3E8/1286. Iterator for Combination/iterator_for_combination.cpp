// Leetcode 1286. Iterator for Combination
// https://leetcode.com/problems/iterator-for-combination/

// a bit waste of space because saved the all result to the vector
class CombinationIterator 
{
    vector<string> combinations;
    int pos = 0;
    
    void makeCombinations(string& characters, int idx, int length, string& combination)
    {
        if (combination.length() == length)
        {
            combinations.push_back(combination);
            return;
        }
        
        for (int i = idx; i < characters.size(); i++)
        {
            combination.push_back(characters[i]);
            makeCombinations(characters, i + 1, length, combination);
            combination.pop_back();
        }
    }
    
public:
    CombinationIterator(string characters, int combinationLength) 
    {
        string combination = "";
        makeCombinations(characters, 0, combinationLength, combination);
    }
    
    string next() 
    {
        return combinations[pos++];
    }
    
    bool hasNext() 
    {
        return pos < combinations.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
