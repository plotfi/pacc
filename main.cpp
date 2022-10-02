#include <fstream>
#include <iostream>
#include <vector>
#include "ast.h"

extern "C" {
  extern int linenum;
  extern int yylval;
  extern FILE *yyin;
}

int yyparse();
extern TranslationUnitDecl *topnode;

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Expected: " << argv[0] << " filename.c\n";
    return -1;
  }

  yyin = fopen(argv[1], "r");
  yyparse();
  fclose(yyin);

  std::cout << "TOPNODE NAME: " << topnode << "\n";
  topnode->dump();
}
