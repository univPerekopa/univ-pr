#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataset.h"
#include "parser.tab.h"
#include "SyntInsertDS.h"
#include "print.h"

// AddDSO(DSRef,KV,адреса) – вставка примірника OWNER з адресою;

void AddDSO(struct dataset *DSRef, struct attribute_list *KV, char *address) {
  DSRef->owner_kv = KV;
  DSRef->owner_address = address;
}

int main(int argc, char **argv) {
  struct dataset_list *dataset_list = NULL;
  for (int i = 1; i < argc; i++) {
    SyntInsertDS_file(&dataset_list, argv[i]);
  }

  // Example:
  
  struct dataset ds = dataset_list->head;

  struct attribute dsharp;
  dsharp.name = "dsharp";
  dsharp.type.meta_type = meta_char;
  dsharp.type.size = 6;

  struct attribute dname;
  dname.name = "dname";
  dname.type.meta_type = meta_char;
  dname.type.size = 9;

  struct attribute_list kv;
  kv.head = dsharp;
  struct attribute_list kv2;
  kv2.head = dname;
  kv.tail = &kv2;

  char* address = "a\0\0\0\0\0longname\0b\0\0\0\0\0nm\0\0\0\0\0\0\0";

  AddDSO(&ds, &kv, address);
  print_dataset(ds);
}
