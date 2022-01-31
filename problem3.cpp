#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            map.clear();
            for (int j = i; j < s.length(); j++) {
                char letter = s[j];
                int len = j - i + 1;
                if (map.find(letter) != map.end()) 
                    break;
                map[letter] = 1;
                if (len > max_len)
                    max_len = len;
            }
        }
        return max_len;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    int len;
    string line;

    cout << "Input a string: ";
    cin >> line;
    
    len = solution.lengthOfLongestSubstring(line);
    cout << "Length of longest substring: " << len << endl;
}