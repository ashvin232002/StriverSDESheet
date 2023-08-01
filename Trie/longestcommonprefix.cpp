#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      int childCount;
      bool isTerminal;


    TrieNode(char ch){
        data =  ch;
        for(int i =0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0 ;
    }
};

class Trie{
    public:
     TrieNode* root;

    Trie(char ch){
         root  =  new TrieNode(ch);
    }


    //insert  word functionlaity
    void insertUtil(TrieNode* root,string word){
         if(word.length() == 0){
             root->isTerminal = true;
             return;
         }

         int index =  word[0]-'a';//assume that all words are capital
         TrieNode* child;

         if(root->children[index] != NULL){
            //basically present the character
            child  = root->children[index];
         }else{
            //basically not present the character
            //so for that reason create a child node
            child  =  new TrieNode(word[0]);
            // insert into the trie 
            root->childCount++;
            root->children[index] = child;
         }
         insertUtil(child,word.substr(1));
    }


    void insertWord(string word){
        insertUtil(root,word);
    }



    bool searchUtil(TrieNode* root,string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index  =  word[0]-'a';
        TrieNode* child;

        if(root->children[index] == NULL){
            return false;
        }else{
            child  =  root->children[index];
        }
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }

    void lcp(string str , string & ans){
         for(int  i = 0;i<str.size();i++){
             int ch =  str[i];
             if(root->childCount  == 1){
                 ans.push_back(ch);
                 int index  =  ch-'a';
                 root  =  root->children[index];
             }else{
                 //if child count is greater than one no need to proceed want a break;
                 break;
             }

             if(root->isTerminal==true){
                 break;
             }
         }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t =  new Trie('\0');

        for(int  i = 0;i<strs.size();i++){
            if(strs[i]==""){
                return "";
            }
            t->insertWord(strs[i]);
        }

        string first  =  strs[0];
        string ans  = "";

        t->lcp(first,ans);
        return ans;
    }
};