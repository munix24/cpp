#include <map>

using namespace std;

class trie_node{
public:
	bool word_end;
	map<char, trie_node*> children;
	//Initialization List to initialize word_end field to false
	trie_node() : word_end(false) {};
};