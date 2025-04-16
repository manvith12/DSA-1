#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define LOAD_FACTOR 0.75

typedef struct HashNode {
    char* key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct HashMap {
    int size;
    int capacity;
    HashNode** buckets;
} HashMap;

unsigned int hash(const char* key, int capacity) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;
    return hash % capacity;
}

HashNode* createNode(const char* key, int value) {
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;
    return node;
}

HashMap* createMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->capacity = capacity;
    map->size = 0;
    map->buckets = (HashNode**)calloc(capacity, sizeof(HashNode*));
    return map;
}

void freeNode(HashNode* node) {
    free(node->key);
    free(node);
}

void resizeMap(HashMap* map);

void insert(HashMap* map, const char* key, int value) {
    unsigned int idx = hash(key, map->capacity);
    HashNode* head = map->buckets[idx];
    HashNode* temp = head;

    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    HashNode* newNode = createNode(key, value);
    newNode->next = head;
    map->buckets[idx] = newNode;
    map->size++;

    if ((float)map->size / map->capacity > LOAD_FACTOR) {
        resizeMap(map);
    }
}

int get(HashMap* map, const char* key, int* found) {
    unsigned int idx = hash(key, map->capacity);
    HashNode* temp = map->buckets[idx];
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            *found = 1;
            return temp->value;
        }
        temp = temp->next;
    }
    *found = 0;
    return -1;
}

int removeKey(HashMap* map, const char* key) {
    unsigned int idx = hash(key, map->capacity);
    HashNode* curr = map->buckets[idx];
    HashNode* prev = NULL;

    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            if (prev) prev->next = curr->next;
            else map->buckets[idx] = curr->next;
            freeNode(curr);
            map->size--;
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

void resizeMap(HashMap* map) {
    int oldCap = map->capacity;
    int newCap = 2 * oldCap;
    HashNode** newBuckets = (HashNode**)calloc(newCap, sizeof(HashNode*));

    for (int i = 0; i < oldCap; i++) {
        HashNode* curr = map->buckets[i];
        while (curr) {
            unsigned int newIdx = hash(curr->key, newCap);
            HashNode* next = curr->next;
            curr->next = newBuckets[newIdx];
            newBuckets[newIdx] = curr;
            curr = next;
        }
    }
    free(map->buckets);
    map->buckets = newBuckets;
    map->capacity = newCap;
}

void destroyMap(HashMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        HashNode* curr = map->buckets[i];
        while (curr) {
            HashNode* next = curr->next;
            freeNode(curr);
            curr = next;
        }
    }
    free(map->buckets);
    free(map);
}

void display(HashMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        HashNode* temp = map->buckets[i];
        printf("[%d] ", i);
        while (temp) {
            printf("(%s: %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
