# LRU Cache
Implementation of an LRU Cache by making use of Doubly Linked List and Hashmap (using C++ STL).
It supports the following operations in O(1) time:-
- insert(Key, Value)
- getValue(Key)
- getMostRecentKey()

# Note:- 
- If a key value pair is inserted in the cache when the cache is full then the least recently used key-value pairs should be deleted and the new one should be inserted.
- If the key already exists in the cache, then simply the value of the key can be updated with the new value.
