## Projeto 2 - Gabriel Shihao Chen Yin
## Como funciona o código
- As duas contas to e from são são do tipo conta e dentro dessa struct é armazenado o saldo de cada conta.
- A função "transferenciaFromTo" é responsável por fazer as transação da conto from para conta to e a função "transferenciaToFrom" é responsável por fazer as transação da conto to para conta from
- Inicialmente as duas contas começam com um saldo de 1000 cada
- 60 threads vão transferir 10 da conta from para a conta to e 40 threads vão transferir 10 da conta to para a conta from
- Para evitar o problema de condição de corrida o mutex é utilizado para sincronizar os acessos das transações.
- Toda vez que uma transação acontece o mutex trava o acesso até a transação for finalizada de fato e só após a transação é concluida a thread destrava o acesso e assim outras threads podem concluir as suas transações
