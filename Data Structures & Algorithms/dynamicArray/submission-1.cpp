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
        return arr[i];
    }

    void set(int i, int n) {
        if(i >= sz)
            sz++;
        arr[i] = n;
    }

    void pushback(int n) {
        if(sz >= capacity)
            resize();
        arr[sz++] = n;
    }

    int popback() {
        return arr[--sz];
    }

    void resize() {
        capacity <<= 1;
        int *narr = new int[capacity];
        for(int i = 0; i < sz; i++)
            narr[i] = arr[i];
        delete []arr;
        arr = narr;
    }

    int getSize() {
        return sz;
    }

    int getCapacity() {
        return capacity;
    }
};
