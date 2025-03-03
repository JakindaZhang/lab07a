#include <iostream>
#include <sstream>
#include "WordCount.h"

using namespace std;

void runTests() {
    WordCount wc;
    
    cout << "Test 1: Incrementing word count\n";
    cout << "Adding 'Hello': " << wc.incrWordCount("Hello") << " (expected 1)\n";
    cout << "Adding 'hello' again: " << wc.incrWordCount("hello") << " (expected 2)\n";
    cout << "Adding 'HELLO' (case insensitive): " << wc.incrWordCount("HELLO") << " (expected 3)\n";
    
    cout << "\nTest 2: Retrieving word count\n";
    cout << "Count of 'hello': " << wc.getWordCount("hello") << " (expected 3)\n";
    cout << "Count of 'world' (not added): " << wc.getWordCount("world") << " (expected 0)\n";

    cout << "\nTest 3: Decrementing word count\n";
    cout << "Decreasing 'Hello': " << wc.decrWordCount("Hello") << " (expected 2)\n";
    cout << "Decreasing 'hello' again: " << wc.decrWordCount("hello") << " (expected 1)\n";
    cout << "Decreasing 'HELLO' (should remove it): " << wc.decrWordCount("HELLO") << " (expected 0)\n";
    cout << "Decreasing 'HELLO' again (does not exist): " << wc.decrWordCount("HELLO") << " (expected -1)\n";

    wc.incrWordCount("test");
    wc.incrWordCount("word");
    wc.incrWordCount("count");
    wc.incrWordCount("word");
    cout << "\nTest 4: Unique and total word count\n";
    cout << "Unique words: " << wc.getNumUniqueWords() << " (expected 3)\n";
    cout << "Total words: " << wc.getTotalWords() << " (expected 4)\n";

    cout << "\nTest 5: Parsing words from text\n";
    string sampleText = "This is a simple test. Can't we test it? Yes, we can!";
    wc.addAllWords(sampleText);
    cout << "Total words after adding sentence: " << wc.getTotalWords() << " (expected 11)\n";
    cout << "Unique words after adding sentence: " << wc.getNumUniqueWords() << " (expected 8)\n";

    cout << "\nTest 6: Sorting words by word order\n";
    cout << "Words sorted by word (descending lexicographically):\n";
    wc.dumpWordsSortedByWord(cout);

    cout << "\nTest 7: Sorting words by occurrence order\n";
    cout << "Words sorted by occurrence:\n";
    wc.dumpWordsSortedByOccurence(cout);
}

int main() {
    runTests();
    return 0;
}
