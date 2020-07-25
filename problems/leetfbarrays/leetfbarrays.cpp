//
// Created by selva on 20-07-2020.
//

#include "leetfbarrays.h"

std::vector<std::vector<int> > leetfb_arrays::Solution::
    threeSum(std::vector<int> &nums) {
  auto mid_itr = std::partition(nums.begin(),nums.end(),
                 [](const auto& elem){return elem >= 0;});
  bool found = false;
  std::vector<std::vector<int>> result;
  for(auto neg_itr = nums.begin() ; neg_itr < mid_itr;  neg_itr++) {
    for(auto pos_itr = mid_itr; pos_itr != nums.end(); pos_itr++) {
      auto sum = *neg_itr + *pos_itr;
      auto found_itr = nums.end();
      if(sum < 0){
        found_itr = std::find(mid_itr,nums.end(),abs(sum));
      } else {
        found_itr = std::find(nums.begin(),mid_itr,abs(sum));
      }
      if(found_itr != nums.end()){
        found = true;
        result.push_back({*neg_itr,*pos_itr,*found_itr});
        if(found_itr == mid_itr){
          mid_itr = nums.erase(found_itr);
        } else {
          nums.erase(found_itr);
        }
        
        break;
      }
    }
    if(found){

    }
  }
  return result;
}