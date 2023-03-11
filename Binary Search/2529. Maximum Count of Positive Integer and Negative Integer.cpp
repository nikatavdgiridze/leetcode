/*
Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.



Example 1:

Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
*/

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();
        int ans1 = 0;
        int ans2 = 0;
        int mid = 0;

        for (int i = 0; i < n; i++)
        {
            int left = 0;
            int right = n - 1;

            while (left <= right)
            {
                mid = (left + right) / 2;
                if (nums[mid] < 0)
                {
                    ans1 = mid + 1;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            left = 0;
            right = n - 1;

            while (left <= right)
            {
                mid = (left + right) / 2;
                if (nums[mid] > 0)
                {
                    ans2 = n - mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return max(ans1, ans2);
    }
};