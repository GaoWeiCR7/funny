#include <iostream>
#include <cstring>
using namespace std;

int partition(int s[],int begin, int end)
{
    int i = begin;
    int j = end;
    int x = s[begin];
    while(i < j)
    {
        while(s[j] > x)
            --j;
        while(i < j&&s[i] <= x)
            ++i;
        if(i < j)
        {
            swap(s[i],s[j]);
        }
    }
    swap(s[begin],s[i]);
    return i;
}

void quicksort(int s[],int begin, int end)
{
    if(begin < end)
    {
        int p = partition(s,begin,end);
        quicksort(s,begin,p-1);
        quicksort(s,p+1,end);
    }
}


int main(int argc, const char * argv[])
{
    int a[] = {9, 1, 6, 6, 8, 3, 5, 100, 300, 200, 99, 99};
    quicksort(a, 0, sizeof(a)/sizeof(a[0]) - 1);


    for (int i : a) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
