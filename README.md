<p>Explicação do Código
Função inicializarTabuleiro:

Inicializa o tabuleiro com a marcação de água (.) em todas as posições.
Função exibirTabuleiro:

Exibe o tabuleiro de batalha na tela.
Função posicionarNavios:

Posiciona navios no tabuleiro em algumas posições fixas. Um navio é representado pela letra 'N'.
Função atacar:

Realiza um ataque simples em uma posição dada. Se o ataque atingir um navio (posição marcada com 'N'), ele é destruído e a célula é marcada com 'X'. Caso contrário, a célula de água é marcada com '~'.
Função atacarAreaEfeito:

Realiza um ataque de área de efeito em torno de uma posição central (um raio de 1). As células ao redor da posição de impacto são afetadas. O código verifica um raio de 3x3 ao redor do ponto central, atingindo navios e marcando células de água com o símbolo '~'.</p>
