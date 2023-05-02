#include "../include/listaMusica.h"

// Construtor da classe, inicializa o ponteiro "head" como "nullptr" e "tamanho" como 0
MusicasLista::MusicasLista() : head(nullptr), tamanho(0) {}

// Destrutor da classe, deleta músicas e nós da lista
MusicasLista::~MusicasLista()
{
    // Percorre lista de músicas em laço while
    while(head)
    {   
        // Define o nó atual como "head"
        NoLista *NoAtual = head;

        // Define próximo nó como "head"
        head = head -> getProxima();

        // Deleta nó
        delete NoAtual;
    }

    // Ao final do laço, define tamanho como 0
    tamanho = 0;
}

// Método responsável por adicionar novas músicas a lista
void MusicasLista::addMusica()
{
    std::cout << std::endl;
    std::cout << "- Adicionar musicas -" << std::endl;
    std::cout << std::endl;

    std::string titulo, cantor;

    // Solicita ao usuário que digite o nome da música
    std::cout << "Insira o nome da musica: ";
    std::getline(std::cin, titulo);

    // Solicita ao usuário que digite o nome do cantor
    std::cout << "Insira o nome do cantor: ";
    std::getline(std::cin, cantor);

    std::cout << std::endl;

    // Confere se usuário deixou algum campo em branco
    if(titulo.empty() || cantor.empty())
    {
        std::cout << "Existem dados faltando! Musica nao pode ser adicionada." << std::endl;
        return;
    }

    // Confere se a música já existe na lista
    if(buscaMusica(titulo))
    {
        std::cout << "A musica " << titulo << " ja existe no sistema!" << std::endl;
        return;
    }

    // Define o nó atual como sendo o "head"
    NoLista *NoAtual = head;

    // A string digitada pelo usuário é passada para o construtor atravéz de um novo ponteiro alocado no heap
    Musica *novaMusica = new Musica(new std::string(titulo), new std::string(cantor));

    // Confere se música foi adicionada
    if(!novaMusica)
    {
        std::cout << "Erro ao adicionar nova musica!" << std::endl;
        return;
    }

    // Cria um novo nó para a lista de músicas
    NoLista *novoNo = new NoLista(novaMusica, head);

    // Confere se novo nó foi criado e deleta música caso não tenha sido
    if(!novoNo)
    {
        std::cout << "Erro ao adicionar novo no!" << std::endl;

        // Deleta música
        delete novaMusica;
        return;
    }

    // Define o novo nó como sendo o "head" da lista
    head = novoNo;

    // Incrimenta o tamanho da lista de músicas em +1
    tamanho++;

    std::cout << "A musica " << titulo << " foi adicionada ao sistema!" << std::endl;
    std::cout << std::endl;
}

// Método responsável por remover músicas da lista
void MusicasLista::removeMusica(std::string titulo)
{
    // Confere se lista está vazia antes de tentar remover
    if(!head)
    {
        std::cout << "Nenhuma musica cadastrada" << std::endl;
        return;
    }
    else
    {
        // Define o nó atual como sendo o "head"
        NoLista *NoAtual = head;

        // Define o nó anterior como sendo "nullptr"
        NoLista *NoAnterior = nullptr;

        // Laço for que percorre toda lista de músicas
        for(NoAtual = head; NoAtual; NoAtual = NoAtual -> getProxima())
        {
            Musica *musicaAtual = NoAtual -> getMusica();

            // Confere se título da música atual é igual ao título passado como parâmetro
            if(*(musicaAtual -> getTitulo()) == titulo)
            {
                // Caso o nó atual seja o "head"
                if(NoAtual == head)
                {
                    // Define o "head" como sendo o próximo nó
                    head = NoAtual -> getProxima();
                }
                else
                {
                    // Define o próximo nó do nó anterior como sendo o próximo nó do nó atual
                    NoAnterior -> setProxima(NoAtual -> getProxima());
                }

                // Deleta nó atual
                delete NoAtual;

                // Decrementa o tamanho da lista de músicas em -1
                tamanho--;

                return;
            }

            // Define o nó anterior como sendo o nó atual
            NoAnterior = NoAtual;
        }
    }
}

// Busca música cadastrada na lista
Musica* MusicasLista::buscaMusica(std::string titulo)
{
    // Confere se lista está vazia antes de tentar buscar
    if(!head)
    {
        return nullptr;
    }
    else
    {
        // Laço for que percorre toda lista de músicas
        for(NoLista *NoAtual = head; NoAtual; NoAtual = NoAtual -> getProxima())
        {
            // Define o nó atual como sendo o "head"
            Musica *musicaAtual = NoAtual -> getMusica();

            // Confere se título da música atual é igual ao título passado como parâmetro
            if(*(musicaAtual -> getTitulo()) == titulo) // The bug was here
            {
                return NoAtual -> getMusica();
            }
        }

        // Caso não encontre música, retorna "nullptr"
        std::cout << "Musica nao encontrada" << std::endl;
        return nullptr;   
    }
}

// Imprime uma lista com todas as músicas cadastradas
void MusicasLista::coutLista()
{
    // Confere se lista está vazia antes de tentar imprimir
    if(!head)
    {
        std::cout << "Nenhuma musica cadastrada" << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "Musicas no sistema: " << std::endl;
    std::cout << std::endl;

    // Laço for que percorre toda lista de músicas
    for(NoLista *NoAtual = head; NoAtual; NoAtual = NoAtual -> getProxima())
    {
        Musica *musicaAtual = NoAtual -> getMusica();

        std::string *titulo = musicaAtual -> getTitulo();
        std::string *cantor = musicaAtual -> getCantor();

        std::cout << "Titulo: " << *titulo << std::endl;
        std::cout << "Cantor: " << *cantor << std::endl;

        std::cout << std::endl;
    }
}
