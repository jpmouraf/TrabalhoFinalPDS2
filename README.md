# Cinerama - Sistema Eletrônico de Locação

Bem-vindo ao Cinerama, o seu sistema eletrônico de locação de mídias! 🎬✨

## Introdução
O Cinerama é um projeto de locadora desenvolvido em C++ que permite gerenciar o cadastro de mídias, clientes, realizar locações e devoluções. Este sistema foi criado para proporcionar uma experiência eficiente e organizada na gestão de uma locadora. O CRC do nosso projeto se encontra [aqui](https://echeung.me/crcmaker/?share=W3sibmFtZSI6Ik1pZGlhIiwic3VwZXJjbGFzc2VzIjoiIiwic3ViY2xhc3NlcyI6IkR2ZCwgRml0YSwgSm9nbyIsInR5cGUiOjIsInJlc3BvbnNpYmlsaXRpZXMiOlsiQ29kaWdvIE51bWVyaWNvIiwiVGl0dWxvIiwiVW5pZGFkZXMgRGlzcG9uaXZlaXMiLCJJbXByaW1pciBpbmZvcm1h5/VlcyIsIkNhbGN1bGFyIHZhbG9yIGRlIGxvY2Hn428iLCIiXSwiY29sbGFib3JhdG9ycyI6WyJKb2dvIiwiRml0YSIsIkR2ZCJdfSx7Im5hbWUiOiJEdmQiLCJzdXBlcmNsYXNzZXMiOiIiLCJzdWJjbGFzc2VzIjoiTGFuY2FtZW50bywgRXN0b3F1ZSwgUHJvbW9jYW8iLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIkltcHJpbWlyIGluZm9ybWHn9WVzIiwiQ2FsY3VsYXIgdmFsb3IgZGUgbG9jYefjbyJdLCJjb2xsYWJvcmF0b3JzIjpbIkxhbmNhbWVudG8iLCJFc3RvcXVlIiwiUHJvbW9jYW8iXX0seyJuYW1lIjoiRml0YSIsInN1cGVyY2xhc3NlcyI6IiIsInN1YmNsYXNzZXMiOiIiLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIkltcHJpbWlyIGluZm9ybWHn9WVzICIsIkNhbGN1bGFyIGxvY2Hn428iXSwiY29sbGFib3JhdG9ycyI6WyIiXX0seyJuYW1lIjoiSm9nbyIsInN1cGVyY2xhc3NlcyI6IiIsInN1YmNsYXNzZXMiOiIiLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIkltcHJpbWlyIGluZm9ybWHn9WVzIiwiQ2FsY3VsYXIgbG9jYefjbyJdLCJjb2xsYWJvcmF0b3JzIjpbIiJdfSx7Im5hbWUiOiJEZXBvc2l0byIsInN1cGVyY2xhc3NlcyI6IiIsInN1YmNsYXNzZXMiOiIiLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIkVzdG9xdWUgZGFzIG1pZGlhcyIsInRpcG8gZGEgbWlkaWEiLCJjYXRlZ29yaWEgZGEgbWlkaWEiLCJDYWRhc3RyYXIgYXMgbWlkaWFzIiwiUmVtb3ZlciBhcyBtaWRpYXMiLCJMZXIgbyBlc3RvcXVlIiwiU2FsdmFyIG8gZXN0b3F1ZSIsIk9yZGVuYXIgcG9yIGNvZGlnb3Mgb3UgIG5vbWUiLCJDb250cm9sYXIgYSByZXRpcmFkYSBlIGRldm9sdefjbyBkZSBtaWRpYXMiLCJJbXByaW1pciBhcyBtaWRpYXMiXSwiY29sbGFib3JhdG9ycyI6WyJMb2NhZG9yIiwiIl19LHsibmFtZSI6IkNsaWVudGUiLCJzdXBlcmNsYXNzZXMiOiIiLCJzdWJjbGFzc2VzIjoiIiwidHlwZSI6MSwicmVzcG9uc2liaWxpdGllcyI6WyJOb21lIiwiQ3BmIiwiSW5pY2lhbGl6YXIgbm9tZSBlIGNwZiJdLCJjb2xsYWJvcmF0b3JzIjpbIkNvbnRyb2xlQ2xpZW50ZSJdfSx7Im5hbWUiOiJDb250cm9sZUNsaWVudGUiLCJzdXBlcmNsYXNzZXMiOiIiLCJzdWJjbGFzc2VzIjoiIiwidHlwZSI6MSwicmVzcG9uc2liaWxpdGllcyI6WyJBcm1hemVuYXIgb3MgY2xpZW50ZXMiLCJWYWxpZGFyIG8gY3BmIiwiQ2FkYXN0cmFyIGUgcmVtb3ZlciBjbGllbnRlcyIsIk9yZGVuYXIgb3MgY2xpZW50ZXMgcG9yIG5vbWUgZSBjcGYiXSwiY29sbGFib3JhdG9ycyI6WyIiXX0seyJuYW1lIjoiTG9jYWRvciIsInN1cGVyY2xhc3NlcyI6IiIsInN1YmNsYXNzZXMiOiIiLCJ0eXBlIjoxLCJyZXNwb25zaWJpbGl0aWVzIjpbIk9iamV0byBkYSBjbGFzc2UgZGVwb3NpdG8iLCJBbHVnYXIgZSBkZXZvbHZlciBtaWRpYXMiLCJMZXIgZSBzYWx2YXIgbyBlc3RvcXVlIiwiQ2FkYXN0cmFyIGUgcmVtb3ZlciBtaWRpYSIsIk9yZGVuYXIgcG9yIGPzZGlnbyBlIG5vbWUiLCJJbXByaW1pciBhcyBt7WRpYXMiLCIiLCIiXSwiY29sbGFib3JhdG9ycyI6WyIiXX1d).

## Como Começar
Para iniciar, certifique-se de estar no diretório correto e execute o programa. O sistema oferece uma variedade de comandos para interação, e para obter uma lista completa, basta digitar 'HP' no console.

## Comandos Principais

### 1. Ler Arquivo de Cadastro (LA)
```cpp
LA <nome_do_arquivo.txt>
```
Este comando permite carregar um arquivo de cadastro para inicializar o sistema com informações pré-existentes.

### 2. Cadastrar Mídia (CF)
```cpp
CF F <quantidade> <id> <titulo> - Cadastrar Fita
CF D <quantidade> <id> <titulo> <categoria> - Cadastrar DVD
```
Utilize esses comandos para cadastrar novas mídias, seja do tipo Fita ou DVD.

### 3. Listar Mídias (LF)
```cpp
LF C - Listar por Código
LF T - Listar por Título
```
Liste as mídias ordenadas por código ou título com esses comandos.

### 4. Imprimir Catálogo (CL)
```cpp
CL
```
Visualize o catálogo com todas as mídias organizadas por formato.

### 5. Remover Mídia (RF)
```cpp
RF <id>
```
Remova uma mídia pelo seu código.

### 6. Cadastrar Cliente (CC)
```cpp
CC <cpf> <nome>
```
Adicione novos clientes ao sistema.

### 7. Remover Cliente (RC)
```cpp
RC <cpf>
```
Remova um cliente cadastrado.

### 8. Listar Clientes (LC)
```cpp
LC C - Listar por CPF
LC N - Listar por Nome
```
Liste os clientes ordenados por CPF ou nome.

### 9. Alugar Mídias (AL)
```cpp
AL
```
Inicie o processo de locação, siga as instruções no console.

### 10. Devolução de Mídias (DV)
```cpp
DV
```
Inicie o processo de devolução, siga as instruções no console.

### 11. Mídias Mais Alugadas (TP)
```cpp
TP
```
Imprima as 10 mídias mais alugadas.

### 12. Finalizar Sistema (FS)
```cpp
FS
```
Encerre o sistema.

Lembre-se de que o sistema realiza automaticamente a leitura e salvamento de arquivos no diretório 'data' para um controle administrativo mais eficiente.

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/DS3ttx">
        <img src="https://avatars.githubusercontent.com/u/92930966" width="100px;" alt="DS3ttx"/><br>
        <sub>
          <b>DS3ttx</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/jpmouraf">
        <img src="https://avatars.githubusercontent.com/u/149010897" width="100px;" alt="jpmouraf"/><br>
        <sub>
          <b>jpmouraf</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/MassiveDiamondDrill">
        <img src="https://avatars.githubusercontent.com/u/140446172" width="100px;" alt="MassiveDiamondDrill"/><br>
        <sub>
          <b>MassiveDiamondDrill</b>
        </sub>
      </a>
    </td>
  </tr>
</table>

Divirta-se explorando o Cinerama! 🍿🎉
