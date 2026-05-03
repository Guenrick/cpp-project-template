# cpp-project-template

# Modelo de Projeto em C++ (TerraLAB)

Esse repositório é um ponto de partida para projetos em C++, seguindo o padrão de versionamento adotado pelo TerraLAB (UFOP) e tem a proposta de começar com uma estrutura organizada, utilizando Gitflow e práticas de TDD (Test Driven Development).

## Organização das Pastas

- \src → arquivos de implementação (.cpp)
- \include → arquivos de cabeçalho (.hpp)
- \bin → onde ficam os executáveis gerados (não vai para o Git)
- \test → testes para garantir que as funcionalidades continuem corretas
- \doc → documentação técnica do projeto

## Tecnologias

- Linguagem: C++
- Compilador: G++ (Linux ou WSL)
- Build: Makefile
- Versionamento: Git com Gitflow

## Como compilar e executar

Utilize um ambiente Linux (ou WSL) com o pacote build-essential instalado.

Para compilar a aplicação principal:

make all
