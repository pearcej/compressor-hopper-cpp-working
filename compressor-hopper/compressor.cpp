// ------------------------------------------------------------------------
// Name: Compressor
// Purpose: It defines a class called Compressor that interacts with a Hopper to compress coal and make diamonds.
//
// Created: 09/06/2018

#include <iostream>
#include <string>
using namespace std;

class Compressor {
    /* This class defines a crusher object that will take coal from a hopper object and compresses it to make diamonds */
    private:
        int DIAMOND_CHANCES = 5;  // the chance that a diamond will form is CONSTANT to ALL compressors 
        int CAPACITY = 10;  // All compressors have the same CAPACITY
    
    public:
        int number_diamonds;
        int number_compressed;
        bool full = false;
        Compressor() {
            number_diamonds = 0;
            number_compressed = 0;
        }

        void get_coal(Hopper in_hopper) {
          /* pre: in_hopper is an object of type of Hopper
             post: the amount of coal in in_hopper is decreased and this object is set to be full so that it will compress. */

            if (in_hopper.amount_coal() > this->CAPACITY){
                in_hopper.drain_coal(this->CAPACITY);  // call the method to subtract coal
                this->full = true;
            }
        }

        void compress() {
          /*post: if the compressor is full, it compresses it and     possibly creates a diamond.
            number_compressed is incremented, and the compressor is set to no longer be full. */
            if (this->full){
                this->number_compressed = this->number_compressed + 1;
                // now check to see if we can make a diamond
                if ( rand() % 101 < this->DIAMOND_CHANCES ){
                    this->number_diamonds = this->number_diamonds + 1;
                }
            }
            this->full = false; // Now that we compressed, we are empty
        }

        string __str__() {
            /* String representation
            post: returns the string with the amount of diamonds */
            string numberDiamonds = to_string(this->number_diamonds);
            string numberCompressed = to_string(this->number_compressed);
            return "The compressor has made " + numberDiamonds + " diamonds compressing " + numberCompressed + " loads of coal.";
        }
};