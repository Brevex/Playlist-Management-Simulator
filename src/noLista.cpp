#include "../include/noLista.h"

// Construtor da classe, define o nó atual com um objeto do tipo "Musica" e define proximo nó
NoLista::NoLista(Musica *novaMusica, NoLista *proximaMusica) : musica(novaMusica), proxima(proximaMusica) {}

// Destrutor
NoLista::~NoLista()
{
    // Verifica se o ponteiro é diferente de "nullptr"
    if (musica != NULL)
    {
        delete musica;   
    }
}

// Retorna a música atual
Musica* NoLista::getMusica()
{
    return musica;
}

// Retorna próximo nó
NoLista* NoLista::getProxima()
{  
    return proxima;
}

// Define próxima música
void NoLista::setProxima(NoLista *proximo)
{
    proxima = proximo;
}
