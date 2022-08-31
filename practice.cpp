#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
    int res = 0;
    while(x){
        res = res*10 + x%10;
        x /= 10;
    }
    return res;
}

int atoi(string str){
    int indicator = 1;
    int ans = 0;
    
    for(int i=0;i<str.size();i++){
        i = str.find_first_not_of(' ');
        if(str[i] == '-'){
            indicator = -1;
        }
        while('0'<=str[i] && str[i]<='9'){
            ans = ans*10 + (str[i++] - '0');
        }
        return ans*indicator;
    }
}

string longestCommonPrefix(vector<string> &str){
    sort(str.begin(), str.end());
    string ans;
    int n = str.size();
    string a = str[0];
    string b = str[n-1];
    for(int i=0;i<str.size();i++){
        if(a[i] == b[i]){
            ans += a[i];
        }
    }
    return ans;
}

string lps(string str){
    int n = str.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));
    string ans;
    int maxLength = 0;
    for(int diff=0;diff<str.size();diff++){
        for(int i=0,j=i+diff;j<n;i++,j++){
            if(i == j){
                dp[i][j] = 1;
            }else if(diff == 1){
                dp[i][j] = str[i] == str[j] ? 2 : 0;
            }else{
                if(str[i] == str[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            }
            if(dp[i][j]){
                if(j-i+1>maxLength){
                    maxLength = j-i+1;
                    ans = str.substr(i, maxLength);
                }
            }
        }
    }
    return ans;
}

string LPS(string s){
    int n = s.size();
    string ans;
    int maxLength = 0;
    vector<vector<int>>dp(n, vector<int>(n,0));
    vector<vector<int>>dp(n, vector<int>(n,0));
    // vector<vector<int>>dp(n, vector<int>(n, 0));
    for(int diff=0;diff<n;diff++){
        for(int i=0,j=i+diff;j<n;i++,j++){
            if(i == j){
                dp[i][j] = 1;
            }else if(diff == 1){
                dp[i][j] = s[i] == s[j] ? 2 : 0;
            }else{
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            }
            if(dp[i][j]){
                if(j-i+1 > maxLength){
                maxLength = j-i+1;
                ans = s.substr(i,maxLength);
            }
            }
        }
    }
    return ans;
}

int main() {
    // Write C++ code here
    cout<<reverse(-123)<<"\n";
    cout<<atoi("-42")<<"\n";
    vector<string> arr = {"flower","flow","flight"};
    cout<<longestCommonPrefix(arr)<<"\n";
    cout<<LPS("babad");
    return 0;
}
