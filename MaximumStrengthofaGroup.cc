class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long result = 0;
        
        const int len = nums.size();
        
        std::vector<int> positives, negatives;
        
        for(auto num: nums){
            if(num < 0) negatives.push_back(num);
            if(num > 0) positives.push_back(num);
        }

        std::sort(negatives.begin(), negatives.end());

        // First solve positive;

        result = positives.empty() ? LLONG_MIN : 1;
        
        for(size_t i = 0; i < positives.size(); ++i){
            result *= positives[i];
        }

        
        long long negativeRes = 1;
        // For negative
        for(size_t i = 0; i + 1 < negatives.size(); i+=2){
            negativeRes *= static_cast<long long>(negatives[i] * negatives[i + 1]);
        }

        if(!negatives.empty() && negatives.size() > 1){
            result = positives.empty() ? negativeRes : negativeRes * result;
        }

        if(result == LLONG_MIN){
            result = *std::max_element(nums.begin(), nums.end());
        }

        return result;
    }
};


// DP：Since it's not a consective array question, so we cannot use Dynamic programming
// This is my failed DP code below
class Solution {
public:
    long long maxStrength(std::vector<int>& nums) {
        // If there's only one element, return it as the maximum strength.
        if (nums.size() == 1) return nums[0];
        
        // Initialize the max and min product arrays with the first element.
        long long max_product = nums[0];
        long long min_product = nums[0];
        long long result = nums[0]; // To store the maximum product found.

  
        // Traverse the array starting from the second element.
        for (size_t i = 1; i < nums.size(); ++i) {
            // Store the current max_product to update min_product correctly.
            long long temp_max = max_product;

            // Update max_product considering three possibilities:
            // 1. The current number alone.
            // 2. The current number multiplied by the previous max product.
            // 3. The current number multiplied by the previous min product.
            max_product = std::max({static_cast<long long>(nums[i]), nums[i] * max_product, nums[i] * min_product});

            // Update min_product similarly.
            min_product = std::min({static_cast<long long>(nums[i]), nums[i] * temp_max, nums[i] * min_product});

            // Update the result to be the maximum found so far.
            result = std::max(result, max_product);
        }
        
        return result;
    }
};

