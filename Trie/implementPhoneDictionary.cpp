#include<bits/stdc++.h>
using namespace std;

//leetcode 1268 Medium marked but hard question

class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i =0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
     TrieNode* root;
    
    Trie(){
        root  =  new TrieNode('\0');
    }

    //support function to insert a word
    void insertUtil(TrieNode* root, string word){
        if(word.length()==0){
            //word length is zero check it's lastnode or not
            root->isTerminal  =  true;
            return;
        }

        TrieNode* child ;
        int index  =  word[0]-'a';

        if(root->children[index]!=NULL){
            //if children is not null character is already exists
            child  = root->children[index];

        }else{
            //children is NULL character is NULL , need to create a NEW node  
            child  =  new TrieNode(word[0]);
            root->children[index] =  child;
        }
        insertUtil(child,word.substr(1));
    }

    //insert a word
    void insertWord(string word){
        insertUtil(root,word);
    }


    //support function to search a particular word
    bool searchUtil(TrieNode* root, string word){
        if(word.length()==0){
            //check if it is last Node or not
            return root->isTerminal;
        }

        TrieNode* child ;
        int index  =  word[0]-'a';

        if(root->children[index]==NULL){
            //if particular character is not exists
            return false;
        }else{
            //if character is exists then find further
            child  =  root->children[index];
        }

        //check further 
        return searchUtil(child,word.substr(1));
    }

    //function to search a word
    bool  searchWord(string word){
        return searchUtil(root,word);
    }

    void printSuggestions(TrieNode* curr , vector<string>& temp,string prefix){
         if(curr->isTerminal){
             temp.push_back(prefix);
         }

         for(char ch = 'a' ; ch<='z' ; ch++){
             TrieNode* next =  curr->children[ch-'a'];

             if(next!=NULL){
                 prefix.push_back(ch);
                 printSuggestions(next,temp,prefix);
                 prefix.pop_back();
             }
         }
    }
    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev  = root;
        vector<vector<string>>output(str.size());
        string prefix ="";

        for(int i =0;i<str.size();i++){
            char lastchar =  str[i];
            prefix.push_back(lastchar);

            int index  =  str[i]-'a';
            
            //check for lastchar
            TrieNode* curr  =  prev->children[index];


            //if curr = NULL
            if(curr==NULL){
                 break;
            }

            vector<string>temp;
            printSuggestions(curr , temp ,prefix);

            sort(temp.begin(),temp.end());
            vector<string>temp2;
            for(int k =0;k<min((int)temp.size(),3);k++){
                  temp2.push_back(temp[k]);
            }
            
            output[i] = (temp2);
            temp.clear();
            prev =  curr;
        }
        
        return output;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
       Trie *t  = new Trie();

       for(int i =0;i<products.size();i++){
           t->insertWord(products[i]);
       }

       return t->getSuggestions(searchWord);

    }
};
