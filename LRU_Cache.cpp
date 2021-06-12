#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

//Node to store the data (Linked List)
class Node{
public:
    string key;
    int value;
    Node(string key, int value){
        this->key = key;
        this->value = value;
    }
};

//LRU Cache Data Structure
class LRUCache{
public:
    int maxSize;
    list <Node> l;
    // hashmap will store the key (string) and value (address of a particular node)
    //address of a node: an iterator to the node of the list 
    unordered_map <string, list<Node>::iterator> m; 

    LRUCache(int maxSize){
        this->maxSize = (maxSize > 1) ? maxSize : 1;
    }

    void insertKeyValue(string key, int value){
        //if the key already exists in the cache
        if(m.count(key) != 0){
            //replace the old value and update with the new one
            auto it = m[key];
            it->value = value;
        }
        else{
            //check if cache is full
            if(l.size() == maxSize){
                //remove the least recently used item from the cache
                Node last = l.back();
                m.erase(last.key); //removal from the cache
                l.pop_back(); //removal from the linked list
            }

            Node newNode (key,value);
            l.push_front(newNode);
            m[key] = l.begin(); 
        }
    }

    int* getValue(string key){
        //if the key is present
        if(m.count(key) != 0){
            auto it = m[key];
            int value = it->value;
             
            //now it has became the most recently used key
            //so it should go to the head of the linked list
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return &l.begin()->value;
        }
        return NULL;
    }

    string mostRecentKey(){
        return l.front().key;
    }
};

int main(){
    LRUCache lru(3);
    lru.insertKeyValue("mango", 10);
    lru.insertKeyValue("apple", 10);
    lru.insertKeyValue("guava", 10);
    cout << lru.mostRecentKey() << endl;

    lru.insertKeyValue("mango", 40);
    cout << lru.mostRecentKey() << endl;

    int *noOfOrders = lru.getValue("mango");
    if(noOfOrders != NULL){
        cout << "Number of orders of Mango: " << *noOfOrders << endl;
    } 

    lru.insertKeyValue("banana", 20);

    if(lru.getValue("apple") == NULL){
        cout << "apple doesn't exist";
    }

    if(lru.getValue("guava") == NULL){
        cout << "guava doesn't exist";
    }

    if(lru.getValue("mango") == NULL){
        cout << "mango doesn't exist";
    }

    if(lru.getValue("banana") == NULL){
        cout << "banana doesn't exist";
    }
}
