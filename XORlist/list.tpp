#ifndef LIST_TPP
#define LIST_TPP
#include "list.hpp"

template <typename T>
XorLinkedList<T>::Node::Node(const T& val, Node* both)
    : m_val(val), m_both(both) {}

template <typename T>
XorLinkedList<T>::Node::Node(T &&val, Node *both = nullptr) noexcept : m_val{val}, m_both{both}{}

template <typename T>
XorLinkedList<T>::Node::~Node() = default;

template <typename T>
typename XorLinkedList<T>::Node* XorLinkedList<T>::XOR(const Node* rhs, const Node* lhs) {
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(rhs) ^ reinterpret_cast<uintptr_t>(lhs));
}

template <typename T>
XorLinkedList<T>::XorLinkedList() noexcept : m_head(nullptr), m_tail(nullptr), m_size(0) {}

template <typename T>
XorLinkedList<T>::XorLinkedList(size_type count, const T& val) : XorLinkedList() {
    for (size_type i = 0; i < count; ++i)
        this->push_back(val);
}


template <typename T>
template <typename InputIt>
XorLinkedList<T>::XorLinkedList(InputIt first, InputIt last) : XorLinkedList() {
    for (; first != last; ++first)
        this->push_back(*first);
}


template <typename T>
XorLinkedList<T>::XorLinkedList(const XorLinkedList& other) : XorLinkedList(other.begin(), other.end()){
}

template <typename T>
XorLinkedList<T>::XorLinkedList(XorLinkedList&& other) noexcept
    : m_head(other.m_head), m_tail(other.m_tail), m_size(other.m_size) {
    other.m_head = nullptr;
    other.m_tail = nullptr;
    other.m_size = 0;
}

template <typename T>
XorLinkedList<T>::XorLinkedList(std::initializer_list<T> list) : XorLinkedList(list.begin(),list.end()) {}

template <typename T>
XorLinkedList<T>& XorLinkedList<T>::operator=(const XorLinkedList& other) {
    if (this != &other) {
        for (Node* current = other.m_head, *prev = nullptr; current != nullptr) {
            push_back(current->m_val);
            Node * next = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(prev) ^ reinterpret_cast<uintptr_t>(current->m_both));
            prev = current;
            current = next;
        }
    }
    return *this;
}
template <typename T>
XorLinkedList<T>::~XorLinkedList() {
    clear();
}

template <typename T>
void XorLinkedList<T>::clear() noexcept {
    Node* prev = nullptr;
    while(m_head != nullptr) {
        Node* next = XOR(m_head->m_both, prev);
        prev = m_head;
        delete m_head;
        m_head = next;
    }
    m_head = m_tail = nullptr;
    m_size = 0;

}

template <typename T>
typename XorLinkedList<T>::reference XorLinkedList<T>::front() {
    return m_head->m_val;
}
template<typename T>
typename XorLinkedList<T>::const_reference XorLinkedList<T>::front() const {
    return m_head->m_val;
}

template <typename T>
typename XorLinkedList<T>::reference XorLinkedList<T>::back() {
    return m_tail->m_val;
}


template <typename T>
typename XorLinkedList<T>::const_reference XorLinkedList<T>::back() const {
    return m_tail->m_val;
}

template <typename T>
bool XorLinkedList<T>::empty() const noexcept {
    return m_head == nullptr;
}
template <typename T>
typename XorLinkedList<T>::size_type XorLinkedList<T>::size() const noexcept {
    return m_size;
} 

template <typename T>
void XorLinkedList<T>::push_back(const T& val) {
    Node* node = new Node(val);
    if (m_head == nullptr) {
        m_head = m_tail = node;
    }else {
        node->m_both = m_tail;
        m_tail->m_both = XOR(m_tail->m_both, node);
        m_tail = node;
    }
    ++m_size;
}

template <typename T>
void XorLinkedList<T>::push_back(T&& val) {
    Node* node = new Node(std::move(val));
    if (m_head == nullptr) {
        m_head = m_tail = node;
    }else {
        node->m_both = m_tail;
        m_tail->m_both = XOR(m_tail->m_both, node);
        m_tail = node;
    }
    ++m_size;
}
template <typename T>
void XorLinkedList<T>::push_front(const T &val) {
    Node * node  = new Node(val);
    if (m_head == nullptr) {
        m_head = m_tail = node;
    }else {
        node->m_both = m_head;
        m_head->m_both = XOR(m_head->m_both,node);
        m_head = node;
    }
    ++m_size;
}

template <typename T>
void XorLinkedList<T>::push_front(T  &&val) {
    Node * node  = new Node(std::move(val));
    if (m_head == nullptr) {
        m_head = m_tail = node;
    }else {
        node->m_both = m_head;
        m_head->m_both = XOR(m_head->m_both,node);
        m_head = node;
    }
    ++m_size;
}

template <typename T>
void XorLinkedList<T>::pop_back() {
    if (m_head == nullptr) return;
    else if (m_head == m_tail) {
        delete m_head;
        m_head = m_tail = nullptr;
    }
    else {

        Node* prev = m_tail->m_both;
        prev->m_both = XOR(prev->m_both, m_tail);
        delete m_tail;
        m_tail = prev;
    }
    --m_size;
}

template <typename T>
void XorLinkedList<T>::pop_front() {
    if (m_head == nullptr) return;
    else if (m_head == m_tail) {
        delete m_head;
        m_head = m_tail = nullptr;
    }else {
        Node* next = m_head->m_both;
        next->m_both = XOR(next->m_both, m_head);
        delete m_head; 
        m_head = next;
    }
    --m_size;
}

#endif
