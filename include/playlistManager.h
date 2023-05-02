#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <vector>
#include "playlist.h"

class PlaylistManager
{
    private:

        std::vector<Playlist*> playlists;

    public:

        // Construtor
        PlaylistManager();

        // Destrutor
        ~PlaylistManager();

        // Cria uma nova playlist
        void criarPlaylist();

        // Remove uma playlist
        void removerPlaylist();

        // Adiciona uma música a uma playlist
        void adicionarMusica(MusicasLista *musicas);

        // Remove uma música de uma playlist
        void removerMusica();

        // Remover música de todas as playlists
        void removerMusicaTodasPlaylists(MusicasLista* musicasLista);

        // move uma música de uma playlist para outra
        void moverMusica();

        // Identifica uma playlist
        Playlist* buscarPlaylistPorNome(std::string nome);

        // Imprime todas as playlists
        void listarPlaylists();

        // Imprime músicas de playlist por recurssão
        void listarMusicasPlaylist();
        void listarMusicasPlaylistRecursivo(NoPlaylist *musicaAtual);
};

#endif
