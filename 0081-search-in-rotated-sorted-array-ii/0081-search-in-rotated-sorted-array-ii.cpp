class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = size (nums) - 1;

        while (low <= high)
        {
            int mid = (low + (high - low) / 2);

            if (target == nums[mid]) return 1;

            if (nums[low] < nums[mid])
            {
                if (target >= nums[low] and target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if (nums[low] == nums[mid]) low ++;
            else
            {
                if (target > nums[mid] and target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return 0;
    }
};