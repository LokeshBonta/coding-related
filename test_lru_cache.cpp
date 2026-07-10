#include "lru_cache.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

static int tests_passed = 0;
static int tests_failed = 0;

#define TEST(name) \
    do { \
        std::cout << "  TEST: " << name << " ... "; \
        try {

#define END_TEST(expected) \
            std::cout << (expected ? "PASS" : "FAIL") << std::endl; \
            if (expected) tests_passed++; else tests_failed++; \
        } catch (const std::exception& e) { \
            std::cout << "FAIL (exception: " << e.what() << ")" << std::endl; \
            tests_failed++; \
        } catch (...) { \
            std::cout << "FAIL (unknown exception)" << std::endl; \
            tests_failed++; \
        } \
    } while(0)

void test_basic_put_and_get() {
    std::cout << "\n=== Test: Basic Put and Get ===" << std::endl;
    LRUCache<int, std::string> cache(3);

    TEST("put and get a single item") {
        cache.put(1, "one");
        auto val = cache.get(1);
        assert(val.has_value());
        assert(val.value() == "one");
        assert(cache.size() == 1);
    } END_TEST(true);

    TEST("get non-existent key returns nullopt") {
        auto val = cache.get(99);
        assert(!val.has_value());
    } END_TEST(true);

    TEST("put multiple items and retrieve them") {
        cache.put(2, "two");
        cache.put(3, "three");
        assert(cache.size() == 3);
        assert(cache.get(1).value() == "one");
        assert(cache.get(2).value() == "two");
        assert(cache.get(3).value() == "three");
    } END_TEST(true);
}

void test_eviction() {
    std::cout << "\n=== Test: Eviction Policy ===" << std::endl;
    LRUCache<int, std::string> cache(3);

    TEST("evicts LRU item when over capacity") {
        cache.put(1, "one");
        cache.put(2, "two");
        cache.put(3, "three");
        cache.put(4, "four");  // Should evict key 1 (LRU)

        assert(cache.size() == 3);
        assert(!cache.get(1).has_value());  // 1 should be evicted
        assert(cache.get(2).value() == "two");
        assert(cache.get(3).value() == "three");
        assert(cache.get(4).value() == "four");
    } END_TEST(true);

    TEST("accessing an item prevents its eviction") {
        LRUCache<int, std::string> c(2);
        c.put(1, "one");
        c.put(2, "two");
        c.get(1);              // Access 1, making 2 the LRU
        c.put(3, "three");     // Should evict 2, not 1

        assert(c.get(1).has_value());
        assert(!c.get(2).has_value());
        assert(c.get(3).has_value());
    } END_TEST(true);
}

void test_update_existing_key() {
    std::cout << "\n=== Test: Update Existing Key ===" << std::endl;
    LRUCache<int, std::string> cache(3);

    TEST("updating a key changes its value and makes it MRU") {
        cache.put(1, "one");
        cache.put(2, "two");
        cache.put(3, "three");
        cache.put(1, "ONE");   // Update key 1, making it MRU

        assert(cache.get(1).value() == "ONE");
        assert(cache.size() == 3);

        // Now add a 4th item - should evict key 2 (now LRU since 1 was accessed)
        cache.put(4, "four");
        assert(!cache.get(2).has_value());
        assert(cache.get(1).value() == "ONE");
        assert(cache.get(3).value() == "three");
        assert(cache.get(4).value() == "four");
    } END_TEST(true);
}

void test_contains() {
    std::cout << "\n=== Test: Contains ===" << std::endl;
    LRUCache<int, std::string> cache(3);

    TEST("contains returns true for existing keys") {
        cache.put(1, "one");
        assert(cache.contains(1));
    } END_TEST(true);

    TEST("contains returns false for non-existing keys") {
        assert(!cache.contains(99));
    } END_TEST(true);

    TEST("contains returns false after eviction") {
        cache.put(2, "two");
        cache.put(3, "three");
        cache.put(4, "four");  // Evicts 1
        assert(!cache.contains(1));
    } END_TEST(true);
}

void test_remove() {
    std::cout << "\n=== Test: Remove ===" << std::endl;
    LRUCache<int, std::string> cache(3);

    TEST("remove existing key returns true and removes it") {
        cache.put(1, "one");
        cache.put(2, "two");
        bool removed = cache.remove(1);
        assert(removed);
        assert(cache.size() == 1);
        assert(!cache.get(1).has_value());
    } END_TEST(true);

    TEST("remove non-existing key returns false") {
        bool removed = cache.remove(99);
        assert(!removed);
    } END_TEST(true);
}

void test_clear() {
    std::cout << "\n=== Test: Clear ===" << std::endl;
    LRUCache<int, std::string> cache(3);

    TEST("clear removes all items") {
        cache.put(1, "one");
        cache.put(2, "two");
        cache.put(3, "three");
        assert(cache.size() == 3);
        cache.clear();
        assert(cache.size() == 0);
        assert(cache.empty());
        assert(!cache.get(1).has_value());
        assert(!cache.get(2).has_value());
        assert(!cache.get(3).has_value());
    } END_TEST(true);
}

void test_capacity_validation() {
    std::cout << "\n=== Test: Capacity Validation ===" << std::endl;

    TEST("zero capacity throws exception") {
        try {
            LRUCache<int, std::string> cache(0);
            assert(false && "Should have thrown");
        } catch (const std::invalid_argument&) {
            // Expected
        }
    } END_TEST(true);

    TEST("capacity 1 works correctly") {
        LRUCache<int, std::string> cache(1);
        cache.put(1, "one");
        assert(cache.get(1).value() == "one");
        cache.put(2, "two");  // Evicts 1
        assert(!cache.get(1).has_value());
        assert(cache.get(2).value() == "two");
    } END_TEST(true);
}

void test_edge_cases() {
    std::cout << "\n=== Test: Edge Cases ===" << std::endl;

    TEST("empty cache properties") {
        LRUCache<int, std::string> cache(3);
        assert(cache.empty());
        assert(cache.size() == 0);
        assert(!cache.get(1).has_value());
        assert(!cache.contains(1));
    } END_TEST(true);

    TEST("string keys work") {
        LRUCache<std::string, int> cache(2);
        cache.put("hello", 1);
        cache.put("world", 2);
        assert(cache.get("hello").value() == 1);
        assert(cache.get("world").value() == 2);
    } END_TEST(true);

    TEST("int values work") {
        LRUCache<int, int> cache(3);
        cache.put(1, 100);
        cache.put(2, 200);
        cache.put(3, 300);
        assert(cache.get(2).value() == 200);
    } END_TEST(true);
}

void test_lru_order_complex() {
    std::cout << "\n=== Test: Complex LRU Order ===" << std::endl;

    TEST("complex access pattern maintains correct order") {
        LRUCache<int, std::string> cache(4);

        // Fill cache: order from MRU to LRU: 4, 3, 2, 1
        cache.put(1, "a");
        cache.put(2, "b");
        cache.put(3, "c");
        cache.put(4, "d");

        // Access 2, making it MRU: order: 2, 4, 3, 1
        cache.get(2);

        // Access 1, making it MRU: order: 1, 2, 4, 3
        cache.get(1);

        // Put 5, should evict 3 (LRU): order: 5, 1, 2, 4
        cache.put(5, "e");

        assert(!cache.get(3).has_value());  // 3 was evicted
        assert(cache.get(1).value() == "a");
        assert(cache.get(2).value() == "b");
        assert(cache.get(4).value() == "d");
        assert(cache.get(5).value() == "e");
        assert(cache.size() == 4);
    } END_TEST(true);
}

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "  LRU Cache Test Suite" << std::endl;
    std::cout << "==========================================" << std::endl;

    test_basic_put_and_get();
    test_eviction();
    test_update_existing_key();
    test_contains();
    test_remove();
    test_clear();
    test_capacity_validation();
    test_edge_cases();
    test_lru_order_complex();

    std::cout << "\n==========================================" << std::endl;
    std::cout << "  Results: " << tests_passed << " passed, "
              << tests_failed << " failed" << std::endl;
    std::cout << "==========================================" << std::endl;

    return tests_failed > 0 ? 1 : 0;
}