#include <iostream>
#include <vector>
#include <algorithm>


bool moveMin(std::vector<int> &in, std::vector<int> &out) {
    int i = 0, j = 0;
    // copy array into output array
    for (i = 0; i < in.size(); i++) {
        out.push_back(in[i]);
    }

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

bool testMoveMin() { // to test the mov Min func
    int i = 0, j = 0;
    std::vector<int> input;
    std::vector<int> output;
    
    for (i = 0; i < 20; i++) {
        input.push_back(rand() % 100 + 1);
    } // random array

    sort(input.begin(), input.end()); // sort it

    input.push_back(23); // push random value to it

    moveMin(input, output); // send to mov Min 

    sort(input.begin(), input.end()); // sort it again

    for (i = 0; i < input.size(); i++) {
        if (input[i] != output[i]) {
            return false;
        }
    } // compare with original

    return true;

}


int main(int argc, char *argv[])
{
    std::vector<int> numbers = { 3, 5, 12, 24, 25, 27, 15 };
    std::vector<int> out;
    bool rc = moveMin(numbers, out); // sanity check
    rc = testMoveMin(); // test the mov Min funct
    if (rc == 1)
        std::cout << "The arrays match completely!\n";
    else
        std::cout << "The arrays do not match.\n";
    return 0;
}

