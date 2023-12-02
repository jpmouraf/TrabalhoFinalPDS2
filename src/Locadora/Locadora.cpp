#include "../../include/Locadora/Locadora.hpp"

// Controle de Midias
void Locadora::ler_estoque(std::string nome_do_arquivo){
    this->central_midia_locacoes.ler_estoque(nome_do_arquivo);
}
void Locadora::salvar_estoque(std::string nome_do_arquivo){
    this->central_midia_locacoes.salvar_estoque(nome_do_arquivo);
}
void Locadora::cadastrar_midia(std::string tipo, int quantidade, int codigo, std::string titulo, std::string categoria){
    this->central_midia_locacoes.cadastrar_midia(tipo, quantidade, codigo, titulo, categoria);
}
void Locadora::remover_midia(int codigo_numerico){
    this->central_midia_locacoes.remover_midia(codigo_numerico);
}
void Locadora::ordenar_midias_por_codigo(){
    this->central_midia_locacoes.imprimir_todas_midias();
}
void Locadora::ordenar_midias_por_titulo(){
    this->central_midia_locacoes.ordenar_titulo();
    //this->central_midia_locacoes.imprimir_todas_midias();
}

// Controle de Clientes
void Locadora::cadastrar_cliente(long cpf, std::string nome){
    this->central_de_clientes.cadastrar_cliente(cpf, nome);
}
void Locadora::remover_cliente(long cpf){
    this->central_de_clientes.remover_cliente(cpf);
}
void Locadora::listar_clientes_por_nome(){
    this->central_de_clientes.listar_codigo();
}
void Locadora::listar_clientes_por_cpf(){
    this->central_de_clientes.listar_nome();
}

// Controle de Locacao
void Locadora::alugar_midias(long cpf, std::map<int, int> locacoes){

}
void Locadora::devolver_midias(long cpf){
    
}