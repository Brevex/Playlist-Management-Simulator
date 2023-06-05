#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "Node.h"

template <typename T> class Lista
{
    private:

        Node<T> *head;
        Node<T> *tail;
        int size;

    public:

        // Construtor
        Lista() : head(nullptr), tail(nullptr), size(0) {}

        // Destrutor
        ~Lista()
        {
            Node<T> *aux = head;

            // Percorre a lista deletando os nodes
            while (aux != nullptr)
            {
                Node<T> *next = aux -> getNext();
                delete aux;

                aux = next;
            }
        }

        // Getters - retorna o head
        Node<T> *getHead()
        {
            return head;
        }

        // Getters - retorna o tail
        Node<T> *getTail()
        {
            return tail;
        }

        // Getters - retorna o tamanho
        int getSize()
        {
            return size;
        }

        // Setters - define o head
        void setHead(Node<T> *m_head)
        {
            head = m_head;
        }
        
        // Setters - define o tail
        void setTail(Node<T> *m_tail)
        {
            tail = m_tail;
        }    

        // Insere um elemento no final da lista
        void inserirNaLista(T *data)
        {
            
            Node<T> *newNode = new Node<T>(data);

            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->setNext(newNode);
                tail = newNode;
            }

            size++;
        }

        // Remove um elemento da lista
        void removerDaLista(T* data)
        {
            Node<T> *aux = head;
            Node<T> *prev = nullptr;
    
            // Percorre a lista até encontrar o node com o dado a ser removido
            while (aux != nullptr && aux -> getData() != data)
            {
                prev = aux;
                aux = aux -> getNext();
            }
    
            // Se o node não for encontrado, retorna
            if (aux == nullptr)
            {
                return;
            }
    
            // Se o node for o head, define o próximo node como head
            if (aux == head)
            {
                head = aux -> getNext();
            }
            // Se o node for o tail, define o node anterior como tail
            else if (aux == tail)
            {
                tail = prev;
                tail -> setNext(nullptr);
            }
            // Se o node estiver no meio da lista, define o node anterior ao node removido como o próximo node do node removido
            else
            {
                prev -> setNext(aux -> getNext());
            }
    
            // Deleta o node
            delete aux;
    
            // Decrementa o tamanho da lista em -1
            size--;
        }

        // Confere se a lista está vazia
        bool estaVazia()
        {
            if (head == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Busca por indice
        T* getItem(int indice)
        {
            Node<T> *aux = head;

            // Percorre a lista até encontrar o indice
            for (int i = 0; i < indice; i++)
            {
                aux = aux -> getNext();
            }

            return aux -> getData();
        }

        // Confere se um item já foi inserido na lista
        bool estaNaLista(T* data)
        {
            Node<T> *aux = head;

            // Percorre a lista até encontrar o item
            while (aux != nullptr && aux -> getData() != data)
            {
                aux = aux -> getNext();
            }

            // Se o item não for encontrado, retorna false
            if (aux == nullptr)
            {
                return false;
            }
            // Se o item for encontrado, retorna true
            else
            {
                return true;
            }
        }
};

#endif
