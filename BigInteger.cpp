#include <iostream>
#include <cstring>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class BigInteger {
    public:
        char *str;
        ListNode *head;
        BigInteger(char *str) : str(str) {
            head = new ListNode;
            ListNode *tail = head;
            int len = strlen(str);
            for (int i = 0; i < len; i++) {
                int digit = str[len-1-i] - '0';
                tail->val = digit;
                if (i < len-1) {
                    tail->next = new ListNode;
                    tail = tail->next;
                }
            }
        }
        BigInteger(char *str, ListNode *head) : str(str), head(head) {}
        BigInteger *add(BigInteger *num);
};

BigInteger* BigInteger::add(BigInteger *num2) {
    ListNode *l1 = head;
    ListNode *l2 = num2->head;
    ListNode *l3 = new ListNode;
    ListNode *l3_head = l3;
    char *result = (char *) malloc(sizeof(char)*50);
    int i = 0;
    int sum, digit, carry = 0;
    
    while (l1 || l2 || carry > 0) {
        sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        digit = sum % 10;
        l3->val = digit;
        carry = sum / 10;
        result[i++] = digit + '0';
        if (l1 || l2 || carry > 0) {
            l3->next = new ListNode;
            l3 = l3->next;  
        }
    }
    result[i] = '\0';
    char save;
    for (int j = 0; j < i/2; j++) {
        save = result[i-j-1];
        result[i-j-1] = result[j];
        result[j] = save;
    }
    return new BigInteger(result, l3_head);
}

int main(int argc, char **argv) {
    char num1[50], num2[50];

    cout << "Input two numbers separated by a space" << endl;
    cout << "First number: ";
    scanf("%49s", num1);
    cout << "Second number: ";
    scanf("%49s", num2);
    
    BigInteger *b1 = new BigInteger(num1);
    BigInteger *b2 = new BigInteger(num2);
    BigInteger *sum = b1->add(b2);

    printf("BigInteger1: %s\n", b1->str);
    printf("BigInteger2: %s\n", b2->str);
    printf("Sum: %s\n", sum->str);

    return 0;
}
