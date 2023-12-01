# Sistema de Locadora 🎬🎮

Bem-vindo ao Sistema de Locadora, um projeto de software em C++ desenvolvido por Denner, Vitor Gabriel e João Paulo!

## Funcionalidades Principais

### 1. Ler Arquivo de Cadastro
```cpp
LA <nome_do_arquivo.txt>
```
Este comando permite a leitura de um arquivo de cadastro para inicializar a locadora.

### 2. Cadastrar Mídia
```cpp
CF F <quantidade> <id> <titulo>
CF D <quantidade> <id> <titulo> <categoria>
```
Cadastra uma nova mídia, seja ela do tipo Fita (F) ou DVD (D), com suas respectivas informações.

### 3. Remover Mídia
```cpp
RF <id>
```
Remove uma mídia com base no seu ID.

### 4. Listar Mídias
```cpp
LF C
LF T
```
Lista as mídias ordenadas por Código (C) ou Título (T).

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

### 8. Aluguel de Mídias
```cpp
AL
```
Realiza o aluguel de mídias.

### 9. Devolução de Mídias
```cpp
DV <cpf>
```
Realiza a devolução de mídias associadas a um cliente.

### 10. Finalizar Sistema
```cpp
FS
```
Encerra o sistema.

### 11. Ajuda
```cpp
HP
```
Exibe uma lista de comandos disponíveis.

## Exemplo de Uso
```cpp
LA dados.txt
CF F 10 001 Titanic
LF T
CC 12345678900 João
AL
DV 12345678900
FS
```

Lembre-se de conferir a ajuda (HP) para uma lista completa de comandos!

Divirta-se explorando o Sistema de Locadora! 🍿🕹️
