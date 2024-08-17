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

.PHONY: all clean

all: _hash_table _unique_str _pal_str _matr _rem_duplicates _common_elem \
_check_branches _rec_sort _bin_search _bin_tree _steps _max_subset

_hash_table: $(HT)/hash_table.cpp
	${CP} ${CCFLAGS} $< -o $(<D)/$@

_pal_str: ${ARRAYS}/pal_str.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_unique_str: ${ARRAYS}/unique_str.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_matr: ${ARRAYS}/matr.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_rem_duplicates: ${LL}/rem_duplicates.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_common_elem: ${LL}/common_elem.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_check_branches: ${ST}/check_branches.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_rec_sort: ${SORT}/rec_sort.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_bin_search: ${SEARCH}/bin_search.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_bin_tree: ${TREES}/bin_tree.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_steps: ${DYN}/steps.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

_max_subset: ${DYN}/max_subset.c
	${CC} ${CCFLAGS} $< -o $(<D)/$@

clean:
	rm -f ${ARRAYS}/_* ${HT}/_* ${LL}/_* ${ST}/_* ${SORT}/_* ${SORT}/_* \
	${SEARCH}/_* ${TREES}/_* ${DYN}/_*