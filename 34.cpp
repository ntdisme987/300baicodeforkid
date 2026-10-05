#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1. slow ends at the last node of the first half
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. reverse the second half
        ListNode* second = reverse(slow->next);

        // 3. compare both halves
        bool ok = true;
        ListNode *p1 = head, *p2 = second;
        while (p2) {
            if (p1->val != p2->val) {
                ok = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 4. restore the list
        slow->next = reverse(second);
        return ok;
    }

private:
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        while (node) {
            ListNode* nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
        }
        return prev;
    }
};

int main() {
    int n;
    cin >> n;

    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        tail->next = new ListNode(v);
        tail = tail->next;
    }

    Solution sol;
    cout << (sol.isPalindrome(dummy.next) ? "true" : "false") << endl;

    // free memory
    while (dummy.next) {
        ListNode* tmp = dummy.next;
        dummy.next = tmp->next;
        delete tmp;
    }
    return 0;
}