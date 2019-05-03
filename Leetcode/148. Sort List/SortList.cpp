// Leetcode 148. Sort List
// https://leetcode.com/problems/sort-list/
// Runtime: 380ms

// using array to keep memory address of each ListNode, then apply quicksort
// this would not change the memory address of the original List
class Solution 
{
public:
    int partition(ListNode *A[], int low, int high)
    {
        int pivot = A[high]->val;
        int i = low;
        for (int j = low; j < high; j++)
        {
            if (A[j]->val < pivot)
            {
                ListNode *tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                
                i++;
            }
        }
        
        ListNode *tmp = A[i];
        A[i] = A[high];
        A[high] = tmp;
        
        return i;
    }
    
    void qs(ListNode *A[], int low, int high)
    {
        if (low < high)
        {
            int p = partition(A, low, high);
            qs(A, low, p - 1);
            qs(A, p + 1, high);
        }
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if (NULL == head || NULL == head->next)
        {
            return head;
        }
        
        int sz = 0;  // length of the List
        ListNode *h = head;
        while (h)
        {
            sz++;
            h = h->next;
        }
        
        ListNode **arr = (ListNode**)malloc(sizeof(ListNode*) * sz);
        h = head;
        
        // initialize the array
        for (int i = 0; i < sz; i++)
        {
            arr[i] = h;
            h = h->next;
        }
        
        qs(arr, 0, sz - 1);
        
        // adjust the next pointer
        for (int i = 0; i < sz - 1; i++)
        {
            arr[i]->next = arr[i + 1];
        }
        arr[sz - 1]->next = NULL;
        
        return arr[0];
    }
};
