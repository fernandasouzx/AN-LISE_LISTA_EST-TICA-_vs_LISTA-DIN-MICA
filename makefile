all: lista_enc.c lista.c lista_dupla_enc.c 
	gcc arquivo.c -o arq
	gcc lista.c -o lista
	gcc lista_enc.c -o lista_enc 
	gcc lista_dupla_enc.c -o lista_dup_enc
clean:
	rm *.o prog
