#ifndef LIST_TPP
#define LIST_TPP
#include "list.hpp"

template <typename T>
XorLinkedList<T>::Node::Node(const T& val, T* both)
    : m_val(val), m_both(both) {}

template <typename T>
XorLinkedList<T>::Node::Node(T &&val, T *both = nullptr) noexcept : m_val{val}, m_both{both}{}

template <typename T>
XorLinkedList<T>::XorLinkedList::Node::~Node() = default;

template <typename T>
typename XorLinkedList<T>::value_type* XorLinkedList<T>::XOR(const Node* rhs, const Node* lhs) {
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t(rsh) ^ reinterpret_cast<uintptr_t(lhs));
}

template <typename T>
XorLinkedList<T>::XorLinkedList() noexcept : head(nullptr), tail(nullptr), m_size(0) {}

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
    : head(other.head), tail(other.tail), m_size(other.m_size) {
    other.head = nullptr;
    other.tail = nullptr;
    other.m_size = 0;
}

template <typename T>
XorLinkedList<T>::XorLinkedList(std::initializer_list<T> list) : XorLinkedList(list.begin(),list.end()) {}

template <typename T>
XorLinkedList<T>& XorLinkedList<T>::operator=(const XorLinkedList& other) {
    if (this != other) {
        for (Node* current = other.m_head, *prev = nullptr; current != nullptr) {
            push_back(current->val);
            Node * next = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(prev) ^ reinterpret_cast<uintptr_t>(current->m_both));
            prev = current;
            current = next;
        }
    }
    return *this;
}
template <typename T>
typename XorLinkedList<T>::reference XorLinkedList<T>::front() {
    return m_head->val;
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
typename XorLinkedList<T>:: reference XorLinkedList<T>::back() {
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


#endif
