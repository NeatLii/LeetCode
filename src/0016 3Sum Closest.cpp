class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int first, second, third;
        int best = 1000000;

        for (first = 0; first < nums.size() - 2; ++first) {
            if (first > 0 && nums[first - 1] == nums[first]) continue;
            second = first + 1;
            third = nums.size() - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target) return target;

                if (abs(sum - target) < abs(best - target)) best = sum;

                if (sum > target) {
                    --third;
                    while (second < third && nums[third] == nums[third + 1])
                        --third;
                }
                else {
                    ++second;
                    while (second < third && nums[second - 1] == nums[second])
                        ++second;
                }
            }
        }

        return best;
    }
};