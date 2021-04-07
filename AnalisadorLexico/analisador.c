/*Construa, em C ou C++, um analisador léxico para uma expressão matemática básica.

Exemplo:

5 + 3*(2-5)/4 +3

Deve retornar:

Número(5)
Operador(Soma)
Número(3)
Operador(Multiplicação)
Pontuação(Abre Parênteses)
Número(2)
Operador(Subtração)
Número(5)
Pontuação(Fecha Parênteses)
Operador(Divisão)
Número(4)
Operador(Soma)
Número(3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char numeros_array[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char operadores_array[] = {'+', '-', '*', '/'};

char pont_array[] = {' ','(', ')'};

char *tipo[] = {
    "Numero", "Operador", "Pontuacao"
};
enum tiposRetorno {
    Numero, Operador, Pontuacao
};

int tipoArray(char n) {
  int tam_num = sizeof(numeros_array);

  for (int i = 0; i < tam_num; i++ ) {
    if (n == numeros_array[i]) {
        return Numero;
      }
      else if(n == operadores_array[i]) {
        return Operador;
      }
      else if(n == pont_array[i]) {
            return Pontuacao;
      }
    }
    return 0;
} 

void analisador( char *exp ) {
    int exp_size = strlen(exp);

    for ( int i = 0; i < exp_size; i++ ) {
        int retorno = tipoArray(exp[i]);
        printf( "%s ('%c') \n ", tipo[retorno], exp[i]);
    }
}

int main( int argc, char *argv[] ) {
    char *expressao = "5 + 3*(2-5)/4 +3";
    analisador(expressao);
    return EXIT_SUCCESS;
}

