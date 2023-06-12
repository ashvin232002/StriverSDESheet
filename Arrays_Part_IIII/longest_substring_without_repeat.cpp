#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        if(s.empty()){
            return  0;
        }

        int i =0;
        int ans = 0;
        int j =0;
        while(i<s.size()){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]++;
                i++;
                ans=max(ans,(int)mp.size());
            }else{
                while(mp[s[i]]>0){
                    mp[s[j]]--;
                    if(mp[s[j]]==0){
                        mp.erase(s[j]);
                    }
                    j++;
                }
                mp[s[i]]++;
                i++;
            }
        }

        ans=max(ans,(int)mp.size());
        return ans;
    }
};