#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
int wordCount(FILE *fptr);
FILE *getFile(char nameArq[100]);

int main(){
	int index;
	char path[100];
	strcpy(path,"test.txt");

	// List of distinct words
	//char words[MAX_WORDS][50];

	int chamada;
	chamada = wordCount(getFile(path));

	// Close file
	/*
	 * Print occurrences of all words in file.
	 */
	return 0;
}

FILE *getFile(char nameArq[100]){
	FILE *fptr;
	/* Input file path */
	printf("Enter file path: ");
	/* Try to open file */
	fptr = fopen(nameArq, "r");

	/* Exit if file not opened successfully */

	if (fptr == NULL){
		printf("Unable to open file.\n");
		printf("Please check you have read previleges.\n");

		exit(EXIT_FAILURE);
	}
	return fptr;

}

int wordCount(FILE *fptr){  
	int len, isUnique,i;
	char word[50];
	int index = 0;

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
	return index;
}