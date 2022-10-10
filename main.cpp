#include "LRUCache.h"
#include "LFUCache.h"

using namespace std;

//------------------------------------------------------------------
// Test function
//------------------------------------------------------------------
void Test(Cache* cache)
{
    string value;
    cache->Insert("1", "Amy");
    cache->Insert("2", "Davis");
    cache->Get("2", value);
    cache->Get("9", value);
    cache->Insert("3", "Trevor");
    cache->Get("2", value);
    cache->Get("1", value);
    cache->Insert("4", "Nonchak");
    cache->Get("2", value);
    cache->Insert("5", "Sheikh");
    cache->Get("9", value);
    cache->Insert("4", "Nonchak");
    cache->Insert("9", "Genghis");
    cache->Insert("8", "Sumer");
    cache->Get("9", value);
    cache->Get("1", value);
    cache->Get("5", value);
    cache->Get("9", value);
    cache->Get("4", value);
    cache->Get("4", value);
    cache->Get("4", value);
    cache->Get("5", value);
    cache->Get("8", value);
    cache->Insert("6", "Tywin");
    cache->DisplayCache();
}


//------------------------------------------------------------------
// M A I N
//------------------------------------------------------------------
int main()
{
    Cache* lruCache = new LRUCache(5);
    Cache* lfuCache = new LFUCache(5);
    Test(lruCache);
    Test(lfuCache);
    delete lruCache;
    delete lfuCache;

    return 0;
}
