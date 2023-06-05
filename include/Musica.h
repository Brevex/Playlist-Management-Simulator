#ifndef MUSICA_H
#define MUSICA_H

#include <string>
#include <iostream>

class Musica
{
    private:

        std::string titulo;
        std::string artista;
    
    public:

        // Construtor
        Musica(std::string titulo, std::string artista);

        // Getters
        std::string getTitulo();
        std::string getArtista();

        // Setters
        void setTitulo(std::string titulo);
        void setArtista(std::string artista);

        // Operador de comparacao
        bool operator==(const Musica& outraMusica) const;
};

#endif
