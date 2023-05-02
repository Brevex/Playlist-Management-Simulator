<h1 align="center"> Playlist-Manager </h1>

<h1 align="center"> Breno Barbosa de Oliveira - 20220021749 </h1>

<p align="center"> Programa em C++ que gerencia músicas e playlists usando lista encadeada simples. Projeto do bacharelado em TI, matéria de Linguagem de Programação I.</p>

<h3> - Como executar o programa - </h3>

<P> Na pasta "/build" você vai encontrar o arquivo executável chamado "Gerenciador". Basta dar duplo clique no executável e usar o programa. </p>

<h3> - Limitações do programa - </h3>

<ul>

<li> Músicas de playlists são listadas como endereço de memória </li>
<li> Esporadicamente ocorre um "crash" ao listar músicas do sistema </li>
<li> Programa não consegue lidar com caracteres especiais e acentuação local </li>

</ul>

<h3> - Dificuldades passadas - </h3>

<ul>

<li> Tive que refazer o trabalho do zero devido ao uso incoerente de "smart pointers" </li>
<li> Achei a criação dos métodos para gerenciar playlists particularmente complicado </li>
<li> Fazer a lista ligada para as músicas funcionar </li>
<li> Gerenciar ponteiros </li>

</ul>

<h3> - Funções do programa - </h3>

<ol>

<li> Menu </li>
<br>

<p> O usuário vai iniciar o programa com uma lista das funções e deverá escolher qual delas
deseja executar. As funções são listadas de (1 - 11), sendo elas: <br><br>1- Adicionar música<br>2- Remover música do sistema<br>3 - Criar playlist<br>4 - Remover playlist<br>5 - Adicionar música a playlist<br>6 - Remover música de playlist<br>7 - Listar playlists<br>8 - Listar músicas de playlist<br>9 - Listar músicas do sistema<br>10 - Mover música de playlist<br>11 - Sair<br><br> O programa vai exibir uma mensagem perguntando qual função ele deseja executar, tudo que ele tem que fazer é inserir um número correspondente a função. Essa escolha possui um tratamento de erro caso o usuário digite algo que não seja um número, retornando uma mensagem de erro caso aconteça. O programa usa o método 'getline(cin, str)' para ler os dados dentro das funções, portanto irá aceitar espaços até que o usuário pressione a tecla "enter".</p>

<li> Adicionar música </li>
<br>

<p>Nessa função o programa vai pedir para o usuário inserir 2 dados, o título da música e o nome do cantor. A música é armazenada em uma lista ligada.<br><br>Exemplo:<br><br>Insira o nome da música: Título<br>Insira o nome do cantor: Nome<br><br>Esse método possui um sistema de verificação de dados que retorna uma mensagem de erro caso o usuário deixa um dos espaços em branco ou se a música já tiver sido cadastrada anteriormente.</p>

<li> Remover música do sistema</li>
<br>

<p>Essa função remove completamente a música do sistema, inclusive das playlists em que ela estiver cadastrada. Ela pede ao usuário somente o título da música que deseja remover, e ela irá sumir do sistema.<br><br>Exemplo:<br><br> Insira o título da música: Título<br><br>O método possui um sistema de verificação que retorna uma mensagem de erro caso o usuário deixe o espaço em branco, como também se a lista estiver vazia.</p>

<li>Criar playlist</li>
<br>

<p>Cria uma nova playlist no sistema. O método irá pedir para o usuário inserir o nome que deseja para a playlist, que por fim é adicionada a um "vector" que armazena todas as playlists do sistema.<br><br>Exemplo:<br><br>Digite o nome da nova playlist: Nome<br><br>O método conta com um sistema de verificação, que retorna uma mensagem de erro caso a playlist já exista ou se os espaço estiver sido deixado em branco.</p>

<li> Remover playlist </li>
<br>

<p>Remove uma playlist do sistema. Assim como o método anterior, o programa irá solicitar do usuário o nome de uma playlist, caso essa playlist exista ela será removida do "vector".<br><br>Exemplo:<br><br>Digite o nome da playlist que deseja remover: Nome<br><br>Esse método também possui um sistema de verificação, que retorna uma mensagem de erro caso a playlist não exista ou se os espaço estiver sido deixado em branco.</p>

<li> Adicionar música a playlist </li>
<br>

<p>Adiciona uma música já cadastrada no sistema a uma playlist que já existe. O programa vai pedir ao usuário para inserir o nome da playlist que ele deseja colocar a música e o título da música. O programa irá buscar a música recebida na lista ligada de músicas e irá adicioná-la a playlist correspondente a entrada do usuário. As playlists armazenadas no "vector" usam uma lista ligada para guardar as músicas cadastradas.<br><br>Exemplo:<br><br>Insira o nome da playlist: Nome<br>Insira o título da música: Título<br><br>O método possui um sistema de verificação, que retorna uma mensagem de erro caso um dos campos tenha sido deixado em branco, se a música ou a playlist não exista ou se a música já tiver sido adicionada a essa playlist.</p>

<li> Remover música de playlist </li>
<br>

<p>Remove uma música que já tenha sido cadastrada a uma playlist. O programa vai pedir ao usuário para inserir o nome da playlist que ele deseja remover a música e o título da música. O programa irá buscar a música recebida na lista ligada de músicas e irá remove-la da playlist correspondente a entrada do usuário.<br><br>Exemplo:<br><br>Insira o nome da playlist: Nome<br>Insira o título da música: Título<br><br>O método possui um sistema de verificação, que retorna uma mensagem de erro caso um dos campos tenha sido deixado em branco ou se a música ou a playlist não exista. </p>

<li> Listar playlists </li>
<br>

<p>Imprime uma lista com todas as playlists cadastradas. O método irá percorrer o "vector" de playlists e imprimir na tela o nome de cada uma delas. Nesse método nenhuma entrada de dados é requisitada ao usuário e retorna uma mensagem de erro caso nenhuma playlist exista.</p>

<li> Listar músicas de playlist </li>
<br>

<p>Imprime todas as músicas cadastradas em uma playlist. O método irá pedir ao usuário o nome da playlist que ele deseja conferir e vai percorrer a lista ligada de músicas que a playlist guarda.<br><br>Exemplo:<br><br>Insira o nome da playlist: Nome<br><br>O método tem um sistema de verificação que irá retornar uma mensagem de erro caso a playlist não exista ou se ela estiver vazia.</p>

<li> Listar músicas do sistema </li>
<br>

<p>Imprime uma lista com todas as músicas cadastradas no sistema. Esse método percorre a lista ligada de músicas e imprime o título e o cantor de cada música que existe no sistema. Esse método não pede nenhuma entrada de dados ao usuário e retorna uma mensagem de erro caso não existam músicas na lista.</p>

<li> Mover música de playlist </li>
<br>

<p>Move uma música de uma playlist para outra. Esse método pede ao usuário para que ele insira o nome da playlist de origem, playlist de destino e título da música. Esse método percorre a lista ligada de músicas da playlist de origem e identifica a música inserida para poder move-la até a playlist de destino.<br><br>Exemplo:<br><br>Insira o nome da playlist de origem: Nome 1<br>Insira o nome da playlist de destino: Nome 2<br>Insira o título da música: Título<br><br>Esse método possui um sistema de verificação que retorna uma mensagem de erro caso alguns dos campos estejam em branco, ou se alguma das playlists ou música inseridas não existam.</p>

</ol>
