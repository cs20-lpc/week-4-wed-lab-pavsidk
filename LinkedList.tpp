template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO
    this->head = nullptr;

    if (copyObj.head == nullptr) {
        this->length = 0;
        return;
    }

    this->head = new Node;
    this->head->value = copyObj.head->value;
    
    Node* curr = this->head;
    Node* copyCurr = copyObj.head->next;

    while (copyCurr != nullptr) {
        curr->next = new Node;
        curr = curr->next;
        curr->value = copyCurr->value;
        copyCurr = copyCurr->next;
    }

    curr->next = nullptr;
    this->length = copyObj.length;
}


template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // TODO
    if (position < 0 || position > this->length) {
        throw string("insert: error, position is out of bounds");
    }

    Node* curr = head;
    Node* n = new Node;
    n->value = elem;
    Node* prev = nullptr;
    
    for (int i = 0; i < position; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr) {
        n->next = head;
        head = n;
    }
    else {
        n->next = curr;
        prev->next = n;
    }
    this->length++;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }

    Node* curr = head;
    Node* prev = nullptr;;

    
    if (position == 0) {
        this->length--;
        head = curr->next;
        delete curr;
        return;
    }

    for (int i = 0; i < position; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        throw string("remove error, out of bounds");
    }

    prev->next = curr->next;
    delete curr;
    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
