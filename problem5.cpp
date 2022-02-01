#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1)
            return s;
        
        map<char, vector<int>> map;
        string result = s.substr(0,1);
        
        for (int i = 0; i < s.length(); i++) {
            char letter = s[i];
            if (!map.count(letter)) 
                map[letter] = {};
            map[letter].push_back(i);
        }
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            vector<int> v = map[c];
            for (int j = v.size()-1; v[j] > i; j--) {
                int len = v[j] - i + 1;
                if (len <= result.length())
                    break;               
                string ss = s.substr(i, len);
                if (is_palindrome(ss))
                    result = ss;
            }
        }
        return result;
    }
    bool is_palindrome(string s) {
        int len = s.length();
        for (int i = 0; i < len/2; i++) 
            if (s[i] != s[len-1-i])
                return false;
        return true;     
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string s;
    string t;

    cout << "Input a string: ";
    cin >> s;

    t = solution.longestPalindrome(s);

    cout << "Longest palindrome: " << t << endl;

    return 0;
}