#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "university.h"
#include "candidate.h"
#include "types.h"
// -O3  -Wextra -std=c99 -pedantic -pthread
int main(int argc, char **argv){
  University *universities = initUniversities(fileOpener(argv[1]));
  Candidate *candidates = initCandidates(fileOpener(argv[2]), universities);
  createCandidatesList(universities, candidates);

	printCandidates(candidates);
  printf("\n");
	printUniversities(universities);

	freeCandidates(candidates);
	freeUniversities(universities);
  return 0;
}
