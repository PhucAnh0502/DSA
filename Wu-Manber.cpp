// C++ code to implement the above approach
#include <bits/stdc++.h>
using namespace std;

// Generate a hash for each subpattern
int HashPattern(string& pattern, int i, int j)
{
	int h = 0;
	for (int k = i; k < j; k++) {
		h = h * 256 + ((int)pattern[k] - 'a');
	}
	return h;
}

// Wu Manber algorithm
void WuManber(string& text, string& pattern)
{
	// Define the length of the pattern and text
	int m = pattern.length();
	int n = text.length();

	// Define the number of subpatterns to use
	int s = 2;

	// Define the length of each subpattern
	int t = m / s;

	// Initialize the hash values for each subpattern
	int h[s];
	for (int i = 0; i < s; i++) {
		h[i] = HashPattern(pattern, i * t, (i + 1) * t);
	}

	// Initialize the shift value for each subpattern
	int shift[s];
	for (int i = 0; i < s; i++) {
		shift[i] = t * (s - i - 1);
	}

	// Initialize the match value
	bool match = false;

	// Iterate through the text
	for (int i = 0; i < n - m + 1; i++) {
		// Check if the subpatterns match
		bool subpatternsMatch = true;
		int j;

		for (j = 0; j < s; j++) {
			if (HashPattern(text, i + j * t,
							i + (j + 1) * t)
				!= h[j]) {
				subpatternsMatch = false;
				break;
			}
		}

		if (subpatternsMatch) {
			// If the subpatterns match, check if the
			// full pattern matches
			if (text.substr(i, m) == pattern) {
				cout << "Match found at index " << i
					<< endl;
				match = true;
			}
		}

		// Shift the pattern by the appropriate amount
		bool shouldShift = true;
		for (j = 0; j < s; j++) {
			if (i + shift[j] < n - m + 1) {
				shouldShift = false;
				break;
			}
		}

		if (shouldShift) {
			i += shift[j];
		}
	}

	// If no match was found, print a message
	if (!match) {
		cout << "No match found \n";
	}
}

int main()
{

	// Code
	string text = "the cat sat on the mat";
	string pattern = "the";

	WuManber(text, pattern);
	return 0;
}

