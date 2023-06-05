#include "../include/Playlist.h"

// Construtor da classe, define o nome da playlist e cria uma lista de músicas vazia
Playlist::Playlist(std::string nomeDaPlaylist) : nomeDaPlaylist(nomeDaPlaylist), listaDeMusicas(new Lista<Musica>()) {}

// Destrutor da classe, deleta a lista de músicas
Playlist::~Playlist() 
{
    delete listaDeMusicas;
}

// Retorna o nome da playlist
std::string Playlist::getNomeDaPlaylist() 
{
    return nomeDaPlaylist;
}

// Retorna a lista de músicas
Lista<Musica> *Playlist::getListaDeMusicas() 
{
    return listaDeMusicas;
}

// Define a lista de músicas
void Playlist::setListaDeMusicas(Lista<Musica> *listaDeMusicas) 
{
    this -> listaDeMusicas = listaDeMusicas;
}

// Define o nome da playlist
void Playlist::setNomeDaPlaylist(std::string nomeDaPlaylist) 
{
    this -> nomeDaPlaylist = nomeDaPlaylist;
}

// Insere uma música na playlist
void Playlist::inserirMusica(Musica *musica) 
{
    listaDeMusicas -> inserirNaLista(musica);
}

// Remove uma música da playlist usando método removeDaLista da classe Lista
void Playlist::removerMusica(Musica *musica) 
{
    listaDeMusicas -> removerDaLista(musica);
}

// Operador de comparacao
bool Playlist::operator==(const Playlist& outraPlaylist) const 
{
    return this -> nomeDaPlaylist == outraPlaylist.nomeDaPlaylist;
}

// Verifica se musica esta na playlist
bool Playlist::estaNaPlaylist(Musica *musica) 
{
    return listaDeMusicas -> estaNaLista(musica);
}

// Verifica se playlist esta vazia
bool Playlist::estaVazia() 
{
    return listaDeMusicas -> estaVazia();
}
