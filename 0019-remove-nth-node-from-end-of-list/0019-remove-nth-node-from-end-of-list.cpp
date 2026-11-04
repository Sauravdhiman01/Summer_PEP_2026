class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* a = temp;
        ListNode* b = temp;

        for(int i = 0; i <= n; i++)
        {
            a = a->next;
        }

        while(a != nullptr)
        {
            a = a->next;
            b = b->next;
        }

        ListNode* temp1 = b->next;
        b->next = b->next->next;

        delete temp1;

        ListNode* newHead = temp->next;
        delete temp;

        return newHead;
    }
};