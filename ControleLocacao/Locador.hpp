#ifndef LOCADOR_HPP
#define LOCADOR_HPP

#include "Deposito.hpp"
#include "Clientes.hpp"

class Locador {
    private:

    public:
        void alugar_midias(int cpf_cliente);
        void devolver_midias(int cpf_cliente);
};


#endif