#include <iostream>
#include <cstring>
using namespace std;

class BigInteger {
    public:
        char *str;
        BigInteger(char *str) : str(str) {}
        BigInteger* add(BigInteger *b);
};

BigInteger* BigInteger::add(BigInteger *b) {
    char *l1 = this->str;
    char *l2 = b->str;
    char *l3 = (char *) malloc(sizeof(char) * 50);
    char *result = l3;
    int sum, digit, carry = 0;

    while (*l1 || *l2 || carry > 0) {
        sum = carry;
        if (*l1) {
            sum += *l1 - '0';
            l1++;
        }
        if (*l2) {
            sum += *l2 - '0';
            l2++;
        }
        digit = sum % 10;
        carry = sum / 10;
        *l3 = digit + '0';
        l3++;
    }
    *l3 = '\0';
    return new BigInteger(result);
}

int main(int argc, char **argv) {
    char num1[50], num2[50];

    cout << "Input two positive integers to get the sum" << endl;
    cout << "First number: ";
    scanf("%49s", num1);
    cout << "Second number: ";
    scanf("%49s", num2);
    
    BigInteger *b1 = new BigInteger(num1);
    BigInteger *b2 = new BigInteger(num2);
    BigInteger *sum = b1->add(b2);
    printf("Sum: %s\n", sum->str);

    return 0;
}
