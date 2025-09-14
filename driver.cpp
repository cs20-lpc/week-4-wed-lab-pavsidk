#include "LinkedList.hpp"
#include <string>

int main() {
    LinkedList<string> myList;

    //empty string list
    cout << "   TESTING APPEND" << endl;
    cout << "*--------------------*" << endl;
    cout << "Length of empty myList: " << myList.getLength() << endl;
    cout << "Checking using the 'isEmpty' method: ";
    if (myList.isEmpty()) {
        cout << "The list is empty. " << endl;
    }
    else {
        cout << "The list is not empty. " << endl;
    }

    myList.append("This");
    myList.append("program");
    cout << "Length of myList after appending two strings: " << myList.getLength() << endl;
    cout << endl;
    cout << endl;

    //testing insert
    cout << "   TESTING INSERT" << endl;
    cout << "*--------------------*" << endl;
    myList.insert(0, "the");
    myList.insert(0, "is");
    cout << "Contents of myList after inserting two strings (both in the beginning): " << myList << endl;
    cout << "   *----*" << endl;
    myList.insert(3, "end");
    cout << "Contents of myList after inserting a string in the end of the list: " << myList << endl;
    cout << "   *----*" << endl;
    myList.insert(2, "within");
    cout << "Contents of myList after inserting a string in between the list: " << myList << endl;
    cout << "   *----*" << endl;
    cout << "Trying to insert an element to myList at position 15 (out of bounds). " << endl;
    try {
        myList.insert(15, "cake");
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << endl;
    cout << endl;

    //testing remove
    cout << "   TESTING REMOVE" << endl;
    cout << "*--------------------*" << endl;
    cout << "Contents of myList: " << myList << endl;
    cout << "Removing element of myList at position 1. " << endl;
    myList.remove(1);
    cout << "   *----*" << endl;
    cout << "Removing element of myList at position 0. " << endl;
    myList.remove(0);
    cout << "   *----*" << endl;
    cout << "Removing element of myList at last position. " << endl;
    myList.remove(2);
    cout << "   *----*" << endl;
    cout << "Contents of myList: " << myList << endl;
    cout << "Trying to remove element of myList at position 10 (out of bounds). " << endl;
    try {
        myList.remove(10);
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << endl;
    cout << endl;

    //testing replace
    cout << "   TESTING REPLACE" << endl;
    cout << "*--------------------*" << endl;
    cout << "Element of myList at position 1: " << myList.getElement(1) << endl;
    cout << "Replacing element of myList at position 1. " << endl;
    myList.replace(1, "word");
    cout << "Element of myList at position 1: " << myList.getElement(1) << endl;
    cout << "   *----*" << endl;

    cout << "Trying to replace element of myList at position 9 (out of bounds). " << endl;
    try {
        myList.replace(9, "food");
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << endl;
    cout << endl;

    //copy list
    cout << "   TESTING DEEP COPY" << endl;
    cout << "*--------------------*" << endl;
    cout << "Copying myList using the overloaded = assignment operator." << endl;
    cout << "Contents of myList: " << myList << endl;
    LinkedList<string> copyList = myList;
    cout << "Contents of copyList: " << copyList << endl;
    cout << "Copying myList using the copy constructor. " << endl;
    LinkedList<string> copyListTwo(myList);
    cout << "Contents of copyListTwo: " << copyListTwo << endl;
    cout << "Inserting an element into copyList at position 1 to check that it is a deep copy. " << endl;
    copyList.insert(1, "additional");
    cout << "Contents of copyList: " << copyList << endl;
    cout << "Contents of myList: " << myList << endl;
    cout << endl;
    cout << endl;

    //clear
    cout << "   TESTING CLEAR" << endl;
    cout << "*--------------------*" << endl;
    cout << "Clearing contents of copyList. " << endl;
    copyList.clear();
    cout << "Contents of copyList: " << copyList << endl;
    cout << endl;

    cout << endl;

    //integer list
    cout << "   OTHER DATATYPE" << endl;
    cout << "*--------------------*" << endl;
    LinkedList<int> intList;
    intList.append(10);
    cout << "Contents of intList: " << intList << endl;
    cout << endl;
    cout << "   *----*" << endl;
    cout << "Removing the only element in intList. " << endl;
    intList.remove(0);
    cout << "Contents of intList: " << intList << endl;
    cout << "   *----*" << endl;
    cout << "Inserting an element to the empty intList. " << endl;
    intList.insert(0, 100);
    cout << "Contents of intList: " << intList << endl;
    cout << "   *----*" << endl;
    cout << "Copying IntList using the copy constructor. " << endl;
    LinkedList<int> copyIntList(intList);
    cout << "Contents of copyIntList: " << copyIntList << endl;
    cout << endl;


}