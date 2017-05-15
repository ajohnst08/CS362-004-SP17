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
	int drawntreasure = 0;
	int temphand[MAX_HAND];
	int temphandCounter = 0;
	int *bonus;

	printf("Testing adventurer card.\n");

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

		//assign one treasure in deck, run function
		G.deck[p][(int)(floor(Random() * G.deckCount[p]))] = 4;
		adventurer_fct(drawntreasure, 0, temphand, temphandCounter, &G, 0, bonus);

		//did the function draw two cards?
		if (G.handCount[p] <= handprev) success = 1;

		//did the function draw two treasures? current hand size -1 is last card in hand, where treausre should be
		if (G.hand[p][(G.handCount[p] - 1)] != 4 && G.hand[0][(G.handCount[p] - 1)] != 5
			&& G.hand[0][(G.handCount[p] - 1)] != 6) {
			success = 2;
		}
	}

		if (success==0)	printf("ALL TESTS OK\n\n");
		else if (success == 1) {
			printf("Failure to draw cards.\n\n");
		}
		else printf("Failure to draw treasure.\n\n");

	return 0;
}
