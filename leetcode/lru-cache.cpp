// LRU Cache
// https://leetcode.com/problems/lru-cache/
// Accepted 2026-07-06 | Runtime 61 ms | Memory 173.3 MB

class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(){
            key = 0;
            val = 0;
            next = nullptr;
            prev = nullptr;
        }
        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
};


class LRUCache {
public:
    Node *left, *right;
    unordered_map<int, Node*> hm;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }

    ~LRUCache(){
        Node* curr = left;
        while(curr){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    void deleteNode(Node* node){
        Node* prevv = node->prev;
        Node* nextt = node->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }

    void addNode(Node* node){
        Node* temp = right->prev;

        node->next = right;
        node->prev = temp;

        right->prev = node;
        temp->next = node;
    }


    int get(int key) {
        if(!hm.count(key)){
            return -1;
        }
        Node* node = hm[key];
        deleteNode(node);
        addNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(hm.count(key)){
            Node* node = hm[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
            return;
        }
        if(hm.size()==capacity){
            Node* lru = left->next;
            deleteNode(lru);
            hm.erase(lru->key);
            delete lru;
        }
        Node* node = new Node(key,value);
        addNode(node);
        hm[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */