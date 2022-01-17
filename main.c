#include <stdio.h>
#include <stdlib.h>
#include ".libs/libsha1.h"

//Imprime cadena de bytes en formato hexadecimal
static void print_hex(const char* data, size_t size)
{
	int i;
	for(i = 0; i < size; ++i)
		printf("%02x",(unsigned char) data[i]);
}

int main()
{
	/************************************************/
	/* Forma segura de ingresar texto desde consola */
	char *texto = NULL; //Importante inicializar en NULL
	size_t n = 0;
	ssize_t l = 0;
	int i;

	printf("Ingrese texto: ");
	l = getline(&texto, &n, stdin); //getline llama a malloc internamente
	printf("El texto ingresado tiene %lu caracteres (incluido el salto de linea).\n",l);
	/************************************************/

	texto[l-1] = '\0'; //OPCIONAL: Sobreescribe el salto de linea

	sha1_ctx ctx; //Contexto para hash sha1
	char dgst[SHA1_DIGEST_SIZE]; //resultado final hash sha1

	//Calcula el hash SHA-1 de texto usando funciones en libsha1
	//TODO: Revisar libsha1.h y test.c en libsha1
	sha1_begin(&ctx);
    	for(i = 0; i < (l-1); ++i)
        	sha1_hash(texto+i, 1, &ctx);
    	sha1_end(dgst, &ctx);

	printf("El texto: \'%s\' en SHA1 es: \n",texto);
	print_hex(dgst, SHA1_DIGEST_SIZE);
	printf("\n");

	free(texto); //liberar espacio reservado para texto
}
