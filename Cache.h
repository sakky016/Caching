#ifndef CACHE_H
#define CACHE_H

#include <string>

class Cache
{
public:
    Cache(size_t capacity);
    virtual void Insert(const std::string & key, const std::string & value) = 0;
    virtual bool Get(const std::string & key, std::string & value /*[OUT]*/) = 0;
    virtual void DisplayCache() = 0;

protected:
    // Capacity of the cache
    size_t m_capacity;
};
#endif
