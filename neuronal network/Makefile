CC = gcc
CFLAGS = -O3
LDFLAGS = -lcmocka
SRC_DIR = matrix
TEST_DIR = test

# Les fichiers source du projet
SRC_FILES = $(SRC_DIR)/matrix.c
SRC_FILES_H = $(SRC_DIR)/matrix.h
# Les fichiers de test
TEST_FILES = $(TEST_DIR)/matrixTest.c

all: check_matrix

check_matrix: $(TEST_FILES) $(SRC_FILES) $(SRC_FILES_H)
	$(CC) -o check_matrix $(TEST_FILES) $(LDFLAGS)
	./check_matrix

delete:
	rm -f *.o check_matrix

.PHONY: all delete