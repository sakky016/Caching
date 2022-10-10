#include <assert.h>
#include "LFUCache.h"
#include <algorithm>
#include <iostream>

using namespace std;


//---------------------------------------------------------------------------------------
// Comparator function to sort in decreasing order of occurance count.
//---------------------------------------------------------------------------------------
bool comp(pair<string, size_t> entry1, pair<string, size_t> entry2)
{
    return (entry1.second > entry2.second);
}


//---------------------------------------------------------------------------------------
LFUCache::LFUCache(size_t capacity) : Cache(capacity)
{
    cout << "Creating LFU cache of capacity " << capacity << endl;
}


//---------------------------------------------------------------------------------------
LFUCache::~LFUCache()
{

}


//---------------------------------------------------------------------------------------
void LFUCache::Insert(const string & key, const string & value)
{
    auto it = m_entries.find(key);
    if (it == m_entries.end())
    {
        // Not found in cache, insert it
        cout << "Insert [" << key << "]" << endl;

        // Update ordering. This should be done before inserting the new element so that 
        // if cache capacity is reached, we can remove the last element before inserting
        // the new one.
        sort(m_entryList.begin(), m_entryList.end(), comp);
        
        if (m_entryList.size() == m_capacity)
        {
            auto entry = m_entryList.back();
            string keyToRemove = entry.first;
            cout << "Cache capacity reached, removing " << keyToRemove << endl;

            auto it2 = m_entries.find(keyToRemove);
            assert(it2 != m_entries.end());
            m_entries.erase(it2);
            m_entryList.pop_back();
        }

        pair<string, size_t> entry = make_pair<string, size_t>(string(key.c_str()), static_cast<size_t>(1));
        m_entries[key] = value;
        m_entryList.push_back(entry);
    }
    else
    {
        cout << key << ": already present in cache\n";
    }
}


//---------------------------------------------------------------------------------------
bool LFUCache::Get(const string & key, string & value /*[OUT]*/)
{
    cout << "Fetch [" << key << "]\n";
    auto it = m_entries.find(key);
    if (it == m_entries.end())
    {
        cout << key << ": Not found in cache" << endl;
        return false;
    }

    // Populate value
    value = it->second;

    // Update referral
    for (auto & entry : m_entryList)
    {
        if (entry.first == key)
        {
            entry.second++;
            break;
        }
    }

    // Update ordering
    sort(m_entryList.begin(), m_entryList.end(), comp);

    return true;
}


//---------------------------------------------------------------------------------------
void LFUCache::DisplayCache()
{
    cout << "+------------------------------------------------+\n";
    cout << "|                 LFU Cache                      |\n";
    cout << "+------------------------------------------------+\n";
    size_t index = 1;
    for (const auto & entry : m_entryList)
    {
        string key = entry.first;
        size_t occurance = entry.second;
        cout << index << ") " << key << " : " << m_entries[key] << " (" << occurance << ")" << endl;
        index++;
    }
    cout << "--------------------------------------------------\n";
}


