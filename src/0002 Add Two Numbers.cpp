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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int sum;
        bool carry;    //加法进位最多为1
        while(l1 || l2 || carry) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (carry ? 1 : 0);
            carry = sum > 9;
            sum = sum % 10;
            if(!head) {
                head = tail = new ListNode(
                    sum);    //直接使用l1或l2的结点会更快，但不安全
            }
            else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head;
    }
};
