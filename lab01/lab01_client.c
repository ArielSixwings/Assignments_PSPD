/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "lab01.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lab01.h"

#define MAX_WORDS 1000

int wordCount (CLIENT *clnt, char nameFile[100]){
	int len, isUnique,i;
	char word[50];
	params ops;
	strcpy(ops.name, nameFile);
	FILE *fptr = wordcount_100_svc(&ops,clnt);
	int index = 0;
	// /* Input file path */
	// printf("Enter file path: ");
	// /* Try to open file */
	// fptr = fopen(name, "r");

	//  Exit if file not opened successfully 

	// if (fptr == NULL){
	// 	printf("Unable to open file.\n");
	// 	printf("Please check you have read previleges.\n");

	// 	exit(EXIT_FAILURE);
	// }

	//List of distinct words
	char words[MAX_WORDS][50];

	// Count of distinct words
	int count[MAX_WORDS];

	// Initialize words count to 0
	for (i = 0; i < MAX_WORDS; i++)
		count[i] = 0;

	while (fscanf(fptr, "%s", word) != EOF){
		// Convert word to lowercase
		//strlwr(word);

		// Remove last punctuation character
		len = strlen(word);
		if (ispunct(word[len - 1]))
			word[len - 1] = '\0';

		// Check if word exits in list of all distinct words
		isUnique = 1;
		for (i = 0; i < index && isUnique; i++){
			if (strcmp(words[i], word) == 0)
				isUnique = 0;
		}

		// If word is unique then add it to distinct words list
		// and increment index. Otherwise increment occurrence
		// count of current word.
		if (isUnique){
			strcpy(words[index], word);
			count[index]++;

			index++;
		}
		else{
			count[i - 1]++;
		}
	}

	printf("\nOccurrences of all distinct words in file: \n");

	for (i = 0; i < index; i++){
		/*
		 * %-15s prints string in 15 character width.
		 * - is used to print string left align inside
		 * 15 character width space.
		 */
		printf("%-15s => %d\n", words[i], count[i]);
	}

	fclose(fptr);
}

int main (int argc, char *argv[]){
	CLIENT *clnt;
	char name[100];

	if (argc != 3)
	{
		fprintf(stderr, "Uso: %s hostname num1 num2\n", argv[0]);
		exit(0);
	}

	clnt = clnt_create(argv[1], PROG, VERSAO, "udp");
	/* Garantindo a criacao da ligacao com o remoto */
	if (clnt == (CLIENT *)NULL)
	{
		clnt_pcreateerror(argv[1]);
		exit(1);
	}
	/* Recupera os 2 operandos passados como argumento */
	strcpy(name, argv[2]);
	int chamada;
	chamada = wordCount(clnt,name);
	//printf("%d + %d = %d\n", x, y, add(clnt, x, y));
	//printf("%d - %d = %d\n", x, y, sub(clnt, x, y));
	return (0);
exit (0);
}
