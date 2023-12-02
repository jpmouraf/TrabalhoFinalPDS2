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


Link para acessar a modelagem CRC https://echeung.me/crcmaker/?share=W3sibmFtZSI6Ik1pZGlhIiwic3VwZXJjbGFzc2VzIjoiIiwic3ViY2xhc3NlcyI6IkR2ZCwgRml0YSwgSm9nbyIsInR5cGUiOjIsInJlc3BvbnNpYmlsaXRpZXMiOlsiQ29kaWdvIE51bWVyaWNvIiwiVGl0dWxvIiwiVW5pZGFkZXMgRGlzcG9uaXZlaXMiLCJJbXByaW1pciBpbmZvcm1h5/VlcyIsIkNhbGN1bGFyIHZhbG9yIGRlIGxvY2Hn428iLCIiXSwiY29sbGFib3JhdG9ycyI6WyJKb2dvIiwiRml0YSIsIkR2ZCJdfSx7Im5hbWUiOiJEdmQiLCJzdXBlcmNsYXNzZXMiOiIiLCJzdWJjbGFzc2VzIjoiTGFuY2FtZW50bywgRXN0b3F1ZSwgUHJvbW9jYW8iLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIkltcHJpbWlyIGluZm9ybWHn9WVzIiwiQ2FsY3VsYXIgdmFsb3IgZGUgbG9jYefjbyJdLCJjb2xsYWJvcmF0b3JzIjpbIkxhbmNhbWVudG8iLCJFc3RvcXVlIiwiUHJvbW9jYW8iXX0seyJuYW1lIjoiRml0YSIsInN1cGVyY2xhc3NlcyI6IiIsInN1YmNsYXNzZXMiOiIiLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIkltcHJpbWlyIGluZm9ybWHn9WVzICIsIkNhbGN1bGFyIGxvY2Hn428iXSwiY29sbGFib3JhdG9ycyI6WyIiXX0seyJuYW1lIjoiSm9nbyIsInN1cGVyY2xhc3NlcyI6IiIsInN1YmNsYXNzZXMiOiIiLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIkltcHJpbWlyIGluZm9ybWHn9WVzIiwiQ2FsY3VsYXIgbG9jYefjbyJdLCJjb2xsYWJvcmF0b3JzIjpbIiJdfSx7Im5hbWUiOiJEZXBvc2l0byIsInN1cGVyY2xhc3NlcyI6IiIsInN1YmNsYXNzZXMiOiIiLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIkVzdG9xdWUgZGFzIG1pZGlhcyIsInRpcG8gZGEgbWlkaWEiLCJjYXRlZ29yaWEgZGEgbWlkaWEiLCJDYWRhc3RyYXIgYXMgbWlkaWFzIiwiUmVtb3ZlciBhcyBtaWRpYXMiLCJMZXIgbyBlc3RvcXVlIiwiU2FsdmFyIG8gZXN0b3F1ZSIsIk9yZGVuYXIgcG9yIGNvZGlnb3Mgb3UgIG5vbWUiLCJDb250cm9sYXIgYSByZXRpcmFkYSBlIGRldm9sdefjbyBkZSBtaWRpYXMiLCJJbXByaW1pciBhcyBtaWRpYXMiXSwiY29sbGFib3JhdG9ycyI6WyJMb2NhZG9yIiwiIl19LHsibmFtZSI6IkNsaWVudGUiLCJzdXBlcmNsYXNzZXMiOiIiLCJzdWJjbGFzc2VzIjoiIiwidHlwZSI6MSwicmVzcG9uc2liaWxpdGllcyI6WyJOb21lIiwiQ3BmIiwiSW5pY2lhbGl6YXIgbm9tZSBlIGNwZiJdLCJjb2xsYWJvcmF0b3JzIjpbIkNvbnRyb2xlQ2xpZW50ZSJdfSx7Im5hbWUiOiJDb250cm9sZUNsaWVudGUiLCJzdXBlcmNsYXNzZXMiOiIiLCJzdWJjbGFzc2VzIjoiIiwidHlwZSI6MSwicmVzcG9uc2liaWxpdGllcyI6WyJBcm1hemVuYXIgb3MgY2xpZW50ZXMiLCJWYWxpZGFyIG8gY3BmIiwiQ2FkYXN0cmFyIGUgcmVtb3ZlciBjbGllbnRlcyIsIk9yZGVuYXIgb3MgY2xpZW50ZXMgcG9yIG5vbWUgZSBjcGYiXSwiY29sbGFib3JhdG9ycyI6WyIiXX0seyJuYW1lIjoiTG9jYWRvciIsInN1cGVyY2xhc3NlcyI6IiIsInN1YmNsYXNzZXMiOiIiLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIk9iamV0byBkYSBjbGFzc2UgZGVwb3NpdG8iLCJBbHVnYXIgZSBkZXZvbHZlciBtaWRpYXMiLCJMZXIgZSBzYWx2YXIgbyBlc3RvcXVlIiwiQ2FkYXN0cmFyIGUgcmVtb3ZlciBtaWRpYSIsIk9yZGVuYXIgcG9yIGPzZGlnbyBlIG5vbWUiLCJJbXByaW1pciBhcyBt7WRpYXMiLCIiLCIiXSwiY29sbGFib3JhdG9ycyI6WyIiXX1d
