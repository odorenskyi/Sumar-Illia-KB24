#ifndef OLEFIROV_H_INCLUDED
#define OLEFIROV_H_INCLUDED

#include "struct_type_project_6.h"

Node* loadFromFile(const std::string& filename);
void saveToFile(const std::string& filename, Node* head);

#endif // OLEFIROV_H_INCLUDED