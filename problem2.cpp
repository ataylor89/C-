#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
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

string to_string(ListNode* node) {
	string result;
	while (node) {
		result += to_string(node->val);
		node = node->next;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main(int argc, char **argv) {
	Solution solution;
	ListNode *sum, *l1, *l2;
	char *line;
	char *token;
	int num1, num2;

	cout << "Input two numbers separated by a space" << endl;
	cout << "Input: ";
	scanf("%d %d", &num1, &num2);

	l1 = linked_list(num1);
	l2 = linked_list(num2);

	sum = solution.addTwoNumbers(l1, l2);
	string result = to_string(sum);

	cout << "Sum: " << result << endl;

	return 0;
}
