CC = gcc
all : cesar cipher cipher_file
libs : libjulius.a julius_fpic.o libjulius.so
exec_dynamique : cesar_dynam cipher_dynam cipher_file_dynam

cesar : chiffrer.o cesar.o
		$(CC) -o $ cesar chiffrer.o cesar.o

chiffrer.o : chiffrer.c
		$(CC) -o chiffrer.o -c chiffrer.c

cesar.o : cesar.c
		$(CC) -o cesar.o -c cesar.c

cipher : chiffrer.o cipher.o
		$(CC) -o cipher chiffrer.o cipher.o

cipher.o : cipher.c
		$(CC) -o cipher.o -c cipher.c

cipher_file : chiffrer.o cipher_file.o
		$(CC) -o cipher_file chiffrer.o cipher_file.o

cipher_file.o : cipher_file.c
		$(CC) -o cipher_file.o -c cipher_file.c

libjulius.a : chiffrer.o
		ar qvs libjulius.a chiffrer.o

julius_fpic.o : chiffrer.c
		$(CC) -fPIC -c chiffrer.c -o julius_fpic.o

libjulius.so : julius_fpic.o
		$(CC) -shared julius_fpic.o -o libjulius.so

cesar_dynam : cesar.c
		$(CC) cesar.c -L. -ljulius -o cesar_dynam

cipher_dynam : cipher.c
		$(CC) cipher.c -L. -ljulius -o cipher_dynam

cipher_file_dynam : cipher_file.c
		$(CC) cipher_file.c -L. -ljulius -o cipher_file_dynam

install : cipher cipher_file chiffrer.h libjulius.so
		@echo "installation fichiers d'entêtes"
		$Q sudo install -m 0755 -d /usr/local/include
		$Q sudo install -m 0755 /chiffrer.h /usr/include
		@echo "installation librairie dynamique"
		$Q sudo install -m 0755 -d /usr/lib
		$Q sudo install -m 0755 /libjulius.so /usr/lib
		@echo "installation Cipher"
		$Q sudo ln -sf $(PWD)/cipher /usr/local/bin
		@echo "installation Cipher_file"
		$Q sudo ln -sf $(PWD)/cipher_file /usr/local/bin

clean :
		rm -rf *.o

clean_for_livrable :
		rm -rf *.o cesar cipher cipher_file cesar_dynam cipher_file_dynam cipher_dynam libjulius.a libjulius.so
