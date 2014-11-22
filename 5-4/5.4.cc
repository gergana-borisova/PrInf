#include "fcpp.hh"

bool deck_check(int deck[], int n)
{
	for (int i=0; i<n; i=i+1)
		if (deck[i] != i)
			return 0;
	return 1;
}

int main()
{
	 const int n = enter_int("deck size:");
	 int deck[n];
	 for (int i=0; i<n; i++) //Deck-Initialisierung
		 deck[i]=i;
	 //Zählervariablen
	 int shuffles_PO = 0;
	 int shuffles_PI = 0;

	//Perfect-Out-Shuffle
	while ((deck_check(deck, n) != 1) || (shuffles_PO < 1))
	{
		 int deck_part1[n/2], deck_part2[n/2];

		 for (int i=0; i<n/2; i++) //Kopie 1. Deck-Hälfte
			 deck_part1[i] = deck[i];

		 for (int i=0; i<n/2; i++) //Kopie 2. Deck-Hälfte
			 deck_part2[i] = deck[n/2+i];

		 for (int i=0; i<n; i++) //sHuFfLe sHuFfLe sHuFfLe!
		 {
			 if (i%2==0)
				 deck[i]=deck_part1[i/2];
			 else
				 deck[i]=deck_part2[(i-1)/2];
		 }
		 shuffles_PO++;
	}

	//Perfect-In-Shuffle
	while ((deck_check(deck, n) != 1) || (shuffles_PI < 1))
	{
		 int deck_part1[n/2], deck_part2[n/2];

		 for (int i=0; i<n/2; i++) //Kopie 1. Deck-Hälfte
			 deck_part1[i] = deck[i];

		 for (int i=0; i<n/2; i++) //Kopie 2. Deck-Hälfte
			 deck_part2[i] = deck[n/2+i];

		 for (int i=0; i<n; i++) //sHuFfLe sHuFfLe sHuFfLe!
		 {
			 if (i%2==0)
				 deck[i]=deck_part2[i/2];
			 else
				 deck[i]=deck_part1[(i-1)/2];
		 }
		 shuffles_PI++;
	}
	printf("#Perfect-Out=%d\n#Perfect-In=%d\n", shuffles_PO, shuffles_PI);
	return shuffles_PO;
}



