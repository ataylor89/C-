#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int sum) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == sum) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums;
	int sum;
	char *line;
	char *token;
	int num;	
	
	cout << "Input a comma-separated list of numbers with no spaces:" << endl;
	cout << "Comma-separated list: ";
	cin >> line;

	token = strtok(line, ",");
	while (token != NULL) {
		num = stoi(token, nullptr, 10);
		nums.push_back(num);
		token = strtok(NULL, ",");	
	}

	cout << "Input a desired sum: ";
	cin >> line;
	sum = stoi(line, nullptr, 10);

	vector<int> indices = solution.twoSum(nums, sum);
	cout << "Indices: " << indices[0] << " and " << indices[1] << endl;
	return 0;
}