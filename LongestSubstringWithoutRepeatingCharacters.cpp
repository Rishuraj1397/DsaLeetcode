#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;  // Map to store the last index of each character
        int maxLength = 0;                    // Variable to store the maximum length of substring
        int start = 0;                        // Left pointer for the current window

        for (int end = 0; end < s.length(); ++end) {
            // If the character is already in the map and is within the current window
            if (charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start) {
                start = charIndex[s[end]] + 1;  // Move the start pointer to the right of the last seen index
            }

            charIndex[s[end]] = end;  // Update the last seen index of the character
            maxLength = max(maxLength, end - start + 1);  // Update the maximum length
        }

        return maxLength;  // Return the maximum length of substring found
    }
};


