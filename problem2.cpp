#include <iostream>
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

ListNode *linked_list(char *num) {
    ListNode *head = new ListNode;
    ListNode *tail = head;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        int digit = num[len-1-i] - '0';
        tail->val = digit;
        if (i < len-1) {
            tail->next = new ListNode;
            tail = tail->next;
        }
    }
    return head;
}

void to_string(ListNode* node, char *str) {
    int i = 0;
    while (node) {
        str[i] = node->val + '0';
        node = node->next;
        i++;
    }
    str[i] = '\0';
    for (int j = 0; j < i/2; j++) {
        char save = str[i-j-1];
        str[i-j-1] = str[j];
        str[j] = save;
    }
}

int main(int argc, char **argv) {
    Solution solution;
    ListNode *sum, *l1, *l2;
    char num1[50], num2[50];
    char result[100];    

    cout << "Input two numbers separated by a space" << endl;
    cout << "First number: ";
    scanf("%49s", num1);
    cout << "Second number: ";
    scanf("%49s", num2);

    l1 = linked_list(num1);
    l2 = linked_list(num2);

    sum = solution.addTwoNumbers(l1, l2);
    to_string(sum, result);
    
    printf("Sum: %s\n", result);

    return 0;
}
