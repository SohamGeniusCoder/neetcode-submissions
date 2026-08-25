class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;int r = nums.size() - 1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid]>nums[r])
            {
                //left is sorted
                if(target <= nums[mid] && target >= nums[l])
                {
                    //target is in left sorted half
                    r = mid-1;
                }
                else
                {
                    //target in right unsorted half with partition
                    l=mid+1;
                }
                
            }
            else
            {
                //right is sorted
                if(target <= nums[r] && target >= nums[mid])
                {
                    //target is in right sorted half
                    l = mid+1;
                }
                else
                {
                    //target in left unsorted half with partition
                    r = mid-1;
                }

                
            }
        }
        return -1;
    }
};
