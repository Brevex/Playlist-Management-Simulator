#include "../include/noPlaylist.h"

// Construtor da classe, recebe a música e inicializa o próximo nó como "nullptr"
NoPlaylist::NoPlaylist(Musica *m_musica) : musica(m_musica), next(nullptr) {}

// Destrutor da classe, deleta o objeto "musica"
NoPlaylist::~NoPlaylist()
{
    // Verifica se o ponteiro é diferente de "nullptr"
    if (musica != nullptr)
    {
        delete musica;
    }
}

// Getter da música
Musica* NoPlaylist::getMusica()
{
    return musica;
}

// Setter da música
void NoPlaylist::setMusica(Musica *m_musica)
{
    musica = m_musica;
}

// Getter do próximo nó da lista
NoPlaylist* NoPlaylist::getNext()
{
    return next;
}

// Setter do próximo nó da lista
void NoPlaylist::setNext(NoPlaylist *m_next)
{
    next = m_next;
}
