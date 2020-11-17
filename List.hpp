#ifndef List_hpp
#define List_hpp

#include <iostream>
#include <stdio.h>

struct Node
{
    char chars;
    Node *next;
};

class List
{
private:
    Node *strNode;

public:
    List();
    void fromString(const std::string &word) const;
    std::string toString() const;
    List operator+(const List &rhs) const;
    ~List();
    void deleteList(Node *&ptr);
    friend std::ostream &operator<<(std::ostream &out, const List &rhs);
};

#endif