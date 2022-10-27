#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<vector<int>> readShuffles();
vector<int> createDeck();
void applyShuffleToDeck(vector<int> &deck, const vector<int> &shuffle);
void printDeck(const vector<int> &deck);

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        auto shuffles = readShuffles();
        auto deck = createDeck();

        for (string line; getline(cin, line) && !line.empty();)
        {
            int m = stoi(line);
            applyShuffleToDeck(deck, shuffles[m - 1]);
        }

        if (test != 0)
        {
            cout << "\n";
        }

        printDeck(deck);
    }
}

vector<vector<int>> readShuffles()
{
    int n;
    cin >> n;
    vector<vector<int>> shuffles(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> deck(52);
        for (int j = 0; j < 52; j++)
        {
            cin >> deck[j];
        }
        shuffles[i] = deck;
    }
    cin.ignore(1024, '\n');
    return shuffles;
}

vector<int> createDeck()
{
    vector<int> deck(52);
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i + 1;
    }
    return deck;
}

void applyShuffleToDeck(vector<int> &deck, const vector<int> &shuffle)
{
    vector<int> temp(sz(deck));
    for (int i = 0; i < sz(deck); i++)
    {
        temp[i] = deck[shuffle[i] - 1];
    }
    deck = temp;
}
void printDeck(const vector<int> &deck)
{
    static const vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    static const vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    for (auto card : deck)
    {
        cout << ranks[(card - 1) % 13] << " of " << suits[(card - 1) / 13] << endl;
    }
}