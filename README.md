<h1 align="center">Breno Barbosa de Oliveira</h1>

<h1 align="center">20220021749</h1>

</br>

<h3 align="center">Sobre o Projeto</h3>

</br>

<p>
O projeto se trata de um gerenciador de Playlists que armazena
tanto Playlists quanto Músicas em uma lista ligada simples criada
do zero. O programa não gerencia arquivos de música .mp3, é apenanas
uma simulação que cria objetos do tipo 'Musica' a partir do titulo
da música e do nome do artista. Essas músicas são armazenadas em uma lista ligada
e a partir dessa lista, podem ser armazenadas em uma Playlist que por sua
vez é definida por um nome apenas.
</p>

</br>
<hr/>

<h3>Requisitos Para o Programa</h3>

</br>

<p>
Para o programa conseguir ser compilado em sua máquina, é necessário
que esta tenha o programa 'CMake' instalado em sua última versão, assim
como o compilador de programas C++.
</p>

</br>
<hr/>

<h3>Como Compilar o Programa</h3>

</br>

<p>
Ao baixar o arquivo .zip deste repositório, extraia o pacote em uma pasta qualquer
e siga as instruções abaixo:

</br>
</br>

<ol>
  <li>Procure a pasta "build" e entre nela;</li>
  <li>Clique com o botão direito do mouse dentro da pasta e abra o terminal;</li>
  <li>Com o terminal aberto, digite o comando "cmake .." e espere o processo finalizar;</li>
  <li>Em seguida, execute o comando "make" e espere o processo ser finalizado;</li>
  <li>Digite "./gerenciador" e comece a usar o programa.</li>
</ol>

</br>
</br>

<strong>!!! NÃO APAGUE NENHUM ARQUIVO DA PASTA !!!!</strong>

</p>

</br>
<hr/>

<h3>Como Usar o Programa</h3>

</br>

<h4>Inserindo uma Música:</h4>

</br>

<p>
Digite a opção "1" no menu do programa. Ao abrir a aba de adicionar
uma música, insira o titulo e o nome do artista correspondentes
aos dados da música que você deseja adicionar.

</br>
</br>

Exemplo:

</br>
</br>

Insira o nome da música: Musica1 (aperte Enter) <br>
Insira o artista da música: Cantor1 (aperte Enter) </br>
</br>

Após inserir os dados, aperte Enter para voltar ao menu principal.
</p>


</br>
<hr/ style="border-top: 2px dotted;">

<h4>Inserindo uma Playlist:</h4>

</br>

<p>
Digite a opção "2" no menu do programa. Ao abrir a aba de adicionar
uma Playlist, insira o nome da PLaylist que deseja criar.

</br>
</br>

Exemplo:

</br>
</br>

Insira o nome da Playlist: Playlist1 (aperte Enter) <br>
</br>

Após inserir os dados, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Remover uma Música:</h4>

</br>

<p>
Digite a opção "3" no menu do programa. Ao abrir a aba de remover
uma música, o programa irá mostrar uma lista de músicas cadastradas no sistema,
basta então inserir os dados da música que deseja remover.

</br>
</br>

Exemplo:

</br>
</br>

Insira o nome da música: Musica1 (aperte Enter) <br>
Insira o artista da música: Cantor1 (aperte Enter) </br>
</br>

Após inserir os dados, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Remover uma Playlist:</h4>

</br>

<p>
Digite a opção "4" no menu do programa. Ao abrir a aba de remover
uma Playlist, o programa irá mostrar uma lista de playlists cadastradas no sistema,
basta então inserir os dados da playlist que deseja remover.

</br>
</br>

Exemplo:

</br>
</br>

Insira o nome da Playlist: Playlist1 (aperte Enter) <br>
</br>

Após inserir os dados, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Listar Músicas:</h4>

</br>

<p>
Digite a opção "5" no menu do programa. Ao abrir a aba de listar as músicas
do sistema, o programa irá automaticamente listar todas as músicas
cadastradas.

</br>
</br>

Após ver a lista, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Listar Playlists:</h4>

</br>

<p>
Digite a opção "6" no menu do programa. Ao abrir a aba de listar as playlists
do sistema, o programa irá automaticamente listar todas as playlists
cadastradas.

</br>
</br>

Após ver a lista, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Adicionar Música a Playlist:</h4>

</br>

<p>
Digite a opção "7" no menu do programa. Ao abrir a aba de adicionar músicas
a uma playlist o programa irá listar as playlists disponíveis, o usuário deve inserir o nome da playlist escolhida. 
Em seguida, o programa irá mostrar uma lista de músicas disponíveis, então basta o usuário inserir
o nome da música e ela será adiciona a playlist.

</br>
</br>

Exemplo:

</br>
</br>

Insira o nome da Playlist: Playlist1 (aperte Enter) <br>
Insira o titulo da Musica: Musica1 (aperte Enter) <br>
</br>

Após inserir os dados, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Remover Música de Playlist:</h4>

</br>

<p>
Digite a opção "8" no menu do programa. Ao abrir a aba de remover músicas
de uma playlist o programa irá listar as playlists disponíveis, o usuário deve inserir o nome da playlist escolhida. 
Em seguida, o programa irá mostrar uma lista de músicas disponíveis, então basta o usuário inserir
o nome da música e ela será removida da playlist.

</br>
</br>

Exemplo:

</br>
</br>

Insira o nome da Playlist: Playlist1 (aperte Enter) <br>
Insira o titulo da Musica: Musica1 (aperte Enter) <br>
</br>

Após inserir os dados, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Listar Músicas de Playlists:</h4>

</br>

<p>
Digite a opção "9" no menu do programa. Ao abrir a aba de listar as músicas de uma playlists
do sistema, o programa irá automaticamente listar todas as playlists
cadastradas. O usuário deve inserir o nome da playlist desejada e o programa irá imprimir a lista com as músicas dessa playlist

</br>
</br>

Insira o nome da Playlist: Playlist1 (aperte Enter) <br>

</br>

Após ver a lista, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Concatenar Playlists:</h4>

</br>

<p>
Digite a opção "10" no menu do programa. Ao abrir a aba de concatenar
playlists o programa irá mostrar automaticamente uma lista de playlist disponíveis. Tudo que
o usuário precisa fazer é digitar o nome das duas playlists que ele quer concatenar. No caso
dessa função, as músicas presentes na playlist de origem serão copiadas para a playlist de destino,
deixando a playlist de origem inalterada.

</br>
</br>

Insira o nome da Playlist de origem: Playlist1 (aperte Enter) <br>
Insira o nome da Playlist de destino: Playlist2 (aperte Enter) <br>
</br>

</br>

Após finalizar o processo, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Unir Playlists:</h4>

</br>

<p>
Digite a opção "11" no menu do programa. Ao abrir a aba de unir
playlists o programa irá mostrar automaticamente uma lista de playlist disponíveis. Tudo que
o usuário precisa fazer é digitar o nome das duas playlists que ele quer unir. No caso
dessa função, a união irá criar uma nova playlist, contendo apenas as músicas não repetidas
das duas playlists escolhidas. O usuário irá nomear essa nova playlist.

</br>
</br>

Insira o nome da primeira Playlist: Playlist1 (aperte Enter) <br>
Insira o nome da segunda Playlist: Playlist2 (aperte Enter) <br>
</br>
Insira o nome da playlist união: Playlist3 (aperte Enter) <br>

</br>

Após finalizar o processo, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Remover Duplicatas em PLaylists:</h4>

</br>

<p>
Digite a opção "12" no menu do programa. Ao abrir a aba de remover duplicatas
o programa irá mostrar automaticamente uma lista de playlist disponíveis. Tudo que
o usuário precisa fazer é digitar o nome das duas playlists que ele quer operar. No caso
dessa função, a primeira playlist inserida será a que vai ter as músicas duplicadas removidas. Já a segunda é a playlist que será
usada como parâmetro. Essa função remove todas as músicas de uma playlist que estejam em outra playlist do sistema.

</br>
</br>

Insira o nome da Playlist a ser modificada: Playlist1 (aperte Enter) <br>
Insira o nome da playlist com as músicas a serem comparadas: Playlist2 (aperte Enter) <br>

</br>

Após finalizar o processo, aperte Enter para voltar ao menu principal.
</p>

</br>
<hr/ style="border-top: 2px dotted;">

<h4>Adicionar Arquivos de Playlists:</h4>

</br>

<p>
Digite a opção "13" no menu do programa. Ao abrir a aba de manipulação
do arquivo, o processo todo será feito de forma automática. Essa função faz a leitura do arquivo "musicas.txt"
que está na pasta build e adiciona as playlists do arquivo com suas respectivas músicas no sistema. Nenhum comando é aceito durante 
a execução dessa função. O usuário terá apenas uma resposta caso a operação tenha sido bem sucedida ou não.
</br>
</br>
Segue abaixo um modelo de como adicionar uma playlist com músicas pelo arquivo "musicas.txt":
</br>
</br>
NomePlaylist;TituloMusica:Artista,TituloMusica:Artista
</br>
</br>

Após finalizar o processo, aperte Enter para voltar ao menu principal.
</p>
