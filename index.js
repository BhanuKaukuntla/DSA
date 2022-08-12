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


// Roman to Integer
// Input: s = "III"
// Output: 3
// Explanation: III = 3.

symbols = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000
};
var romanToInt = function(s) {
    let value = 0
    for(let i=0;i<s.length;i++){
        symbols[s[i]] < symbols[s[i+1]] ? value -= symbols[s[i]] : value += symbols[s[i]]
    }
    return value
};


// 3Sum
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

function threeSum(nums) {
	const results = []

	// obviously irrelevant if we don't have at least 3 numbers to play with!
	if (nums.length < 3) return results

	// having the numbers in ascending order will make this problem much easier.
	// also, knowing the overall problem  will take at least O(N^2) time, we can
	// afford the O(NlogN) sort operation
	nums = nums.sort((a, b) => a - b)

    // if the question asks us for a custom target, we can control it here
	let target = 0

	for (let i = 0; i < nums.length - 2; i++) {
		// `i` represents the "left" most number in our sorted set.
		// once this number hits 0, there's no need to go further since
		// positive numbers cannot sum to a negative number
		if (nums[i] > target) break

		// we don't want repeats, so skip numbers we've already seen
		if (i > 0 && nums[i] === nums[i - 1]) continue

		// `j` represents the "middle" element between `i` and `k`.
		// we will increment this up through the array while `i` and `k`
		// are anchored to their positions. we will decrement `k` for
		// for each pass through the array, and finally increment `i`
		// once `j` and `k` meet.
		let j = i + 1

		// `k` represents the "right" most element
		let k = nums.length - 1
		
		// to summarize our setup, we have `i` that starts at the beginning,
		// `k` that starts at the end, and `j` that races in between the two.
		//
		// note that `i` is controlled by our outer for-loop and will move the slowest.
		// in the meantime, `j` and `k` will take turns inching towards each other depending
		// on some logic we'll set up below. once they collide, `i` will be incremented up
		// and we'll repeat the process.

		while (j < k) {
			let sum = nums[i] + nums[j] + nums[k]

			// if we find the target sum, increment `j` and decrement `k` for
			// other potential combos where `i` is the anchor
			if (sum === target) {
				// store the valid threesum
				results.push([nums[i], nums[j], nums[k]])

				// this is important! we need to continue to increment `j` and decrement `k`
				// as long as those values are duplicated. in other words, we wanna skip values
				// we've already seen. otherwise, an input array of [-2,0,0,2,2] would result in
				// [[-2,0,2], [-2,0,2]].
				//
				// (i'm not a fan of this part because we're doing a while loop as we're
				// already inside of another while loop...)
				while (nums[j] === nums[j + 1]) j++
				while (nums[k] === nums[k - 1]) k--

				// finally, we need to actually move `j` forward and `k` backward to the
				// next unique elements. the previous while loops will not handle this.
				j++
				k--

			// if the sum is too small, increment `j` to get closer to the target
			} else if (sum < target) {
				j++

			// if the sum is too large, decrement `k` to get closer to the target
			} else { // (sum > target)
				k--
			}
		}
	}

	return results
};


// Search in Rotated Sorted Array
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

 var search = function(nums, target) {
    let ans = -1
    for(let i=0;i<nums.length;i++){
        if(nums[i] == target){
            ans = i
        }
    }
    return ans
};



// Trapping Rain Water
// Input: height = [4,2,0,3,2,5]
// Output: 9

 var trap = function(height) {
    let ans = 0
    let lMax = {}
    let rMax = {}
    let n = height.length
    lMax[0] = height[0]
    for(let i=1;i<n;i++){
        lMax[i] = Math.max(height[i], lMax[i-1])
    }
    rMax[n-1] = height[n-1]
    for(let i=n-2;i>=0;i--){
        rMax[i] = Math.max(height[i], rMax[i+1])
    }
    for(let i=0;i<n;i++){
        ans += Math.min(lMax[i], rMax[i]) - height[i]
    }
    return ans
};


// Best Time to Buy and Sell Stock
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

var maxProfit = function(prices) {
    let maxProfit = 0
    let buy = prices[0]
    for(let i=0;i<prices.length;i++){
        buy = Math.min(prices[i], buy)
        maxProfit = Math.max(prices[i]-buy, maxProfit)
    }
    return maxProfit
};


// Majority Element
// Input: nums = [3,2,3]
// Output: 3

var majorityElement = function(nums) {
    let ans = null
    let map = new Map()
    for(let i=0;i<nums.length;i++){
        if(map.has(nums[i])){
            map.set(nums[i], map.get(nums[i]) + 1)
        }else{
            map.set(nums[i], 1)
        }
    }
    map.forEach((key, value)=> {
        if(key >= nums.length/2){
            ans = value
        }
    })
    return ans
};

nums = [3,2,3]
console.log(majorityElement(nums))


// Contains Duplicate
// Input: nums = [1,2,3,1]
// Output: true

var containsDuplicate = function(nums) {
    let ans = false
    let map = new Map()
    for(let i=0;i<nums.length;i++){
        if(map.has(nums[i])){
            map.set(nums[i], map.get(nums[i])+1)
        }else{
            map.set(nums[i],1)
        }
    }
    map.forEach((key,value)=> {
      console.log(key, value)
      if(key >= 2){
        ans = true
      }
    })
    return ans
};


// Missing Number
// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.


var missingNumber = function(nums) {
    let arrSum = 0
    let n = nums.length
    let sum = (n*(n+1)/2)
    for(let i=0;i<n;i++){
        arrSum += nums[i]
    }
    let ans = sum - arrSum
    return ans
};



// Move Zeroes
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

function moveZeroes(nums) {
    var idx = 0
    for(let i=0;i<nums.length;i++){
        if(nums[i] != 0){
            nums[idx] = nums[i]
            nums[i] = idx == i ? nums[i] : 0
            idx++
        }
    }
      return nums
  }



  
// Javascript program to add two numbers
// represented by linked list
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
var head1, head2;

class Node
{
	constructor(val)
	{
		this.data = val;
		this.next = null;
	}
}
var addTwoLists = function(first, second) {
    var List = new Node(0);
    var head = List;
    var sum = 0;
    var carry = 0;

    while(first!==null||second!==null||sum>0){

        if(first!==null){
            sum = sum + first.data;
            first = first.next;
        }
        // console.log(first)
        if(second!==null){
            sum = sum + second.data;
            second = second.next;
        }
        if(sum>=10){
            carry = 1;
            sum = sum - 10;
        }
        // console.log("sum", sum)
        head.next = new Node(sum);
        head = head.next;

        sum = carry;
        carry = 0;

    }
    // console.log(List.next)
    return List.next;
};

/* Utility function to print a
linked list */
function printList(head)
{
	while (head != null)
	{
		document.write(head.data + " ");
		head = head.next;
	}
	document.write("<br/>");
}

// Driver Code
// Creating first list
head1 = new Node(7);
head1.next = new Node(5);
head1.next.next = new Node(9);
head1.next.next.next = new Node(4);
head1.next.next.next.next = new Node(6);
document.write("First List is ");
printList(head1);

// Creating second list
head2 = new Node(8);
head2.next = new Node(4);
document.write("Second List is ");
printList(head2);

// Add the two lists and see the
// result
rs = addTwoLists(head1, head2);
document.write("Resultant List is ");
printList(rs);
// console.log(addTwoLists(head1, head2))
// This code is contributed by aashish1995