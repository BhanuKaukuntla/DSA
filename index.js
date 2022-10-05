// 1
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

// 2
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


// 3
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


// 4
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


// 5
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


// 6
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


// 7
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


// 8
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


// 9
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


// 10
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

// 11
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


// 12
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

// 13
// Longest Palindromic Substring
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

  var longestPalindrome = function(s) {
    
	if(s.length <= 1) return s;
	
	// construct a 2D array
    const dp = [...new Array(s.length + 1)].map(_ => new Array(s.length + 1).fill(false));
	
    let lps = '';
    
	// base case for one character
    for(let i = 0; i < s.length; i++) {
        dp[i][i] = true;
        lps = s[i];
    }
    
	// base case for two characters
    for(let i = 0; i < s.length; i++) {
        if(s[i] === s[i + 1]) dp[i][i+1] = true;
        if(dp[i][i+1]) lps = s.substring(i, i + 2);
    }

    // expand to three or more characters
    for(let i = s.length - 1; i >= 0; i--) {
        for(let j = i + 2; j < s.length; j++) {
            dp[i][j] = dp[i+1][j-1] && s[i] === s[j];
            if(dp[i][j]) lps = lps.length < (j - i + 1) ? s.substring(i, j + 1) : lps;
        }
    }
    
    return lps;
}
  
  or 
  
function longestPalindrome(str)
{
    let n = str.length; // calculating size of string
    if (n < 2)
        return str; // if string is empty then size will be 0.
                // if n==1 then, answer will be 1(single
                // character will always palindrome)
 
    let maxLength = 1,start=0;
    let low, high;
    for (let i = 0; i < n; i++) {
        low = i - 1;
        high = i + 1;
        while ( high < n && str[high] == str[i]) //increment 'high'                               
            high++;
     
        while ( low >= 0 && str[low] == str[i]) // decrement 'low'               
            low--;
     
        while (low >= 0 && high < n && str[low] == str[high]){
            low--;
            high++;
        }
 
        let length = high - low - 1;
        if (maxLength < length) {
            maxLength = length;
            start=low+1;
        }
    }
     
    // document.write("Longest palindrome substring is: ");
    // document.write(str.substring(start,maxLength+start));
    return str.substring(start,maxLength+start);
}
  
// 14
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
// console.log(addTwoLists(head1, head2))
printList(rs);


or

//  * function ListNode(val) {
//  *     this.val = val;
//  *     this.next = null;
//  * }

var addTwoNumbers = function(l1, l2) {
    var List = new ListNode(0);
    var head = List;
    var sum = 0;
    var carry = 0;

    while(l1!==null||l2!==null||sum>0){

        if(l1!==null){
            sum = sum + l1.val;
            l1 = l1.next;
        }
        if(l2!==null){
            sum = sum + l2.val;
            l2 = l2.next;
        }
        if(sum>=10){
            carry = 1;
            sum = sum - 10;
        }

        head.next = new ListNode(sum);
        head = head.next;

        sum = carry;
        carry = 0;

    }

    return List.next;
};


// 15
// Binary Tree Inorder Traversal
// Input: root = [1,null,2,3]
// Output: [1,3,2]


function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}
var root;
function inorderTraversal(root) {
 const stack = [];
 const res = [];

 while (root || stack.length) {
   if (root) {
     stack.push(root);
     root = root.left;
   } else {
     root = stack.pop();
     res.push(root.val);
     root = root.right;
   }
 }

 return res;
}

root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
console.log(inorderTraversal(root))


// 16
// Median of Two Sorted Arrays
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000

var findMedianSortedArrays = function(nums1, nums2) {
    if(nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1)
    let x = nums1.length
    let y = nums2.length
    let low = 0, high = x
    while(low <= high) {
        const partitionX = (high + low) >> 1
        const partitionY = ((x + y + 1) >> 1) - partitionX
        
        const maxX = partitionX == 0 ? Number.NEGATIVE_INFINITY : nums1[partitionX - 1]
        const maxY = partitionY == 0 ? Number.NEGATIVE_INFINITY : nums2[partitionY - 1]
        
        const minX = partitionX == nums1.length ? Number.POSITIVE_INFINITY : nums1[partitionX]
        const minY = partitionY == nums2.length ? Number.POSITIVE_INFINITY : nums2[partitionY ]
        
        if(maxX <= minY && maxY <= minX) {
            const lowMax = Math.max(maxX, maxY)
            if( (x + y) % 2 == 1)
                return lowMax
            return (lowMax + Math.min(minX, minY)) / 2
        } else if(maxX < minY) {
            low = partitionX + 1
        } else 
            high = partitionX - 1
    }
    
};


// 17
// Remove Nth Node From End of List
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

function Node(val) {
    this.data = val;
	this.next = null;
}
var RemoveNodeFromList = function(head, n) {
        var start = new Node();
        start.next = head;
        var fast = start;
        var slow = start;
        for(let i=0;i<=n;i++){
            fast = fast.next;
        }
        while(fast.next!= null){
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return start.next;
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
head1 = new Node(1);
head1.next = new Node(2);
head1.next.next = new Node(3);
head1.next.next.next = new Node(4);
head1.next.next.next.next = new Node(5);
document.write("First List is ");
printList(head1);

// Add the two lists and see the
// result
let n = 2
rs = RemoveNodeFromList(head1, n-1);
document.write("Resultant List is ");
// console.log(addTwoLists(head1, head2))
printList(rs);



// 18
// Valid Parentheses
// Input: s = "()[]{}"
// Output: true
// Input: s = "(]"
// Output: false

var isValid = function(s) {
    let map = {
        ")": "(",
        "]": "[",
        "}": "{"
    }
    let arr = [];
    for(let i = 0; i < s.length; i ++){
        if(s[i] === "(" || s[i] === "[" || s[i] === "{"){
            arr.push(s[i]);
        }
        else{
            if(arr[arr.length - 1] === map[s[i]]){
                arr.pop();
            }
            else return false;
        }
    }
    return arr.length === 0 ? true : false;
};
