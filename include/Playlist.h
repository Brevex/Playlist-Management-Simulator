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
        Playlist();
        Playlist(std::string nomeDaPlaylist);
        Playlist(const Playlist& outraPlaylist);

        // Destrutor
        ~Playlist();

        // Getters
        std::string getNomeDaPlaylist();
        Lista<Musica> *getListaDeMusicas();

        // Setters
        void setListaDeMusicas(Lista<Musica> *listaDeMusicas);
        void setNomeDaPlaylist(std::string nomeDaPlaylist);

        // Métodos de inserir músicas na playlist
        void inserirMusica(Musica *musica);
        void addListaMusicas(Lista<Musica>& listaMusicas);

        // Métodos de remover músicas da playlist 
        void removerMusica(Musica *musica);
        void removerListaMusicas(Lista<Musica>& listaMusicas);

        // Operador de comparacao
        bool operator==(const Playlist& outraPlaylist) const;

        // Verifica se musica esta na playlist
        bool estaNaPlaylist(Musica *musica);

        // Verifica se playlist esta vazia
        bool estaVazia();

        // Faz união de duas playlists
        Playlist unirPlaylists(Playlist& playlist1, Playlist& playlist2);

        // Remove músicas repetidas da playlist
        void removerMusicasRepetidas();
};

#endif
