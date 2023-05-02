#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "listaMusica.h"
#include "noPlaylist.h"

class Playlist
{
    private:

        std::string nomePlaylist;
        NoPlaylist *head;
        int tamanhoPlaylist;

    public:

        // Construtor
        Playlist(std::string m_nomePlaylist);

        // Destrutor
        ~Playlist();

        // procura música na playlist
        Musica* buscaMusicaPlaylist(std::string *titulo);

        // Adiciona música à playlist
        void addMusicaPlaylist(Musica *m_musica);

        // Remove música da playlist
        void removeMusicaPlaylist(std::string *titulo);

        // Getter
        std::string getNome();
        NoPlaylist *getHead();

        // setter
        void setHead(NoPlaylist *m_head);
};

#endif
