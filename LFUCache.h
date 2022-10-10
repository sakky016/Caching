#ifndef LFUCACHE_H
#define LFUCACHE_H

#include "Cache.h"
#include <unordered_map>
#include <vector>
#include <utility>

//-------------------------------------------------------------------------------------------
// This class implements the Least Frequently Used Cache
//-------------------------------------------------------------------------------------------
class LFUCache : public Cache
{
public:
    LFUCache(size_t capacity);
    ~LFUCache();
    void Insert(const std::string & key, const std::string & value) override;
    bool Get(const std::string & key, std::string & value /*[OUT]*/) override;
    void DisplayCache() override;

private:
    std::unordered_map<std::string, std::string> m_entries;

    // Cache entries in the appropriate order
    std::vector<std::pair<std::string, size_t>> m_entryList;
};
#endif
