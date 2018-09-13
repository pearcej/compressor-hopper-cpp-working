//-----------------------------------------------------------------------------
// Name: hopper.cpp
// Purpose: It defines a hopper object that contains some coal.
//
// Created: 09/06/2018
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class Hopper {
    /* A Hopper class, which contains coal */

    private:
        int MAX_CAPACITY = 100; // how much coal any HOPPER can hold

    public:
        int coal;
        Hopper (){
            /* post: this object will have no coal in it.*/
            coal = 0;
        }

        void fill_coal(){
            /* post: refill the hopper to MAX_CAPACITY*/
            this->coal = this->MAX_CAPACITY;
        }

        int amount_coal(){
            /* access the amount of coal in this hopper */
            return this->coal;
        }

        void drain_coal(int drain_amount) {
            /* post: the amount of coal in this hopper is decreased by the drain_amount only if there is enough to drain */
            if (this->coal > drain_amount) {
                this->coal = this->coal - drain_amount;
            }
        }

        string __str__() {
            /* convert the information of this hopper into a string */
            string output = to_string(this->amount_coal());
            return "hopper contains " + output + "pounds of coal";
        }
};
