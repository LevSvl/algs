CP = g++
CC = gcc

CCFLAGS = -Wall -g

# folders
ARRAYS = arrays
HT = hash_tables
LL = linked_lists


ht: $(HT)/hash_table.cpp
	${CP} ${CCFLAGS} $(HT)/hash_table.cpp -o $(HT)/_hash_table
	$(HT)/_hash_table

# pal_str: ${ARRAYS}/pal_str.c
# 	${CC} ${CCFLAGS} ${ARRAYS}/pal_str.c -o $(ARRAYS)/_pal_str

matr: ${ARRAYS}/matr.c
	${CC} ${CCFLAGS} ${ARRAYS}/matr.c -o $(ARRAYS)/_matr

rem_duplicates: ${LL}/rem_duplicates.c
	${CC} ${CCFLAGS} ${LL}/rem_duplicates.c -o $(LL)/_rem_duplicates
	$(LL)/_rem_duplicates

common_elem: ${LL}/common_elem.c
	${CC} ${CCFLAGS} ${LL}/common_elem.c -o $(LL)/_common_elem
	$(LL)/_common_elem