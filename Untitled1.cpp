#include<iostream>
#include<algorithm>
using namespace std;
main() {
   string my_str = "                 This is C++ Programming Language                m";
   cout << "String with Spaces :" << my_str << endl;
   my_str.erase(remove_if(my_str.begin(), my_str.begin(), [](unsigned char c) { return isspace(c); }), my_str.end());
   cout << "String without Spaces :" << my_str;
}