#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


int main() {

	//game initialization declarations
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	int seed = 1000;
	struct gameState G;
	int numPlayer = 2;

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.deckCount[0] = 3;

	printf("\nTesting fullDeckCount():\n");

	G.deck[0][0] = 0;
	G.deck[0][1] = 0;
	G.deck[0][2] = 1;
	int check = fullDeckCount(0, 0, &G);
	if (check == 2) {
		printf("Test deck count=%d successful.\n", check);
	}
	else printf("Test deck count=%d failed.\n", check);

	G.handCount[0] = 3;

	G.hand[0][0] = 0;
	G.hand[0][1] = 0;
	G.hand[0][2] = 1;
	if (check == 2) {
		printf("Test hand count=%d successful.\n", check);
	}
	else printf("Test hand count=%d failed.\n", check);


	G.discardCount[0] = 3;

	G.discard[0][0] = 0;
	G.discard[0][1] = 0;
	G.discard[0][2] = 1;
	if (check == 2) {
		printf("Test discard count=%d successful.\n", check);
	}
	else printf("Test discard count=%d failed.\n", check);

	
	return 0;
}