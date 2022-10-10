#ifndef LRUCACHE_H
#define LRUCACHE_H

#include "Cache.h"
#include <unordered_map>
#include <list>

//-------------------------------------------------------------------------------------------
// This class implements the Least Recently Used Cache
//-------------------------------------------------------------------------------------------
class LRUCache : public Cache
{
public:
    LRUCache(size_t capacity);
    ~LRUCache();
    void Insert(const std::string & key, const std::string & value) override;
    bool Get(const std::string & key, std::string & value /*[OUT]*/) override;
    void DisplayCache() override;

private:
    // Map of cache entries for faster lookup
    std::unordered_map<std::string, std::string> m_entries;

    // Cache entries in the appropriate order
    std::list<std::string> m_entryList;
};
#endif
