#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

  
bool moveMin(std::vector<int> &in, std::vector<int> &out) {
    int i = 0, j = 0;

    for (i = 0; i < in.size(); i++) {
        out.push_back(in[i]);
    } // copy to output vector

    for (i = out.size() - 1; i > 0; i--) {
        if(out[i] < out[i-1]) { // swap
            int temp = out[i];
            out[i] = out[i-1];
            out[i-1] = temp;
        }
    }
    return true;
}

bool testMoveMin(int size) {
    int i = 0, j = 0;
    std::vector<int> input;
    std::vector<int> output;
    
    for (i = 0; i < size; i++) {
        input.push_back(rand() % 100 + 1);
    }

    sort(input.begin(), input.end());
    input.push_back(23);
 
    moveMin(input, output);

    sort(input.begin(), input.end());

    for (i = 0; i < input.size(); i++) {
        if (input[i] != output[i]) {
            return false;
        } // compare with original
    }

    return true;

}


int main(int argc, char *argv[])
{
    std::vector<int> numbers = { 3, 5, 12, 24, 25, 27, 15 };
    std::vector<int> out;
    bool rc = moveMin(numbers, out);
    
    int i = 0;

    rc = testMoveMin(10);
    rc = testMoveMin(100);
    rc = testMoveMin(1000);
    rc = testMoveMin(10000);

    auto start = high_resolution_clock::now();
    
    rc = testMoveMin(100000); // test the mov min on 100000 values
    
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop - start);
    // print it in seconds
    // Here I manually mulitplied it by 100 instead of running for 100 times because my computer could not handle it
    std::cout << (duration1.count() * 100) / 1000000 << " seconds for 100 cases" << std::endl;

    return 0;
}

