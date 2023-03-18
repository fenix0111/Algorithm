// Leetcode 1472. Design Browser History
// https://leetcode.com/problems/design-browser-history/description/

class BrowserHistory
{
    vector<string> history;
    int front = 0;
    int current = 0;
public:
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        front = 0;
        current = 0;
    }
    
    void visit(string url)
    {
        if (current == history.size() - 1)
        {
            history.push_back(url);
            front++;
            current++;
            return;
        }

        current++;
        front = current;
        history[current] = url;
    }
    
    string back(int steps)
    {
        if (current - steps >= 0)
        {
            current -= steps;
        }
        else
        {
            current = 0;
        }

        return history[current];
    }
    
    string forward(int steps)
    {
        if (current + steps <= front)
        {
            current += steps;
        }
        else
        {
            current = front;
        }

        return history[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
