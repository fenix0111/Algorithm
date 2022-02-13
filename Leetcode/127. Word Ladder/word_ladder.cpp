// BFS

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> words;
        unordered_set<string> visited;
        for (string& word : wordList)
        {
            words.insert(word);
        }
        
        if (words.count(endWord) == 0)
        {
            return 0;
        }
        
        int length = 0;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        
        while (!q.empty())
        {
            int sz = q.size();
            length++;
            for (int j = 0; j < sz; j++)
            {
                string s = q.front();
                q.pop();
                if (endWord.compare(s) == 0)
                {
                    found = true;
                    goto finalize;
                }

                for (int i = 0; i < s.length(); i++)
                {
                    char c = s[i];
                    for (char a = 'a'; a <= 'z'; a++)
                    {
                        s[i] = a;
                        if (words.count(s) && visited.count(s) == 0)
                        {
                            q.push(s);
                            visited.insert(s);
                        }
                    }
                    s[i] = c;
                }
            }
        }

finalize:
        if (found)
        {
            return length;
        }
        
        return 0;
    }
};
