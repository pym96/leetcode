#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);

        return nums;
    }

private:
    int partition(vector<int>& nums, int low, int high){

        int random_num = low + rand() % (high - low + 1);
        std::swap(nums[low], nums[random_num]);

        int pivox = nums[low];
        int i = low, j = high;

        while(i < j){
            while(i < j && nums[j] >= pivox) j--;
            if(i < j) nums[i] = nums[j];

            while(i < j && nums[i] <= pivox) i++;
            if(i < j) nums[j] = nums[i];
        }

            nums[i] = pivox;
            return i;
    }

    void quick_sort(vector<int>& nums, int low, int high){
        if(low < high){
            int pivox = partition(nums, low, high);
            
            quick_sort(nums, low, pivox - 1);
            quick_sort(nums, pivox + 1, high);
        }
    }


};