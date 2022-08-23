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


int myAtoi(string str) {
    long result = 0;
    int indicator = 1;
    for(int i = 0; i<str.size();)
    {
        i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-')? -1 : 1;
        while('0'<= str[i] && str[i] <= '9') 
        {
            result = result*10 + (str[i++]-'0');
            if(result*indicator >= INT_MAX) return INT_MAX;
            if(result*indicator <= INT_MIN) return INT_MIN;                
        }
        return result*indicator;
    }
}


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
