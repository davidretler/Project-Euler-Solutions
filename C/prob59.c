#include "stdio.h"
#include "stdlib.h"
#include "prob59.h"

int xor(int cipher, int key) {
	return cipher ^ key;
}

int decrypt(int key[3]);

void display();

int main(int argc, char* argv[]) {

	//printf("%c\n", 42);
	//printf("%d\n", xor(107,42));

	
	/* Used to find the key
	int k[3] = {0,0,0};
	for(k[0] = 0; k[0] <= 127; k[0]++) {
		for(k[1] = 0; k[1] <= 127; k[1]++) {
			for(k[2] = 0; k[2] <= 127; k[2]++) {
				
				
				if(decrypt(k)==0) {
					printf("%c%c%c\n\n\n", k[0], k[1], k[2]);
					display();
					printf("\n\n=========================\n\n");
				}
				
				
			}
		}

	}
	*/
	
	int key[3] = {103, 111, 100};
	decrypt(key);
	int sum = 0;
	for(int i = 0; i < LEN; i++) {
		sum += message[i];
	}
	printf("%d\n", sum);
	


	return 0;
}

int decrypt(int key[3]) {
	int curr = 0;
	for(int i = 0; i < LEN; i++) {
		message[i] = xor(cipher[i], key[curr]);
		curr = (curr + 1) % 3;
		if(message[i] > 122 || message[i] < 32) return -1;
	}
	return 0;
}

void display() {
	for(int i = 0; i < LEN; i++) {
		printf("%c",message[i]);
	}
}
