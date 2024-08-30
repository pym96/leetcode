// 3153
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        std::ios::sync_with_stdio(false);

        int digits = static_cast<int>(log10(abs(nums[0])) + 1);
        // int digits = std::to_string(nums[0]).length();

        long long total_difference = 0;
        
        for(int pos = 0; pos < digits; pos++){
            long sum = 0;
            long prefix = 0;

            std::vector<int> temp_tank(10, 0);

            for(auto num : nums){
                int dig = static_cast<int>(num / (pow(10, pos))) % 10;
                temp_tank[dig]++;
            }

            
            for(int i = 0; i < 10; ++i){
                sum += prefix * temp_tank[i];
                prefix += temp_tank[i];
            }
                
            total_difference += sum;

        }
        
        return total_difference;
        

    }
};