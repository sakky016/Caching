#include "LRUCache.h"
#include "algorithm"
#include <iostream>

using namespace std;

//---------------------------------------------------------------------------------------
LRUCache::LRUCache(size_t capacity) : Cache(capacity)
{
    cout << "Creating LRU cache of capacity " << capacity << endl;
}


//---------------------------------------------------------------------------------------
LRUCache::~LRUCache()
{

}


//---------------------------------------------------------------------------------------
void LRUCache::Insert(const string & key, const string & value)
{
    auto it = m_entries.find(key);
    if (it == m_entries.end())
    {
        // Not found in cache, insert it
        cout << "Insert [" << key << "]" << endl;
        m_entries[key] = value;
        m_entryList.push_front(key);

        // Update ordering
        if (m_entryList.size() >  m_capacity)
        {
            string entryToRemove = m_entryList.back();
            cout << "Cache capacity reached. Removing [" << entryToRemove << "]" << endl;

            m_entryList.pop_back();
            m_entries.erase(entryToRemove);
        }
    }
    else
    {
        cout << key << ": already present in cache\n";
    }
}


//---------------------------------------------------------------------------------------
bool LRUCache::Get(const string & key, string & value /*[OUT]*/)
{
    cout << "Fetch [" << key << "]\n";
    auto it = m_entries.find(key);
    if (it == m_entries.end())
    {
        cout << key << ": Not found in cache" << endl;
        return false;
    }

    value = it->second;

    // Update ordering
    auto it2 = find(m_entryList.begin(), m_entryList.end(), key);
    string entry = *it2;
    m_entryList.erase(it2);
    m_entryList.push_front(entry);

    return true;
}


//---------------------------------------------------------------------------------------
void LRUCache::DisplayCache()
{
    cout << "+------------------------------------------------+\n";
    cout << "|                 LRU Cache                      |\n";
    cout << "+------------------------------------------------+\n";
    size_t index = 1;
    for (const auto & entry : m_entryList)
    {
        cout << index << ") " << entry << " : " << m_entries[entry] << endl;
        index++;
    }
    cout << "--------------------------------------------------\n";
}


