// Two Sum
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

const twoSum = (nums, target) => {
    let map = new Map()
    for(let i=-0;i<nums.length;i++){
        if(map.get(nums[i]) == undefined){
            map.set(target - nums[i], i)
        }else{
            return [map.get(nums[i]), i]
        }
    }
  };