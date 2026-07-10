#ifndef LRU_CACHE_HPP
#define LRU_CACHE_HPP

#include <unordered_map>
#include <list>
#include <cstddef>
#include <stdexcept>
#include <optional>

/**
 * @brief A thread-unsafe LRU (Least Recently Used) Cache implementation.
 *
 * Evicts the least recently used item when the cache reaches capacity.
 * Provides O(1) average time complexity for both get() and put() operations.
 *
 * @tparam Key The key type (must be hashable via std::hash)
 * @tparam Value The value type (must be copy-constructible)
 */
template<typename Key, typename Value>
class LRUCache {
public:
    using key_type = Key;
    using value_type = Value;

    /**
     * @brief Construct an LRU Cache with the given capacity.
     * @param capacity Maximum number of items the cache can hold.
     * @throws std::invalid_argument if capacity is 0.
     */
    explicit LRUCache(std::size_t capacity)
        : capacity_(capacity)
    {
        if (capacity_ == 0) {
            throw std::invalid_argument("LRUCache capacity must be greater than 0");
        }
    }

    /**
     * @brief Get the value associated with the given key.
     *        Moves the accessed item to the front (most recently used).
     * @param key The key to look up.
     * @return std::optional<Value> containing the value if found, std::nullopt otherwise.
     */
    std::optional<Value> get(const Key& key) {
        auto it = cache_map_.find(key);
        if (it == cache_map_.end()) {
            return std::nullopt;
        }

        // Move the accessed node to the front (most recently used)
        usage_list_.splice(usage_list_.begin(), usage_list_, it->second.list_iterator);
        return it->second.value;
    }

    /**
     * @brief Insert or update a key-value pair.
     *        If the key already exists, updates its value and moves it to the front.
     *        If the cache is full, evicts the least recently used item.
     * @param key The key to insert/update.
     * @param value The value to associate with the key.
     */
    void put(const Key& key, const Value& value) {
        auto it = cache_map_.find(key);

        if (it != cache_map_.end()) {
            // Key exists: update value and move to front
            it->second.value = value;
            usage_list_.splice(usage_list_.begin(), usage_list_, it->second.list_iterator);
            return;
        }

        // Evict LRU item if at capacity
        if (cache_map_.size() >= capacity_) {
            const Key& lru_key = usage_list_.back();
            cache_map_.erase(lru_key);
            usage_list_.pop_back();
        }

        // Insert new item at the front
        usage_list_.push_front(key);
        cache_map_[key] = {value, usage_list_.begin()};
    }

    /**
     * @brief Check if a key exists in the cache without affecting its LRU status.
     * @param key The key to check.
     * @return true if the key exists, false otherwise.
     */
    bool contains(const Key& key) const {
        return cache_map_.find(key) != cache_map_.end();
    }

    /**
     * @brief Remove a key-value pair from the cache.
     * @param key The key to remove.
     * @return true if the key was found and removed, false otherwise.
     */
    bool remove(const Key& key) {
        auto it = cache_map_.find(key);
        if (it == cache_map_.end()) {
            return false;
        }

        usage_list_.erase(it->second.list_iterator);
        cache_map_.erase(it);
        return true;
    }

    /**
     * @brief Remove all items from the cache.
     */
    void clear() {
        cache_map_.clear();
        usage_list_.clear();
    }

    /**
     * @brief Get the current number of items in the cache.
     * @return Current size.
     */
    std::size_t size() const {
        return cache_map_.size();
    }

    /**
     * @brief Get the maximum capacity of the cache.
     * @return Capacity.
     */
    std::size_t capacity() const {
        return capacity_;
    }

    /**
     * @brief Check if the cache is empty.
     * @return true if empty, false otherwise.
     */
    bool empty() const {
        return cache_map_.empty();
    }

private:
    struct CacheEntry {
        Value value;
        typename std::list<Key>::iterator list_iterator;
    };

    std::size_t capacity_;
    std::list<Key> usage_list_;                              // Front = MRU, Back = LRU
    std::unordered_map<Key, CacheEntry> cache_map_;          // O(1) key lookup
};

#endif // LRU_CACHE_HPP