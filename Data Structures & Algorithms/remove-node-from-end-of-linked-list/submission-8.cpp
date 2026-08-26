/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *temp = head;
        int length = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        cout<<length<<endl;
        temp = head;
        if(length > 2)
        {
            if(length == n)
            {
                return head -> next;
            }
            for(int i = 0;i<length - n-1;i++)
            {
                temp = temp->next;
            }
        }
        else if(length == 2)
        {
            if(n == 1)
            {
                head->next = NULL;
                return head;
            }
            else if(n ==2)
            {
                return head ->next;
            }
        }
        else if(length == 1)
        {
            return NULL;
        }
        
        if(temp->next != NULL)
        {
            ListNode *nxt = temp->next;
            temp->next = nxt->next;
            cout<<temp->val;
        }
        

        return head;
    }
};
