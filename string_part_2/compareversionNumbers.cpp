#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int compareVersion(string s1, string s2) {
        int  i =0;
        int j = 0;

        int count1 = 0;
        int count2 = 0 ;

        while(i<s1.size() || j<s2.size()){
            while(i<s1.size() && s1[i]!='.'){
                count1= count1*10  + (s1[i]-'0');
                i++;
            }

            while(j<s2.size() && s2[j]!='.'){
                count2 = count2*10  + (s2[j]-'0');
                j++;
            }

            if(count1>count2)return 1;
            if(count2>count1)return -1;

            count1=0;
            count2=0;

            i++;
            j++;
        }
        
        return 0;
    }
};