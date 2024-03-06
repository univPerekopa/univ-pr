#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataset.h"
#include "parser.tab.h"
#include "SyntInsertDS.h"
#include "print.h"

// Usage: ./main file1 file2 ...

int main(int argc, char **argv) {
  struct dataset_list *dataset_list = NULL;
  for (int i = 1; i < argc; i++) {
    SyntInsertDS_file(&dataset_list, argv[i]);
  }
  print_dataset_list(dataset_list);
}
