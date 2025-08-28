#ifndef XLL_HPP
#define XLL_HPP


#include <cstdint>
#include <initializer_list>
#include <iterator>


template <typename T>
struct XorLinkedList {
   class Node {
       T m_val;
       Node *m_both;


       explicit Node(const T &val = T(), Node *both = nullptr);
       explicit Node(T &&val, Node *both = nullptr) noexcept;
       ~Node();
   };
public:
   using value_type = T;
   using size_type = size_t;
   using reference = T&;
   using const_reference = const T&;
   using pointer = T*;
   using const_pointer = const T*;


   class ConstIterator;
   class Iterator;
   class reverse_iterator;



   // static method for Node::m_both pointer
   static Node *XOR(const Node *rhs, const Node *lhs);


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
   Iterator begin() noexcept;
   Iterator end() noexcept;


   ConstIterator cbegin() const noexcept;
   ConstIterator cend() const noexcept;

   reverse_iterator rbegin() noexcept;
   reverse_iterator rend() noexcept;


   // capacity
   bool empty() const noexcept;
   size_type size() const noexcept;
 


   // modifiers
   void clear() noexcept;


//    Iterator insert(const_iterator pos, const T &val);
//    Iterator insert(const_iterator pos, T &&val);
//    Iterator insert(const_iterator pos, size_type count, const T &val);
//    template <typename InputIt>
//    iterator insert(const_iterator pos, InputIt first, InputIt last);
//    Iterator insert(const_iterator pos, std::initializer_list<T> ilist);
  
//    template <typename ...Args>
//    Iterator emplace(const_iterator pos, Args &&...args);


//    Iterator erase(iterator pos);
//    Iterator erase(const_iterator pos);
//    Iterator erase(iterator first, iterator last);
//    Iterator erase(const_iterator first, const_iterator last);


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
        explicit ConstIterator(const Node* a, const Node* b) : prev(a), curr(b)  {} 

        reference  operator*() const{
            return curr->m_val;
        }
        pointer operator->() const {
            return curr;
        }
        ConstIterator& operator++() {
            Node* next = XOR(curr->both, prev);
            prev = curr;
            curr = next;
            return *this;
        }
        ConstIterator operator++(int) {
            ConstIterator tmp = *this;
            ++(*this);
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
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
    private:
        Node* prev;
        Node* curr;
    public:
        explicit Iterator (Node* a, Node* b) : prev(a), curr(b)  {} 

        reference  operator*() {
            return *curr;
        }
        pointer operator->() {
            return curr->m_val;
        }
        Iterator& operator++() {
            Node* next = XOR(curr->m_both, prev);
            prev = curr;
            curr = next;
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            Node* next = XOR(curr->both, prev);
            ++(*this);
            return tmp;
        }

        Iterator& operator--() {
            Node* next = XOR(curr->both, prev);
            prev = curr;
            curr = next;
            return *this;
        }
        Iterator operator--(int) {
            Iterator tmp = *this;
            Node* next = XOR(curr->both, prev);
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            return curr == other.curr;
        }

        bool operator!=(const Iterator& other) const {
            return curr != other.curr;
        }
        
};

class reverse_iterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

private:
    Node* curr;
    Node* next; 

public:
    reverse_iterator(Node* a, Node* b)
        : curr(a), next(b) {}

    reference operator*() const {
        return curr->m_val;
    }

    pointer operator->() const {
        return curr.operator->();
    }

    reverse_iterator& operator++() {
        Node* prev = next;
        next = curr;
        curr = XOR(curr->m_both, prev);
        return *this;
    }

    reverse_iterator operator++(int) {
        reverse_iterator tmp = *this;
        ++(*this);
        return tmp;
    }
    reverse_iterator& operator--() {
    Node* next_node = next;              
    next = curr;                           
    curr = XOR(curr->m_both, next_node);   
    return *this;
    }

    reverse_iterator& operator--(int) {
        Node* next_node = next;               
        next = curr;                           
        curr = XOR(curr->m_both, next_node);   
        return *this;
    }

    bool operator==(const reverse_iterator& other) const {
        return curr == other.curr && next == other.next;
    }

    bool operator!=(const reverse_iterator& other) const {
        return !(*this == other);
    }
};



private:
   Node *m_head;
   Node *m_tail;

};
#endif