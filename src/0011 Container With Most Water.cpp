class Solution {
  public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int shortest = min(height[left], height[right]);
            result = max(result, shortest * (right - left));
            //快速跳过
            while (height[left] <= shortest && left < right) ++left;
            while (height[right] <= shortest && left < right) --right;
        }
        return result;
    }
};