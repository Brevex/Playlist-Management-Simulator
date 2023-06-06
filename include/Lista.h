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

        // Construtor cópia (requisito da parte 2 do projeto)
        Lista(Lista<T>& outraLista) : head(nullptr), tail(nullptr), size(0)
        {
            Node<T>* aux = outraLista.getHead();

            // Percorre a lista recebida e insere cada elemento na nova lista
            while (aux != nullptr)
            {
                inserirNaLista(aux -> getData());
                aux = aux -> getNext();
            }
        }

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
        
        // Insere uma lista ligada de elementos a lista atual (requisito da parte 2 do projeto)
        void addElementos(Lista<T>& lista)
        {
            Node<T>* aux = lista.getHead();

            // Percorre a lista recebida e insere cada elemento na lista atual
            while (aux != nullptr)
            {
                inserirNaLista(aux -> getData());
                aux = aux -> getNext();
            }
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

        // Recebe uma lista ligada de elementos que devem ser removidos da lista atual (requisito da parte 2 do projeto)
        void removerElementos(Lista<T>& lista)
        {
            Node<T>* aux = lista.getHead();

            // Percorre a lista recebida e remove cada elemento da lista atual
            while (aux != nullptr)
            {
                removerDaLista(aux -> getData());
                aux = aux -> getNext();
            }
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

        // Operador de concatenação (requisito da parte 2 do projeto)
        Lista<T> operator+(Lista<T>& outraLista)
        {
            Lista<T> novaLista(*this); // Cria uma cópia da lista atual

            Node<T>* aux = outraLista.getHead();

            // Percorre a lista recebida e insere cada elemento na nova lista
            while (aux != nullptr)
            {
                novaLista.inserirNaLista(aux -> getData());
                aux = aux -> getNext();
            }

            return novaLista;
        }

        // Operador de extração (requisito da parte 2 do projeto)
        friend Lista<T>& operator>>(Lista<T>& lista, Node<T>*& no)
        {
            if (!lista.estaVazia())
            {
                T valor = lista.getTail() -> getData(); // Obtém o valor do último elemento
                lista.removerDaLista(valor); // Remove o último elemento da lista
                no = new Node<T>(valor); // Cria um novo nó com o valor do último elemento
            }
            else
            {
                no = nullptr; // A lista está vazia, atribui nullptr ao nó
            }

            return lista;
        }

        // Operador de inserção (requisito da parte 2 do projeto)
        friend Lista<T>& operator<<(Lista<T>& lista, Node<T>*& no)
        {
            if (no != nullptr)
            {
                lista.inserirNaLista(no -> getData()); // Insere o valor do nó no fim da lista
            }

            return lista;
        }

        // Remove elementos repetidos da lista
        void removerRepetidos()
        {
            Node<T>* aux = head;

            // Percorre a lista
            while (aux != nullptr)
            {
                Node<T>* aux2 = aux -> getNext();

                // Percorre a lista a partir do elemento seguinte ao elemento atual
                while (aux2 != nullptr)
                {
                    // Se o elemento atual for igual ao elemento seguinte, remove o elemento seguinte
                    if (aux -> getData() == aux2 -> getData())
                    {
                        removerDaLista(aux2 -> getData());
                    }

                    aux2 = aux2 -> getNext();
                }

                aux = aux -> getNext();
            }
        }
};

#endif
