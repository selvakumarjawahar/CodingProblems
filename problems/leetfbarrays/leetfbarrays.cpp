//
// Created by selva on 20-07-2020.
//

#include "leetfbarrays.h"

std::vector<std::vector<int> > leetfb_arrays::Solution::
    threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> result;
  if(nums.empty())return result;
  std::sort(nums.begin(),nums.end());
  for(int i=0; i<nums.size() && nums[i]<=0; ++i){
    if (i == 0 || nums[i - 1] != nums[i]){
      int begin = i+1;
      int end = nums.size()-1;
      while(begin<end){
        int sum = nums[i] + nums[begin] + nums[end];
        if (sum < 0 || (begin > i + 1 && nums[begin] == nums[begin - 1]))
          ++begin;
        else if (sum > 0 || (end < nums.size() - 1 && nums[end] == nums[end + 1]))
          --end;
        else
          result.push_back({ nums[i], nums[begin++], nums[end--]});
      }
   }
  }
  return result;
}