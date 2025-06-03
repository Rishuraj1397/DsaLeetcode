#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // Dummy node to simplify handling edge cases
        ListNode* current = dummyHead;          // Pointer to build the result list
        int carry = 0;                          // Carry to handle sums >= 10

        // Traverse both lists until all digits are processed or carry is not 0
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // Start with carry value

            // Add l1's value if l1 is not null
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;  // Move to the next node in l1
            }

            // Add l2's value if l2 is not null
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;  // Move to the next node in l2
            }

            carry = sum / 10;  // Update carry for the next iteration
            current->next = new ListNode(sum % 10);  // Create a new node for the current digit
            current = current->next;  // Move to the next node
        }

        return dummyHead->next;  
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummyHead->next;  


