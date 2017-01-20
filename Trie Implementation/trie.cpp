#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include "node.cpp"

class trie {
public:
	trie_node* root;
	//constructor to allocate root
	trie() : root(new trie_node()) {};

	//add word in trie
	void addWord(const string& s) {
		trie_node* cur = root;
		//iterate through input characters
		for (unsigned int i = 0; i < s.size(); i++) {
			//will set insert map if not already present
			cur->children.insert(pair<char, trie_node*>(s[i], new trie_node()));	
			//iterate through children
			cur = cur->children[s[i]];
		}
		// set the node as a valid word end
		cur->word_end = true;
	}

	//trie destructor to release memory
	~trie() {
		queue<trie_node*> q;
		trie_node* t;
		//loop through all nodes starting with root
		q.push(root);
		while (!q.empty()) {
			t = q.front();
			q.pop();

			map<char, trie_node*>::iterator it;
			for (it =t->children.begin();it!=t->children.end();it++){ 
				q.push(it->second);
			}
			delete t;
		}
	}

	//autocomplete method
	vector<string> autocomplete(const string& s) {
		trie_node* cur = root;
		vector<string> ret;
		unsigned int i;

		//loop until the string is invalid or not found
		for (i = 0; i < s.size(); ++i) {
			if (cur->children.find(s[i]) == cur->children.end())
			{
				return ret;	//string not found, return empty vector
			}
			cur = cur->children[s[i]]; //string was found continue to traverse children starting with this node
		}

		queue<pair<string, trie_node*> > q;
		pair<string, trie_node*> t;
		//traverse through all descendant strings
		q.push( pair<string, trie_node*>(s.substr(0, i), cur));	//start with substring that was found
		while (!q.empty()) {
			t = q.front();
			q.pop();

			if (t.second->word_end) {
				ret.push_back(t.first);	//add to output if node is a word end
			}
			
			map<char, trie_node*>::iterator it;
			for (it = t.second->children.begin(); it!= t.second->children.end();it++){	//continue to loop through all children
				q.push(pair<string,trie_node*>(t.first + it ->first,it->second));	//combine string that was found with children
			}
		}
		return ret;
	}

	void buildDictionaryTrie(trie &t) {
	//set dictionary name
		ifstream inf("Dictionary.txt");
		string word;
		if(!inf.is_open())
			cout<<"Couldn't open Dictionary file"<<endl;	//handle missing file
		else{
			cout << "Building trie, please wait...\n";
			while (inf >> word) {
				t.addWord(word);
			}
		}
	}
};