using namespace std;
#include <iostream>
#include "List.cpp"

int main()
{
    List list1;
    List list2;
    List list3;

    string word1 = "cat";
    string word2 = "fish";
    string word3 = "";

    list1.fromString(word1);
    list2.fromString(word2);
    word3 = list1.toString();

    cout << list1 << " + " << list2 << " = ";
    list3 = list1 + list2;
    cout << list3 << endl;

    return 0;
}
