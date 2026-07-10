# LRU Cache (Least Recently Used Cache)

A generic, thread-unsafe LRU Cache implementation in C++ with **O(1) average time complexity** for both `get()` and `put()` operations.

## What is an LRU Cache?

An **LRU (Least Recently Used) Cache** is a fixed-size data structure that stores key-value pairs. When the cache reaches its maximum capacity, it **evicts the least recently accessed item** to make room for new entries. This ensures that frequently accessed data stays in the cache while stale data is removed.

### Real-World Use Cases

- **Web browsers** – caching recently visited web pages and assets
- **Database query caching** – keeping frequently queried results in memory
- **Operating systems** – page replacement in virtual memory
- **API response caching** – reducing latency for frequently requested endpoints

## How It Works

The implementation uses two data structures working together:

```
┌─────────────────────────────────────────────────────┐
│                    LRU Cache                         │
│                                                      │
│   ┌──────────┐    ┌──────────┐    ┌──────────┐      │
│   │  Key: 3  │    │  Key: 1  │    │  Key: 2  │      │
│   │ Val: "c" │ ←→ │ Val: "a" │ ←→ │ Val: "b" │      │
│   └──────────┘    └──────────┘    └──────────┘      │
│     ↑ MRU                          ↑ LRU             │
│   (Most Recently Used)        (Least Recently Used)  │
│                                                      │
│   ┌──────────────────────────────────────────────┐   │
│   │         Hash Map (O(1) lookup)               │   │
│   │   Key 1 → {value: "a", iterator → node 1}    │   │
│   │   Key 2 → {value: "b", iterator → node 2}    │   │
│   │   Key 3 → {value: "c", iterator → node 3}    │   │
│   └──────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────┘
```

### Data Structures

1. **`std::list<Key>` (doubly linked list)** – Maintains the access order:
   - **Front** = Most Recently Used (MRU) item
   - **Back** = Least Recently Used (LRU) item
   - Moving nodes to the front is O(1) using `splice()`

2. **`std::unordered_map<Key, CacheEntry>` (hash map)** – Provides O(1) key lookups:
   - Each entry stores the **value** and an **iterator** pointing to the corresponding node in the linked list
   - The iterator allows O(1) removal/reordering of the list node

### Operations

#### `get(key)` – O(1)
1. Look up the key in the hash map
2. If **not found** → return `std::nullopt`
3. If **found** → move the corresponding list node to the **front** (MRU position) using `splice()`, then return the value

#### `put(key, value)` – O(1)
1. Look up the key in the hash map
2. If **key exists** → update the value and move the node to the **front** (MRU position)
3. If **key does not exist**:
   - If the cache is **full** → evict the LRU item (the node at the **back** of the list) and remove it from the hash map
   - Insert the new key at the **front** of the list and add it to the hash map with an iterator to the new node

## API Reference

| Method | Description | Time Complexity |
|--------|-------------|-----------------|
| `get(key)` | Retrieve value by key. Returns `std::optional<Value>`. Moves accessed item to MRU position. | O(1) avg |
| `put(key, value)` | Insert or update a key-value pair. Evicts LRU item if at capacity. | O(1) avg |
| `contains(key)` | Check if a key exists **without** affecting LRU status. | O(1) avg |
| `remove(key)` | Remove a specific key-value pair. Returns `true` if found. | O(1) avg |
| `clear()` | Remove all items from the cache. | O(n) |
| `size()` | Get the current number of items. | O(1) |
| `capacity()` | Get the maximum capacity. | O(1) |
| `empty()` | Check if the cache is empty. | O(1) |

## Usage Example

```cpp
#include "lru_cache.hpp"
#include <iostream>

int main() {
    // Create a cache with capacity 3
    LRUCache<int, std::string> cache(3);

    // Insert items
    cache.put(1, "apple");
    cache.put(2, "banana");
    cache.put(3, "cherry");

    // Access an item (moves it to MRU position)
    auto val = cache.get(1);  // Returns "apple"

    // Insert a 4th item → evicts the LRU item (key 2, "banana")
    cache.put(4, "date");

    std::cout << cache.get(2).value_or("(evicted)");  // Prints "(evicted)"

    return 0;
}
```

## Building and Running Tests

```bash
# Compile
g++ -std=c++17 -o test_lru_cache test_lru_cache.cpp lru_cache.cpp

# Run tests
./test_lru_cache
```

## Requirements

- C++17 or later (for `std::optional`)
- Standard Template Library (STL)

## Limitations

- **Not thread-safe** – external synchronization (e.g., `std::mutex`) is required for concurrent access
- **Keys must be hashable** via `std::hash<Key>`
- **Values must be copy-constructible**