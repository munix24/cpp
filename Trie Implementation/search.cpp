
#include "trie.cpp"

int main() {
	trie theTrie;
	//build trie from dictionary
	theTrie.buildDictionaryTrie(theTrie);
	cout << "Please type search queriess:\n";

	string prefix;
	vector<string> suggest;
	cin >> prefix;
	suggest = theTrie.autocomplete(prefix);	//build suggestions vector
	cout << "Your options are:\n";
	for (vector<string>::iterator it = suggest.begin(); it != suggest.end(); ++it) {// loop through suggestions 
		cout << *it << "\n";	//output suggestions 
	}
	cin.ignore();
	return 0;
};