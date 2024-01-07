Problem--
You are given a 0-indexed array of positive integers nums.

A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.

Return the total number of incremovable subarrays of nums.

Note that an empty array is considered strictly increasing.

A subarray is a contiguous non-empty sequence of elements within an array.

My Code---


class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
         int ans=0;
        if(nums.size()==1) return 1;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                vector<int>v;
                
                for(int k=0;k<nums.size();k++)
                {
                    if(k>=i and k<=j) continue;
                    
                    v.push_back(nums[k]);
                    
                }
                bool f=true;
                
                if(v.size()<=1)ans++;
                
                for(int w=1;w<v.size();w++)
                {
                    if(v[w]<=v[w-1])
                    {
                        f=false;
                        
                        break;
                    }
                }
                if(f)
               ans++;
            }
            
            
        }
        int val= ans-3;
        
        return val;
    }
};
