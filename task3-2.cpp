#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std::chrono;


bool bubbleSort(std::vector<int> &in, std::vector<int> &out) {
    int i = 0, j = 0;

    for (i = 0; i < in.size(); i++) {
        out.push_back(in[i]);
    } // copy to output vector

    for (i = 0; i < out.size() - 1; i++) {
        for (j = 0; j < out.size() - i - 1; j++) {
            if (out[j] > out[j+1]) { // swap
                int temp = out[j];
                out[j] = out[j+1];
                out[j+1] = temp;
            }
        }
    }

    return true;
}

bool testBubbleSort(int size) {
    int i = 0, j = 0;
    std::vector<int> input;
    std::vector<int> output;
    
    for (i = 0; i < size; i++) {
        input.push_back(rand() % 100 + 1);
    }
    sort(input.begin(), input.end());
    input.push_back(23);
 
    bubbleSort(input, output);

    sort(input.begin(), input.end());

    for (i = 0; i < input.size(); i++) {
        if (input[i] != output[i]) {
            return false;
        } // compare if both are equal
    }

    return true;

}


int main(int argc, char *argv[])
{
    std::vector<int> numbers = { 3, 5, 12, 24, 25, 27, 15 };
    std::vector<int> out;
    
    int i = 0;

    bool rc = testBubbleSort(10);
    rc = testBubbleSort(100);
    rc = testBubbleSort(1000);
    rc = testBubbleSort(10000);

    std::cerr << "Processing...\n";
    auto start = high_resolution_clock::now();

    rc = testBubbleSort(100000);

    auto stop = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(stop - start);
    // print it in seconds
    // Here I manually mulitplied it by 100 instead of running for 100 times because my computer could not handle it
    std::cerr << (double)((duration2.count() * 100) / 1000000) << " seconds for 100 cases" << "\n";
    return 0;
}
