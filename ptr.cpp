#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main() {
    auto_ptr<string> p1(new string("auto_ptr"));
    auto_ptr<string> p2;
    p2 = p1;

    /*unique_ptr<string> p3(new string("unique_ptr"));
    unique_ptr<string> p4;
    p4 = p3;*/

    unique_ptr<string> p5;
    p5 = unique_ptr<string>(new string("unique_ptr"));

    unique_ptr<string> u1,u2;
    u1.reset(new string("u1"));
    u2 = move(u1);
    u1.reset(new string("u2"));
    cout << *u1 << ' ' << *u2 << endl;



    return 0;
}
