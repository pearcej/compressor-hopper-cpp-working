// compressor-hopper.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.
//---------------------------------------------------------------------------------------
// Name: compressor-hopper.cpp
// Purpose: The main() function exists in this file for the program that uses
//          the Compressor and Hopper classes in the compressor.cpp and hopper.cpp files
//          in the same directory.
//
// Created: 09/08/2018 by Dr. Jan Pearce and Dostonbek Toirov, Berea College
// Original idea implemented in Python by Dr. Mario Nakazawa, Berea College
//---------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Hopper {
	/* A Hopper class, which contains coal */

	const int MAX_CAPACITY = 100; // how much coal any Hopper can hold

private:
	int coal;

public:
	Hopper(); //constructor
	void fill_coal(); //post: refill the hopper to MAX_CAPACITY		
	int get_coal(); //access the amount of coal in this hopper
	void drain_coal(int drain_amount); //post: the amount of coal in this hopper is decreased by the drain_amount only if there is enough to drain */
	friend ostream &operator << (ostream &stream, Hopper hopper);
};

class Compressor {
	/* This class defines a crusher object that will take coal from a hopper object and compresses it to make diamonds */

	//FIXME: IMPORTANT!
	// srand(time(NULL)); //uncomment and include this as the first line in main() 

	const int MAX_CAPACITY = 100; // how much coal any Hopper can hold
	const int DIAMOND_CHANCES = 5;  // the chance that a diamond will form is CONSTANT to ALL compressors 
	const int CAPACITY = 10;  // All compressors have the same CAPACITY

public:
	Compressor();  //Constructor
	void use_coal(Hopper &in_hopper);
	void compress();
	int get_number_diamonds();
	int get_number_compressed();
	friend ostream &operator << (ostream& stream, Compressor mycompress);

private:
	int number_diamonds;
	int number_compressed;
	bool full;
};


int main() {
	srand(time(NULL));			//needed by the Compressor class
	Compressor thecompressor;   // create a Compressor object
	Hopper thehopper;           // create a Hopper object 
	thehopper.fill_coal();      // fill out the Hopper object with coal

	// loop through and have the Compressor object take coal out of the Hopper
	// and compress it.
	for (int i = 0; i < 10; i++) {
		cout << thehopper << endl;
		thecompressor.use_coal(thehopper);
		thecompressor.compress();
	}
	cout << thecompressor << endl;
	return 0;
}

//---------------------------------------------------------------------
// Hopper class functions begin here
//---------------------------------------------------------------------
	Hopper::Hopper() {
		coal = MAX_CAPACITY;
	}

	void Hopper::fill_coal() {
		/* post: refill the hopper to MAX_CAPACITY*/
		this->coal = MAX_CAPACITY;
	}

	int Hopper::get_coal() {
		/* access the amount of coal in this hopper */
		return this->coal;
	}

	void Hopper::drain_coal(int drain_amount) {
		/* post: the amount of coal in this hopper is decreased by the drain_amount only if there is enough to drain */
		if (this->coal > drain_amount) {
			this->coal = this->coal - drain_amount;
		}
	}

	ostream &operator<<(ostream& stream, Hopper hopper) {
		/* convert the information of this hopper into a string */
		stream << "The hopper contains " << hopper.get_coal() << " pounds of coal.";
		return stream;
	}
	//---------------------------------------------------------------------
// Compressor class functions begin here
//---------------------------------------------------------------------
		Compressor::Compressor() {
			number_diamonds = 0;
			number_compressed = 0;
			full = false;
		}

		void Compressor::use_coal(Hopper &in_hopper) {
			/* pre: in_hopper is an object of type of Hopper
			   post: the amount of coal in in_hopper is decreased and this object is set to be full so that it will compress. */

			if (in_hopper.get_coal() >= this->CAPACITY) {
				in_hopper.drain_coal(this->CAPACITY);  // call the method to subtract coal
				this->full = true;
			}
		}

		void Compressor::compress() {
			/*post: if the compressor is full, it compresses it and possibly creates a diamond.
			  number_compressed is incremented, and the compressor is set to no longer be full. */
			  /* initialize random seed: */
			int random_variable= rand();
			random_variable = rand();
			if (this->full) {
				this->number_compressed = this->number_compressed + 1;
				// now check to see if we can make a diamond
				random_variable = rand();
				if (random_variable % 8 <= this->DIAMOND_CHANCES) {
					this->number_diamonds = this->number_diamonds + 1;
					cout << "A diamond was created!" << endl;
				}
				else {
					cout << "Sorry, diamond creation failed." << endl;
				}
			}
			this->full = false; // Now that we compressed, we are empty
		}

		int Compressor::get_number_diamonds() {
			return this->number_diamonds;
		};

		int Compressor::get_number_compressed() {
			return this->number_compressed;
		};


		ostream &operator << (ostream &stream, Compressor mycompress) {
			//post: returns the string with the amount of diamonds */
			stream << "The compressor has made " << mycompress.get_number_diamonds() << " diamonds compressing " << mycompress.get_number_compressed() << " loads of coal.";
			return stream;
		}


	