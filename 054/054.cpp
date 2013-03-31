/**
 * In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
 *
 *     High Card: Highest value card.
 *     One Pair: Two cards of the same value.
 *     Two Pairs: Two different pairs.
 *     Three of a Kind: Three cards of the same value.
 *     Straight: All cards are consecutive values.
 *     Flush: All cards of the same suit.
 *     Full House: Three of a kind and a pair.
 *     Four of a Kind: Four cards of the same value.
 *     Straight Flush: All cards are consecutive values of same suit.
 *     Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
 *
 * The cards are valued in the order:
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 *
 * If two players have the same ranked hands then the rank made up of the highest value wins;
 * for example, a pair of eights beats a pair of fives (see example 1 below).
 * But if two ranks tie, for example, both players have a pair of queens, then highest cards
 * in each hand are compared (see example 4 below); if the highest cards tie then the next
 * highest cards are compared, and so on.
 *
 * Consider the following five hands dealt to two players:
 * Hand	 	Player 1	 	Player 2	 	Winner
 * 1	 	5H 5C 6S 7S KD
 * Pair of Fives
 * 	 	2C 3S 8S 8D TD
 * Pair of Eights
 * 	 	Player 2
 * 2	 	5D 8C 9S JS AC
 * Highest card Ace
 * 	 	2C 5C 7D 8S QH
 * Highest card Queen
 * 	 	Player 1
 * 3	 	2D 9C AS AH AC
 * Three Aces
 * 	 	3D 6D 7D TD QD
 * Flush with Diamonds
 * 	 	Player 2
 * 4	 	4D 6S 9H QH QC
 * Pair of Queens
 * Highest card Nine
 * 	 	3D 6D 7H QD QS
 * Pair of Queens
 * Highest card Seven
 * 	 	Player 1
 * 5	 	2H 2D 4C 4D 4S
 * Full House
 * With Three Fours
 * 	 	3C 3D 3S 9S 9D
 * Full House
 * with Three Threes
 * 	 	Player 1
 *
 * The file, poker.txt, contains one-thousand random hands dealt to two players.
 * Each line of the file contains ten cards (separated by a single space):
 * the first five are Player 1's cards and the last five are Player 2's cards.
 * You can assume that all hands are valid (no invalid characters or repeated cards),
 * each player's hand is in no specific order, and in each hand there is a clear winner.
 *
 * How many hands does Player 1 win?
 *
 * @task 054
 * @answer 376
 */
#include "../projecteuler.h"

class pokerHand {
    private:
        UC cardRanks[5], cardSuits[5], cardCount, rankCounts[15];

        void sortByRank() {
            FOR(i,0,5) {
                FOR(j,i + 1,5) {
                    if (cardRanks[i] > cardRanks[j]) {
                        swap(cardRanks[i], cardRanks[j]);
                        swap(cardSuits[i], cardSuits[j]);
                    }
                }
            }
        }

        void countRanks() {
            memset(rankCounts, 0, sizeof rankCounts);
            FOR(i,0,5) {
                rankCounts[cardRanks[i]]++;
            }
        }

        UC getNumberOfRanksWithCount(UC count) {
            UC cnt = 0;

            FOR(i,0,15) {
                if (rankCounts[i] == count) {
                    cnt++;
                }
            }

            return cnt;
        }

        UC getRankWithCount(UC count) {
            FOR(i,0,15) {
                if (rankCounts[i] == count) {
                    return i;
                }
            }

            return 0;
        }

        bool continues() {
            FOR(i,1,5) {
                if (
                    cardRanks[i - 1] + 1 != cardRanks[i]
                    && !(cardRanks[i - 1] == 5 && cardRanks[i] == 14) // straight A2345
                ) {
                    return false;
                }
            }

            return true;
        }

        bool sameSuit() {
            FOR(i,1,5) {
                if (cardSuits[i - 1] != cardSuits[i]) {
                    return false;
                }
            }

            return true;
        }

    public:
        pokerHand() {
            cardCount = 0;
        }

        void addCard(char rank, char suit) {
            UC r, s;

            switch (suit) {
                case 'C': case 'c': s = 0; break;
                case 'D': case 'd': s = 1; break;
                case 'H': case 'h': s = 2; break;
                case 'S': case 's': s = 3; break;
            }

            switch (rank) {
                case 'A': r = 14; break;
                case 'K': r = 13; break;
                case 'Q': r = 12; break;
                case 'J': r = 11; break;
                case 'T': r = 10; break;
                default: r = (rank - '0'); break;
            }

            cardRanks[cardCount] = r;
            cardSuits[cardCount] = s;
            cardCount++;
        }

        UI getHandStrength() {
            sortByRank();
            countRanks();
            bool areContinues = continues();
            bool haveSameSuit = sameSuit();
            bool has4ofAkind = getNumberOfRanksWithCount(4);
            bool has3ofAkind = getNumberOfRanksWithCount(3);
            UC numberOfPairs = getNumberOfRanksWithCount(2);

            UI handClass, strengthWithinClass;
            if (areContinues && haveSameSuit && cardRanks[0] == 10) {
                // Royal Flush
                handClass = 11;
                strengthWithinClass = 0;
            } else if (areContinues && haveSameSuit) {
                // Straight Flush
                handClass = 10;
                if (cardRanks[4] == 14 && cardRanks[0] == 2) {
                    strengthWithinClass = 0;
                } else {
                    strengthWithinClass = cardRanks[0];
                }
            } else if (has4ofAkind) {
                // Four of a Kind
                handClass = 9;
                strengthWithinClass = (((UI)getRankWithCount(4)) << 5);
                strengthWithinClass |= getRankWithCount(1);
            } else if (has3ofAkind && numberOfPairs == 1) {
                // Full House
                handClass = 8;
                strengthWithinClass  = (((UI)getRankWithCount(3)) << 5);
                strengthWithinClass |= getRankWithCount(2);
            } else if (haveSameSuit) {
                // Flush
                handClass = 7;
                strengthWithinClass = 0;
                for (int i = 4; i >= 0; i--) {
                    strengthWithinClass |= cardRanks[i];
                    strengthWithinClass <<= 4;
                }
            } else if (areContinues) {
                // Straight
                handClass = 6;
                if (cardRanks[4] == 14 && cardRanks[0] == 2) {
                    strengthWithinClass = 0;
                } else {
                    strengthWithinClass = cardRanks[0];
                }
            } else if (has3ofAkind) {
                // Three of a Kind
                handClass = 5;
                UI threeOfaKindRank = getRankWithCount(3);
                strengthWithinClass = (threeOfaKindRank << 10);
                for (int i = 4; i >= 0; i--) {
                    if (cardRanks[i] == threeOfaKindRank) {
                        continue;
                    }

                    strengthWithinClass |= cardRanks[i];
                    strengthWithinClass <<= 4;
                }
            } else if (numberOfPairs == 2) {
                // Two Pairs
                handClass = 4;
                UC highCard = getRankWithCount(1);
                strengthWithinClass = 0;
                for (int i = 4; i >= 0; i--) {
                    if (cardRanks[i] == highCard) {
                        continue;
                    }

                    strengthWithinClass |= cardRanks[i];
                    strengthWithinClass <<= 4;
                }
                strengthWithinClass |= highCard;
            } else if (numberOfPairs == 1) {
                // One Pair
                handClass = 3;
                UC pair = getRankWithCount(2);
                strengthWithinClass = pair;
                strengthWithinClass <<= 4;
                for (int i = 4; i >= 0; i--) {
                    if (cardRanks[i] == pair) {
                        continue;
                    }

                    strengthWithinClass |= cardRanks[i];
                    strengthWithinClass <<= 4;
                }
            } else {
                // High Card
                handClass = 2;
                strengthWithinClass = 0;
                for (int i = 4; i >= 0; i--) {
                    strengthWithinClass |= cardRanks[i];
                    strengthWithinClass <<= 4;
                }
            }

            UI strength = (handClass << 25) + strengthWithinClass;
            return strength;
        }

        UI getHandClass() {
            return (getHandStrength() >> 25);
        }
};

void assertEqualsUI(UI expect, UI got) {
    static UI test = 0;
    test++;

    if (expect != got) {
        cout << "assertEquals :: error on test " << test << " :: expecting " << expect << " :: got " << got << endl;
    }
}

pokerHand handFromString(const char *str) {
    pokerHand hand;
    F(i,10) {
        hand.addCard(str[i], str[i + 1]);
        i++;
    }

    return hand;
}

UI getHandClass(const char *str) {
    return handFromString(str).getHandClass();
}

UI getHandStrength(const char *str) {
    return handFromString(str).getHandStrength();
}

void testPokerHandClassResolution() {
    // Royal flushes
    assertEqualsUI(11, getHandClass("AdKdQdJdTd"));
    assertEqualsUI(11, getHandClass("KdAdQdTdJd"));

    // Straight flushes
    assertEqualsUI(10, getHandClass("KdQdTdJd9d"));
    assertEqualsUI(10, getHandClass("5d6d4d3d2d"));
    assertEqualsUI(10, getHandClass("5d4dAd3d2d"));

    //Four of a Kind
    assertEqualsUI(9, getHandClass("2d2c2s2dAs"));
    assertEqualsUI(9, getHandClass("2d2cAs2s2d"));

    // Full House
    assertEqualsUI(8, getHandClass("AdKcKsAcAs"));

    // Flush
    assertEqualsUI(7, getHandClass("3d5d7d9dJd"));

    // Straight
    // -- 10 --
    assertEqualsUI(6, getHandClass("5d4dAs3d2d"));

    // Three of a Kind
    assertEqualsUI(5, getHandClass("5d5h5s3d2d"));

    // Two Pairs
    assertEqualsUI(4, getHandClass("5d5h2s3d2d"));
    assertEqualsUI(4, getHandClass("KdKcQdQhAs"));

    // One Pair
    assertEqualsUI(3, getHandClass("5d5hJs3d2d"));

    // High card
    assertEqualsUI(2, getHandClass("Kd5hJs3d2d"));
}

void testPokerHandStrengths() {
    // 1
    assertTrue(getHandStrength("Kd5hJs3d2d") > getHandStrength("Kd5hTs3d2d"));
    assertTrue(getHandStrength("Kd5hJs3d2d") > getHandStrength("Kd4hJs3d2d"));
    assertTrue(getHandStrength("TdTs3s4h5d") > getHandStrength("TdTs2s4h5d"));
    assertTrue(getHandStrength("JdJs3s4h5d") > getHandStrength("TdTs3s4h5d"));
    assertTrue(getHandStrength("AdAs3s4h5d") > getHandStrength("TdTs3s4h5d"));

    // 6
    assertTrue(getHandStrength("AdAs3s3h5d") > getHandStrength("AdAs3s3h2d"));
    assertTrue(getHandStrength("AdAs4s4h5d") > getHandStrength("AdAs3s3hKd"));
    assertTrue(getHandStrength("AdAs4s4h5d") > getHandStrength("KdKsQsQhAd"));
    assertTrue(getHandStrength("AdAsAs4h5d") > getHandStrength("AdAsAc5h3d"));
    assertTrue(getHandStrength("AdKsQhJcTd") > getHandStrength("Ad2s3h4c5d"));

    // 11
    assertTrue(getHandStrength("6d2s3h4c5d") > getHandStrength("Ad2s3h4c5d"));
    assertTrue(getHandStrength("AhKhQhJh8h") > getHandStrength("AhKhQhJh7h"));
    assertTrue(getHandStrength("Ah2hQhJh8h") > getHandStrength("Ah2hQhJh7h"));
    assertTrue(getHandStrength("AhAcAdAsKc") > getHandStrength("AhAcAdAsQc"));
    assertTrue(getHandStrength("AhAcAdAs2c") > getHandStrength("AhKcKdKsKc"));

    // 16
    assertTrue(getHandStrength("6d2d3d4d5d") > getHandStrength("Ad2d3d4d5d"));
    assertTrue(getHandStrength("AdKdQdJdTd") > getHandStrength("Ad2d3d4d5d"));
}

void testPokerHand() {
    testPokerHandClassResolution();
    testPokerHandStrengths();
}

pokerHand readHand(ifstream &in) {
    pokerHand hand;
    F(j,5) {
        char c[3];
        in >> c;
        hand.addCard(c[0], c[1]);
    }

    return hand;
}

UI solve054() {
    //testPokerHand();

    UI playerOneWins = 0;
    ifstream in("poker.txt");
    F(i,1000) {
        pokerHand h1 = readHand(in);
        pokerHand h2 = readHand(in);
        if (h1.getHandStrength() > h2.getHandStrength()) {
            playerOneWins++;
        }
    }

    return playerOneWins;
}

int main() {
    cout << solve054();
    return 0;
}
