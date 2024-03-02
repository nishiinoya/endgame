#include "header.h"

char *textbuf(FILE *txt)
{
	fseek(txt, 0, SEEK_END);
	fileSize = ftell(txt);
	rewind(txt);

	// Выделяем память под буфер
	buffer = (char *)malloc(fileSize * sizeof(char));
	if (buffer == NULL) {
		printf("Ошибка выделения памяти.\n");
		return NULL;
	}

	fread(buffer, sizeof(char), fileSize, txt);

	return buffer;
}

