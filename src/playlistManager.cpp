#include "../include/playlistManager.h"

// Construtor da classe, inicializa o "vector" de playlists como vazio
PlaylistManager::PlaylistManager() : playlists{} {}

// Destrutor da classe, deleta todas as playlists
PlaylistManager::~PlaylistManager()
{
    // Percorre o "vector" de playlists
    for (auto& playlist : playlists)
    {
        delete playlist;
    }

    // Limpa o "vector" de playlists
    playlists.clear();
}

// Adiciona uma nova playlist ao sistema
void PlaylistManager::criarPlaylist()
{
    std::cout << std::endl;
    std::cout << "- Criar Playlist -" << std::endl;

    std::string nomePlaylist;

    // Solicita ao usuário que digite o nome da playlist
    std::cout << std::endl;
    std::cout << "Digite o nome da nova playlist: ";
    std::getline(std::cin, nomePlaylist);

    // Caso o parâmetro esteja vazio, printa mensagem de erro e retorna
    if (nomePlaylist.empty())
    {
        std::cout << "Nome da playlist nao pode ser vazio." << std::endl;
        return;
    }

    // confere se playlist já existe
    for (auto& playlist : playlists)
    {
        // Se já existe, printa mensagem de erro e retorna
        if (playlist -> getNome() == nomePlaylist)
        {
            std::cout << std::endl;
            std::cout << "A playlist " << nomePlaylist << " ja existe!" << std::endl;
            return;
        }
    }

    // Cria uma nova playlist e adiciona ela ao "vector"
    Playlist* novaPlaylist = new Playlist(nomePlaylist);
    playlists.push_back(novaPlaylist);

    // Printa mensagem de sucesso
    std::cout << std::endl;
    std::cout << "Playlist \"" << nomePlaylist << "\" criada com sucesso!" << std::endl;
}

// Remove uma playlist do sistema
void PlaylistManager::removerPlaylist()
{
    std::cout << std::endl;
    std::cout << "- Remover Playlist -" << std::endl;

    std::string nomePlaylist;

    // Solicita ao usuário que digite o nome da playlist
    std::cout << std::endl;
    std::cout << "Digite o nome da playlist que deseja remover: ";
    std::getline(std::cin, nomePlaylist);

    // Caso o parâmetro esteja vazio, printa mensagem de erro e retorna
    if (nomePlaylist.empty())
    {
        std::cout << "Nome da playlist nao pode ser vazio." << std::endl;
        return;
    }

    // Percorre o "vector" de playlists
    for (auto it = playlists.begin(); it != playlists.end(); ++it)
    {
        // Se encontrou a playlist, remove ela do "vector"
        if ((*it) -> getNome() == nomePlaylist)
        {
            // Remove a playlist do "vector"
            delete (*it);
            playlists.erase(it);

            std::cout << std::endl;
            std::cout << "Playlist \"" << nomePlaylist << "\" removida com sucesso!" << std::endl;

            return;
        }
    }

    std::cout << std::endl;
    std::cout << "A playlist " << nomePlaylist << " nao existe!" << std::endl;
}

// Recebe o nome de uma playlist como parâmetro e confere se ela existe no "vector"
Playlist* PlaylistManager::buscarPlaylistPorNome(std::string nome)
{
    // Caso o parâmetro esteja vazio
    if (nome.empty())
    {
        std::cout << "Nome nao pode ser vazio." << std::endl;
        return nullptr;
    }

    // Percorre o vetor de playlists
    for (auto playlist : playlists)
    {
        // Se encontrou uma playlist com o nome passado, retorna a playlist
        if (playlist -> getNome() == nome)
        {
            return playlist;
        }
    }

    // Se não encontrou nenhuma playlist com o nome passado
    return nullptr;
}

// Adiciona uma música a uma playlist
void PlaylistManager::adicionarMusica(MusicasLista *musicas)
{
    std::cout << std::endl;
    std::cout << "- Adicionar musica a playlist -" << std::endl;

    std::string tituloMusica, nomePlaylist;

    // Solicita ao usuário que digite o nome da playlist e o título da música
    std::cout << std::endl;
    std::cout << "Insira o nome da playlist: ";
    std::getline(std::cin, nomePlaylist);

    std::cout << "Insira o titulo da musica: ";
    std::getline(std::cin, tituloMusica);

    // Verifica se os campos estão vazios
    if(tituloMusica.empty() || nomePlaylist.empty())
    {
        std::cout << std::endl;
        std::cout << "Nome da playlist ou titulo da musica nao pode ser vazio." << std::endl;

        return;
    }

    // Verifica se a playlist existe
    if (buscarPlaylistPorNome(nomePlaylist) == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Playlist nao encontrada." << std::endl;
        return;
    }

    // Verifica se música já foi cadastrada na playlist
    if (buscarPlaylistPorNome(nomePlaylist) -> buscaMusicaPlaylist(&tituloMusica) != nullptr)
    {
        std::cout << std::endl;
        std::cout << "Musica ja cadastrada na playlist." << std::endl;
        return;
    }

    // Busca playlist por nome
    Playlist *playlist = buscarPlaylistPorNome(nomePlaylist);

    // Verifica se a playlist existe
    if (playlist == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Playlist nao encontrada." << std::endl;
        return;
    }

    // Busca música por título usando método da classe MusicasLista
    Musica *musica = musicas -> buscaMusica(tituloMusica);

    // Verifica se a música existe
    if (musica == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Musica nao encontrada." << std::endl;
        return;
    }

    // Adiciona música à playlist
    playlist -> addMusicaPlaylist(musica);

    // Printa mensagem de sucesso
    std::cout << std::endl;
    std::cout << "Musica adicionada com sucesso a playlist " << playlist -> getNome() << "." << std::endl;
}

// Remove uma música de uma playlist
void PlaylistManager::removerMusica()
{
    std::cout << std::endl;
    std::cout << "- Remover musica de playlist -" << std::endl;

    std::string tituloMusica, nomePlaylist;

    // Solicita ao usuário que digite o nome da playlist e o título da música
    std::cout << std::endl;
    std::cout << "Insira o nome da playlist: ";
    std::getline(std::cin, nomePlaylist);

    std::cout << "Insira o titulo da musica: ";
    std::getline(std::cin, tituloMusica);

    // Verifica se os campos estão vazios
    if(tituloMusica.empty() || nomePlaylist.empty())
    {
        std::cout << std::endl;
        std::cout << "Nome da playlist ou titulo da musica nao podem ser vazios." << std::endl;

        return;
    }

    // Busca playlist por nome usando o método criado na classe playlistManager
    Playlist *playlist = buscarPlaylistPorNome(nomePlaylist);

    // Verifica se a playlist existe
    if (playlist == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Playlist nao encontrada." << std::endl;

        return;
    }

    // Busca música por título usando método da classe Playlist
    Musica *musica = playlist -> buscaMusicaPlaylist(&tituloMusica);

    // Verifica se a música existe na playlist
    if (musica == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Musica nao encontrada na playlist " << playlist -> getNome() << "." << std::endl;

        return;
    }

    // Remove música da playlist usando método da classe Playlist
    playlist -> removeMusicaPlaylist(&tituloMusica);

    // Printa mensagem de sucesso
    std::cout << std::endl;
    std::cout << "Musica removida com sucesso da playlist " << playlist -> getNome() << "." << std::endl;
}

// Remover música de todas as playlists
void PlaylistManager::removerMusicaTodasPlaylists(MusicasLista* musicasLista)
{
    std::cout << std::endl;
    std::cout << "- Remover musica de todas as playlists -" << std::endl;

    std::string tituloMusica;

    // Solicita ao usuário que digite o título da música
    std::cout << std::endl;
    std::cout << "Insira o titulo da musica: ";
    std::getline(std::cin, tituloMusica);

    // Verifica se o campo está vazio
    if(tituloMusica.empty())
    {
        std::cout << std::endl;
        std::cout << "Titulo da musica nao pode ser vazio." << std::endl;

        return;
    }

    // Percorre o vetor de playlists
    for (auto playlist : playlists)
    {
        // Busca música na playlist
        Musica *musica = playlist -> buscaMusicaPlaylist(&tituloMusica);

        // Se a música estiver na playlist, remove
        if (musica != nullptr)
        {
            // Remove música da playlist usando método da classe Playlist
            playlist -> removeMusicaPlaylist(&tituloMusica);
        }
    }

    // Remove música da lista global de músicas usando método da classe MusicasLista
    musicasLista -> removeMusica(tituloMusica);

    // Printa mensagem de sucesso
    std::cout << std::endl;
    std::cout << "Musica removida com sucesso de todas as playlists." << std::endl;
}

// move uma música de uma playlist para outra
void PlaylistManager::moverMusica()
{
    std::cout << std::endl;
    std::cout << "- Mover musica de playlist -" << std::endl;

    std::string tituloMusica, nomePlaylistOrigem, nomePlaylistDestino;

    // Solicita ao usuário que digite o nome da playlist e o título da música
    std::cout << std::endl;
    std::cout << "Insira o nome da playlist de origem: ";
    std::getline(std::cin, nomePlaylistOrigem);

    std::cout << "Insira o nome da playlist de destino: ";
    std::getline(std::cin, nomePlaylistDestino);

    std::cout << "Insira o titulo da musica: ";
    std::getline(std::cin, tituloMusica);

    // Verifica se os campos estão vazios
    if(tituloMusica.empty() || nomePlaylistOrigem.empty() || nomePlaylistDestino.empty())
    {
        std::cout << std::endl;
        std::cout << "Nome da playlist ou titulo da musica nao podem ser vazios." << std::endl;

        return;
    }

    // Busca playlist de origem por nome usando o método criado na classe playlistManager
    Playlist *playlistOrigem = buscarPlaylistPorNome(nomePlaylistOrigem);

    // Verifica se a playlist de origem existe
    if (playlistOrigem == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Playlist de origem nao encontrada." << std::endl;

        return;
    }

    // Busca playlist de destino por nome usando o método criado na classe playlistManager
    Playlist *playlistDestino = buscarPlaylistPorNome(nomePlaylistDestino);

    // Verifica se a playlist de destino existe
    if (playlistDestino == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Playlist de destino nao encontrada." << std::endl;

        return;
    }

    // Busca música por título usando método da classe Playlist
    Musica *musica = playlistOrigem -> buscaMusicaPlaylist(&tituloMusica);

    // Verifica se a música existe na playlist de origem
    if (musica == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Musica nao encontrada na playlist " << playlistOrigem -> getNome() << "." << std::endl;
    }

    // Remove música da playlist de origem usando método da classe Playlist
    playlistOrigem -> removeMusicaPlaylist(&tituloMusica);

    // Adiciona música na playlist de destino usando método da classe Playlist
    playlistDestino -> addMusicaPlaylist(musica);

    // Printa mensagem de sucesso
    std::cout << std::endl;
    std::cout << "Musica movida com sucesso da playlist " << playlistOrigem -> getNome() << " para a playlist " << playlistDestino -> getNome() << "." << std::endl;
}

// Lista todas as playlists cadastradas
void PlaylistManager::listarPlaylists()
{
    std::cout << std::endl;
    std::cout << " - Playlists - " << std::endl;

    // Confere se o vetor de playlists está vazio
    if(playlists.empty())
    {
        std::cout << std::endl;
        std::cout << "Nenhuma playlist cadastrada!" << std::endl;
        return;
    }

    // Percorre o vetor de playlists e imprime o nome de cada uma
    for(auto playlist : playlists)
    {
        std::cout << std::endl;
        std::cout << playlist -> getNome() << std::endl;
    }
}

// Lista todas as músicas de uma playlist escolhida pelo usuário
void PlaylistManager::listarMusicasPlaylist() 
{
    std::cout << std::endl;
    std::cout << "- Imprimir Musicas de uma Playlist -" << std::endl;

    std::string nomePlaylist;
    
    // Solicita ao usuário que digite o nome da playlist
    std::cout << std::endl;
    std::cout << "Digite o nome da playlist: ";
    std::getline(std::cin, nomePlaylist);

    // Verifica se o campo está vazio
    if(nomePlaylist.empty())
    {
        std::cout << std::endl;
        std::cout << "Nome da playlist nao pode ser vazio." << std::endl;

        return;
    }

    // Verifica se a playlist existe
    for (auto& playlist : playlists) 
    {
        // Se etapa atual do laço tiver mesmo nome que a playlist inserida, imprime as músicas
        if (playlist -> getNome() == nomePlaylist) 
        {
            std::cout << std::endl;
            std::cout << "Musicas da Playlist \"" << nomePlaylist << "\":" << std::endl;
            std::cout << std::endl;

            // Verifica se a playlist não possui músicas
            if (playlist -> getHead() == nullptr) 
            {
                std::cout << std::endl;
                std::cout << "A playlist \"" << nomePlaylist << "\" nao possui musicas!" << std::endl;
                return;
            }

            // Chama a função auxiliar para imprimir as músicas
            listarMusicasPlaylistRecursivo(playlist -> getHead());
            return;
        }
    }

    // Se a playlist não existir, imprime mensagem de erro
    std::cout << std::endl;
    std::cout << "A playlist \"" << nomePlaylist << "\" nao existe!" << std::endl;
}

// Lista todas as músicas de uma playlist usando recursão (auxiliar)
void PlaylistManager::listarMusicasPlaylistRecursivo(NoPlaylist *musicaAtual) 
{
    // Confere se a música atual não é nula
    if (musicaAtual != nullptr) 
    {
        // Imprime a música atual
        std::cout << "- " << (*musicaAtual -> getMusica()).getTitulo() << " (" << (*musicaAtual -> getMusica()).getCantor() << ")" << std::endl;

        // Chama a função novamente com a próxima música
        listarMusicasPlaylistRecursivo(musicaAtual -> getNext());
    }
}
