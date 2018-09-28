// Leetcode 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/description/
// Runtime: 48ms

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 // a bit strange quiz..
class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if (head == NULL)
            return NULL;
        
        RandomListNode *newhead = new RandomListNode(head->label);
        RandomListNode *newwalk = newhead;
        RandomListNode *walk = head;
        
        vector<RandomListNode*> v;
        vector<RandomListNode*> newv;
        
        int counter = 0;
        while (walk)
        {            
            if (walk->next)
            {
                newwalk->next = new RandomListNode(walk->next->label);
            }
            
            v.push_back(walk);
            newv.push_back(newwalk);
            
            newwalk = newwalk->next;
            walk = walk->next;
        }
        
        walk = head;
        newwalk = newhead;
        
        int max = v.size();
        
        while (walk)
        {
            counter = 0;
            if (walk->random)
            {
                while (counter < max)
                {
                    if (walk->random == v[counter])
                    {
                        newwalk->random = newv[counter];
                        break;
                    }
                    else
                    {
                        counter++;
                    }
                }
            }
            
            walk = walk->next;
            newwalk = newwalk->next;
        }
        
        return newhead;
    }
};
