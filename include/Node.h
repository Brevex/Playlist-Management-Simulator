#ifndef NODE_H
#define NODE_H

template <typename T> class Node
{
    private:

        T *data;
        Node<T> *next;

    public:

        // Construtor
        Node(T* m_data) : data(m_data), next(nullptr) {}

        // Getters - retorna data
        T* getData()
        {
           return data; 
        }

        // Getters - retorna next
        Node<T>* getNext()
        {
            return next;
        }

        // Setters - define data
        void setData(T m_data)
        {
            data = m_data;
        }

        // Setters - define next
        void setNext(Node<T>* m_next)
        {
            next = m_next;
        }
};

#endif
