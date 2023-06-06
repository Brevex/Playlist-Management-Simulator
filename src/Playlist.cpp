#include "../include/Playlist.h"

// Construtor padrão da classe, define o nome da playlist como "Sem nome" e cria uma lista de músicas vazia
Playlist::Playlist()
{
    nomeDaPlaylist = "";
    listaDeMusicas = new Lista<Musica>();
}

// Construtor da classe, define o nome da playlist e cria uma lista de músicas vazia
Playlist::Playlist(std::string nomeDaPlaylist) : nomeDaPlaylist(nomeDaPlaylist), listaDeMusicas(new Lista<Musica>()) {}

// Construtor cópia da classe, copia o nome da playlist e a lista de músicas (requisito da parte 2 do projeto)
Playlist::Playlist(const Playlist& outraPlaylist)
{
    nomeDaPlaylist = outraPlaylist.nomeDaPlaylist;
    listaDeMusicas = new Lista<Musica>(*outraPlaylist.listaDeMusicas);
}

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

// Adiciona uma lista de músicas na playlist (requisito da parte 2 do projeto)
void Playlist::addListaMusicas(Lista<Musica>& listaMusicas) 
{
    listaDeMusicas -> addElementos(listaMusicas);
}

// Remove uma música da playlist usando método removeDaLista da classe Lista
void Playlist::removerMusica(Musica *musica) 
{
    listaDeMusicas -> removerDaLista(musica);
}

// Remove todas as músicas da playlist atual que estejam na lista recebida por parâmetro (requisito da parte 2 do projeto)
void Playlist::removerListaMusicas(Lista<Musica>& listaMusicas)
{
    listaDeMusicas -> removerElementos(listaMusicas);
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

// Une duas playlists em uma nova playlist (requisito da parte 2 do projeto)
Playlist Playlist::unirPlaylists(Playlist& playlist1, Playlist& playlist2)
{
    // Cria uma nova playlist com o nome da playlist1
    Playlist playlistUnida(playlist1.nomeDaPlaylist);

    // Adiciona as músicas da playlist1 na playlist unida
    playlistUnida.addListaMusicas(*playlist1.listaDeMusicas);

    // Adiciona as músicas da playlist2 na playlist unida
    playlistUnida.addListaMusicas(*playlist2.listaDeMusicas);

    // Remove as músicas repetidas da playlist unida
    playlistUnida.listaDeMusicas -> removerRepetidos();

    // Retorna a playlist unida
    return playlistUnida;
}

// Remove músicas repetidas da playlist
void Playlist::removerMusicasRepetidas()
{
    listaDeMusicas -> removerRepetidos();
}
