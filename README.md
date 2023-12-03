# Sistema de Locadora 🎬🎮

Bem-vindo ao Sistema de Locadora, um projeto de software em C++ desenvolvido por Denner, Vitor Gabriel e Joao Paulo!

## Funcionalidades Principais

### 1. Ler Arquivo de Cadastro
```cpp
LA <nome_do_arquivo.txt>
```
Este comando permite a leitura de um arquivo de cadastro para inicializar a locadora.

### 2. Cadastrar Midia
```cpp
CF F <quantidade> <id> <titulo>
CF D <quantidade> <id> <titulo> <categoria>
```
Cadastra uma nova midia, seja ela do tipo Fita (F) ou DVD (D), com suas respectivas informacoes.

### 3. Remover Midia
```cpp
RF <id>
```
Remove uma midia com base no seu ID.

### 4. Listar Midias
```cpp
LF C
LF T
```
Lista as midias ordenadas por Codigo (C) ou Titulo (T).

### 5. Cadastrar Cliente
```cpp
CC <cpf> <nome>
```
Cadastra um novo cliente com CPF e nome.

### 6. Remover Cliente
```cpp
RC <cpf>
```
Remove um cliente com base no CPF.

### 7. Listar Clientes
```cpp
LC C
LC N
```
Lista os clientes ordenados por CPF (C) ou Nome (N).

### 8. Aluguel de Midias
```cpp
AL
```
Realiza o aluguel de midias.

### 9. Devolucao de Midias
```cpp
DV <cpf>
```
Realiza a devolucao de midias associadas a um cliente.

### 10. Finalizar Sistema
```cpp
FS
```
Encerra o sistema.

### 11. Ajuda
```cpp
HP
```
Exibe uma lista de comandos disponiveis.

## Exemplo de Uso
```cpp
LA dados.txt
CF F 10 001 Titanic
LF T
CC 12345678900 Joao
AL
DV 12345678900
FS
```

Lembre-se de conferir a ajuda (HP) para uma lista completa de comandos!

Divirta-se explorando o Sistema de Locadora! 🍿🕹️
