#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>



int main() {

	int n, p;
	int success = 0;

	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	int seed = 1000;
	struct gameState G;
	int numPlayer = 2;

	printf("Testing village card.\n");

	SelectStream(2);
	PutSeed(3);

	//randomize game state
	for (n = 0; n < 2000; n++) {

		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G); // initialize a new game

												//randomize selectd player
		p = (int)floor(Random() * 2);

		//set random deck, discard, and hand counts
		G.deckCount[p] = (int)floor(Random() * MAX_DECK);
		G.discardCount[p] = (int)floor(Random() * MAX_DECK);
		int handprev = G.handCount[p] = (int)floor(Random() * MAX_HAND);
		int actions = G.numActions;

		//put village in hand, run function
		G.hand[p][0] = 14;
		village_fct(0, &G, 0);

		//did function add two actions?
		if (G.numActions != (actions+2)) success = 1;

		//did function add card to hand?
		if (G.handCount[p]!=handprev) {
			success = 2;
		}
	}

	if (success == 0)	printf("ALL TESTS OK\n\n");
	else if (success == 1) {
		printf("Failure to increase actions by 2.\n\n");
	}
	else printf("Failure to draw card.\n\n");

	return 0;
}
