#include <stdint.h>
#include <netinet/in.h>
#include <stdio.h>

uint32_t read_number(char *filename){
	uint8_t buffer[4];
	FILE *file = fopen(filename, "rb");
	fread(buffer, sizeof(char), 4, file);	
	uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
	fclose(file);	
	return *p;
}

int main(int argc, char *argv[]) {
    int number1 = htonl(read_number(argv[1]));
    int number2 = htonl(read_number(argv[2]));
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", number1, number1, number2, number2, number1+number2, number1+number2);
    return 0;
}

