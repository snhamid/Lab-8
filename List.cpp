#include "List.hpp"

List::List()
{
    strNode = new Node;
    strNode->next = nullptr;
}

void List::fromString(const std::string &word) const
{
    Node *ptr = strNode;
    int i;
    for (i = 0; i < word.length(); i++)
    {
        ptr->chars = word[i];
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->next = nullptr;
    }
}

std::string List::toString() const
{
    std::string returnWord;
    Node *ptr = strNode;

    while (ptr->next != nullptr)
    {
        returnWord += ptr->chars;
        ptr = ptr->next;
    }
    return returnWord;
}

List List::operator+(const List &rhs) const
{
    std::string combinedWord;
    std::string lhs = this->toString();
    std::string rhs2 = rhs.toString();
    combinedWord = lhs + rhs2;
    List combinedList;

    combinedList.fromString(combinedWord);

    return combinedList;
}

std::ostream &operator<<(std::ostream &out, const List &rhs)
{
    Node *ptr = rhs.strNode;

    while (ptr != nullptr)
    {
        out << ptr->chars;
        ptr = ptr->next;
    }
    return out;
}

void List::deleteList(Node *&ptr)
{
    if (ptr != nullptr)
    {
        ptr = nullptr;
        //deleteList(ptr);
    }
    else
    {
        deleteList(ptr->next);
    }
}

List::~List()
{
    deleteList(strNode);
}