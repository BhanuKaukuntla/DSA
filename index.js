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

// Longest Substring Without Repeating Characters
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

var lengthOfLongestSubstring = function(s) {
    let maxLen = 0
    let start = 0
    let n = s.length
    let map = new Map()
    for(let i=0;i<n;i++){
        if(map.has(s[i])){
            start = Math.max(map.get(s[i]) + 1, start)
        }
        map.set(s[i], i)
        maxLen = Math.max(i - start + 1, maxLen)
    }
    return maxLen
};


// Container With Most Water
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49

 var maxArea = function(height) {
    let area = 0
    let maxArea = 0
    let left = 0
    let right = height.length-1
    while(left < right){
        area = Math.min(height[left], height[right]) * (right - left)
        maxArea = Math.max(area, maxArea)
        if(height[left] > height[right]){
            right--
        }else{
            left++
        }
    }
    return maxArea
};
