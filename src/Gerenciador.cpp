#include <limits>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "../include/Playlist.h"

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

// Protótipo das funções - Utilidades
bool verificaEntrada(const std::string& str);
void menuPrincipal(Lista<Musica> *listaDeMusicas, Lista<Playlist> *listaDePlaylists);
void limparTela();
void imprimirCabecalho();
void imprimirCabecalhoFuncao(const std::string& nomeFuncao);
int getLarguraTerminal();

int main(int argc, char* args[])
{
    // Lista ligada de músicas e playlists
    Lista<Musica> *listaDeMusicas = new Lista<Musica>();
    Lista<Playlist> *listaDePlaylists = new Lista<Playlist>();

    // Menu principal
    menuPrincipal(listaDeMusicas, listaDePlaylists);

    return 0;
}

// Função que adiciona uma música a lista ligada do sistema
void adicionarMusica(Lista<Musica> *listaDeMusicas)
{
    imprimirCabecalhoFuncao("ADICIONAR MUSICA AO SISTEMA");

    std::string titulo, artista;

    std::cout << "Insira o título da musica: ";
    std::getline(std::cin, titulo);

    std::cout << "Insira o artista da musica: ";
    std::getline(std::cin, artista);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(titulo) || !verificaEntrada(artista))
    {
        std::cout << std::endl;
        std::cout << "Erro: Dados da musica nao podem estar em branco!" << std::endl;
        return;
    }

    // Verifica se a música já está cadastrada
    if (listaDeMusicas -> estaNaLista(new Musica(titulo, artista)))
    {
        std::cout << std::endl;
        std::cout << "Erro: Musica ja cadastrada!" << std::endl;
        return;
    }

    Musica *musica = new Musica(titulo, artista);

    listaDeMusicas -> inserirNaLista(musica);

    std::cout << std::endl;
    std::cout << "Musica '" << titulo << "' adicionada com sucesso!" << std::endl;
}

// Função que remove uma música da lista ligada do sistema
void removerMusica(Lista<Musica> *listaDeMusicas)
{
    imprimirCabecalhoFuncao("REMOVER MUSICA DO SISTEMA");

    // Verifica se a lista está vazia
    if (listaDeMusicas -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha musicas cadastradas!" << std::endl;

        return;
    }

    std::string titulo, artista;

    std::cout << "Insira o título da musica: ";
    std::getline(std::cin, titulo);

    std::cout << "Insira o artista da musica: ";
    std::getline(std::cin, artista);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(titulo) || !verificaEntrada(artista))
    {
        std::cout << std::endl;
        std::cout << "Erro: Dados da musica nao podem estar em branco!" << std::endl;

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

            std::cout << std::endl;
            std::cout << "Musica '" << titulo << "' removida com sucesso!" << std::endl;

            return;
        }
    }

    std::cout << std::endl;
    std::cout << "Erro: Musica nao encontrada!" << std::endl;
}

// Função que lista todas as músicas da lista ligada do sistema
void listarMusicas(Lista<Musica> *listaDeMusicas)
{
    imprimirCabecalhoFuncao("LISTA DE MUSICAS DO SISTEMA");

    // Verifica se a lista está vazia
    if (listaDeMusicas -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha musicas cadastradas!" << std::endl;

        return;
    }

    // Percorre a lista de músicas
    for (int i = 0; i < listaDeMusicas -> getSize(); i++)
    {
        Musica *musica = listaDeMusicas -> getItem(i);

        std::cout << "Titulo: " << musica -> getTitulo() << std::endl;
        std::cout << "Artista: " << musica -> getArtista() << std::endl;
        std::cout << std::endl;
    }
}

// Função que adiciona uma playlist a lista ligada do sistema
void adicionarPlaylist(Lista<Playlist> *listaDePlaylists)
{
    imprimirCabecalhoFuncao("ADICIONAR PLAYLIST AO SISTEMA");

    std::string nomeDaPlaylist;

    std::cout << "Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist))
    {
        std::cout << std::endl;
        std::cout << "Erro: Dados da playlist nao podem estar em branco!" << std::endl;

        return;
    }

    // Verifica se a playlist já está cadastrada
    if (listaDePlaylists -> estaNaLista(new Playlist(nomeDaPlaylist)))
    {
        std::cout << std::endl;
        std::cout << "Erro: Playlist ja cadastrada!" << std::endl;

        return;
    }

    Playlist *playlist = new Playlist(nomeDaPlaylist);

    listaDePlaylists -> inserirNaLista(playlist);

    std::cout << std::endl;
    std::cout << "Playlist '" << nomeDaPlaylist << "' criada com sucesso!" << std::endl;
}

// Função que remove uma playlist da lista ligada do sistema
void removerPlaylist(Lista<Playlist> *listaDePlaylists)
{
    imprimirCabecalhoFuncao("REMOVER PLAYLIST DO SISTEMA");

    // Verifica se a lista está vazia
    if (listaDePlaylists -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha playlists cadastradas!" << std::endl;

        return;
    }

    std::string nomeDaPlaylist;

    std::cout << "Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist))
    {
        std::cout << std::endl;
        std::cout << "Erro: Dados da playlist nao podem estar em branco!" << std::endl;

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
            std::cout << "Playlist '" << nomeDaPlaylist << "' removida com sucesso!" << std::endl;

            return;
        }
    }

    std::cout << std::endl;
    std::cout << "Erro: Playlist nao encontrada!" << std::endl;
}

// Função de listar todas as playlists do sistema
void listarPlaylists(Lista<Playlist> *listaDePlaylists)
{
    imprimirCabecalhoFuncao("LISTA DE PLAYLISTS DO SISTEMA");

    // Verifica se a lista está vazia
    if (listaDePlaylists -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha playlists cadastradas!" << std::endl;

        return;
    }

    // Percorre a lista de playlists
    for (int i = 0; i < listaDePlaylists -> getSize(); i++)
    {
        Playlist *playlist = listaDePlaylists -> getItem(i);
        
        std::cout << i + 1 << ": " << playlist -> getNomeDaPlaylist() << std::endl;
        std::cout << std::endl;
    }
}

// Função que adiciona uma música a uma playlist
void adicionarMusicaAPlaylist(Lista<Playlist> *listaDePlaylists, Lista<Musica> *listaDeMusicas)
{
    imprimirCabecalhoFuncao("ADICIONAR MUSICA A PLAYLIST");

    // Verifica se a lista de playlists ou de músicas está vazia
    if (listaDePlaylists -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha playlists cadastradas!" << std::endl;

        return;
    }
    else if (listaDeMusicas -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha musicas cadastradas!" << std::endl;

        return;
    }

    std::string nomeDaPlaylist, titulo;

    std::cout << "Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    std::cout << "Insira o titulo da musica: ";
    std::getline(std::cin, titulo);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist) || !verificaEntrada(titulo))
    {
        std::cout << std::endl;
        std::cout << "Erro: Dados da playlist e/ou da musica nao podem estar em branco!" << std::endl;

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
                    // Verifica se a música já está na playlist
                    if (playlist -> estaNaPlaylist(musica))
                    {
                        std::cout << std::endl;
                        std::cout << "Erro: Musica ja cadastrada na playlist!" << std::endl;

                        return;
                    }

                    playlist -> inserirMusica(musica);

                    std::cout << std::endl;
                    std::cout << "Musica '" << titulo << "' adicionada a playlist '" << nomeDaPlaylist << "' com sucesso!" << std::endl;

                    return;
                }
            }

            std::cout << std::endl;
            std::cout << "Erro: Musica nao encontrada!" << std::endl;

            return;
        }
    }
}
               
// Função que remove uma música de uma playlist
void removerMusicaDePlaylist(Lista<Playlist> *listaDePlaylists, Lista<Musica> *listaDeMusicas)
{
    imprimirCabecalhoFuncao("REMOVER MUSICA DE PLAYLIST");

    // Verifica se a lista de playlists ou de músicas está vazia
    if (listaDePlaylists -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha playlists cadastradas!" << std::endl;

        return;
    }
    else if (listaDeMusicas -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha musicas cadastradas!" << std::endl;

        return;
    }

    std::string nomeDaPlaylist, titulo;

    std::cout << "Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    std::cout << "Insira o titulo da musica: ";
    std::getline(std::cin, titulo);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist) || !verificaEntrada(titulo))
    {
        std::cout << std::endl;
        std::cout << "Erro: Dados da playlist e/ou da musica nao podem estar em branco!" << std::endl;

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
                        std::cout << "Erro: Musica nao cadastrada na playlist!" << std::endl;

                        return;
                    }

                    playlist -> removerMusica(musica);

                    std::cout << std::endl;
                    std::cout << "Musica '" << titulo << "' removida da playlist '" << nomeDaPlaylist << "' com sucesso!" << std::endl;

                    return;
                }
            }

            std::cout << std::endl;
            std::cout << "Erro: Musica nao encontrada!" << std::endl;

            return;
        }
    }
}

// Função que lista as músicas de uma playlist
void listarMusicasDePlaylist(Lista<Playlist> *listaDePlaylists)
{
    imprimirCabecalhoFuncao("LISTA DE MUSICAS DA PLAYLIST");

    // Verifica se a lista de playlists está vazia
    if (listaDePlaylists -> estaVazia())
    {
        std::cout << std::endl;
        std::cout << "Erro: Nao ha playlists cadastradas!" << std::endl;

        return;
    }

    std::string nomeDaPlaylist;

    std::cout << "Insira o nome da playlist: ";
    std::getline(std::cin, nomeDaPlaylist);

    // Verifica se dados foram inseridos corretamente
    if (!verificaEntrada(nomeDaPlaylist))
    {
        std::cout << std::endl;
        std::cout << "Erro: Dados da playlist nao podem estar em branco!" << std::endl;

        return;
    }

    // Percorre a lista de playlists
    for (int i = 0; i < listaDePlaylists -> getSize(); i++)
    {
        Playlist *playlist = listaDePlaylists -> getItem(i);

        // Verifica se a playlist foi encontrada
        if (playlist -> getNomeDaPlaylist() == nomeDaPlaylist)
        {
            std::cout << std::endl;
            std::cout << "Playlist: " << nomeDaPlaylist << std::endl;
            std::cout << std::endl;

            // Verifica se a playlist está vazia
            if (playlist -> estaVazia())
            {
                std::cout << "Erro: Playlist vazia!" << std::endl;

                return;
            }

            // Percorre a lista de músicas
            for (int j = 0; j < playlist -> getListaDeMusicas() -> getSize(); j++)
            {
                Musica *musica = playlist -> getListaDeMusicas() -> getItem(j);

                std::cout << "Titulo: " << musica -> getTitulo() << std::endl;
                std::cout << "Artista: " << musica -> getArtista() << std::endl;
                std::cout << std::endl;
            }

            return;
        }
    }
}

// Função que verifica se a entrada do usuário é válida
bool verificaEntrada(const std::string& str)
{
    if(str.empty() || std::all_of(str.begin(), str.end(), isspace))
    {
        return false;
    }

    return true;
}

// Função que limpa a tela
void limparTela() 
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

// Função que retorna a largura do terminal
int getLarguraTerminal()
{
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

// Função que imprime o cabeçalho
void imprimirCabecalho()
{
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
    int larguraTerminal = getLarguraTerminal();
    int larguraCabecalho = static_cast<int>(nomeFuncao.size()) + 4;

    int espacosEsquerda = std::floor((larguraTerminal - larguraCabecalho) / 2.0);
    int espacosDireita = larguraTerminal - larguraCabecalho - espacosEsquerda;

    std::cout << std::string(larguraTerminal, '=') << std::endl;
    std::cout << std::string(espacosEsquerda, ' ') << nomeFuncao << std::string(espacosDireita, ' ') << std::endl;
    std::cout << std::string(larguraTerminal, '=') << std::endl;
    std::cout << std::endl;
}

// Função que imprime o menu principal
void menuPrincipal(Lista<Musica> *listaDeMusicas, Lista<Playlist> *listaDePlaylists)
{
    int opcao = 0;

    while(opcao != 10)
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
        std::cout << "10 - Sair" << std::endl;

        std::cout << std::endl;

        std::cout << "Insira a opcao desejada: ";

        // Lê a opção digitada pelo usuário e limpa o buffer
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Caso usuário digite um valor não inteiro
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << std::endl;
            std::cout << "Opcao invalida!" << std::endl;

            continue;
        }

        // Verifica se a opção é válida
        if (opcao < 0 || opcao > 10)
        {
            std::cout << std::endl;
            std::cout << "Opcao invalida!" << std::endl;

            continue;
        }

        limparTela();

        switch (opcao)
        {
            case 1:
                adicionarMusica(listaDeMusicas);
                break;
            case 2:
                adicionarPlaylist(listaDePlaylists);
                break;
            case 3:
                removerMusica(listaDeMusicas);
                break;
            case 4:
                removerPlaylist(listaDePlaylists);
                break;
            case 5:
                listarMusicas(listaDeMusicas);
                break;
            case 6:
                listarPlaylists(listaDePlaylists);
                break;
            case 7:
                adicionarMusicaAPlaylist(listaDePlaylists, listaDeMusicas);
                break;
            case 8:
                removerMusicaDePlaylist(listaDePlaylists, listaDeMusicas);
                break;
            case 9:
                listarMusicasDePlaylist(listaDePlaylists);
                break;
            case 10:
                std::cout << "Saindo..." << std::endl;
                return;
            default:
                std::cout << "Erro: Opcao invalida!" << std::endl;
                break;
        }

        std::cout << std::endl;
        std::cout << "Pressione Enter para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limparTela();
    }
}
