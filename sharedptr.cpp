#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main() {
    string* s1 = new string("s1");
    shared_ptr<string> p1(s1);
    shared_ptr<string> p2 = p1;

    *s1 = "dadada";
    cout << *p1 << endl;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    cout << p1.unique() << endl;

    string* s3 = new string("s3");
    shared_ptr<string> p3(s3);


    cout << p1.get() << endl;
    cout << p3.get() << endl;
    swap(p1,p3);
    cout << p1.get() << endl;
    cout << p3.get() << endl;

    cout << p1.use_count()<<endl;
    cout << p2.use_count() << endl;
    p2 = p1;
    cout << p1.use_count()<<endl;
    cout << p2.use_count() << endl;

    p1.reset();	//放弃ps1的拥有权，引用计数的减少
    cout << p1.use_count()<<endl;	//0
    cout << p2.use_count()<<endl;	//1
    return 0;
}
