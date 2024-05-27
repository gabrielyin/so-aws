## Projeto 2 - Gabriel Shihao Chen Yin
## Como funciona o código
- As duas contas to e from são são do tipo conta e dentro dessa struct é armazenado o saldo de cada conta.
- A função "transferenciaFromTo" é responsável por fazer as transação da conto from para conta to e a função "transferenciaToFrom" é responsável por fazer as transação da conto to para conta from
- Inicialmente as duas contas começam com um saldo de 1000 cada
- 60 threads vão transferir 10 da conta from para a conta to e 40 threads vão transferir 10 da conta to para a conta from
- Para evitar o problema de condição de corrida o mutex é utilizado para sincronizar os acessos das transações.
- Toda vez que uma transação acontece o mutex trava o acesso até a transação for finalizada de fato e só quando a transação é concluida a thread destrava o acesso e assim outras threads podem concluir as suas transações
## Execução do código
### A conta to pode receber mais de uma transferência simultânea;
Conta to recebendo 60 transferências da conta from

![image](https://github.com/gabrielyin/so-aws/assets/70323043/633c3430-b380-426e-9cc2-b76ea2c52a34)
#### Como compilar
- Se necessário altere o valor do saldo das contas from e to nas linhas 'from.saldo' e 'to.saldo'
- Para alterar o valor de cada transferência altere a variável valor
- No primeiro for defina a quantidade de transferências
- No segundo for defina a quantidade de transferências da conta to para from (100 - quantidade) e altere o o valor adicionado no i para o mesmo valor da quantidade de transferências definida no primeiro for loop
- gcc main.c
- ./a.out
  
![image](https://github.com/gabrielyin/so-aws/assets/70323043/b58743c5-7e52-48be-870e-985967287fa2)

### A conta from pode enviar mais de uma transferência simultânea;
Conta from enviando 60 transferências para a conta to

![image](https://github.com/gabrielyin/so-aws/assets/70323043/633c3430-b380-426e-9cc2-b76ea2c52a34)
#### Como compilar
- Se necessário altere o valor do saldo das contas from e to nas linhas 'from.saldo' e 'to.saldo'
- Para alterar o valor de cada transferência altere a variável valor
- No primeiro for defina a quantidade de transferências
- No segundo for defina a quantidade de transferências da conta to para from (100 - quantidade) e altere o o valor adicionado no i para o mesmo valor da quantidade de transferências definida no primeiro for loop
- gcc main.c
- ./a.out
  
![image](https://github.com/gabrielyin/so-aws/assets/70323043/b58743c5-7e52-48be-870e-985967287fa2)

### A conta from não pode enviar dinheiro se não tiver mais saldo;
#### Como compilar
- Se necessário altere o valor do saldo das contas from e to nas linhas 'from.saldo' e 'to.saldo'
- Altere a variável valor para 200 assim rapidamente o saldo vai ser insuficiente em algum momento
- gcc main.c
- ./a.out
  
![image](https://github.com/gabrielyin/so-aws/assets/70323043/c3754b89-8219-4edc-b934-bb17de1105c4)

### A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar
#### Como compilar
- Se necessário altere o valor do saldo das contas from e to nas linhas 'from.saldo' e 'to.saldo'
- No primeiro for defina a quantidade de transferências
- No segundo for defina a quantidade de transferências da conta to para from (100 - quantidade) e altere o o valor adicionado no i para o mesmo valor da quantidade de transferências definida no primeiro for loop (para que troca de ordem acontece é necessário que as quantidades nos dois for loops seja maior que 1)
- gcc main.c
- ./a.out
  
![image](https://github.com/gabrielyin/so-aws/assets/70323043/da024a74-1863-424b-9066-55e96d5a7e07)

### Poderão ser realizadas até 100 transações simultâneas de transferência.
Realizando 100 transações simultâneas

![image](https://github.com/gabrielyin/so-aws/assets/70323043/c099c04c-9ab0-44dd-80fb-3431d2c50eaf)
#### Como compilar
- Se necessário altere o valor do saldo das contas from e to nas linhas 'from.saldo' e 'to.saldo'
- Para alterar o valor de cada transferência altere a variável valor
- No primeiro for defina a quantidade de transferências
- No segundo for defina a quantidade de transferências da conta to para from (100 - quantidade) e altere o o valor adicionado no i para o mesmo valor da quantidade de transferências definida no primeiro for loop (a soma das transferências tem que dar 100 para simular 100 transferências simultâneas)
- gcc main.c
- ./a.out


![image](https://github.com/gabrielyin/so-aws/assets/70323043/7d714dde-b87f-497d-9c19-e46fd35c5574)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/29774d79-dcad-4e5f-addf-f05d047da957)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/b7564a28-ef3b-4b28-a3fc-3db05abeb295)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/bb8a0823-fbd2-4356-addb-44c2cdf8ff54)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/b79042b1-f716-411a-ac2e-9405790b3056)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/d72aad12-eefa-4944-baa2-b5ac7d4b999d)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/827763d9-fd5e-4764-9eda-db5ca8977438)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/faa331e9-8e31-446e-b699-b558178f150a)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/5bd22d4c-b838-4bb7-874a-2e47ccf9109a)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/4bd8a825-c708-4495-9769-8ba1bc0496e5)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/60ffa1d5-6dda-44dd-ae42-c995fa2fd3c1)
![image](https://github.com/gabrielyin/so-aws/assets/70323043/1aae221e-da87-43aa-8953-d09190658bd3)











