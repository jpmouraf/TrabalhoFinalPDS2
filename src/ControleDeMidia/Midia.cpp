#include "../../include/ControleDeMidia/Midia.hpp"

class MidiaErro : public std::exception {
    private:
        const char* _mensagem;
    
    public:
        MidiaErro(const char* mensagem) : _mensagem(mensagem) {}
        
        virtual const char* what() const noexcept {
            return _mensagem;
        }
};

class RedefinirConstanteTipo : public MidiaErro {
    public:
        RedefinirConstanteTipo(char* mensagem) : MidiaErro(mensagem) {}
};

Midia::Midia(int codigo_numerico, std::string titulo, int unidades_disponiveis) : _codigo_numerico(codigo_numerico) , _titulo(titulo) , _unidades_disponiveis(unidades_disponiveis){}

std::string Midia::getTipo() {
    std::cout << _tipo << std::endl;
}

std::string Midia::getTitulo() {
    return this->_titulo;
}

int Midia::getCodigoNumerico() {
    return this->_codigo_numerico;
}

int Midia::getUnidadesDisponiveis() {
    return this->_unidades_disponiveis;
}

void Midia::imprimir_info(){
    std::cout << this->getCodigoNumerico() << this->getTitulo() << this->getUnidadesDisponiveis();
}

void Midia::setTipo(std::string tipo){
    if (this->_const_tipo == false){
        this->_tipo = tipo;
        this->_const_tipo = true;
    } else{
        throw RedefinirConstanteTipo("[MIDIA] ERRO: Você esta tentando redefinir uma constante");
    }
}
