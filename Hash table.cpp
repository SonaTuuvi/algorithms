/*
Problem-solving principle

This code implements a simple hash table that supports three main operations: adding an element (put), retrieving an element by key (get), and deleting an element by key (delete). The hash table is used for fast key-based data lookup, and these operations are implemented as follows:

1. Adding an element (put):
   - The hash function calculates an index in the `buckets` array where the key should be stored.
   - If the key already exists in the corresponding list (chain), the value is updated.
   - If the key is not found, a new key-value pair is added.

2. Retrieving an element by key (get):
   - The hash function calculates an index in the `buckets` array.
   - A search for the key is conducted in the corresponding list.
   - If the key is found, the value is returned.
   - If the key is not found, `"None"` is returned.

3. Deleting an element by key (delete):
   - The hash function calculates an index in the `buckets` array.
   - A search for the key is conducted in the corresponding list.
   - If the key is found, it is deleted, and the value is returned.
   - If the key is not found, `"None"` is returned.

Performance of the code

1. Hash function (hashFunction):
   - Time complexity: O(1) — the hash function is computed in constant time.
   - Space complexity: O(1) — a fixed amount of memory is required to compute the hash.

2. `put` operation:
   - Time complexity: O(L) — in the worst case, all elements in the list `buckets[hashValue]` need to be scanned, where L is the length of the list.
   - On average, the complexity is close to O(1) if the keys are evenly distributed and the number of collisions is minimal.
   - Space complexity: O(1) for inserting one element, but it can grow proportionally to the number of elements in the table.

3. `get` operation:
   - Time complexity: O(L) — in the worst case, the entire list for a specific `buckets[hashValue]` index needs to be scanned.
   - On average, the complexity is also close to O(1) with a good hash function distribution.
   - Space complexity: O(1).

4. `delete` operation:
   - Time complexity: O(L) — in the worst case, the entire list in `buckets[hashValue]` needs to be scanned.
   - Space complexity: O(1).

Overall performance estimate

- In the average case: All main operations (`put`, `get`, `delete`) are performed in O(1), assuming the hash function distributes keys evenly across the table and the collision list (chain) remains short.
- In the worst case: If all keys hash to the same bucket (collision list), the complexity of operations can grow to O(n), where n is the number of elements in the table.

Memory

- The overall space complexity of the hash table is O(n + SIZE), where n is the number of elements, and SIZE is the size of the `buckets` array. The size of the array is fixed, while memory for storing elements in the chains is allocated as needed.
*/


#include <iostream>
#include <vector>
#include <list>
#include <utility>  // for std::pair

using namespace std;

class HashTable {
private:
    // Size of the buckets array, a prime number for better distribution of keys
    static const int SIZE = 100003;
    // Vector of lists to handle collisions using chaining
    vector<list<pair<int, int>>> buckets;

    // Hash function to compute the index for a given key
    int hashFunction(int key) {
        return (key % SIZE + SIZE) % SIZE; // Ensures a non-negative index
    }

public:
    // Constructor initializing the buckets vector with SIZE empty lists
    HashTable() : buckets(SIZE) {}

    // Inserts a key-value pair into the hash table or updates the value if the key already exists
    void put(int key, int value) {
        int hashValue = hashFunction(key); // Compute the bucket index
        // Check if the key already exists and update its value
        for (auto& pair : buckets[hashValue]) {
            if (pair.first == key) {
                pair.second = value; // Update the existing value
                return;
            }
        }
        // If key is not found, insert a new key-value pair
        buckets[hashValue].emplace_back(key, value);
    }

    // Retrieves the value associated with a key from the hash table
    string get(int key) {
        int hashValue = hashFunction(key); // Compute the bucket index
        // Search for the key in the corresponding bucket
        for (const auto& pair : buckets[hashValue]) {
            if (pair.first == key) {
                return to_string(pair.second); // Return the value if the key is found
            }
        }
        return "None"; // Return "None" if the key is not found
    }

    // Deletes a key-value pair from the hash table and returns the value
    string deleteKey(int key) {
        int hashValue = hashFunction(key); // Compute the bucket index
        // Iterate over the bucket to find the key
        for (auto it = buckets[hashValue].begin(); it != buckets[hashValue].end(); ++it) {
            if (it->first == key) {
                int value = it->second;
                buckets[hashValue].erase(it); // Remove the key-value pair
                return to_string(value); // Return the value of the deleted key
            }
        }
        return "None"; // Return "None" if the key is not found
    }
};

int main() {
    int n;
    cin >> n; // Read the number of operations

    HashTable table; // Create an instance of HashTable

    for (int i = 0; i < n; ++i) {
        string command;
        int key;
        cin >> command >> key; // Read the command and key

        // Process each command
        if (command == "put") {
            int value;
            cin >> value; // Read the value for the put command
            table.put(key, value); // Insert or update the key-value pair
        } else if (command == "get") {
            cout << table.get(key) << endl; // Retrieve and print the value for the key
        } else if (command == "delete") {
            cout << table.deleteKey(key) << endl; // Delete the key-value pair and print the value
        }
    }

    return 0; // Return success
}
