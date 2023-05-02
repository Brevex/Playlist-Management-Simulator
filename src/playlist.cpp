#include "../include/playlist.h"

// Construtor da classe, recebe o nome da playlist e inicia ela como uma lista vazia
Playlist::Playlist(std::string m_nomePlaylist) : nomePlaylist(m_nomePlaylist), head(nullptr), tamanhoPlaylist(0) {}

// Destrutor da classe, deleta todos os nós da lista
Playlist::~Playlist()
{
    NoPlaylist *aux = head;

    // Percorre a lista deletando os nós
    while (aux != nullptr)
    {
        NoPlaylist *temp = aux -> getNext();
        delete aux;
        aux = temp;
    }
}

// Adiciona uma música à playlist
void Playlist::addMusicaPlaylist(Musica *m_musica)
{
    // Cria um novo nó
    NoPlaylist *novoNo = new NoPlaylist(m_musica);

    // Caso a lista esteja vazia
    if(head == nullptr)
    {
        head = novoNo;
    }
    else
    {
        NoPlaylist *aux = head;

        // Percorre a lista até o último nó
        while (aux -> getNext() != nullptr)
        {
            aux = aux -> getNext();
        }

        // Adiciona o novo nó ao final da lista
        aux -> setNext(novoNo);
    }

    tamanhoPlaylist++;
}

// Remove uma música da playlist
void Playlist::removeMusicaPlaylist(std::string *titulo)
{
    // Caso a lista esteja vazia
    if(head == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Playlist vazia!" << std::endl;

        return;
    }

    NoPlaylist *aux = head;

    // Caso a música seja a primeira da playlist
    if(*(head -> getMusica() -> getTitulo()) == *titulo)
    {
        // Define o segundo nó como o primeiro
        head = head -> getNext();
        
        // Deleta o primeiro nó antigo
        delete aux;
        tamanhoPlaylist--;

        return;
    }

    // Caso a música seja encontrada em outra posição da playlist
    while(aux -> getNext() != nullptr)
    {
        // Verifica se o título da música é igual ao título procurado
        if (*(aux -> getNext() -> getMusica() -> getTitulo()) == *titulo)
        {
            NoPlaylist *temp = aux -> getNext();
            aux -> setNext(temp -> getNext());
            delete temp;
            tamanhoPlaylist--;

            return;
        }

        aux = aux -> getNext();
    }

    // Caso a música não seja encontrada
    std::cout << "Musica nao encontrada!" << std::endl;
}

// Procura uma música na playlist
Musica* Playlist::buscaMusicaPlaylist(std::string *titulo)
{
    // Se a playlist estiver vazia, não é possível buscar uma música
    if(!head)
    {
        std::cout << "Playlist vazia!" << std::endl;
        return nullptr;
    }

    // Percorre a playlist
    for(NoPlaylist *atual = head; atual != nullptr; atual = atual -> getNext())
    {
        // Verifica se o título da música atual é igual ao título procurado
        if(*(atual -> getMusica() -> getTitulo()) == *titulo)
        {
            // Retorna o endereço da música encontrada
            return atual -> getMusica();
        }
    }
    
    // Se a música não foi encontrada, retorna nullptr
    return nullptr;
}

// Retorna o nome da playlist
std::string Playlist::getNome()
{
    return nomePlaylist;
}

// Retorna o primeiro nó da playlist
NoPlaylist* Playlist::getHead()
{
    return head;
}

// Define o primeiro nó da playlist
void Playlist::setHead(NoPlaylist *m_head)
{
    head = m_head;
}
