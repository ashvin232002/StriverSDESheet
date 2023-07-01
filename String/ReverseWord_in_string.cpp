#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;

        int j =0;
       
        while(j<s.size()){
            if(s[j]!=' '){
                int i =j;
                 string temp ="";
                while(i<s.size()){
                    if(s[i]==' '){
                        break;
                    }else{
                        temp+=s[i];
                        i++;
                    }
                }
                st.push(temp);
                i++;
                j=i;
            }else{
                j++;
            }
        }

        string ans ="";

        while(!st.empty()){
            string curr  =  st.top();
            st.pop();
            if(!st.empty()){
                ans+=curr;
                ans+=" ";
            }else{
                ans+=curr;
            }
        }
        return ans;
    }
};