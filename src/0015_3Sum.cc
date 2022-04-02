class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());

        int first, second, third, target;
        for (first = 0; first < nums.size(); ++first) {
            if (first > 0 && nums[first - 1] == nums[first]) continue;
            if (nums[first] > 0) return result;
            target = -nums[first];
            second = first + 1;
            third = nums.size() - 1;
            while (second < third) {
                if (nums[second] + nums[third] < target)
                    ++second;
                else if (nums[second] + nums[third] > target)
                    --third;
                else {
                    result.push_back({nums[first], nums[second], nums[third]});
                    ++second;
                    --third;
                    while (second < third && nums[second - 1] == nums[second])
                        ++second;
                    while (second < third && nums[third] == nums[third + 1])
                        --third;
                }
            }
        }

        return result;
    }
};
