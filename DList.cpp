#include <iostream>
#include "Node.cpp"
#include <cassert>

template <typename T>
class DList
{
public:
    DList():m_size(0){
        m_head = nullptr;
    }
    ~DList(){
        clear();
    }
    void push(const T& value){
        Node<T>* newNode = new Node<T>(value,m_head);
        if(m_head != nullptr)
            m_head->prev = newNode;

        m_head = newNode;
        ++m_size;
    }
    void pop(){
        assert(!isEmpty());
        Node<T>* tmp = m_head;
        m_head = m_head->next;
        if(m_head != nullptr)
            m_head->prev = nullptr;

        delete tmp;
        --m_size;
    }
    T top() const{
        assert(!isEmpty());

        return m_head->value;
    }
    bool isEmpty() const{
        return m_size == 0;
    }
    void clear(){
        while(!isEmpty()){
            pop();
        }
    }
private:
    Node<T>* m_head;
    int m_size;
};