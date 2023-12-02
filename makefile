CC=g++
CFLAGS=-std=c++17 -Wall
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build

# Procurando todos os cpp's em cada diretório
CLIENTES_SRC=$(wildcard $(SRC_DIR)/clientes/*.cpp)
CONTROLE_LOCACAO_SRC=$(wildcard $(SRC_DIR)/ControleDeLocacao/*.cpp)
CONTROLE_MIDIA_SRC=$(wildcard $(SRC_DIR)/ControleDeMidia/*.cpp)
LOCADORA_SRC=$(wildcard $(SRC_DIR)/Locadora/*.cpp)
MAIN_SRC=$(wildcard $(SRC_DIR)/*.cpp)

# Transformando os arquivos fonte em objetos
CLIENTES_OBJ=$(CLIENTES_SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
CONTROLE_LOCACAO_OBJ=$(CONTROLE_LOCACAO_SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
CONTROLE_MIDIA_OBJ=$(CONTROLE_MIDIA_SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
LOCADORA_OBJ=$(LOCADORA_SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
MAIN_OBJ=$(MAIN_SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Procurando todos os arquivos de cabeçalho
INCLUDES=$(wildcard $(INCLUDE_DIR)/*.hpp)

# Definindo o executável
TARGET=$(BUILD_DIR)/program

# Comando para limpar arquivos gerados durante a compilação
ifeq ($(OS),Windows_NT)
	RM = del /q
	MKDIR = mkdir
	FIXPATH = $(subst /,\,$1)
else
	RM = rm -f
	MKDIR = mkdir -p
	FIXPATH = $1
endif

all: directories $(TARGET)

# Compilando os arquivos fonte em objetos
$(BUILD_DIR)/clientes/%.o: $(SRC_DIR)/clientes/%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/ControleDeLocacao/%.o: $(SRC_DIR)/ControleDeLocacao/%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/ControleDeMidia/%.o: $(SRC_DIR)/ControleDeMidia/%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/Locadora/%.o: $(SRC_DIR)/Locadora/%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(MAIN_OBJ) $(CLIENTES_OBJ) $(CONTROLE_LOCACAO_OBJ) $(CONTROLE_MIDIA_OBJ) $(LOCADORA_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Criando os diretórios dentro do build
directories: $(BUILD_DIR)/clientes $(BUILD_DIR)/ControleDeLocacao $(BUILD_DIR)/ControleDeMidia $(BUILD_DIR)/Locadora

$(BUILD_DIR)/clientes:
	$(MKDIR) $(call FIXPATH,$@)

$(BUILD_DIR)/ControleDeLocacao:
	$(MKDIR) $(call FIXPATH,$@)

$(BUILD_DIR)/ControleDeMidia:
	$(MKDIR) $(call FIXPATH,$@)

$(BUILD_DIR)/Locadora:
	$(MKDIR) $(call FIXPATH,$@)

# Regra para limpar os arquivos gerados durante a compilação
# Chame 'make clean' para usar
clean:
	$(RM) $(call FIXPATH,$(BUILD_DIR)/*)
