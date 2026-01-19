#include <iostream>
#include <string>
#include<vector>
using namespace std;
 void  longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(text1[idx1-1]==text2[idx2-1]) {
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                }
                else{
                    dp[idx1][idx2]=0+max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
                }
            }
         }
        int len=dp[n][m];
        string s('$',len);
        int idx1=n,idx2=m;
        int ptr=len-1;
        while(idx1>0 && idx2>0){
            if( text1[idx1-1]==text2[idx2-1]){
                s[ptr]=text1[idx1-1];
                ptr--;
                idx1--;
                idx2--;
            }
            //up
            else if(dp[idx1-1][idx2]>dp[idx1][idx2-1]){
                idx1--;
            }
            //left
            else{
                idx2--;
                
            }
        }
        cout<<s;
    }
int main() {
    string s1="abcde";
    string s2="bdqek";
    longestCommonSubsequence(s1,s2);
    return 0;
}