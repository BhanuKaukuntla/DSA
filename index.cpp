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



