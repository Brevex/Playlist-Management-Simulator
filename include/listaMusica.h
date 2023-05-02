#ifndef LISTAMUSICA_H
#define LISTAMUSICA_H

#include "noLista.h"

class MusicasLista
{
    private:

        NoLista *head;
        int tamanho;
    
    public:

        // Construtor
        MusicasLista();

        // Destrutor
        ~MusicasLista();

        // Adicionar e remover músicas
        void addMusica();
        void removeMusica(std::string titulo);

        // Busca música cadastrada na lista
        Musica* buscaMusica(std::string titulo);

        // Imprime lista de músicas
        void coutLista();
};

#endif
