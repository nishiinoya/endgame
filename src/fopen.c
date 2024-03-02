#include "header.h"

FILE *file = NULL;

FILE *ofile(char* path) {
	file = fopen(path, "r");

	// Проверяем, успешно ли открыт файл
	if (file == NULL) 
	{
		printf("Error\n");
		return NULL;
	}
	return file;
}

