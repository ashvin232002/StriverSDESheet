#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>GenerateKMp(string &t){
        vector<int>kmp(t.size());
        int i=1, m =0;
        kmp[0]=0;
        while(i<t.size()){
             if(t[i]==t[m]){
                 m++;
                 kmp[i]=m;
                 i++;
             }else if(m>0){
                 m=kmp[m-1];
             }else{
                 kmp[i++]=0;
                 
             }
        }
        return kmp;
    }
    int strStr(string s, string t) {
        vector<int>kmp=GenerateKMp(t);
        for(int i =0,j=0;i<s.size();){
            if(t[j]==s[i]){
                i++;j++;
            }
            if(j==t.size())return i-j;
            if(i<s.size() && s[i]!=t[j]){
                if(j>0){
                    j=kmp[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
};