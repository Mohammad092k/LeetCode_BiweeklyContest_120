Problem--

You are given a 0-indexed array of positive integers nums.

A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.

Return the total number of incremovable subarrays of nums.

Note that an empty array is considered strictly increasing.

A subarray is a contiguous non-empty sequence of elements within an array.


Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

My Code---

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        auto binary_search = [&](int start, int x) {
            
            int s = start, e = n - 1;
            
            if (nums[e] <= x) {
                return n;
            }
            while (s <e) {
                long long mid = s + (e - s) / 2;
                
                if (nums[mid]> x) {
                    e = mid;
                    
                } else {
                    s = mid + 1;
                }
            }
            return s;
        };

        long long p2 = n - 2;
        while (p2 >= 0 and nums[p2] < nums[p2 + 1]) {
            p2 -= 1;
        }
        p2 += 1;
        
        long long val = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 1 && nums[i - 1] <= nums[i - 2]) {
                break;
            }
            int xyz = (i == 0) ? -1 : nums[i - 1];
            
            int idx = binary_search(p2, xyz);
            if (idx <= i) {
                idx = i + 1;
            }
            val += n-idx + 1;
        }
        
        return val;
    }
};
