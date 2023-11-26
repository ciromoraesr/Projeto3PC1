SOURCE_DIR = source
HEADER_DIR = header

OBJ = main.o leitura.o shar.o quebra.o saida.o


main: $(OBJ)
	gcc -Wall $(OBJ) -o exec -lssl -lcrypto


main.o: $(SOURCE_DIR)/main.c $(HEADER_DIR)/leitura.h $(HEADER_DIR)/shar.h $(HEADER_DIR)/quebra.h $(HEADER_DIR)/saida.h
	gcc -c -Wall $(SOURCE_DIR)/main.c -I$(HEADER_DIR)

leitura.o: $(SOURCE_DIR)/leitura.c $(HEADER_DIR)/leitura.h
	gcc -c -Wall $(SOURCE_DIR)/leitura.c -I$(HEADER_DIR)

shar.o: $(SOURCE_DIR)/shar.c $(HEADER_DIR)/shar.h
	gcc -c -Wall $(SOURCE_DIR)/shar.c -I$(HEADER_DIR)
	
quebra.o: $(SOURCE_DIR)/quebra.c $(HEADER_DIR)/quebra.h
	gcc -c -Wall $(SOURCE_DIR)/quebra.c -I$(HEADER_DIR)

saida.o: $(SOURCE_DIR)/saida.c $(HEADER_DIR)/saida.h
	gcc -c -Wall $(SOURCE_DIR)/saida.c -I$(HEADER_DIR)


clean:
	rm -f exec $(OBJ)
