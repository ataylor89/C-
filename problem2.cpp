#include <iostream>
#include <algorithm>
using namespace std;

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
		ListNode *head = new ListNode;
		ListNode *tail = head;
		
		int sum, digit, carry = 0;
		while (l1 || l2 || carry > 0) {
			// cout << "carry = " << carry << endl;
			sum = carry;
			if (l1) {
				sum += l1->val;
				// cout << "l1->val = " << l1->val << endl;
				l1 = l1->next;
			}
			if (l2) {
				sum += l2->val;
				// cout << "l2->val = " << l2->val << endl;
				l2 = l2->next;
			}
			// cout << "sum = " << sum << endl;
			digit = sum % 10;
			// cout << "digit = " << digit << endl;
			tail->val = digit;
			carry = sum / 10;
			if (l1 || l2 || carry > 0) {
				tail->next = new ListNode;
				tail = tail->next;
			}
			// cout << endl;
		}
		return head;
	}
};

ListNode* linked_list(int num) {
	ListNode *head = new ListNode;
	ListNode *tail = head;
	while (num > 0) {
		tail->val = num % 10;
		num /= 10;
		if (num > 0) {
			tail->next = new ListNode;
			tail = tail->next;
		}
	}
	return head;
}

int main(int argc, char **argv) {
	ListNode *l1 = linked_list(243);
	ListNode *l2 = linked_list(564);

	Solution solution;
	ListNode *sum = solution.addTwoNumbers(l1, l2);

	string result;
	while (sum) {
		result += to_string(sum->val);
		sum = sum->next;
	}
	reverse(result.begin(), result.end());

	cout << "Sum: " << result << endl;
	return 0;
}
