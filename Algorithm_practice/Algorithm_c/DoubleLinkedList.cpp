#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* prevNode;
    Node* nextNode;
} Node;

class DoubleLinkedList {
    Node* head;
    Node* tail;
    int length;
    
    Node* makeNode(int data) {
        Node* node = new Node;
        node->data = data;
        node->prevNode = nullptr;
        node->nextNode = nullptr;
        return node;
    }
    
    void isValidNode(Node* node) const {
        if(node==nullptr) {
            throw out_of_range("Index Error: Out of bounds.");
        }
    }

public:
    // about create and delete
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        length =0;
    }

    DoubleLinkedList(int data) {
        head = makeNode(data);
        tail = head;
        length = 1;
    }
    
    DoubleLinkedList(int *datas, int size) {
        head = nullptr;
        tail = nullptr;
        length = 0;
    
        for(int i=0; i<size; ++i) {
            this->put(datas[i]);
        }
    }
    
    DoubleLinkedList(const DoubleLinkedList& DDList) {
        head = nullptr;
        tail = head;
        length = 0;
        
        Node* current = DDList.head;
        while(current != nullptr) {
            this->put(current->data);
            current = current->nextNode;
        }
    }
    
    ~DoubleLinkedList() {
        Node* current = head;
        Node* next;
        while(current != nullptr) {
            next = current->nextNode;
            delete current;
            current = next;
        }
    }
    
    // operator's overriding
    DoubleLinkedList& operator=(const DoubleLinkedList& DDList) {
        if(this == &DDList) { return *this; }
        this->clear();
        
        Node* current = DDList.head;
        while(current != nullptr) {
            this->put(current->data);
            current = current->nextNode;
        }
        return *this;
    } 
    
    DoubleLinkedList operator+(const DoubleLinkedList& DLList) const {
        DoubleLinkedList newList = *this;
        Node* current = DLList.head;
        
        while(current != nullptr) {
            newList.put(current->data);
            current = current->nextNode;
        }
        return newList;
    }
    
    int& operator[](int idx) {
        Node* node = getNode(idx);
        return node->data;
    }
    
    //putter
    int putHead(int data) {
        Node* node = makeNode(data);
        if(length==0) {
            head = node;
            tail = head;
        } else {
            head->prevNode = node;
            node->nextNode = head;
            head = node;
        }
        length++;
        return 0;
    }
    
    int put(int data) {
        Node* node = makeNode(data);
        if(length==0) {
            head = node;
            tail = head;
        } else {
            tail->nextNode = node;
            node->prevNode = tail;
            tail = node;
        }
        length++;
        return 0;
    }
    
    int insert(int idx, int value) {
        if(idx>0 && idx<length) {
            Node* prev = getNode(idx-1);
            Node* next = prev->nextNode;
            Node* curr = makeNode(value);
            prev->nextNode = curr;
            curr->prevNode = prev;
            curr->nextNode = next;
            next->prevNode = curr;
            return 0;
        }
        else if(idx==0) {
            this->putHead(value);
        }
        else if(idx==length) {
            this->put(value);
        }
        cout << "Index Error: Invalid index for inserting." << endl;
        return -1;
    }
    
    int insert(int idx, const int *datas, size_t size) {
        DoubleLinkedList others(*datas);
        Node* current = getNode(idx);
        Node* next = current->nextNode;

        others.head->prevNode = current;
        others.tail->nextNode = next;
        current->nextNode = others.head;
        next->prevNode = others.tail;
        return 0;
    }
    
    // print and search
    int print(bool reverse=false) {
        Node* current = (reverse) ? tail : head;
        while(current != nullptr) {
            cout << current->data << " ";
            current = (reverse) ? current->prevNode : current->nextNode;
        }
        cout << endl;
        return 0;
    }
    
    Node* searchByData(int value) {
        // this search node matched data from first
        Node* current = head;
        while(current != nullptr) {
            if(current->data == value) {
                return current;
            }
            current = current->nextNode;
        }
        cout << "There isn't exist value " << value << "data." << endl;
        return nullptr;
    }
    
    // clear and remove
    int remove(int idx) {
        Node* target = this->getNode(idx);
        isValidNode(target);
        
    }
    
    int clear() {
        Node* current = head;
        Node* next;
        while(current != nullptr) {
            next = current->nextNode;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
        
        return 0;
    }
    
    // utils
    Node* sort() {
        cout << "Sort is Not Implemented." << endl;
        return nullptr;
    }
    
    // getter
    int getLength() {
        return length;
    }
    
    Node* getNode(int idx) {
        if(idx<0 || idx >= length) {
            throw out_of_range("IndexError: Index out of bounds.");
        }
        Node* current;
        if(idx < length/2) {
            current = head;
            for(int i=0;i<idx;++i) {
                current = current->nextNode;
            }
            return current;
        } else {
            current = tail;
            for(int i=0;i<length-idx-1;++i) {
                current = current->prevNode;
            }
            return current;
        }
    }
    
    int getData(Node* node) {
        isValidNode(node);
        return node->data;
    }
    
    int getData(int idx) {
        return getNode(idx)->data;
    }
};

int tester() {
    DoubleLinkedList list1(3);
    list1.put(10);
    list1.put(53);
    list1.print();
    
    DoubleLinkedList list2(10);
    list2.put(40);
    list2.put(3);
    list2.putHead(11);
    list2.print();
    
    DoubleLinkedList list3;
    list3 = list1;
    list3.print();
    
    DoubleLinkedList list4(list2);
    list4.put(59);
    list4.print();
    
    list2.clear();
    list2.print();
    
    cout << list4[2] << endl;
    list3 = list1 + list4;
    list3.print();
    cout << list3[7] << endl;
    
    cout << list3.searchByData(11)->data << endl;
    cout << "length: " << list3.getLength() << endl;
    
    return 0;
}

int main()
{   
    // tester();
    int toddlist[] = {3, 4, 2, 1};
    int size = sizeof(toddlist) / sizeof(toddlist[0]);
    DoubleLinkedList list0(toddlist, size);
    list0.print();
    
    return 0;
}