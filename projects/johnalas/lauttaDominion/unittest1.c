#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define PRINTOUT 1 //set to 1 for test printout

int main() {

	//game values
	int i;
	int p, handCount, replacement;
	handCount = 5;
	p = 0;

	//game initialization declarations
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall }; 
	int seed = 1000;
	struct gameState G;
	int numPlayer = 2;
	

	printf("\nTesting scoreFor():\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.handCount[p] = handCount;

	for (replacement = 1; replacement < 4; replacement++) {
		//replace cards in hand to non-score cards
		for (i = 0; i < handCount; i++) {
			G.hand[p][i] = 17;
		}
		int p1cur = scoreFor(p, &G);
		//replace cards in hand to all provinces
		for (i = 0; i < handCount; i++) {
			G.hand[p][i] = replacement;
		}
		int p1curnew = scoreFor(p, &G);

		//compare scores
		if (p1curnew - p1cur == 30) {
			printf("Province count test successful.\n");
		}
		if (p1curnew - p1cur == 15) {
			printf("Duchy count test successful.\n");
		}
		if (p1curnew - p1cur == 5) {
			printf("Estate count test successful.\n");
		}
	}

	return 0;
}