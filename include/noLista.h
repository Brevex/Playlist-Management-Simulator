#ifndef NOLISTA_H
#define NOLISTA_H

#include "musica.h"
#include <iostream>

class NoLista
{
    private:

        Musica *musica;
        NoLista *proxima;
    
    public:
        
        // Construtor
        NoLista(Musica *novaMusica, NoLista *proximaMusica);

        // Destrutor
        ~NoLista();

        // Getters
        Musica *getMusica();
        NoLista *getProxima();

        // Setter
        void setProxima(NoLista *proximo);
};

#endif
