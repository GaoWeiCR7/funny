#include <iostream>
using namespace std;

template <class T>
class SharedPtr{
private:
    T* ptr;
    int* count;
public:
    SharedPtr():ptr(nullptr),count(nullptr){};

    SharedPtr(T* p)
    {
        ptr = p;
        count = new int(1);
    }
    SharedPtr(const SharedPtr<T> &s)
    {
        ptr = s.ptr;
        ++*s.count;
        count = s.count;
    }
    SharedPtr<T>& operator=(const SharedPtr<T> &s)
    {
        if(this == &s)
            return *this;
        --*count;
        if(*count == 0)
        {
            delete ptr;
            delete count;
        }
        ++*s.count;
        ptr = s.ptr;
        count = s.count;
        return *this;
    }
    T operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
    ~SharedPtr()
    {
        if(ptr!= nullptr)
        {
            --*count;
            if(*count == 0)
            {
                delete ptr;
                delete count;
            }
        }
    }
    int getcount()
    {
        return *count;
    }
};

int main()
{
    SharedPtr<int> p1(new int(1));
    SharedPtr<int> p2(p1);
    SharedPtr<int> p3 = p2;
    cout << *p2 << endl;
    cout << p2.getcount() << endl;
    return 0;
}