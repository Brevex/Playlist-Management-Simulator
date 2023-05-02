#include "../include/playlistManager.h"
#include <limits>

int main(int argc, char *argv[])
{
    // Cria instâncias das classes
    MusicasLista musicas;
    PlaylistManager listas;

    // Variável que armazena a opção digitada pelo usuário
    int opcao = 0;

    // Imprime o cabeçalho do programa
    std::cout << "========== GERENCIADOR DE PLAYLISTS ==========" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "   Projeto LP I - Breno Barbosa de Oliveira   " << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    std::cout << std::endl;

    // Laço while que roda até que o usuário digite a opção 11 (menu de navegação)
    while (opcao != 11)
    {
        std::cout << std::endl;
        std::cout << "1  - Adicionar musica" << std::endl;
        std::cout << "2  - Remover musica do sistema" << std::endl;
        std::cout << "3  - Criar playlist" << std::endl;
        std::cout << "4  - Remover playlist" << std::endl;
        std::cout << "5  - Adicionar musica a playlist" << std::endl;
        std::cout << "6  - Remover musica de playlist" << std::endl;
        std::cout << "7  - Listar playlists" << std::endl;
        std::cout << "8  - Listar musicas de playlist" << std::endl;
        std::cout << "9  - Listar musicas do sistema" << std::endl;
        std::cout << "10 - Mover musica de playlist" << std::endl;
        std::cout << "11 - Sair" << std::endl;

        // Solicita ao usuário que digite a opção desejada
        std::cout << std::endl;
        std::cout << "Digite a opcao desejada: ";

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

        // Switch case para navegação do menu
        switch (opcao)
        {
            case 1:
                musicas.addMusica();
                break;
            case 2:
                listas.removerMusicaTodasPlaylists(&musicas);
                break;
            case 3:
                listas.criarPlaylist();
                break;
            case 4:
                listas.removerPlaylist();
                break;
            case 5:
                listas.adicionarMusica(&musicas);
                break;
            case 6:
                listas.removerMusica();
                break;
            case 7:
                listas.listarPlaylists();
                break;
            case 8:
                listas.listarMusicasPlaylist();
                break;
            case 9:
                musicas.coutLista();
                break;
            case 10:
                listas.moverMusica();
                break;
            case 11:
                std::cout << std::endl;
                std::cout << "Saindo..." << std::endl;
                std::cout << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }
    }

    system("pause");

    return 0;
}
