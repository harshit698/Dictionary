#include<bits/stdc++.h>
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		
		return insertWord(child, word.substr(1));
	}

	
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    int k=0;
    void autoComplete(vector<string> input, string pattern) {
        
      for(int i=0;i<input.size();i++){
        
        insertWord(input[i]);
      }
      autoComplete(root,input,pattern,k);
      
    }
    
 
  void autoComplete(TrieNode *root,vector<string> input, string pattern,int k) {
        
      
    if(root==NULL){
      return;
    }
    
    if(pattern[0]=='\0'){
      
      for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
          cout<<root->children[i]->data<<endl;
          autoComplete(root->children[i],input,pattern);
        }
      }
      
      int index=pattern[k]-'a';
    }
    
    	if(root->children[index]!=NULL){
          
          autoComplete(root->children[index],input,pattern,k++);
          
        }
    else{
      return;
    }    
    }
};

