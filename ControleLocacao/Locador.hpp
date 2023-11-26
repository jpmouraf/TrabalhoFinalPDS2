#ifndef LOCADOR_HPP
#define LOCADOR_HPP

#include "Deposito.hpp"
#include "Clientes.hpp"
#include <vector>


class Locador {
    private:
        Deposito armazenamento;
    public:
        void alugar_midias(long int cpf_cliente, ControleCliente clientes);
        void devolver_midias(long int cpf_cliente);
};


#endif