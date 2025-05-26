#ifndef STRUCT_TYPE_PROJECT_6_H_INCLUDED
#define STRUCT_TYPE_PROJECT_6_H_INCLUDED

#include <string>
using namespace std;

struct Product {
    string sectionNumber;
    string sectionName;
    string productCode;
    string productName;
};

struct Node {
    Product data;
    Node* next;
};

#endif // STRUCT_TYPE_PROJECT_6_H_INCLUDED
