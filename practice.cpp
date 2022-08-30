#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
    long long res=0;
    while(x){
        res = res*10 + x%10;
        x /= 10;
    }
    return (res<INT_MIN || res>INT_MAX) ? 0 : res;
}

int atoi(string str){
    int indicator = 1;
    int result = 0;
    for(int i=0;i<str.size(); i++){
        if(str[i] == '-'){
            indicator = -1;
        }
        while('0'<=str[i] && str[i]<='9'){
            result = result*10 + (str[i++] - '0');
        }
        return result*indicator;
    }
}

string longestCommonPrefix(vector<string>& str){
    int n = str.size();
    string ans;
    sort(str.begin(), str.end());
    string a = str[0];
    string b = str[n-1];
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            ans += a[i];
        }
    }
    return ans;
}

int main() {
    // Write C++ code here
    vector<string> arr = {"flower","flow","flight"};
    cout<<longestCommonPrefix(arr);
    return 0;
}
