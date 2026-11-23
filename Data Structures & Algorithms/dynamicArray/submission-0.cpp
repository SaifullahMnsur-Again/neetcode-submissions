class DynamicArray {
    int *arr;
    int capacity;
    int sz;
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        sz = 0;
        arr = new int[capacity];
    }

    int get(int i) {
        cerr << "get\n";
        return arr[i];
    }

    void set(int i, int n) {
        cerr << "set\n";
        if(i >= sz)
            sz++;
        arr[i] = n;
    }

    void pushback(int n) {
        cerr << "pushback\n";
        cerr << sz << " " << capacity << endl;
        if(sz >= capacity)
            resize();
        arr[sz++] = n;
    }

    int popback() {
        cerr << "popback\n";
        return arr[--sz];
    }

    void resize() {
        cerr << "resize\n";
        capacity <<= 1;
        int *narr = new int[capacity];
        for(int i = 0; i < sz; i++)
            narr[i] = arr[i];
        delete []arr;
        arr = narr;
    }

    int getSize() {
        cerr << "get size\n";
        return sz;
    }

    int getCapacity() {
        cerr << "get capacity\n";
        return capacity;
    }
};
