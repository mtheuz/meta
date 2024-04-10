# Define o alvo padrão 'all', que depende do alvo 'hello'
all: hello

# Define o alvo 'hello', que depende do arquivo 'hello.c'
hello: hello.c
    gcc -o hello hello.c # Compila 'hello.c' para criar o executável 'hello'

# Define o alvo 'clean', que é usado para remover o executável 'hello'
clean:
    rm -f hello # Remove o arquivo 'hello'
