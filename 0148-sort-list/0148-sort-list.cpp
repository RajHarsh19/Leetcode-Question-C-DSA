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
    ListNode* mergeTwoLists(ListNode*list1,ListNode*list2){
        ListNode*dNode = new ListNode(-1);
        ListNode*temp=dNode;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            } else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        temp->next=(list1!=nullptr) ? list1:list2;

        return dNode->next;
    }
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }


    ListNode* sortList(ListNode* head) {
         if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* middle = findMiddle(head);

        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return mergeTwoLists(left,right);

    }
};