template <typename T>
class DoubleLinkedList {
   protected:

        struct Node {
            T data;
            Node* prev;
            Node* next;
            Node(const T& value) : data{value}, prev{nullptr}, next{nullptr} {}
        };

        Node* head;
        Node* tail;
    public:
        DoubleLinkedList() : head{nullptr}, tail{nullptr} {}
        DoubleLinkedList(const DoubleLinkedList& other) : head{nullptr}, tail{nullptr} {
            Node* curr = other.head;
            while(curr) {
                push_back(curr->data);
		curr = curr->next;
            }
        }
        DoubleLinkedList(DoubleLinkedList&& other) noexcept : head{other.head}, tail{other.tail} {
            other.head = nullptr;
            other.tail = nullptr;
        }

        DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept {
            if(this != &other) {
                clear();
                head = other.head;
                tail = other.tail;
                other.head = nullptr;
                other.tail = nullptr;
            }
            return * this;
        }
	
	~DoubleLinkedList() {
    		clear();
	}

        void push_front(const T& value) {
            Node* newNode = new Node(value);
            newNode->next = head;
	    if(head)  head->prev = newNode;
	    else tail = newNode;
            head = newNode;
        }
        void push_back(const T& value) {
            Node* newNode = new Node(value);
            newNode->prev = tail;
            if(tail) tail->next = newNode;
	    else head = newNode; 
            tail = newNode;
        }
        void pop_front() {
	    if(!head) return;
            Node* tmp = head;
            head = head->next;
            if(head) head->prev = nullptr;
	    else tail = nullptr;
            delete tmp;
        }

        void pop_back() {
	    if(!tail) return;
            Node* tmp = tail;
            tail = tail->prev;
            if(tail) tail->next = nullptr;
	    else head = nullptr;
            delete tmp;
        }

        void erase(Node* node) {
	    if(!node) return;

            
             if(node->next) node->next->prev = node->prev;
	     else tail = node->prev;
             if(node->prev) node->prev->next = node->next;
	     else head = node->next;
             delete node;
        }

        void clear() {
            while(head) {
		Node* tmp = head;
	    	head = head->next;
		delete tmp;
	    }
        }
        T& front() const {return head->data;}
        T& back() const {return tail->data;}
        Node*find(const T& value) const {
            Node* tmp = head;
            while(tmp) {
                if(tmp->data == value) return tmp;                
                tmp = tmp->next;
            }
            return nullptr;
        }
        
        void merge(DoubleLinkedList<T>& other) {
            if(!other.head) return;
	    if(tail == nullptr) {
                head = other.head;
                tail = other.tail;    
            }
            else{
                tail->next = other.head;
                other.head->prev = tail;
                tail = other.tail;    
            }
            other.tail = nullptr;
            other.head =nullptr;
        }
	

