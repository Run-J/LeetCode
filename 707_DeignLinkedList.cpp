// - Note the wild pointer, remember to assign temp to nullptr after deleting temp.
// - Note that there are times when current = dummyHead, and times when current = dummyHead->next, which are used for different purposes.

class MyLinkedList {

public:

    struct LinkedNode {
        int value;
        LinkedNode* next;
        LinkedNode(int value) : value(value), next(nullptr) {}
    };

    // ctor
    MyLinkedList() {
        dummyHead = new LinkedNode(0);
        size = 0;
    }
    

    int get(int index) {
        if (index < 0 || index > size - 1)
        {
            return -1;
        }

        LinkedNode* current = dummyHead->next;

        while (index--)
        {
            current = current->next;
        }

        return current->value;
    }
    

    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* current = dummyHead;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;

        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* current = dummyHead;

        int counter = 0;
        while (index--)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size || size == 0)
        {
            return;
        }

        LinkedNode* current = dummyHead;
        while (index--)
        {
            current = current->next;
        }

        LinkedNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        temp=nullptr; // Important !!!!! to assign temp with nullptr after delete
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        size--;
    }

private:
    LinkedNode* dummyHead;
    int size;

};


// - 注意野指针，切记在delete temp后，给temp赋值为nullptr。
// - 注意有些时候用current = dummyHead, 有些时候用current = dummyHead->next。这俩用途不一样。
    
/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*/