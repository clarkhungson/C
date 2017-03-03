// gcc -o 4-dbmDatabse -I/usr/include/gdbm 4-dbmDatabse.c -lgdbm_compat -lgdbm
// Doc file database from terminal: $od -c 4-dbmDatabase.dbg

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

//#include <ndbm.h>
#include <gdbm-ndbm.h>
#include <string.h>
#define TEST_DB_FILE "/home/clark/work/C_programming/Data Management/4-dbmDatabse"
#define ITEMS_USED 3

struct test_data {
	char misc_chars[15];
	int any_integer;
	char more_chars[21];
};

int main()
{
	// Du lieu luu vao, va du lieu lay ra
	struct test_data items_to_store[ITEMS_USED];
	struct test_data item_retrieved;

	char key_to_use[20];
	int i, result;

	datum key_datum;
	datum data_datum;

	// Mo database cho viec read and write
	DBM *dbm_ptr;
	dbm_ptr = dbm_open(TEST_DB_FILE, O_RDWR | O_CREAT, 0666);
	if (!dbm_ptr) {
		fprintf(stderr, "Failed to open database\n");
		exit(EXIT_FAILURE);
	}

	//Them du lieu vao struct items_to_store
	memset(items_to_store, '\0', sizeof(items_to_store));
	strcpy(items_to_store[0].misc_chars, "First!");
	items_to_store[0].any_integer = 47;
	strcpy(items_to_store[0].more_chars, "foo");

	strcpy(items_to_store[1].misc_chars, "large!");
	items_to_store[1].any_integer = 13;
	strcpy(items_to_store[1].more_chars, "unlucky");

	strcpy(items_to_store[2].misc_chars, "Third!");
	items_to_store[2].any_integer = 3;
	strcpy(items_to_store[2].more_chars, "baz");


	// Tao key cho viec tham chieu
	for (i = 0; i < ITEMS_USED; i++) {
		sprintf(key_to_use, "%c%c%d", 
			items_to_store[i].misc_chars[0],
			items_to_store[i].more_chars[0],
			items_to_store[i].any_integer);
		// printf("Key:\n");
		// printf("%c%c%d\n", 
		// 	items_to_store[i].misc_chars[0],
		// 	items_to_store[i].more_chars[0],
		// 	items_to_store[i].any_integer);


		key_datum.dptr = (void *) key_to_use;
		key_datum.dsize = strlen(key_to_use);
		data_datum.dptr = (void *)&items_to_store[i];
		data_datum.dsize = sizeof(struct test_data);

		// Luu tru vao database
		result = dbm_store(dbm_ptr, key_datum, data_datum, DBM_REPLACE);
		if (result != 0)
		{
			fprintf(stderr, "dbm_store failed on key %s\n", key_to_use);
			exit(2);
		}
	}

	// Lay du lieu tu database
	sprintf(key_to_use, "lu%d", 13);
	key_datum.dptr = key_to_use;
	key_datum.dsize = strlen(key_to_use);

	key_datum = dbm_firstkey(dbm_ptr);
	// key_datum = dbm_nextkey(dbm_ptr);
	// key_datum = dbm_nextkey(dbm_ptr);

	data_datum = dbm_fetch(dbm_ptr, key_datum);
	if (data_datum.dptr) {
		printf("Data retrieved\n");
		memcpy(&item_retrieved, data_datum.dptr, data_datum.dsize);
		printf("Retrieved item - %s %d %s\n", 
			item_retrieved.misc_chars,
			item_retrieved.any_integer,
			item_retrieved.more_chars);
	}
	else {
		printf("No data found for key %s\n", key_to_use);
	}
	// Dong database
	dbm_close(dbm_ptr);
	exit(EXIT_SUCCESS);

}
