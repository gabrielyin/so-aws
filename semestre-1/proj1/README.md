1) ![image](https://github.com/gabrielyin/so-aws/assets/70323043/14b8116c-9157-4ebc-af81-5d343d5602bc)
2) ![image](https://github.com/gabrielyin/so-aws/assets/70323043/20c217fb-6c7c-485d-a274-cc417da3a5c5)
3) ![image](https://github.com/gabrielyin/so-aws/assets/70323043/afdae69c-0d56-4a90-b0ef-c341293ddbf5)
4) ![image](https://github.com/gabrielyin/so-aws/assets/70323043/3d66c499-1307-490d-9316-cfb32a5d0bb3)
5) TIMEOUT
6) TIMEOUT
7) TIMEOUT
8) TIMEOUT
9) TIMEOUT
10) TIMEOUT

até

58) TIMEOUT

Problemas no código
O código não funciona quando mais de uma pessoa entra na fila de espera pois a última pessoa que entra na fila de espera sempre vai sobscrever a pessoa que já está na fila. Então o problema acontece quando a direção da escada rolante troca e a fila de espera não é executado da maneira correta com todas as pessoas.

Qual a estratégia que você utilizou para evitar que duas pessoas acessem a escada rolante ao mesmo tempo em cada abordagem?

Para evitar que duas pessoas acessem a escada rolante ao mesmo tempo eu criei uma variable global chamada direction que não permite que pessoas em direções diferentes acessem a escada rolante ao mesmo tempo. Uma variável global guarda o tempo da pessoa que está na escada rolante e todas pessoas que vão entrar nesse intervalo de tempo na mesma direção podem acessar a escada rolante.

Como garantir que somente uma das direções está ativa de cada vez em cada uma das abordagens?

Para garantir que somente uma das direções está ativa eu começo com uma direção e vou verificando todas as pessoas que estão no intervalo permitido e querem ir na mesma direção e caso uma pessoa queira acessar a escada em outra direção eu armazena essa pessoa em uma lista de espera para ser executada depois da escada estiver vazia.

Discorra sobre as diferenças entre as implementações utilizando threads e processos e diga qual foi mais eficiente na solução do problema, justificando sua resposta.

A implementação com threads fez mais sentido para mim por conta do da thread pode acessar um espaço de memória compartilhada assim não foi necessário criar pipes para fazer a comunicação entre os processos.
