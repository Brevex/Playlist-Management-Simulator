#include "../include/Musica.h"

// Construtor da classe Musica, define titulo e artista
Musica::Musica(std::string m_titulo, std::string m_artista) : titulo(m_titulo), artista(m_artista) {}

// Getters - retorna o titulo
std::string Musica::getTitulo() 
{
    return titulo;
}

// Getters - retorna o artista
std::string Musica::getArtista() 
{
    return artista;
}

// Setters - define o titulo
void Musica::setTitulo(std::string m_titulo) 
{
    titulo = m_titulo;
}

// Setters - define o artista
void Musica::setArtista(std::string m_artista) 
{
    artista = m_artista;
}

// Operador de comparação
bool Musica::operator==(const Musica& outraMusica) const
{
    return (titulo == outraMusica.titulo && artista == outraMusica.artista);
}
