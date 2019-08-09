/*
    为了使get和put都是O(1)时间复杂度，考虑使用map和双向链表，空间换时间
    时间复杂度：O(1)
    空间复杂度：O(n)
*/
struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k,int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
private:
    Node* head;
    Node* tail;
    unordered_map<int,Node*> map;
    int capacity;
    int cnt;
    
    void updateNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = head;
        node->next = head->next;
        head->next = node;    
        node->next->prev = node;
    }
public:
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        cnt = 0;
    }
    
    int get(int key) {
        if(!map.count(key)) return -1;
        else {
            Node* node = map[key];
            updateNode(node);
        }
        return map[key]->val;
    }
    
    void put(int key, int value) {
        if(map.count(key)) {
            map[key]->val = value;
            updateNode(map[key]);
        } else {
            Node* node = new Node(key,value);
            map[key] = node;
            node->prev = head;
            node->next = head->next;
            node->next->prev = node;
            head->next = node;
            if(++cnt > capacity) {
                map.erase(tail->prev->key);
                tail->prev = tail->prev->prev;
                tail->prev->next = tail;
                cnt--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */