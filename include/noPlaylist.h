#ifndef NOPLAYLIST_H
#define NOPLAYLIST_H

#include "Musica.h"

class NoPlaylist
{
    private:

        Musica *musica;
        NoPlaylist *next;

    public:

        // Construtor
        NoPlaylist(Musica *m_musica);

        // Destrutor
        ~NoPlaylist();

        // Getter e setter da música
        Musica* getMusica();
        void setMusica(Musica *m_musica);

        // Getter e setter do próximo nó da lista
        NoPlaylist* getNext();
        void setNext(NoPlaylist *m_next);
};

#endif
