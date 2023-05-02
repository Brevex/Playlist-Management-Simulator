#ifndef MUSICA_H
#define MUSICA_H

#include <string>

class Musica
{
    private:

        std::string *titulo;
        std::string *cantor;

    public:

        // Construtor
        Musica(std::string *m_titulo, std::string *m_cantor);

        // Destrutor
        ~Musica();

        // Getters
        std::string *getTitulo();
        std::string *getCantor();
};

#endif
