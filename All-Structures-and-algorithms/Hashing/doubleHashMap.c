#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 13  // Prime size helps with better distribution
#define EMPTY -1
#define DELETED -2

typedef struct {
    int key;
    int value;
} Entry;

Entry hashTable[TABLE_SIZE];

int h1(int key) {
    return key % TABLE_SIZE;
}

int h2(int key) {
    // Must be non-zero and coprime with TABLE_SIZE
    return 7 - (key % 7);
}

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i].key = EMPTY;
}

int insert(int key, int value) {
    int index = h1(key);
    int step = h2(key);
    int i = 0;

    while (hashTable[index].key != EMPTY && hashTable[index].key != DELETED && hashTable[index].key != key) {
        i++;
        index = (h1(key) + i * step) % TABLE_SIZE;
        if (i == TABLE_SIZE) return 0;
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
    return 1;
}

int search(int key) {
    int index = h1(key);
    int step = h2(key);
    int i = 0;

    while (hashTable[index].key != EMPTY && i < TABLE_SIZE) {
        if (hashTable[index].key == key)
            return hashTable[index].value;

        i++;
        index = (h1(key) + i * step) % TABLE_SIZE;
    }
    return -1;
}

int delete(int key) {
    int index = h1(key);
    int step = h2(key);
    int i = 0;

    while (hashTable[index].key != EMPTY && i < TABLE_SIZE) {
        if (hashTable[index].key == key) {
            hashTable[index].key = DELETED;
            return 1;
        }
        i++;
        index = (h1(key) + i * step) % TABLE_SIZE;
    }
    return 0;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key == EMPTY)
            printf("[%d] ---\n", i);
        else if (hashTable[i].key == DELETED)
            printf("[%d] <deleted>\n", i);
        else
            printf("[%d] Key: %d, Value: %d\n", i, hashTable[i].key, hashTable[i].value);
    }
}

int main() {
    initTable();

    insert(18, 180);
    insert(41, 410);
    insert(22, 220);
    insert(44, 440);
    insert(59, 590);
    insert(32, 320);

    printf("Initial Table:\n");
    display();

    printf("\nSearching for key 22: %d\n", search(22));
    printf("Deleting key 41: %s\n", delete(41) ? "Success" : "Failed");

    printf("\nTable After Deletion:\n");
    display();

    return 0;
}
