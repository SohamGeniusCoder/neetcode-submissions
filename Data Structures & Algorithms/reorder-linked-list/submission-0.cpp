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
    void reorderList(ListNode* head) 
    {
        int length = 0;int count = 0;
        ListNode *l1 = head;
        ListNode *l2 = head;
        ListNode *temp = head;
        //find length of list
        while(temp != NULL)
        {
            length++;
            temp=temp->next;
        }
        //find middle of list
        temp = l1;
        while(count < length/2)
        {
            l2=l2->next;
            count++;
            if(count < length/2)
            {
                temp=temp->next;
            }   
        }
        temp->next = NULL;
        //reverse 2nd half of list
        temp = l2;
        ListNode *prev = NULL; 
        while(temp != NULL)
        {
            ListNode *nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        //join the two lists
        l2 = prev;
        
        while(l1 != NULL && l2 != NULL)
        {
            temp = l2;
            ListNode *first = l1->next;
            ListNode *second = l2->next;
            l1->next = l2;
            l2->next = first;
            l1 = first;
            l2 = second;
            
            
        }
        if(l2 != NULL)
        {
            temp->next = l2;
        }



        


    }
};
