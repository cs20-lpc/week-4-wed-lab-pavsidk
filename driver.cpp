#include "LinkedList.hpp"
#include <string>

int main() {
    LinkedList<string> myList;

    //empty string list
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
    cout << "*--------------------*" << endl;

    //testing insert
    myList.insert(0, "the");
    myList.insert(0, "is");
    cout << "Length of myList after inserting two strings: " << myList.getLength() << endl;
    cout << "Contents of myList: " << myList << endl;
    cout << "----" << endl;
    myList.insert(3, "end");
    cout << "Length of myList after inserting a string at the end: " << myList.getLength() << endl;
    cout << "Contents of myList: " << myList << endl;
    cout << "Element of myList at position 4: " << myList.getElement(4) << endl;
    cout << "----" << endl;
    myList.insert(2, "within");
    cout << "Contents of myList after inserting a string in between the list: " << myList << endl;
    cout << "----" << endl;
    cout << "Inserting element to myList at position 15 (out of bounds). " << endl;
    try {
        myList.insert(15, "cake");
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << "*--------------------*" << endl;

    //testing remove
    cout << "Contents of myList: " << myList << endl;
    cout << "Removing element of myList at position 2. " << endl;
    myList.remove(2);
    cout << "----" << endl;
    cout << "Removing element of myList at position 0. " << endl;
    myList.remove(0);
    cout << "----" << endl;
    cout << "Removing element of myList at last position. " << endl;
    myList.remove(2);
    cout << "----" << endl;
    cout << "Contents of myList: " << myList << endl;

    cout << "Removing element of myList at position 10 (out of bounds). " << endl;
    try {
        myList.remove(10);
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << "*--------------------*" << endl;

    //testing replace
    cout << "Element of myList at position 1: " << myList.getElement(1) << endl;
    cout << "Replacing element of myList at position 1. " << endl;
    myList.replace(1, "word");
    cout << "Element of myList at position 1: " << myList.getElement(1) << endl;
    cout << "----" << endl;

    cout << "Replacing element of myList at position 9 (out of bounds). " << endl;
    try {
        myList.replace(9, "food");
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << "*--------------------*" << endl;

    //copy list
    cout << "Contents of myList: " << myList << endl;
    LinkedList<string> copyList = myList;
    cout << "Contents of copyList: " << copyList << endl;
    cout << "*--------------------*" << endl;

    //clear
    cout << "Clearing contents of copyList. " << endl;
    copyList.clear();
    cout << "Contents of copyList: " << copyList << endl;
    cout << "*--------------------*" << endl;

    //integer list
    LinkedList<int> intList;
    intList.append(10);
    intList.append(20);
    cout << "Contents of intList: " << intList << endl;

}

// Methods to test:
// 1. LinkedList()                  // default constructor U
// 2. LinkedList(const LinkedList&) // copy constructor   Verify deep copy — make sure modifying the copy doesn’t affect the original:
// 3. ~LinkedList()                 // destructor
// 4. operator=                     // assignment operator     U
// 5. operator<<                     // output stream operator U
// 6. append(const T&)              // add element to end      U
// 7. clear()                       // delete all nodes        U
// 8. copy(const LinkedList&)       // deep copy helper         U
// 9. getElement(int) const         // access element by index  U
// 10. getLength() const            // get current list length  U
// 11. isEmpty() const              // check if list is empty   U
// 12. insert(int, const T&)        // insert element at index  U
// 13. remove(int)                  // remove element at index  U
// 14. replace(int, const T&)       // replace element at index U
