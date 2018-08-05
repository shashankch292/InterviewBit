/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRUCache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

 NOTE: If you are using any global variables, make sure to clear them in the constructor. 
Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 

LINK: https://www.interviewbit.com/problems/lru-cache/
*/

#include <list>
 
list<pair<int, int> > dq;
unordered_map<int, list<pair<int, int> >::iterator> mp;
int cache_cap;
 
LRUCache::LRUCache(int capacity)
{
    dq.clear();
    mp.clear();
    cache_cap = capacity;
}
 
int LRUCache::get(int key)
{
    if(mp.find(key) == mp.end())
        return -1;
 
    int value = (*mp[key]).second;
    dq.erase(mp[key]);
    dq.push_front({key,value});
    mp[key] = dq.begin();
    return value;
}
 
void LRUCache::set(int key, int value)
{
    if(mp.find(key) == mp.end())
    {
        if(dq.size() == cache_cap)
        {
            int k = (dq.back()).first;
            dq.pop_back();
            mp.erase(k);
        }
    }
    else
        dq.erase(mp[key]);
 
    dq.push_front({key,value});
    mp[key] = dq.begin();
}