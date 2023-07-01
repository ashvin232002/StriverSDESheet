#include<bits/stdc++.h>
using namespace std;


//roman to int
class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp ={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int count = 0 ;
        int total =0;
        total += mp[s.back()];

        for(int  i =s.size()-2;i>=0;i--){
            if(mp[s[i]]<mp[s[i+1]]){
                total -=mp[s[i]];
            }else{
                total+=mp[s[i]];
            }
        }
        return total;
    }
};


//int to roman
class Solution {
public:
    string intToRoman(int num) {
        int integer[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string ans ="";
        for(int i =0;i<13;i++){
            int val=integer[i];
            while(num>=val){
                ans+=s[i];
                num=num-val;
            }
        }
        return ans;
    }
};