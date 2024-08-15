PREFIX = x86_64-linux-gnu-
CP = ${PREFIX}g++
CC = ${PREFIX}gcc
LD = ${PREFIX}ld

CCFLAGS = -Wall -g
LDFLAGS =

# folders
ARRAYS = arrays
HT = hash_tables
LL = linked_lists
ST = stack
SORT = sort
SEARCH = search
TREES = trees
DYN = dynamic

ht: $(HT)/hash_table.cpp
	${CP} ${CCFLAGS} $(HT)/hash_table.cpp -o $(HT)/_hash_table
	$(HT)/_hash_table

pal_str: ${ARRAYS}/pal_str.c
	${CC} ${CCFLAGS} ${ARRAYS}/pal_str.c -o $(ARRAYS)/_pal_str

unique_str: ${ARRAYS}/unique_str.c
	${CC} ${CCFLAGS} ${ARRAYS}/unique_str.c -o $(ARRAYS)/_unique_str

matr: ${ARRAYS}/matr.c
	${CC} ${CCFLAGS} ${ARRAYS}/matr.c -o $(ARRAYS)/_matr

rem_duplicates: ${LL}/rem_duplicates.c
	${CC} ${CCFLAGS} ${LL}/rem_duplicates.c -o $(LL)/_rem_duplicates
	$(LL)/_rem_duplicates

common_elem: ${LL}/common_elem.c
	${CC} ${CCFLAGS} ${LL}/common_elem.c -o $(LL)/_common_elem
	$(LL)/_common_elem

check_branches: ${ST}/check_branches.c
	${CC} ${CCFLAGS} ${ST}/check_branches.c -o $(ST)/_check_branches
	$(ST)/_check_branches

rec_sort: ${SORT}/rec_sort.c
	${CC} ${CCFLAGS} ${SORT}/rec_sort.c -o $(SORT)/_rec_sort

bin_search: ${SEARCH}/bin_search.c
	${CC} ${CCFLAGS} ${SEARCH}/bin_search.c -o $(SEARCH)/_bin_search

bin_tree: ${TREES}/bin_tree.c
	${CC} ${CCFLAGS} ${TREES}/bin_tree.c -o ${TREES}/_bin_tree
	${TREES}/_bin_tree

steps: ${DYN}/steps.c
	${CC} ${CCFLAGS} ${DYN}/steps.c -o ${DYN}/_steps
	${DYN}/_steps 2