#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
	int st, ed, val;
	int *data;

public:
    // Default constructor
    Evil() : st(0), ed(0), val(0), data(new int[1]()) {}

    // Parameterized constructor
    Evil(int st, int ed, int val) : st(st), ed(ed), val(val) {
        int size = ed - st + 1;
        data = new int[size]();
    }

    // Copy constructor (needed for proper deep copy)
    Evil(const Evil& other) : st(other.st), ed(other.ed), val(other.val) {
        int size = ed - st + 1;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator overload
    Evil& operator=(const Evil& other) {
        if (this != &other) {
            delete[] data;
            st = other.st;
            ed = other.ed;
            val = other.val;
            int size = ed - st + 1;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Subscript operator overload
    int& operator[](int i) {
        if (i < st || i > ed) {
            return data[0];
        }
        return data[i - st];
    }

    // Prefix ++ overload
    Evil& operator++() {
        ++val;
        return *this;
    }

    // Postfix ++ overload
    Evil operator++(int) {
        Evil temp(*this);
        ++val;
        return temp;
    }

    // Output operator overload
    friend ostream& operator<<(ostream& os, const Evil& evil) {
        os << evil.val << " ";
        for (int i = 0; i < evil.ed - evil.st + 1; ++i) {
            os << evil.data[i] << " ";
        }
        os << endl;
        return os;
    }

    // Destructor
    ~Evil() {
        delete[] data;
    }

    void Print(){
	    cout << val << " ";
	    for(int i = 0;i < ed-st+1;++i)
	        cout << data[i] <<" ";
	    cout << endl;
	}
};

#endif//EVIL_HPP
