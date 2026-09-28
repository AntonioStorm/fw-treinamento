GREEN = \033[0;32m
NC = \033[0m # No Color

# Instala as dependências do sistema operacional
installDependencies:
	@echo -e "\n\n"
	@echo -e "$(GREEN)***********************$(NC)"
	@echo -e "$(GREEN)Instalando Dependencias$(NC)"
	@echo -e "$(GREEN)***********************\n$(NC)"
	bash ./scripts/installDepsFw.sh

# Configura e sincroniza o SDK do Raspberry Pi Pico
setup_sdk:
	@echo -e "\n\n"
	@echo -e "$(GREEN)***********************$(NC)"
	@echo -e "$(GREEN)  Instalando Pico SDK  $(NC)"
	@echo -e "$(GREEN)***********************\n$(NC)"
	bash ./scripts/pico_sdk.sh

# Limpa o cache e compila o projeto a partir do zero
rebuild:
	@echo -e "\n\n"
	@echo -e "$(GREEN)***********************$(NC)"
	@echo -e "$(GREEN)        Rebuild        $(NC)"
	@echo -e "$(GREEN)***********************\n$(NC)"
	bash ./scripts/clean_and_build.sh

# Compila o projeto aproveitando o cache (para o dia a dia)
build:
	@echo -e "\n\n"
	@echo -e "$(GREEN)***********************$(NC)"
	@echo -e "$(GREEN)         Build         $(NC)"
	@echo -e "$(GREEN)***********************\n$(NC)"
	bash ./scripts/build.sh

# Alvo para configurar o ambiente do zero
setup_all: installDependencies setup_sdk rebuild
