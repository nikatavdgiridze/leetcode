/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.



Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
*/

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int left = 0;
            int right = m - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (grid[i][mid] >= 0)
                {
                    left = mid + 1;
                }
                else
                {
                    ans += (right - mid) + 1;
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
};