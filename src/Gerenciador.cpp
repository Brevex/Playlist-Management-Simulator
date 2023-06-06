#include <limits>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <fstream>

#include "../include/Playlist.h"

// Bibliotecas referentes ao sistema operacional
#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

// Protótipo das funções - Músicas
void adicionarMusica(Lista<Musica> *listaDeMusicas);
void removerMusica(Lista<Musica> *listaDeMusicas);
void listarMusicas(Lista<Musica> *listaDeMusicas);

// Protótipo das funções - Playlists
void adicionarPlaylist(Lista<Playlist> *listaDePlaylists);
void removerPlaylist(Lista<Playlist> *listaDePlaylists);
void listarPlaylists(Lista<Playlist> *listaDePlaylists);

// Protótipo das funções - Gerenciar músicas nas playlists
void adicionarMusicaAPlaylist(Lista<Playlist> *listaDePlaylists, Lista<Musica> *listaDeMusicas);
void removerMusicaDePlaylist(Lista<Playlist> *listaDePlaylists, Lista<Musica> *listaDeMusicas);
void listarMusicasDePlaylist(Lista<Playlist> *listaDePlaylists);

// Protótipos das funções - Métodos do projeto parte 2
void adicionarMusicasDePlaylist(Lista<Playlist> *listaDePlaylists);
void removerListaEmPlaylist(Lista<Playlist> *listaDePlaylists);
void unirDuasPlaylists(Lista<Playlist> *listaDePlaylists);
void lerArquivoDeMusicas(Lista<Playlist> *listaDePlaylists);

// Protótipo das funções - Auxiliares
bool verificaEntrada(const std::string& str);
void menuPrincipal(Lista<Musica> *listaDeMusicas, Lista<Playlist> *listaDePlaylists);
void limparTela();
void imprimirCabecalho();
void imprimirCabecalhoFuncao(const std::string& nomeFuncao);
int getLarguraTerminal();

// Função principal
int main(int argc, char* args[])
{
    // Lista ligada de músicas e playlists
    Lista<Musica> *listaDeMusicas = new Lista<Musica>();
    Lista<Playlist> *listaDePlaylists = new Lista<Playlist>();

    // Menu principal (navegação - todas as funções do programa)
    menuPrincipal(listaDeMusicas, listaDePlaylists);

    return 0;
}

// Função que adiciona uma música a lista ligada do sistema
void adicionarMusica(Lista<Musica> *listaDeMusicas)
{
    std::string titulo, artista;

    std::cout << " Insira o título da musica: ";
    std::getline(std::cin, titulo);

    std::cout << " Insira o artista da musica: ";
    std::getline(std::cin, artista);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(titulo) || !verificaEntrada(artista))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados da musica nao podem estar em branco!" << std::endl;
        return;
    }

    Musica *musica = new Musica(titulo, artista);

    listaDeMusicas -> inserirNaLista(musica);

    std::cout << std::endl;
    std::cout << " Musica '" << titulo << "' adicionada com sucesso!" << std::endl;
}

// Função que remove uma música da lista ligada do sistema
void removerMusica(Lista<Musica> *listaDeMusicas, Lista<Playlist> *listaDePlaylists)
{
    // Verifica se a lista está vazia
    if (listaDeMusicas -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Nao ha musicas cadastradas!" << std::endl;

        return;
    }

    // Imprimelista de musicas disponiveis
    std::cout << " Musicas disponiveis: " << std::endl;
    std::cout << std::endl;

    listarMusicas(listaDeMusicas);

    std::string titulo, artista;

    std::cout << " Insira os dados abaixo para remover a musica " << "\u2192 " << std::endl;
    std::cout << std::endl;

    std::cout << " Insira o título da musica: ";
    std::getline(std::cin, titulo);

    std::cout << " Insira o artista da musica: ";
    std::getline(std::cin, artista);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(titulo) || !verificaEntrada(artista))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados da musica nao podem estar em branco!" << std::endl;

        return;
    }

    // Percorre a lista de músicas
    for (int i = 0; i < listaDeMusicas -> getSize(); i++)
    {
        Musica *musica = listaDeMusicas -> getItem(i);

        // Verifica se a música foi encontrada
        if (musica -> getTitulo() == titulo && musica -> getArtista() == artista)
        {
            listaDeMusicas -> removerDaLista(musica);
            
            // Se estiver cadastrada em alguma playlist, remove a música da playlist
            for (int j = 0; j < listaDePlaylists -> getSize(); j++)
            {
                Playlist *playlist = listaDePlaylists -> getItem(j);

                for (int k = 0; k < playlist -> getListaDeMusicas() -> getSize(); k++)
                {
                    Musica *musicaPlaylist = playlist -> getListaDeMusicas() -> getItem(k);

                    if (musicaPlaylist -> getTitulo() == titulo && musicaPlaylist -> getArtista() == artista)
                    {
                        playlist -> getListaDeMusicas() -> removerDaLista(musicaPlaylist);
                    }
                }
            }

            std::cout << std::endl;
            std::cout << " Musica '" << titulo << "' removida com sucesso!" << std::endl;

            return;
        }
    }

    std::cout << std::endl;
    std::cout << " Erro: Musica nao encontrada!" << std::endl;
}

// Função que lista todas as músicas da lista ligada do sistema
void listarMusicas(Lista<Musica> *listaDeMusicas)
{
    // Verifica se a lista está vazia
    if (listaDeMusicas -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Nao ha musicas cadastradas!" << std::endl;

        return;
    }

    // Percorre a lista de músicas
    for (int i = 0; i < listaDeMusicas -> getSize(); i++)
    {
        Musica *musica = listaDeMusicas -> getItem(i);

        std::cout << " Titulo: " << musica -> getTitulo() << std::endl;
        std::cout << " Artista: " << musica -> getArtista() << std::endl;
        std::cout << std::endl;
    }
}

// Função que adiciona uma playlist a lista ligada do sistema
void adicionarPlaylist(Lista<Playlist> *listaDePlaylists)
{
    std::string nomeDaPlaylist;

    std::cout << " Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados da playlist nao podem estar em branco!" << std::endl;

        return;
    }

    Playlist *playlist = new Playlist(nomeDaPlaylist);

    listaDePlaylists -> inserirNaLista(playlist);

    std::cout << std::endl;
    std::cout << " Playlist '" << nomeDaPlaylist << "' criada com sucesso!" << std::endl;
}

// Função que remove uma playlist da lista ligada do sistema
void removerPlaylist(Lista<Playlist> *listaDePlaylists)
{
    // Verifica se a lista está vazia
    if (listaDePlaylists -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Nao ha playlists cadastradas!" << std::endl;

        return;
    }

    // Imprime lista de playlists disponiveis
    std::cout << " Playlists disponiveis: " << std::endl;
    std::cout << std::endl;

    listarPlaylists(listaDePlaylists);

    std::string nomeDaPlaylist;

    std::cout << " Insira os dados abaixo para remover a Playlist " << "\u2192 " << std::endl;
    std::cout << std::endl;

    std::cout << " Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados da playlist nao podem estar em branco!" << std::endl;

        return;
    }

    // Percorre a lista de playlists
    for (int i = 0; i < listaDePlaylists -> getSize(); i++)
    {
        Playlist *playlist = listaDePlaylists -> getItem(i);

        // Verifica se a playlist foi encontrada
        if (playlist -> getNomeDaPlaylist() == nomeDaPlaylist)
        {
            listaDePlaylists -> removerDaLista(playlist);

            std::cout << std::endl;
            std::cout << " Playlist '" << nomeDaPlaylist << "' removida com sucesso!" << std::endl;

            return;
        }
    }

    std::cout << std::endl;
    std::cout << " Erro: Playlist nao encontrada!" << std::endl;
}

// Função de listar todas as playlists do sistema
void listarPlaylists(Lista<Playlist> *listaDePlaylists)
{
    // Verifica se a lista está vazia
    if (listaDePlaylists -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Nao ha playlists cadastradas!" << std::endl;

        return;
    }

    // Percorre a lista de playlists
    for (int i = 0; i < listaDePlaylists -> getSize(); i++)
    {
        Playlist *playlist = listaDePlaylists -> getItem(i);
        
        std::cout << " " << i + 1 << ": " << playlist -> getNomeDaPlaylist() << std::endl;
        std::cout << std::endl;
    }
}

// Função que adiciona uma música a uma playlist
void adicionarMusicaAPlaylist(Lista<Playlist>* listaDePlaylists, Lista<Musica>* listaDeMusicas)
{
    if (listaDePlaylists->estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Nao ha playlists cadastradas!" << std::endl;
        return;
    }

    if (listaDeMusicas->estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Nao ha musicas cadastradas!" << std::endl;
        return;
    }

    std::cout << " Playlists disponiveis: " << std::endl;
    std::cout << std::endl;

    listarPlaylists(listaDePlaylists);

    std::string nomeDaPlaylist, titulo;

    std::cout << " Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    if (!verificaEntrada(nomeDaPlaylist))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados da playlist nao podem estar em branco!" << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << " Musicas disponiveis: " << std::endl;
    std::cout << std::endl;

    listarMusicas(listaDeMusicas);

    std::cout << " Insira o titulo da musica: ";
    std::getline(std::cin, titulo);

    if (!verificaEntrada(titulo))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados da musica nao podem estar em branco!" << std::endl;
        return;
    }

    bool playlistEncontrada = false;
    bool musicaEncontrada = false;

    for (int i = 0; i < listaDePlaylists->getSize(); i++)
    {
        Playlist* playlist = listaDePlaylists->getItem(i);

        if (playlist->getNomeDaPlaylist() == nomeDaPlaylist)
        {
            playlistEncontrada = true;

            for (int j = 0; j < listaDeMusicas->getSize(); j++)
            {
                Musica* musica = listaDeMusicas->getItem(j);

                if (musica->getTitulo() == titulo)
                {
                    musicaEncontrada = true;
                    playlist->inserirMusica(musica);

                    std::cout << std::endl;
                    std::cout << " Musica '" << titulo << "' adicionada a playlist '" << nomeDaPlaylist << "' com sucesso!" << std::endl;

                    break;  // Interrompe o loop interno, pois a música já foi encontrada e adicionada à playlist
                }
            }

            break;  // Interrompe o loop externo, pois a playlist foi encontrada
        }
    }

    if (!playlistEncontrada)
    {
        std::cout << std::endl;
        std::cout << " Erro: Playlist nao encontrada!" << std::endl;
    }
    else if (!musicaEncontrada)
    {
        std::cout << std::endl;
        std::cout << " Erro: Musica nao encontrada!" << std::endl;
    }
}
               
// Função que remove uma música de uma playlist
void removerMusicaDePlaylist(Lista<Playlist> *listaDePlaylists, Lista<Musica> *listaDeMusicas)
{
    // Verifica se a lista de playlists ou de músicas está vazia
    if (listaDePlaylists -> estaVazia() || listaDeMusicas -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Nao ha playlists e/ou Musicas cadastradas!" << std::endl;

        return;
    }

    // Imprime lista de playlists disponiveis
    std::cout << " Playlists disponiveis: " << std::endl;
    std::cout << std::endl;

    listarPlaylists(listaDePlaylists);

    std::string nomeDaPlaylist, titulo;

    std::cout << " Insira os dados abaixo para remover uma músicade sua Playlist " << "\u2192 " << std::endl;
    std::cout << std::endl;

    std::cout << " Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    std::cout << " Insira o titulo da musica: ";
    std::getline(std::cin, titulo);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist) || !verificaEntrada(titulo))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados da playlist e/ou da musica nao podem estar em branco!" << std::endl;

        return;
    }

    // Percorre a lista de playlists
    for (int i = 0; i < listaDePlaylists -> getSize(); i++)
    {
        Playlist *playlist = listaDePlaylists -> getItem(i);

        // Verifica se a playlist foi encontrada
        if (playlist -> getNomeDaPlaylist() == nomeDaPlaylist)
        {
            // Percorre a lista de músicas
            for (int j = 0; j < listaDeMusicas -> getSize(); j++)
            {
                Musica *musica = listaDeMusicas -> getItem(j);

                // Verifica se a música foi encontrada
                if (musica -> getTitulo() == titulo)
                {
                    // Verifica se a música está na playlist
                    if (!playlist -> estaNaPlaylist(musica))
                    {
                        std::cout << std::endl;
                        std::cout << " Erro: Musica nao cadastrada na playlist!" << std::endl;

                        return;
                    }

                    playlist -> removerMusica(musica);

                    std::cout << std::endl;
                    std::cout << " Musica '" << titulo << "' removida da playlist '" << nomeDaPlaylist << "' com sucesso!" << std::endl;

                    return;
                }
            }

            std::cout << std::endl;
            std::cout << " Erro: Musica nao encontrada!" << std::endl;

            return;
        }
        else
        {
            std::cout << std::endl;
            std::cout << " Erro: Playlist nao encontrada!" << std::endl;

            return;
        }
    }
}

// Função que lista as músicas de uma playlist
void listarMusicasDePlaylist(Lista<Playlist>* listaDePlaylists)
{
    if (listaDePlaylists->estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Nao ha playlists cadastradas!" << std::endl;
        return;
    }

    std::cout << " Playlists disponiveis: " << std::endl;
    std::cout << std::endl;

    listarPlaylists(listaDePlaylists);

    std::string nomeDaPlaylist;

    std::cout << " Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    if (!verificaEntrada(nomeDaPlaylist))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados da playlist nao podem estar em branco!" << std::endl;
        return;
    }

    std::cout << std::endl;

    bool playlistEncontrada = false;

    for (int i = 0; i < listaDePlaylists->getSize(); i++)
    {
        Playlist* playlist = listaDePlaylists->getItem(i);

        if (playlist->getNomeDaPlaylist() == nomeDaPlaylist)
        {
            playlistEncontrada = true;

            if (playlist->estaVazia())
            {
                std::cout << " Erro: Playlist vazia!" << std::endl;
                return;
            }

            for (int j = 0; j < playlist->getListaDeMusicas()->getSize(); j++)
            {
                Musica* musica = playlist->getListaDeMusicas()->getItem(j);

                std::cout << " Titulo: " << musica->getTitulo() << std::endl;
                std::cout << " Artista: " << musica->getArtista() << std::endl;
                std::cout << std::endl;
            }

            return;
        }
    }

    if (!playlistEncontrada)
    {
        std::cout << std::endl;
        std::cout << " Erro: Playlist nao encontrada!" << std::endl;
    }
}

// Função que adiciona as músicas de uma playlist existente a outra playlist
void adicionarMusicasDePlaylist(Lista<Playlist> *listaDePlaylists)
{
    // Verifica se a lista de playlists está vazia
    if (listaDePlaylists->estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Não há playlists cadastradas!" << std::endl;
        return;
    }

    // Imprime lista de playlists disponíveis
    std::cout << " Playlists disponíveis: " << std::endl;
    std::cout << std::endl;

    listarPlaylists(listaDePlaylists);

    std::string nomeDaPlaylist1, nomeDaPlaylist2;

    std::cout << " Insira os dados abaixo para adicionar as músicas de uma playlist a outra " << "\u2192 " << std::endl;
    std::cout << std::endl;

    std::cout << " Insira o nome da playlist de origem: ";
    std::getline(std::cin, nomeDaPlaylist1);

    std::cout << " Insira o nome da playlist de destino: ";
    std::getline(std::cin, nomeDaPlaylist2);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist1) || !verificaEntrada(nomeDaPlaylist2))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados das playlists não podem estar em branco!" << std::endl;
        return;
    }

    std::cout << std::endl;

    Playlist *playlistOrigem = nullptr;
    Playlist *playlistDestino = nullptr;

    // Percorre a lista de playlists para encontrar a playlist de origem e a playlist de destino
    for (int i = 0; i < listaDePlaylists->getSize(); i++)
    {
        Playlist *playlist = listaDePlaylists->getItem(i);

        if (playlist->getNomeDaPlaylist() == nomeDaPlaylist1)
        {
            playlistOrigem = playlist;
        }

        if (playlist->getNomeDaPlaylist() == nomeDaPlaylist2)
        {
            playlistDestino = playlist;
        }
    }

    // Verifica se a playlist de origem foi encontrada
    if (playlistOrigem == nullptr)
    {
        std::cout << std::endl;
        std::cout << " Erro: Playlist de origem não encontrada!" << std::endl;
        return;
    }

    // Verifica se a playlist de destino foi encontrada
    if (playlistDestino == nullptr)
    {
        std::cout << std::endl;
        std::cout << " Erro: Playlist de destino não encontrada!" << std::endl;
        return;
    }

    // Verifica se a playlist de origem está vazia
    if (playlistOrigem->estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Playlist de origem vazia!" << std::endl;
        return;
    }

    // Verifica se a playlist de destino está vazia
    if (playlistDestino->estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Playlist de destino vazia!" << std::endl;
        return;
    }

    playlistDestino->addListaMusicas(*playlistOrigem -> getListaDeMusicas());

    std::cout << std::endl;
    std::cout << " Músicas da playlist '" << nomeDaPlaylist1 << "' adicionadas à playlist '" << nomeDaPlaylist2 << "' com sucesso!" << std::endl;
}

// Função que remove musicas de uma playlist de outra playlist
void removerListaEmPlaylist(Lista<Playlist> *listaDePlaylists)
{
    // Verifica se a lista de playlists está vazia
    if (listaDePlaylists->estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Erro: Não há playlists cadastradas!" << std::endl;
        return;
    }

    // Imprime lista de playlists disponíveis
    std::cout << " Playlists disponíveis:" << std::endl;
    std::cout << std::endl;

    listarPlaylists(listaDePlaylists);

    std::string nomePlaylist1, nomePlaylist2;

    std::cout << " Insira o nome da playlist a ser modificada: ";
    std::getline(std::cin, nomePlaylist1);

    std::cout << " Insira o nome da playlist com as músicas a serem comparadas: ";
    std::getline(std::cin, nomePlaylist2);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomePlaylist1) || !verificaEntrada(nomePlaylist2))
    {
        std::cout << std::endl;
        std::cout << " Erro: Dados das playlists não podem estar em branco!" << std::endl;
        return;
    }

    std::cout << std::endl;

    Playlist *playlist1 = nullptr;
    Playlist *playlist2 = nullptr;

    // Percorre a lista de playlists
    for (int i = 0; i < listaDePlaylists->getSize(); i++)
    {
        Playlist *playlist = listaDePlaylists->getItem(i);

        // Verifica se a primeira playlist foi encontrada
        if (playlist -> getNomeDaPlaylist() == nomePlaylist1)
        {
            playlist1 = playlist;
            break;
        }
    }

    // Verifica se a primeira playlist foi encontrada
    if (playlist1 == nullptr)
    {
        std::cout << std::endl;
        std::cout << " Erro: Primeira playlist não encontrada!" << std::endl;
        return;
    }

    // Percorre a lista de playlists novamente
    for (int i = 0; i < listaDePlaylists->getSize(); i++)
    {
        Playlist *playlist = listaDePlaylists->getItem(i);

        // Verifica se a segunda playlist foi encontrada
        if (playlist -> getNomeDaPlaylist() == nomePlaylist2)
        {
            playlist2 = playlist;
            break;
        }
    }

    // Verifica se a segunda playlist foi encontrada
    if (playlist2 == nullptr)
    {
        std::cout << std::endl;
        std::cout << " Erro: Segunda playlist não encontrada!" << std::endl;
        return;
    }

    Lista<Musica> listaMusicasRemover;

    // Percorre a lista de músicas da segunda playlist
    for (int i = 0; i < playlist2 -> getListaDeMusicas() -> getSize(); i++)
    {
        Musica *musica = playlist2 -> getListaDeMusicas() -> getItem(i);

        // Verifica se a música está presente na primeira playlist
        if (playlist1 -> estaNaPlaylist(musica))
        {
            listaMusicasRemover.inserirNaLista(musica);
        }
    }

    if (listaMusicasRemover.estaVazia())
    {
        std::cout << std::endl;
        std::cout << " Não foram encontradas músicas duplicadas entre as playlists." << std::endl;
        return;
    }

    playlist1 -> removerListaMusicas(listaMusicasRemover);

    std::cout << std::endl;
    std::cout << " Foram removidas todas as músicas duplicadas da playlist '" << nomePlaylist1 << "'." << std::endl;
}

// Faz a união de duas playlists 
void unirDuasPlaylists(Lista<Playlist> *listaDePlaylists)
{
    // Verifica se existem pelo menos duas playlists na lista
    if (listaDePlaylists->getSize() < 2)
    {
        std::cout << " Erro: Não há playlists suficientes para unir!" << std::endl;
        return;
    }

    // Imprime lista de playlists disponíveis
    std::cout << " Playlists disponíveis:" << std::endl;
    std::cout << std::endl;

    listarPlaylists(listaDePlaylists);

    std::string nomePlaylist1, nomePlaylist2;

    // Pede ao usuário para inserir o nome da primeira playlist
    std::cout << " Insira o nome da primeira playlist: ";
    std::getline(std::cin, nomePlaylist1);

    // Pede ao usuário para inserir o nome da segunda playlist
    std::cout << " Insira o nome da segunda playlist: ";
    std::getline(std::cin, nomePlaylist2);

    // Busca as playlists na lista de playlists do sistema
    Playlist* playlist1 = nullptr;
    Playlist* playlist2 = nullptr;

    // Percorre a lista de playlists
    for (int i = 0; i < listaDePlaylists -> getSize(); i++)
    {
        Playlist* playlist = listaDePlaylists -> getItem(i);

        if (playlist -> getNomeDaPlaylist() == nomePlaylist1)
        {
            playlist1 = playlist;
        }
        else if (playlist -> getNomeDaPlaylist() == nomePlaylist2)
        {
            playlist2 = playlist;
        }

        // Se ambas as playlists forem encontradas, encerra o loop
        if (playlist1 && playlist2)
        {
            break;
        }
    }

    // Verifica se as duas playlists foram encontradas
    if (!playlist1 || !playlist2)
    {
        std::cout << " Erro: Playlist(s) não encontrada(s)!" << std::endl;
        return;
    }

    // Cria a nova playlist unida
    Playlist* playlistUnida = new Playlist();

    // Adiciona as músicas da playlist1 na playlist unida
    playlistUnida -> addListaMusicas(*playlist1 -> getListaDeMusicas());

    // Adiciona as músicas da playlist2 na playlist unida
    playlistUnida -> addListaMusicas(*playlist2 -> getListaDeMusicas());

    // Remove as músicas repetidas da playlist unida
    playlistUnida -> removerMusicasRepetidas();

    // Pede ao usuário para inserir o nome da nova playlist unida
    std::string nomeNovaPlaylist;
    std::cout << " Insira o nome da nova playlist unida: ";
    std::getline(std::cin, nomeNovaPlaylist);

    // Define o nome da nova playlist unida
    playlistUnida -> setNomeDaPlaylist(nomeNovaPlaylist);

    // Adiciona a nova playlist unida à lista de playlists do sistema
    listaDePlaylists -> inserirNaLista(playlistUnida);

    // Imprime o nome da nova playlist unida
    std::cout << " Nova playlist unida: " << playlistUnida -> getNomeDaPlaylist() << std::endl;
    std::cout << std::endl;
}

// Usa biblioteca <fstream> para ler o arquivo de músicas
void lerArquivoDeMusicas(Lista<Playlist>* listaDePlaylists)
{
    std::ifstream arquivo;
    std::string linha;

    // Abre o arquivo de músicas
    arquivo.open("musicas.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo.is_open())
    {
        // Percorre o arquivo de músicas
        while (std::getline(arquivo, linha))
        {
            // Verifica se a linha não está vazia
            if (!linha.empty())
            {
                // Faz leitura da string até o ";" e armazena nome da playlist
                std::string nomePlaylist = linha.substr(0, linha.find(";"));

                // Cria uma playlist com o nome lido
                Playlist* playlist = new Playlist(nomePlaylist);

                // Armazena a posição do ";" na linha
                size_t pos = linha.find(";");

                // Percorre a linha a partir da posição do ";"
                while (pos != std::string::npos)
                {
                    // Faz leitura da string a partir do ":" e antes da ","
                    std::string nomeMusica = linha.substr(pos + 1, linha.find(":", pos) - pos - 1);

                    // Faz leitura da string a partir do ":" e depois da ","
                    std::string nomeArtista = linha.substr(linha.find(":", pos) + 1, linha.find(",", pos) - linha.find(":", pos) - 1);

                    // Cria música com o titulo e artista lidos
                    Musica* musica = new Musica(nomeMusica, nomeArtista);

                    // Adiciona a música à playlist
                    playlist -> inserirMusica(musica);

                    // Atualiza a posição da "," para continuar a busca
                    pos = linha.find(",", pos + 1);
                }

                // Adiciona a playlist à lista de playlists
                listaDePlaylists -> inserirNaLista(playlist);
            }
        }
    }
    else
    {
        std::cout << " Erro: Nao foi possivel abrir o arquivo de musicas!" << std::endl;
        return;
    }

    // Fecha o arquivo de músicas
    arquivo.close();

    // Imprime mensagem de sucesso
    std::cout << " Arquivo de musicas lido com sucesso!" << std::endl;
    std::cout << std::endl;
}

// Função que verifica se a entrada do usuário é válida
bool verificaEntrada(const std::string& str)
{
    // Verifica se a string está vazia ou se é composta apenas por espaços
    if(str.empty() || std::all_of(str.begin(), str.end(), isspace))
    {
        return false;
    }

    return true;
}

// Função que limpa a tela (varia de acordo com sistema operacional)
void limparTela() 
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

// Função que retorna a largura do terminal (varia de acordo com sistema operacional)
int getLarguraTerminal()
{
    // Verifica se o sistema operacional é Windows ou Linux
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
        struct winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
        return size.ws_col;
    #endif
}

// Função que imprime o cabeçalho principal
void imprimirCabecalho()
{
    // Define header, subheader e largura do terminal 
    std::string header = "GERENCIADOR DE PLAYLISTS";
    std::string subheader = "Projeto LP I - Breno Barbosa de Oliveira";
    int terminal_width = getLarguraTerminal();

    std::ostringstream line;
    line << std::setfill('-') << std::setw(terminal_width) << "";
    std::cout << line.str() << std::endl;

    std::cout << std::setfill(' ') << std::setw((terminal_width + header.length()) / 2) << header << std::endl;

    std::cout << line.str() << std::endl;

    std::cout << std::setfill(' ') << std::setw((terminal_width + subheader.length()) / 2) << subheader << std::endl;

    std::cout << line.str() << std::endl;

    std::cout << std::endl;
}

// Função que imprime o cabeçalho de uma função
void imprimirCabecalhoFuncao(const std::string& nomeFuncao)
{
    // Define largura do terminal do sistema
    int larguraTerminal = getLarguraTerminal();
    int larguraCabecalho = static_cast<int>(nomeFuncao.size()) + 4;

    // Define espaços a esquerda e a direita do cabeçalho (cmath)
    int espacosEsquerda = std::floor((larguraTerminal - larguraCabecalho) / 2.0);
    int espacosDireita = larguraTerminal - larguraCabecalho - espacosEsquerda;

    // Imprime cabeçalho
    std::cout << std::string(larguraTerminal, '=') << std::endl;
    std::cout << std::string(espacosEsquerda, ' ') << nomeFuncao << std::string(espacosDireita, ' ') << std::endl;
    std::cout << std::string(larguraTerminal, '=') << std::endl;
    std::cout << std::endl;
}

// Função que imprime o menu principal
void menuPrincipal(Lista<Musica> *listaDeMusicas, Lista<Playlist> *listaDePlaylists)
{
    int opcao = 0;

    // Loop do menu principal - funciona até que o usuário digite 10
    while(opcao != 14)
    {
        limparTela();
        imprimirCabecalho();

        std::cout << " 1 - Cadastrar Musica" << std::endl;
        std::cout << " 2 - Cadastrar Playlist" << std::endl;
        std::cout << " 3 - Remover Musica" << std::endl;
        std::cout << " 4 - Remover Playlist" << std::endl;
        std::cout << " 5 - Listar Musicas" << std::endl;
        std::cout << " 6 - Listar Playlists" << std::endl;
        std::cout << " 7 - Adicionar Musica a Playlist" << std::endl;
        std::cout << " 8 - Remover Musica de Playlist" << std::endl;
        std::cout << " 9 - Listar Musicas de Playlist" << std::endl;
        std::cout << "10 - Concatenar Playlists" << std::endl;
        std::cout << "11 - Unir Playlists" << std::endl;
        std::cout << "12 - Remover Duplicatas em Playlists" << std::endl;
        std::cout << "13 - Adicionar arquivo de Playlist" << std::endl;
        std::cout << "14 - Sair" << std::endl;

        std::cout << std::endl;

        std::cout << " Insira a opcao desejada: ";
        std::cin >> opcao;

        // Limpa o buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Caso usuário digite um valor não inteiro
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << std::endl;
            std::cout << " Opcao invalida!" << std::endl;

            continue;
        }

        // Verifica se a opção é válida
        if (opcao < 0 || opcao > 14)
        {
            std::cout << std::endl;
            std::cout << " Opcao invalida!" << std::endl;

            continue;
        }

        limparTela();

        // Executa a função de acordo com a opção escolhida
        switch (opcao)
        {
            case 1:
                imprimirCabecalhoFuncao("ADICIONAR MUSICA AO SISTEMA");
                adicionarMusica(listaDeMusicas);
                break;
            case 2:
                imprimirCabecalhoFuncao("ADICIONAR PLAYLIST AO SISTEMA");
                adicionarPlaylist(listaDePlaylists);
                break;
            case 3:
                imprimirCabecalhoFuncao("REMOVER MUSICA DO SISTEMA");
                removerMusica(listaDeMusicas, listaDePlaylists);
                break;
            case 4:
                imprimirCabecalhoFuncao("REMOVER PLAYLIST DO SISTEMA");
                removerPlaylist(listaDePlaylists);
                break;
            case 5:
                imprimirCabecalhoFuncao("LISTA DE MUSICAS DO SISTEMA");
                listarMusicas(listaDeMusicas);
                break;
            case 6:
                imprimirCabecalhoFuncao("LISTA DE PLAYLISTS DO SISTEMA");
                listarPlaylists(listaDePlaylists);
                break;
            case 7:
                imprimirCabecalhoFuncao("ADICIONAR MUSICA A PLAYLIST");
                adicionarMusicaAPlaylist(listaDePlaylists, listaDeMusicas);
                break;
            case 8:
                imprimirCabecalhoFuncao("REMOVER MUSICA DE PLAYLIST");
                removerMusicaDePlaylist(listaDePlaylists, listaDeMusicas);
                break;
            case 9:
                imprimirCabecalhoFuncao("LISTA DE MUSICAS DA PLAYLIST");
                listarMusicasDePlaylist(listaDePlaylists);
                break;
            case 10:
                imprimirCabecalhoFuncao("CONCATENAR PLAYLISTS");
                adicionarMusicasDePlaylist(listaDePlaylists);
                break;
            case 11:
                imprimirCabecalhoFuncao("UNIR DUAS PLAYLISTS");
                unirDuasPlaylists(listaDePlaylists);
                break;
            case 12:
                imprimirCabecalhoFuncao("REMOVER DUPLICATAS EM PLAYLISTS");
                removerListaEmPlaylist(listaDePlaylists);
                break;
            case 13:
                imprimirCabecalhoFuncao("ADICIONAR MUSICAS POR AQUIVO");
                lerArquivoDeMusicas(listaDePlaylists);
                break;
            case 14:
                std::cout << "Saindo..." << std::endl;
                return;
            default:
                std::cout << "Erro: Opcao invalida!" << std::endl;
                break;
        }

        // Pausa o programa até que o usuário pressione Enter
        std::cout << std::endl;
        std::cout << " Pressione Enter para retornar ao menu " << "\u21B5 ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limparTela();
    }
}
