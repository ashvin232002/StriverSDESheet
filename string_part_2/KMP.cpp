//writing the pseduo code

//take one array 
// LPS(N)   (Longest Proper Prfix which is also a Proper Suffix)
//Proper Prefix and Proper Suffix simply means that it does not include a whole string




/*
//This is The Pseduo code to fill the LPS table .
int i  = 1, int len  =  1

while(i<s.size()){
    if(s[i]==s[len]){
        len++;
        LPS[i] =  len ;
        i++;
    }else{
        if(len>0){
            len  =  LPS[len-1];
        }else{
            LPS[i]=0;
            i++;
        }
    }
}
*/


/*
DRY Run The Example

//count the number of times the pattern occurs inside the string s
s  =  "aabaacaabaad"
pattern =  "aab"

*/

#include<bits/stdc++.h>
using namespace std; 

vector<int>computeLPS(string pattern){
    int m  =  pattern.size();

    vector<int>lps(m,0);
    int i = 0;
    int j = 1;

    while(j<m){
        if(pattern[j]==pattern[i]){
            i++;
            lps[j]=i;
            j++;
        }else{
            if(i==0){
                lps[j]=0;
                j++;
            }else{
                i =  lps[i-1];
            }
        }
    }
    return lps;
}

vector<int> KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPS(pattern);
    vector<int>indices;
    int i = 0;
    int  j = 0;

    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;

            if(j==m){
                 indices.push_back(i-j);
                 j = lps[j - 1];
            }
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
    return indices;
}
int  main(){
     
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

     
     vector<int>ans  = KMPSearch(text, pattern);
     for(int  i= 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
     }
    return 0 ;

}
