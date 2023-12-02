#include <vector>
#include <filesystem>
#include "../../include/ControleDeMidia/Deposito.hpp"

Deposito::Deposito(){
    std::filesystem::path caminho = std::filesystem::current_path()/"../data/banco_de_midias.txt";
    this->ler_estoque(caminho.string());
}

Deposito::~Deposito(){
    this->salvar_estoque();
}

void Deposito::cadastrar_jogo(std::string tipo, int unidades_disponiveis, int codigo_numerico, std::string titulo) {
    auto it = _midias.find(codigo_numerico);
    if (it != _midias.end()) {
        throw DadosRepetidos ("ERRO: codigo repetido");
    }
    if(tipo == "FITA") {
        Jogo* nova_fita = new Jogo(codigo_numerico, titulo, unidades_disponiveis);
        _midias[codigo_numerico] = nova_fita;
        std::cout << "Midia " << codigo_numerico << " cadastrada com sucesso" << std::endl;
    }
    else {
        throw DadosInexistente ("ERRO: dados incorretos");
    }
};

void Deposito::cadastrar_fita(std::string tipo, int unidades_disponiveis, int codigo_numerico, std::string titulo) {
    auto it = _midias.find(codigo_numerico);
    if (it != _midias.end()) {
        throw DadosRepetidos ("ERRO: codigo repetido");
    }
    if(tipo == "FITA") {
        Fita* nova_fita = new Fita(codigo_numerico, titulo, unidades_disponiveis);
        _midias[codigo_numerico] = nova_fita;
        std::cout << "Midia " << codigo_numerico << " cadastrada com sucesso" << std::endl;
    }
    else {
        throw DadosInexistente ("ERRO: dados incorretos");
    }
};

void Deposito::cadastrar_dvd(std::string tipo, int unidades_disponiveis, int codigo_numerico, std::string titulo, std::string categoria) {
   auto it = _midias.find(codigo_numerico);
    if (it != _midias.end()) {
        throw DadosRepetidos ("ERRO: codigo repetido");
    }
   Dvd* novo_dvd = nullptr;
    if (tipo == "DVD") {
        if (categoria == "Lancamento") {
            novo_dvd = new Lancamento(codigo_numerico, titulo, unidades_disponiveis);
        } 
        else if (categoria == "Estoque") {
            novo_dvd = new Estoque(codigo_numerico, titulo, unidades_disponiveis);
        } 
        else if (categoria == "Promocao") {
            novo_dvd = new Promocao(codigo_numerico, titulo, unidades_disponiveis);
        }
    }
    if (novo_dvd != nullptr) {
        _midias[codigo_numerico] = novo_dvd;
        std::cout << "Midia " << codigo_numerico << " cadastrado com sucesso" << std::endl;
    }
    else {
        throw DadosInexistente ("ERRO: dados incorretos");
    }
};

void Deposito::remover_midia(int codigo_numerico) {
    auto it = _midias.find(codigo_numerico);
    if(it != _midias.end()) {
        _midias.erase(it);
        std::cout << "Midia " << codigo_numerico << " removida com sucesso" << std::endl;
    } else {
        throw DadosInexistente ("ERRO: codigo inexistente");
    }
};

void Deposito::ler_estoque(std::string nome_arquivo) {
    if (nome_arquivo.find(".txt") == std::string::npos) {
        throw FormatoInvalido("[DPST] ERRO: Voce selecionou um formato de arquivo invalido. Apenas TXT sao aceitados");
    }

    std::ifstream arquivo;
    arquivo.open(nome_arquivo);
    if (arquivo.is_open()) {
        std::string tipo, titulo, categoria;
        int unidades_disponiveis, codigo_numerico;
        int contador = 0;

        while (arquivo >> tipo >> unidades_disponiveis >> codigo_numerico) {
            getline(arquivo, titulo);
            if (tipo == "DVD") {
                getline(arquivo, categoria);
                cadastrar_dvd(tipo, unidades_disponiveis, codigo_numerico, titulo, categoria);
            } else if (tipo == "FITA") {
                cadastrar_fita(tipo, unidades_disponiveis, codigo_numerico, titulo);
            } else if (tipo == "JOGO") {
                cadastrar_jogo(tipo, unidades_disponiveis, codigo_numerico, titulo);
            }
            contador++;
        }
        arquivo.close();
        std::cout << contador << " Midias cadastradas com sucesso" << std::endl;
    } else {
        throw ExcecaoDeposito ("ERRO: arquivo inexistente");
    }
};

void Deposito::salvar_estoque(std::string nome_do_arquivo){
    std::ofstream estoque_saida(nome_do_arquivo);

    for (auto& midia : this->_midias){
        if (typeid(*midia.second) == typeid(Promocao)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "promocao\n";
        }

        else if (typeid(*midia.second) == typeid(Lancamento)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "lancamento\n";
        }

        else if (typeid(*midia.second) == typeid(Estoque)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "estoque\n";
        }
        
        else if (typeid(*midia.second) == typeid(Fita)) {
            estoque_saida << "F" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "\n";
        }
    }
    
    estoque_saida.close();
};

void Deposito::salvar_estoque(){
    std::ofstream estoque_saida;
    std::filesystem::path caminho = std::filesystem::current_path()/"../data/banco_de_midias.txt";
    estoque_saida.open(caminho.string());

    for (auto& midia : this->_midias){
        if (typeid(*midia.second) == typeid(Promocao)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "promocao\n";
        }

        else if (typeid(*midia.second) == typeid(Lancamento)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "lancamento\n";
        }

        else if (typeid(*midia.second) == typeid(Estoque)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "estoque\n";
        }
        
        else if (typeid(*midia.second) == typeid(Fita)) {
            estoque_saida << "F" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "\n";
        }
    }
    
    estoque_saida.close();
};

void Deposito::ordenar_codigo() {
    std::map<int, Midia*>::iterator it;
    for(it = _midias.begin(); it != _midias.end(); it++) {
        std::cout << it ->first << ": " << it->second << std::endl;
    }
};

void Deposito::ordenar_titulo() {
    std::map<std::string, Midia*> temp_map;
    for(auto it : _midias){
        std::string nome = it.second->getTitulo();
        if(temp_map.find(nome) != temp_map.end()){
            temp_map[nome] = it.second;
        }
    }
    std::cout << "## {RELAToRIO}: Titulo de todas as midias em estoque ##" << std::endl;
    for(auto it : temp_map){
        std::cout << it.first << std::endl;
    }
    std::cout << "################## FIM DO RELAToRIO ##################" << std::endl;
    
};

void Deposito::imprimir_todas_midias(){
    for (auto& midia : this->_midias) {
        midia.second->imprimir_info();
    }
};

Midia* Deposito::get_midia(int codigo_numerico){
    if(_midias.find(codigo_numerico) != _midias.end()){
        return _midias[codigo_numerico];
    } else {
        throw DadosInexistente("Nenhuma midia encontrada com o codigo numerico dado");
    }
};

void Deposito::imprimir_todas_midias_agrupadas_nome(){
    std::map<std::string, std::vector<Midia*>> categorias;
    for(auto it : _midias){
        Midia* midia_atual = it.second;
        std::string nome = midia_atual->getTitulo();
        if(categorias.find(nome) != categorias.end()){ //se o vetor desse nome existe
            categorias.find(nome)->second.push_back(midia_atual);
        } else { //se o vetor desse nome nao existe
            std::vector<Midia*> temp;
            temp.push_back(midia_atual);
            categorias[nome] = temp;
        }
    }

    for(auto it : categorias){
        std::cout << "Nome da midia: " << it.first << ". Disponivel nos seguintes formatos: " << std::endl;
        for(auto it2 : it.second){
            std::cout << " - "<< it2->getTipo() << ", " << it2->getUnidadesDisponiveis() << " unidades disponiveis em estoque." << std::endl;
        }
    }
};

void Deposito::retirar_midia(int codigo_numerico, int quantidade){
    try {
        _midias[codigo_numerico] += quantidade;
    } catch(std::out_of_range e){
        throw DadosInexistente("ERRO: Midia nao existente na base de dados.");
    }
};

void Deposito::devolver_midia(int codigo_numerico, int quantidade){ //talvez tenhamos que revisar isso
    try {
        _midias[codigo_numerico] += quantidade;
    } catch(std::out_of_range e){
        throw DadosInexistente(("[DPST] ERRO: Midia nao existe na base de dados. Verifique se a midia nao foi descadastrada durante o periodo de locacao."));
    }
};
