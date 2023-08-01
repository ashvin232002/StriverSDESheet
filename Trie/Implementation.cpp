#include<bits/stdc++.h>
using namespace std;

//map takes O(length) time in wrost cases to find a particular word 
//or insert a particular word 

//so the solution fo that problem in a very precies way to use a
//trie data structure  which perform a opertaion in a O(1) time.


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
        root =  new TrieNode('\0');
    }


    //insert  word functionlaity
    void insertUtil(TrieNode* root,string word){
         if(word.length() == 0){
             root->isTerminal = true;
             return;
         }

         int index =  word[0]-'A';//assume that all words are capital
         TrieNode* child;

         if(root->children[index] != NULL){
            //basically present the character
            child  = root->children[index];
         }else{
            //basically not present the character
            //so for that reason create a child node
            child  =  new TrieNode(word[0]);
            // insert into the trie 
            root->children[index] = child;
         }
         insertUtil(child,word.substr(1));
    }


    void insertWord(string word){
        insertUtil(root,word);
    }


    //search functionality

    bool searchUtil(TrieNode* root,string word){
          if(word.length() == 0 ){
               return root->isTerminal;
          }

          int index  =  word[0]-'A';
          TrieNode* child;

          if(root->children[index]==NULL){
            //absent 
            return false;
          }else{
            //present that word[i]
            child  =  root->children[index];
          }
          return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
         return searchUtil(root,word);
    }
};



int main(){

    Trie *t =  new Trie();
    t->insertWord("abcd");

    cout<<"Present or nOt "<<t->searchWord("abcd")<<endl;
    return  0 ;

}