#include<bits/stdc++.h>
using namespace std;

class TrieNode{
	
	public:
		char data;
		TrieNode **children;
		bool isTerminal;
		string matlab;
		
		TrieNode(char data){
			
			this->data=data;
			children = new TrieNode*[26];
			
			for(int i=0;i<26;i++){
				children[i]=NULL;
			}
			isTerminal=false;	
			matlab="NoMeaningFound";
		}
};

class Trie{
	
	TrieNode *root;
	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}
		
		bool searchWord(TrieNode* root,string word){
        
        if(word.size()==0){
            return root->isTerminal;
        }
        	int index =word[0]-'a';
			TrieNode *child;
			
			if(root->children[index]!=NULL){
				child=root->children[index];
			}
			else{
				return false;
			}
			
	return searchWord(child,word.substr(1));

    }
    
    bool searchWord(string word){
       bool ans=searchWord(root,word);
       
       if(ans){
       	cout<<root->matlab;
       	return true;
	   }
	   return false;
    }
		
		void removeWord(TrieNode *root,string word){
			
				if(word.size()==0){
					root->isTerminal==false;
					return;
				}
				

				TrieNode *child;
				int index=word[0]-'a';
				
				if(root->children[index]!=NULL){
					child=root->children[index];
				}
				else{
					return;
				}
				
				removeWord(child,word.substr(1));
					
				if(child->isTerminal==false){
					
					for(int i=0;i<26;i++){
						if(child->children[i]!=NULL){
							return;
						}
					} 
					
					delete child;
					root->children[index]=NULL;
				}
			}
			void removeWord(string word){
				removeWord(root,word);
			}		
		
	void Display(TrieNode *root,char str[],int level){
		
		if(root->isTerminal){
			str[level]='\0';
			cout<<str<<endl;
		}
		
		for(int i=0;i<26;i++){
			
			if(root->children[i]){
				str[level]=i+'a';
				Display(root->children[i],str,level+1);
			}
			
		}
			
	}	
	
	void DisplayTrie(char str[],int level){
		
		Display(root,str,0);
		
	}	
	bool insertWord(TrieNode *root, string word,string meaning) {
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

		return insertWord(child, word.substr(1),meaning);
	}


	void insertWord(string word,string meaning){
		root->matlab=meaning;
		if (insertWord(root, word,meaning)) {
			this->count++;
		}
	}
  
  void autoComplete(TrieNode *node,string pattern)
  {

   if(node->isTerminal == true)
   {
     cout<<pattern<<endl;
   }
	    string output; 
		int flag = 0;
	    TrieNode *child;
	   for(int i=0;i<26;i++)
	   {
	     if(node->children[i]!=NULL)
	     {
	       int index = i + 'a';
	       string s ;
	       s = (char)index;
	       output = pattern + s;
	       child = node->children[i];
	       autoComplete(child,output);
     }
     
   }
    return;
  }
    
    void autoComplete(string pattern) {
      
      TrieNode *node = root;
      string check = pattern;
      int flag = 0;
      while(check.size()!=0)
      {
        int index = check[0] - 'a';
        if(node->children[index]!=NULL)
        {
          node = node->children[index];
          check = check.substr(1);
        }
        else
        {
          flag = 1;
          cout<<" Empty";
          break;
        }
      }  
      
      if(flag!=1)
      autoComplete(node,pattern);
    }
		
};

int main(){
	
	Trie t;	
	t.insertWord("am","dfg");
	t.insertWord("abcd","df");
	t.insertWord("def","fg");
	t.insertWord("harshit","sdfg");
	t.insertWord("bh","sdf");
	t.insertWord("bha","sdf");
	t.insertWord("bhat","scv");
	t.insertWord("bhati","qwer");
	t.insertWord("bhatia","qwe");
	t.insertWord("den","asdf");
	t.insertWord("har","qdfger");
	t.insertWord("hars","qwscvr");
	t.insertWord("harsh","asdqwer");
	
	cout<<endl;
	cout<<endl;
	cout<<"                    ---------------Welcome to my own Dictionary named as Harshit's Dictionary---------------";
	cout<<endl;
	cout<<endl;
	cout<<"  ******MENU******"<<endl;
	cout<<endl;
	
	cout<<" 1.Search meaning of any word"<<endl;
	cout<<" 2.Add new word in the dictionary"<<endl;
	cout<<" 3.Delete any word from the dictionary"<<endl;
	cout<<" 4.You know only some starting alphabets of the word and wants some suggestions(autocomplete)"<<endl;
	cout<<" 5.See the search history."<<endl;
	cout<<" 6.See all the words present in the dictionary"<<endl;
	
	cout<<endl;
	
	int choice;
	string str,meaning;
	
	fstream fio; 
    
    fio.open("history.txt", ios::app| ios::out | ios::in); 
     
	do{
		cout<<"Enter your choice :";
		cin>>choice;
		if(choice ==1){
			cout<<"Enter the word you want to search:"<<endl;
			cin>>str;
			cout<<endl;
			if(t.searchWord(str)){
				cout<<endl;
			}
			else{
				cout<<"     ***word not found***"<<endl;
				cout<<"Don't worry may be you are not entering the word correctly"<<endl;
				cout<<"here are some suggestions"<<endl;
				t.autoComplete(str);
			}	
		}
		else if(choice==2){
			while(true){
				int flag=0;
				cout<<"First let me tell the password:";
			string pass;
			cin>>pass;
			
			if(pass=="pass@123"){
				flag=1;
				cout<<"correct password--"<<endl;
				cout<<"Enter the word you want to add:"<<endl;
				cin>>str;
				cout<<"Enter the meaning of the word:";
				cin>>meaning;
				t.insertWord(str,meaning);
				cout<<"word added succesfully";
			    fio << str << endl; 
			    fio.seekg(0, ios::beg);
			}
			else{
				
				cout<<"sorry! wrong password.Please try again"<<endl;
			}
			
			if(flag==1){
				break;
			}
			}
				
		}

		else if(choice==3){
			cout<<"First let me tell the password:";
			string pass;
			cin>>pass;
			
			if(pass=="pass@123"){
				
				cout<<"Enter the word you want to delete:";
				cin>>str;
				if(t.searchWord(str)){
					t.removeWord(str);
					cout<<endl<<"word deleted succesfully"<<endl;	
				}
				else{
					cout<<"Sorry word not found"<<endl;
				}
				
				
			}
			else{
				
				cout<<"sorry! wrong password"<<endl;
			}
			
		}
		else if(choice==4){
			cout<<"you want some suggestions:"<<endl;
			cin>>str;
			cout<<"****";
			cout<<"Here are some suggestions:"<<endl;
			t.autoComplete(str);
			
		}
		else if(choice==5){
			cout<<"so you want to see the history: "<<endl;
			string pass;
			cout<<"first enter the correct password:"<<endl;
			cin>>pass;	
			
			if(pass=="pass@123"){
				cout<<"So here is the history:::::::";
					while (fio) { 
			        getline(fio, str); 
					cout << str << endl; 
   					} 
				}	
			else{
				cout<<"wrong password try again later."<<endl;
			}
		}
		else if(choice==6){
			
			cout<<"Following are all the words of the dictionary"<<endl;
			char str[20];
			int level=0;
			t.DisplayTrie(str,level);
			
		}
		cout<<endl;
		cout<<"Do you want to exit?"<<endl;
		cout<<"If yes enter -1 ,otherwise enter your choice"<<endl;
	}
	while(choice!=-1);
	fio.close(); 
	return 0;	
}
