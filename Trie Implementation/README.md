

To auto complete a query with an existing Trie, you use the depth first traversal
on Trie. For example, if I started typing letter “t”, then you will start depth
first search on the subtree of node “t”. After you complete your depth first
search, you should return search query string “to”, “top”, “tea”, “ted” and
“ten” as possible auto completion options.

