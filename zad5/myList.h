#ifndef UNTITLED1_MYLIST_H
#define UNTITLED1_MYLIST_H


#include <iostream>
#include <memory>

template <typename T>
class MyList{
    private:
        //increments size+1
        void incSize() {size_++;}
        //decrements size-1
        void decSize() {size_--;}
    public:
        using value_type =T;
        struct Node{
            std::unique_ptr<Node> next= nullptr;
            T data={};
        };
        /** My list stuff **/
        explicit MyList();
        //get size
        [[nodiscard]] int size() const { return size_;}
        //add item to front
        void push_front(T addData);
        //deletes and returns first item
        T pop_front();
        //show first element
        T front();
        //making copying unavailable
        MyList(const MyList&) = delete;
        void operator=(const MyList&) =delete;
        //remove
        void remove(T element);
        //printer
        void printList();

        template<typename A>
        friend std::ostream & operator<<(std::ostream &out,const MyList<A> &m);
        /** Iterator stuff **/


        //template <typename PoniterType>
        class Iterator{
            friend class MyList;
            public:
                using value_type =T;
                using pointer=T*;
                using reference = T&;
                using iterator_category=std::forward_iterator_tag ;
                using difference_type=std::ptrdiff_t;
                Iterator() noexcept : currentNode(nullptr){};
                Iterator(Node* node) noexcept : currentNode(node){};
                Iterator& operator++(){
                    if (currentNode!=NULL){
                        currentNode=currentNode->next.get();
                    }
                    return *this;
                }
                Iterator operator+(const int& n) const{
                    Iterator temp = Iterator(currentNode);
                    for (int i=0;i<n;i++){
                        if (temp.currentNode!=NULL) {
                            ++temp;
                        }
                        else{
                            break;
                        }
                    }
                    return temp;
                }
                bool operator!=(const Iterator& other) const noexcept
                {
                    return this->currentNode !=  other.currentNode;
                };
                bool operator==(const Iterator& other) const noexcept
                {
                    return this->currentNode ==  other.currentNode;
                };
                T& operator*() const{
                    return this->currentNode->data;
                };
                T* operator->() const{
                    return &(this->currentNode->data);
                };

            private:
                Node* currentNode = nullptr;
        };

        typedef Iterator iterator;

    class constIterator{
        friend class MyList;
        public:
            using value_type =const T;
            using pointer=const T*;
            using reference = const T&;
            using iterator_category=std::forward_iterator_tag ;
            using difference_type=std::ptrdiff_t;
            constIterator() noexcept : currentNode(nullptr){};
            constIterator(const Node* node) noexcept : currentNode(node){};
            constIterator& operator++(){
                if (currentNode!=NULL){
                    currentNode=currentNode->next.get();
                }
                return *this;
            }
            constIterator operator+(const int& n) const{
                Iterator temp = Iterator(currentNode);
                for (int i=0;i<n;i++){
                    if (temp.currentNode!=NULL) {
                        ++temp;
                    }
                    else{
                        break;
                    }
                }
                return temp;
            }
            bool operator!=(const constIterator& other) const noexcept
            {
                return this->currentNode !=  other.currentNode;
            };
            bool operator==(const constIterator& other) const noexcept
            {
                return this->currentNode ==  other.currentNode;
            };
            const T& operator*() const {
                return this->currentNode->data;
            };
            const T* operator->() const {
                return &(this->currentNode->data);
            };

        private:
            const Node* currentNode = nullptr;
        };

        typedef constIterator const_iterator;
        Iterator begin() {return Iterator(this->head.get());};
        Iterator end() {return Iterator();};
        constIterator cbegin() const  {return constIterator(this->head.get());};
        constIterator cend() const  {return constIterator();};


    /*
        typedef Iterator<int*> IteratorType;
        typedef Iterator<const int*> ConstIteratorType;
        //begin and end returns appropriate Nodes from list
        ConstIteratorType begin() const noexcept {return ConstIteratorType(this->head);};
        IteratorType begin()  {return IteratorType(this->head);};
        ConstIteratorType end() const noexcept {return ConstIteratorType();};
        IteratorType end() {return IteratorType();};
        */

        //atributes
    protected:
        std::unique_ptr<Node> head= nullptr;
        int size_=0;


};




template<typename T>
MyList<T>::MyList() {
    size_=0;
    head= nullptr;
}

template<typename T>
void MyList<T>::push_front(T addData) {
    head=std::unique_ptr<Node>(new Node{std::move(head),addData});
    incSize();
}

template<typename T>
T MyList<T>::pop_front() {
    if (head!=NULL){
        decSize();
        T toReturn = head->data;
        head=std::move(head->next);
        return toReturn;
    }
    else{
        throw std::out_of_range("Out of range");
    }
}

template<typename T>
T MyList<T>::front() {
    if (head!=NULL){
        return head->data;
    }
    else{
        throw std::out_of_range("Out of range");
    }
}

template<typename T>
void MyList<T>::remove(T element) {
    Node * temp = head.get();
    //only in middle and end
    while(temp->next!=NULL){
        while (temp->next.get()->data==element){
            //std::cout<<temp->next.get()->next.get()->data<<std::endl;
            std::unique_ptr<Node>& toMove=temp->next.get()->next;
            temp->next=std::move(toMove);
            decSize();
            //we need to control if nullptr was moved as next Node
            if (temp->next==NULL){
                break;
            }

        }
        //we need to control if nullptr was moved as next Node
        if (temp->next==NULL){
            break;
        }
        temp=temp->next.get();
    }
    //check start of list
    if (head.get()->data==element){
        this->pop_front();
    }

}

template<typename T>
void MyList<T>::printList() {
   Node * temp=head.get();
   while (temp->next!=NULL){
       std::cout<<temp->data<<"->";
       temp=temp->next.get();
   }
   std::cout<<temp->data<<std::endl;
}
template<typename T>
std::ostream &operator<< (std::ostream &out, const MyList<T> &m) {
    for (auto i=m.cbegin(); i!=m.cend(); ++i)
    {
        out<<*i<<" ";
    }
    return out;
}



#endif //UNTITLED1_MYLIST_H
