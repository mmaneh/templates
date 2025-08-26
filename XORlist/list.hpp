#ifndef XLL_HPP
#define XLL_HPP


#include <cstdint>
#include <initializer_list>
#include <iterator>


template <typename T>
struct XorLinkedList {
   class Node {
       T m_val;
       XorLinkedList *m_both;


       explicit Node(const T &val = T(), T *both = nullptr);
       explicit Node(T &&val, T *both = nullptr) noexcept;
       ~Node();
   };
public:
   using value_type = T;
   using size_type = size_t;
   using reference = T&;
   using const_reference = const T&;
   using pointer = T*;
   using const_pointer = const T*;


   class const_iterator;
   class iterator;
   class reverse_iterator;
   class const_reverse_iterator;


   // static method for Node::m_both pointer
   static T *XOR(const Node *rhs, const Node *lhs);


   // Ctors and Dtor
   XorLinkedList() noexcept;
   explicit XorLinkedList(size_type count, const T &val = T());
   template <typename InputIt>
   XorLinkedList(InputIt first, InputIt last);
   XorLinkedList(const XorLinkedList &other);
   XorLinkedList(XorLinkedList &&other) noexcept;
   XorLinkedList(std::initializer_list<T> init);
   ~XorLinkedList();


   // assignment operators
   XorLinkedList &operator=(const XorLinkedList &other);
   XorLinkedList &operator=(XorLinkedList &&other) noexcept;


   // element access
   reference front();
   const_reference front() const;
   reference back();
   const_reference back() const;


   // iterators
   iterator begin() noexcept;
   const_iterator begin() const noexcept;
   const_iterator cbegin() const noexcept;


   iterator end() noexcept;
   const_iterator end() const noexcept;
   const_iterator cend() const noexcept;


   reverse_iterator rbegin() noexcept;
   const_reverse_iterator rbegin() const noexcept;
   const_reverse_iterator crbegin() const noexcept;


   reverse_iterator rend() noexcept;
   const_reverse_iterator rend() const noexcept;
   const_reverse_iterator crend() const noexcept;


   // capacity
   bool empty() const noexcept;
   size_type size() const noexcept;
   size_type max_size() const noexcept;


   // modifiers
   void clear() noexcept;


   iterator insert(const_iterator pos, const T &val);
   iterator insert(const_iterator pos, T &&val);
   iterator insert(const_iterator pos, size_type count, const T &val);
   template <typename InputIt>
   iterator insert(const_iterator pos, InputIt first, InputIt last);
   iterator insert(const_iterator pos, std::initializer_list<T> ilist);
  
   template <typename ...Args>
   iterator emplace(const_iterator pos, Args &&...args);


   iterator erase(iterator pos);
   iterator erase(const_iterator pos);
   iterator erase(iterator first, iterator last);
   iterator erase(const_iterator first, const_iterator last);


   void push_back(const T &val);
   void push_back(T  &&val);


   template <typename ...Args>
   void emplace_back(Args &&...args);


   void pop_back();


   void push_front(const T &val);
   void push_front(T  &&val);


   template <typename ...Args>
   void emplace_front(Args &&...args);   


   void pop_front();


   void resize(size_type count);
   void resize(size_type count, const T &val);


   void swap(XorLinkedList &other) noexcept;


   class ConstIterator { 
        public:
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
    private:
        Node* prev;
        Node* curr;
    public:
        explicit Iterator (const Node* a, const Node* b) : prev{a}, curr{b}  {} 

        reference  operator*() const{
            return curr->m_val;
        }
        pointer operator->() const {
            return curr;
        }
        ConstIterator& operator++() {
            Node* next = XOR(current->both, prev);
            prev = current;
            current = next;
            return *this;
        }
        ConstIterator operator++(int) {
            ConstIterator tmp = *this;
            (++this)
            return tmp;
        }

        bool operator==(ConstIterator& other) const {
            return curr == other.curr;
        }

        bool operator!=(ConstIterator& other) const {
            return curr != other.curr;
        }
        
    };


class Iterator {
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
    private:
        Node* prev;
        Node* curr;
    public:
        explicit Iterator (Node* a, Node* b) : prev{a}, curr{b}  {} 

        reference  operator*() {
            return curr->m_val;
        }
        pointer operator->() {
            return curr->m_val;
        }
        Iterator& operator++() {
            Node* next = XOR(current->both, prev);
            prev = current;
            current = next;
            return *this;
        }
        Iterator operator++(int) {
            Iterato tmp = *this;
            Node* next = XOR(current->both, prev);
            (++this);
            return tmp;
        }

        bool operator==(const iterator& other) const {
            return curr == other.curr;
        }

        bool operator!=(const iterator& other) const {
            return curr != other.curr;
        }
        
};


   class const_reverse_iterator { ... };


   class reverse_iterator { ... };


private:
   Node *m_head;
   Node *m_tail;

};
#endif