#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indexOf;
        for (int i = 0; i < nums.size(); i++)
        {
            int number = nums[i];
            auto indexOfComplement = indexOf.find(target - number);
            if (indexOfComplement != indexOf.end())
            {
                return {indexOf[target - number], i};
            }
            indexOf.insert({number, i});
        }
        return {};
    }
};

// This is boilerplate to be able to test locally in VS Code
int main()
{
    Solution solution;
    // Input the test case here!
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;

    vector<int> result = solution.twoSum(nums, target);
    cout << "Indices: ";
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
