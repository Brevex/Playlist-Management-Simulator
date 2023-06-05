#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Musica.h"
#include "Lista.h"

class Playlist
{
    private:

        std::string nomeDaPlaylist;
        Lista<Musica> *listaDeMusicas;

    public:

        // Construtor
        Playlist(std::string nomeDaPlaylist);

        // Destrutor
        ~Playlist();

        // Getters
        std::string getNomeDaPlaylist();
        Lista<Musica> *getListaDeMusicas();

        // Setters
        void setListaDeMusicas(Lista<Musica> *listaDeMusicas);
        void setNomeDaPlaylist(std::string nomeDaPlaylist);

        // Insere uma música na playlist
        void inserirMusica(Musica *musica);

        // Remove uma música da playlist 
        void removerMusica(Musica *musica);

        // Operador de comparacao
        bool operator==(const Playlist& outraPlaylist) const;

        // Verifica se musica esta na playlist
        bool estaNaPlaylist(Musica *musica);

        // Verifica se playlist esta vazia
        bool estaVazia();
};

#endif
