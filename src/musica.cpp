#include "../include/musica.h"

// Construtor da classe, cria uma música a partir dos dados passados no parâmetro (dispensa criação de setters)
Musica::Musica(std::string *m_titulo, std::string *m_cantor) : titulo(m_titulo), cantor(m_cantor) {} 

// Destrutor da classe, deleta os objetos "titulo" e "cantor"
Musica::~Musica()
{
    // Verifica se os ponteiros são diferentes de "nullptr"
    if (titulo != nullptr) delete titulo;
    if (cantor != nullptr) delete cantor;
}

// Retorna o titulo da música
std::string* Musica::getTitulo()
{
    return titulo;
}

// Retorna o cantor da música
std::string* Musica::getCantor()
{
    return cantor;
}
