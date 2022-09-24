// 1
// Reverse Integer
// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};


// 2
// String to Integer (atoi)
// Input: s = "   -42"
// Output: -42


class Solution {
public:
    int myAtoi(string str)
{
    //Your code here
    int result=0;   //Stores and returns the integer converted value for str
    int i=0;    //just a current character pointer for string
    int sign = 1;   //multiplied at the end to result to determine if the string is +ve or -ve
    i = str.find_first_not_of(' ');
    if(str[i]=='-') //Check the sign of string (+ or -)
    {
        sign = -1;
        i++;
    }
    //Now traverse the entire string and convert it into integer
    while(str[i])
    {
        //If any character is not an integer then just return -1
        
        if(!(str[i]-'0'>=0 && str[i]-'0'<=9))
            return -1;
        //else just keep updating the result
        result = result*10 + str[i]-'0';
        i++;
    }
    return result*sign;
}
};


// 3
// Longest Palindromic Substring
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

#include<bits/stdc++.h>
using namespace std;

string lPS(string s){
    int n = s.size();
    vector<vector<int>>dp(n, vector<int>(n,0));
    int maxLength = 0;
    string ans;
    for(int diff = 0;diff<n;diff++){
        for(int i=0, j=i+diff; j<n;i++,j++){
            if(i==j){
                dp[i][j]=1;
            }else if(diff == 1){
                dp[i][j] = s[i] == s[j] ? 2 : 0;
            }else{
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            }
            if(dp[i][j]){
                if(j-i+1>maxLength){
                    maxLength = j-i+1;
                    ans = s.substr(i, maxLength);
                }
            }
        }
    }
    return ans;
}

int main() {
    // Write C++ code here
    std::cout << lPS("babad") ;

    return 0;
}

// 4
// Longest Common Prefix
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        int n =strs.size();
        string ans; 
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i =0; i< a.size(); i++){
            if(a[i] == b[i]){
                ans += a[i];
            }else break;
        }
        return ans;
    }
};



// 5
// Merge two sorted lists

class Solution {

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // when list1 is empty then 
        // our output will be same as list2
        if(l1 == NULL) return l2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->val > l2->val) std::swap(l1,l2);

        // act as head of resultant merged list
        ListNode* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            ListNode* temp = NULL;

            while(l1 != NULL && l1->val <= l2->val) {

                temp = l1;//storing last sorted node  
                l1 = l1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            std::swap(l1,l2);
        }

        return res;
    }
};


// 6
// Merge k Sorted Lists
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
class Solution {
public:
ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
    priority_queue<ListNode *, vector<ListNode *>, compare> q;
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    for(int i=0;i<lists.size();i++) {
        if(lists[i] != NULL)  q.push(lists[i]);
    }           
    while(!q.empty()) {
        ListNode* temp = q.top();
        tail->next = temp;
        tail=temp;
        q.pop();
        if(temp->next !=NULL) q.push(temp->next);
    }
    return dummy->next;
}
};


// 7
// Remove Duplicates from Sorted Array
// Input: nums = [1,1,2]
// Output: nums = [1,2]



class Solution{
    public:
    ListNode* deleteDuplicates(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp->next != NULL){
            if(temp->val == temp->next->val){
                ListNode* del = temp->next;
                temp->next = del->next;
                delete del;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
}



// 8
// Sudoku Solver


#include <iostream>

#include <vector>

using namespace std;

bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solve(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solve(board))
              return true;
            else
              board[i][j] = '.';
          }
        }

        return false;
      }
    }
  }
  return true;
}
int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solve(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}


// 9
// Count and Say
// Input: n = 4
// Output: "1211"

string countAndSay(int n, string s = "1") { // initial value of the string is "1"
    if(n==1) return s; // base case, when n recursive calls are finished
	
    int i=0, j, len = s.size(); // 'len' is the length of the string 's'
    string res = ""; // result after we 'say' the string 's'
	
	// 'i' starts from index 0
    while(i<len) {
        j=i; // fix 'j' as the current position (i)
		
		// increment the value of 'i' till valid position
        while(i<len && s[i]==s[j]) i++;
		
		// substring with same values as s[j] is [j,i-1] & "i-j" is the count of that value
		// add the concatenation of (count + s[j]) to the result 
        res += to_string(i-j) + s[j];
    }
	
	// recursively, call the same function by decrementing the count
	// and update the result 'res', which will be the next string 's'
    return countAndSay(n-1, res);
}


// 10
// First Missing Positive
// Input: nums = [3,4,-1,1]
// Output: 2

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i+1==nums[i]) continue;
            int x = nums[i];
            while(x>=1 && x<=nums.size() && x!=nums[x-1]){
                swap(x, nums[x-1]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(i+1!=nums[i])    return i+1;
        }
        return nums.size()+1;
    }
};


// 11
// Letter Combinations of a Phone Number
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combs;
        string comb;
        combine(digits, 0, comb, combs);
        return combs;
    }
private:
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void combine(string digits, int i, string comb, vector<string>& combs) {
        if (i == digits.size()) {
            if (!comb.empty()) {
                combs.push_back(comb);
            }
        } else {
            for (char c : dict[digits[i] - '0']) {
                combine(digits, i + 1, comb + c, combs);
            }
        }
    }
};

// 12
// Find First and Last Position of Element in Sorted Array
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {BinarySearch(nums, target, "FIRST"), BinarySearch(nums, target, "LAST")};
    }
    
    int BinarySearch(vector<int> nums, int num, string find) {
        int left = 0, right = nums.size() - 1, mid;
        int result = -1;

        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] == num) {
                result = mid;
                (find == "FIRST") ? right = mid - 1 : left = mid + 1;
            }
            else if (nums[mid] > num) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return result;
    }
};




// 13
// Generate Paranthesis
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

class Solution{
    public:
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        func(ans, n, 0, 0, "");
        return ans;
    }
    void func(vector<string>& ans, int n, int open, int close, string curr_str){
        if(curr_str.size() == n*2){
            ans.push_back(curr_str);
            return;
        }
        if(open<n) func(ans, open+1, close, curr_str+"(");
        if(close<open) func(ans, open, close+1, curr_str+")");
    }
}


// 14
// Permutations
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


#include<bits/stdc++.h>

using namespace std;
class Solution {
  private:
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;
    }
};

int main() {
  Solution obj;
  vector < int > v {1,2,3};
  vector < vector < int >> sum = obj.permute(v);
  cout << "All Permutations are" << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }
}


// 15
// Rotate Image
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]


class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        int n = M.size();
        
        //First transpose the matrix once!
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
               swap(M[i][j], M[j][i]);
            }
        }
        
        //Reverse every column!
        for(int i=0; i<n; i++){
            reverse(M[i].begin(), M[i].end());
        }
    }
};

// 16
// Group Anagrams
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

//Hashtable
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> rlt;
        int i=0;
        for(string s : strs){
            sort(s.begin(), s.end());
            map[s].push_back(strs[i++]);
        }
        
        for(auto p : map){
            sort(p.second.begin(), p.second.end());
            rlt.push_back(p.second);
        }
        
        return rlt;
    }
};



// 17
// Pow(x, n)
// Input: x = 2.00000, n = 10
// Output: 1024.00000


#include<bits/stdc++.h>

using namespace std;
double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}

int main() {
  cout << myPow(2, 10) << endl;
}



// 18
// Maximum Subarray
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        for (int num : nums) {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return smax;
    }
};



// 19
// Spiral Matrix
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]


#include <bits/stdc++.h>

using namespace std;

const int R = 4, C = 4;

void printSpiral(int mat[4][4], int R, int C) {
  int top = 0, left = 0, bottom = R - 1, right = C - 1;

  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++)
      cout << mat[top][i] << " ";

    top++;

    for (int i = top; i <= bottom; i++)
      cout << mat[i][right] << " ";

    right--;

    if (top <= bottom) {
      for (int i = right; i >= left; i--)
        cout << mat[bottom][i] << " ";

      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        cout << mat[i][left] << " ";

      left++;
    }
  }
}

int main() {
  int arr[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
	           {9, 10, 11, 12},
		   {13, 14, 15, 16}};
  printSpiral(arr, R, C);

  return 0;
}

// 20
// Jump Game
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

bool canJump(vector<int>& nums) {
      int n = nums.size(), farest = 0;
      for(int i = 0;i < n; i++)
      {
        if(farest < i) return false;
        farest = max(i + nums[i], farest);
      }
      
      return true;
    }


// 21
// Merge Intervals
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0) {
            return mergedIntervals; 
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0]; 
        
        for(auto it : intervals) {
            if(it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1], tempInterval[1]); 
            } else {
                mergedIntervals.push_back(tempInterval); 
                tempInterval = it; 
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals; 
    }
};

// 22
// Unique Paths
// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};




// 23
// Plus One
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1;i >= 0;i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};




// 24
// Sqrt(x)
// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.


class Solution {
public:
    int mySqrt(int x) {
        long long s=0, e=x, ans, mid;   //long long due to some of test cases overflows integer limit.
        while(s<=e){             
            mid=(s+e)/2;
            if(mid*mid==x) return mid;     //if the 'mid' value ever gives the result, we simply return it.
            else if(mid*mid<x){             
                s=mid+1;        //if 'mid' value encounterted gives lower result, we simply discard all the values lower than mid.
                ans=mid;        //an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value. 
            }
            else e=mid-1;       //if 'mid' value encountered gives greater result, we simply discard all the values greater than mid. 
        }
        return ans;   
    }
};



// 25
// Climbing Stairs
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step


#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}



// 26
// Set Matrix Zeroes
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}


// 27
// Sort Colors
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
         
    }
};


// 28
// Merge Sorted Array
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};


// 29
// Subsets
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};

//30
// Two Sum
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};


//31
// Longest Substring Without Repeating Characters
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};

int main() {
  string str = "takeUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}


//32 
// Container With Most Water
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &nums)
{
    int i = 0,j = nums.size() - 1, mx = INT_MIN;
	while(i < j)
	{
		int water = (j-i)*min(nums[i],nums[j]);
		mx = max(mx,water);
		if(nums[i] < nums[j])
		    i++;
		else
		    j--;
	}
	
	return mx;
}

int main() {
    vector<int> nums {1, 4, 2, 3};
  
    cout << "Maximum amount of water is: " << maxArea(nums);
  
    return 0;
}



//33
// Roman to Integer
// Input: s = "III"
// Output: 3
// Explanation: III = 3.



int romanToInt(string s) 
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;
}


//34
// 3Sum
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
int main() {
  vector < int > arr{-1,0,1,2,-1,-4};
  vector < vector < int >> ans;
  ans = threeSum(arr);
  cout << "The triplets are as follows: "<< endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] <<" ";
    }
    cout << endl;
  }
  return 0;
}



// 35
// Search in Rotated Sorted Array
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

#include<bits/stdc++.h>

using namespace std;

int search(vector < int > & nums, int target) {
  int low = 0, high = nums.size() - 1; //<---step 1

  while (low <= high) { //<--- step 2
    int mid = (low + high) >> 1; //<----step 3
    if (nums[mid] == target)
      return mid; // <---step 4

    if (nums[low] <= nums[mid]) { //<---step 5
      if (nums[low] <= target && nums[mid] >= target)
        high = mid - 1; //<---step 6 
      else
        low = mid + 1; //<---step 7
    } else { //<---step 7
      if (nums[mid] <= target && target <= nums[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return -1; //<---step 8
}

int main() {
  vector<int> nums = {4,5,6,7,0,1,2,3};
  int target = 3;
  cout << "The index in which the target is present is " << search(nums, target);

  return 0;
}


// 36
// Trapping Rain Water
// Input: height = [4,2,0,3,2,5]
// Output: 9

#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}



// 37
// Best Time to Buy and Sell Stock
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
	
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}



// 38
// Majority Element
// Input: nums = [3,2,3]
// Output: 3
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate) count += 1; 
            else count -= 1; 
        }

        return candidate;
    }
};

or 
	
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }
};



// 39 part-1
// Contains Duplicate
// Input: nums = [1,2,3,1]
// Output: true

#include<bits/stdc++.h>
using namespace std;
    
bool containsDuplicate(vector<int> nums) {
 
    unordered_set<int> set;
    
    for(int i = 0; i<nums.size();i++){
        set.insert(nums[i]);
    }
    
    // if it contains duplicate then the size of 
    // set will not equal to the length of the array
    if(set.size() < nums.size())
        return true;
    
    return false;
}
    
int main () {
	    
    vector<int> nums {1, 2, 3, 1};
    
    bool res = containsDuplicate(nums);
    
    // printing the result
    if(res== 1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}

// 39 part-2
// Find Duplicate
// Input: nums = [1,2,3,1]
// Output: 1

#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}


// 40
// Missing Number
// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

// Input Format:  array[] = {3,1,2,5,3}

// Result: {3,4)

// Explanation: A = 3 , B = 4 
// Since 3 is appearing twice and 4 is missing

vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}


// 41
// Move Zeroes
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

#include<bits/stdc++.h>

using namespace std;
void zerosToEnd(int arr[], int n) {

  //finding first zero occurrence
  int k = 0;
  while (k < n) {
    if (arr[k] == 0) {

      break;
    } else {
      k = k + 1;
    }
  }

  //finding zeros and immediate non-zero elements and swapping them
  int i = k, j = k + 1;

  while (i < n && j < n) {
    if (arr[j] != 0) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;

    }

    j++;

  }
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int arr[] ={ 1,2,0,1,0,4,0};
  zerosToEnd(arr, 7);
}

//42
// Javascript program to add two numbers
// represented by linked list
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};


// 43
// Binary Tree Inorder Traversal
// Input: root = [1,null,2,3]
// Output: [1,3,2]


#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

  vector < int > inOrder;
  inOrderTrav(root, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
  return 0;
}



// 44
// Remove Nth Node From End of List
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};

// 45
// Median of Two Sorted Arrays
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000

#include<bits/stdc++.h>
using namespace std;

float median(int num 1[],int num2[],int m,int n) {
    if(m>n)
        return median(nums2,nums1,n,m);//ensuring that binary search happens on minimum size array
        
    int low=0,high=m,medianPos=((m+n)+1)/2;
    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = medianPos - cut1;
        
        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
        int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
        
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
}

int main() {
    int nums1[] = {1,4,7,10,12};
    int nums2[] = {2,3,6,15};
    int m = sizeof(nums1)/sizeof(nums1[0]);
    int n = sizeof(nums2)/sizeof(nums2[0]);
    cout<<"The Median of two sorted arrays is"<<fixed<<setprecision(5)
    <<median(nums1,nums2,m,n);
    return 0;
}


// 46
// Valid Parentheses
// Input: s = "()[]{}"
// Output: true
// Input: s = "(]"
// Output: false

#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
        stack<char>st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
    }
int main()
{
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}


// 47
// Symmetric Tree
// Input: root = [1,2,2,3,4,4,3]
// Output: true


#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool isSymmetricUtil(node * root1, node * root2) {
  if (root1 == NULL || root2 == NULL)
    return root1 == root2;
  return (root1 -> data == root2 -> data) && isSymmetricUtil(root1 -> left, root2->
  right) && isSymmetricUtil(root1 -> right, root2 -> left);
}
bool isSymmetric(node * root) {
  if (!root) return true;
  return isSymmetricUtil(root -> left, root -> right);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> right = newNode(4);
  root -> right = newNode(2);
  root -> right -> left = newNode(4);
  root -> right -> right = newNode(3);

  bool res;
  res = isSymmetric(root);

  if (res)
    cout << "The tree is symmetrical";
  else cout << "The tree is NOT symmetrical";

  return 0;
}



// 48
// Binary Tree Level Order Traversal
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans; 
        
        if(root == NULL) 
            return ans; 
            
        queue<TreeNode*> q; 
        q.push(root); 
        
        while(!q.empty()) {
           
            TreeNode *temp = q.front(); 
            q.pop(); 
            
            if(temp->left != NULL) 
                q.push(temp->left); 
            if(temp->right != NULL) 
                q.push(temp->right); 
                
            ans.push_back(temp->val); 
        }
        return ans; 
    }
};

// 49
// Binary Tree Zigzag Level Order Traversal
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

#include<bits/stdc++.h>

using namespace std;

class Node {
  public:
    int val;
  Node * left, * right;
};

vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < Node * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      Node * node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);

      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}
Node * newNode(int data) {
  Node * node = new Node;
  node -> val = data;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}
int main() {
  int i, j;
  Node * root = newNode(3);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);
  vector < vector < int >> ans;
  ans = zigzagLevelOrder(root);
  cout << "Zig Zag Traversal of Binary Tree" << endl;
  for (i = 0; i < ans.size(); i++) {
    for (j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}



// 50
// Maximum Depth of Binary Tree
// Input: root = [3,9,20,null,null,15,7]
// Output: 3

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};


// 51
// Convert Sorted Array to Binary Search Tree
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* sortedArrayByBST(int arr[], int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayByBST(arr, start, mid-1);
    root->right = sortedArrayByBST(arr, mid+1, end);
}

void preOrderPrint(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main(){
    int arr[] = {10,20,30,40,50};
    Node* root = sortedArrayByBST(arr, 0, 4);
    preOrderPrint(root);
    cout<<endl;
    return 0;
}

or 
	
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int low,int high){
        if(low<=high){
            int mid = low + (high-low)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = helper(nums, low, mid-1);
            root->right = helper(nums, mid+1, high);
            return root;
        }
        return NULL;
    }
};


// 52
// Pascal's Triangle
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret;
	for (int i = 0; i < numRows; i++) {
		vector<int> row(i + 1, 1);
		for (int j = 1; j < i; j++) {
			row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
		ret.push_back(row);
	}
	return ret;
}
