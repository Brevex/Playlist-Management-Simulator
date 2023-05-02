cmake_minimum_required(VERSION 3.5)

# Nome do seu projeto
project(Gerenciador)

# flags de compilação, vc pode colocar aqui
# o addres sanitizer por exemplo
# set ( CMAKE_CXX_FLAGS "-Wall" )

include_directories( include )

# Adiciona a flag de depuração "-g" ao compilar com o GCC ou Clang
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()

# Adiciona a flag de depuração "/DEBUG" ao compilar com o MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /DEBUG")
endif()

# Adiciona os arquivos fonte ao executável
add_executable( Gerenciador
src/main.cpp
src/musica.cpp
src/noLista.cpp
src/listaMusica.cpp
src/noPlaylist.cpp
src/playlist.cpp
src/playlistManager.cpp)