class LinkedList {
    class Node {
    public:
        int val;
        Node *next;
        Node() {
            next = nullptr;
        }
        Node(int n) {
            val = n;
            next = nullptr;
        }
        Node(int n, Node *next) {
            val = n;
            this->next = next;
        }
    };
    Node *head, *tail;
    int sz;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    int get(int index) {
        // cerr << "Get\n";
        if(index < sz) {
            Node *tmp = head;
            while(index--) {
                tmp = tmp->next;
            }
            return tmp->val;
        } else {
            return -1;
        }
    }

    void insertHead(int val) {
        head = new Node(val, head);
        if(!tail)
            tail = head;
        sz++;
    }
    
    void insertTail(int val) {
        // cerr << "insert tail\n";
        // // cerr << tail->val << endl;
        Node *newNode = new Node(val);
        if(tail != nullptr) {
            // cerr << "Tail valid!\n";
            // cerr << tail << endl;
            // cerr << "val: " << tail->val << endl;
            tail->next = newNode;
            // cerr << "tail added\n";
            tail = tail->next;
        } else {
            tail = newNode;
            head = tail;
        }
        // cerr << "done insert tail\n";
        sz++;
    }

    bool remove(int index) {
        // cerr << "remove" << endl;
        // cerr << index << " " << sz << endl;
        if(index < sz) {
            sz--;
            if(index == 0) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
                if(sz == 0)
                    head = tail = nullptr;
                return true;
            }
            Node *curr = head;
            while(--index > 0) {
                // cerr << index << " - ";
                curr = curr->next;
                // cerr << "curr: " << curr->val << endl;
            }
            Node *tmp = curr->next;
            // cerr << "tmp: " << tmp->val << endl;
            if(tmp->next)
                curr->next = tmp->next;
            else {
                curr->next = nullptr;
                tail = curr;
            }
            delete tmp;
            // cerr << "done\n";
            if(sz == 0)
                head = tail = nullptr;
            return true;
        } else {
            return false;
        }
    }

    vector<int> getValues() {
        // cerr << "call get values\n";
        vector<int> vals;
        Node *curr = head;
        while(curr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        // cerr << "done get values\b";
        return vals;
    }
};
