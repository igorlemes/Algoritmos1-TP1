#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "university.h"
#include "candidate.h"

// node *stableMatching(){
//     // Inicialize todos os h ∈ H e m ∈ M como solteiros
// 		node *M;
//     while(some university U is unmatched and hasn't proposed to every candidate){
//         c = primeiro candidato na lista de U ao qual U ainda não propôs
//         Se m esta disponivel
//             (h, m) começam a namorar
//         Senao (h', m) já namoram
//             Se m prefere o h do que o h'
//                 h' fica solteiro
//                 (h, m) começam a namorar
//             Senao
//                 (h', m) continuam namorando
//     }
// }

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
