#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;

        int len = nums.size();
        int max_num = 1;

        std::vector<int> dp(nums.size(), 1);

        for(int i = 1; i < len; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max_num = std::max(max_num, dp[i]);
        }
        return max_num;
    }
};