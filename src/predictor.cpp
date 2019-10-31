//========================================================//
//  predictor.c                                           //
//  Source file for the Branch Predictor                  //
//                                                        //
//  Implement the various branch predictors below as      //
//  described in the README                               //
//========================================================//
#include <stdio.h>
#include "predictor.h"

//slice 
#include <vector>
#include <numeric>
#include <iostream>
//
using namespace std;
// TODO:Student Information
//
const char *studentName = "Justin Law";
const char *studentID   = "A12346613";
const char *email       = "jklaw@ucsd.edu";

//------------------------------------//
//      Predictor Configuration       //
//------------------------------------//

// Handy Global for use in output routines
const char *bpName[4] = { "Static", "Gshare",
                          "Tournament", "Custom" };

int ghistoryBits; // Number of bits used for Global History
int lhistoryBits; // Number of bits used for Local History
int pcIndexBits;  // Number of bits used for PC index
int bpType;       // Branch Prediction Type
int verbose;

// recall in class that the professor used the passing of a function into a class.

// so we had a function that was called every time 

struct Register
{
  Register(int value, int size_bits) : _bitvector(value),_overflow_value(1<<size_bits), size_reg(size_bits) {}

  Register& addHistory(bool bit) {
		// history bit is 1 if taken, 0 if not taken
		bool history_bit = 1 ? (bit==TAKEN) : NOTTAKEN;
    _bitvector = (_bitvector << 1) + history_bit;
    bool overflow = 1 ? (_bitvector >= _overflow_value) : 0;
    if (overflow) {
			_bitvector ^= _overflow_value;
    }

    return *this;
  }

  int get() const {
    return _bitvector;
  }

  int size() const {
		return this->size_reg;
  }

  protected:
    int _bitvector;
    int _overflow_value;
    int size_reg;
};

struct twoBitSatCounter 
{
	twoBitSatCounter(int initial=WN) {
		_counter = initial;
	}

	twoBitSatCounter& operator++(int) {
		if((_counter) != ST) {	
			_counter++;
		}

		return *this;
	}

	twoBitSatCounter& operator--(int) {
		if((_counter) != WN) {	
			_counter--;
		}

		return *this;
	}

	int get() {
		return _counter;
	}

	int set(int value) {
		_counter = value;
		return _counter;
	}

	protected:
		int _counter;
};

void take(int index, int nbits) {
	size_bits = sizeof(index) << 3; // sizeof is in bytes
	// eg say size_Bits = 4 and bits=1. 4 bit number want 0th bit. Shift by 3 to right and shift back.
	return (index << (size_bits - nbits)) >> (size_bits - nbits);
}

void test()
{
	int value = 5;
	Register testReg = Register(value, 3);
	
	std::cout << testReg.get() << '\n';
	testReg.addHistory(NOTTAKEN);
	std::cout << testReg.get() << '\n';
	testReg.addHistory(TAKEN);
	std::cout << testReg.get() << '\n';
	testReg.addHistory(TAKEN);
	std::cout << testReg.get() << '\n';
	testReg.addHistory(TAKEN);
	std::cout << testReg.get() << '\n';
	
	std::cout << "sat counter tests" << '\n';
	twoBitSatCounter testCnt = twoBitSatCounter(WN); 
	std::cout << testCnt.get() << '\n';
	testCnt++;
	std::cout << testCnt.get() << '\n';
	testCnt++;
	std::cout << testCnt.get() << '\n';
	testCnt++;
	std::cout << testCnt.get() << '\n';
	testCnt++;
	std::cout << testCnt.get() << '\n';

	testCnt = twoBitSatCounter(ST);
	std::cout << testCnt.get() << '\n';
	testCnt--;
	std::cout << testCnt.get() << '\n';
	testCnt--;
	std::cout << testCnt.get() << '\n';
	testCnt--;
	std::cout << testCnt.get() << '\n';
}

//      Predictor Data Structures     //
//------------------------------------//

//
//TODO: Add your own Branch Predictor data structures here
//


//------------------------------------//
//        Predictor Functions         //
//------------------------------------//

// Initialize the predictor
//
void
init_predictor()
{
	test();
  //
  //TODO: Initialize Branch Predictor Data Structures
  //
  
}

// Make a prediction for conditional branch instruction at PC 'pc'
// Returning TAKEN indicates a prediction of taken; returning NOTTAKEN
// indicates a prediction of not taken
//
uint8_t
make_prediction(uint32_t pc)
{
  //
  //TODO: Implement prediction scheme
  //

  // Make a prediction based on the bpType
  switch (bpType) {
    case STATIC:
      return TAKEN;
    case GSHARE:
    case TOURNAMENT:
    case CUSTOM:
    default:
      break;
  }

// If there is not a compatable bpType then return NOTTAKEN
  return NOTTAKEN;
}

// Train the predictor the last executed branch at PC 'pc' and with
// outcome 'outcome' (true indicates that the branch was taken, false
// indicates that the branch was not taken)
//
void
train_predictor(uint32_t pc, uint8_t outcome)
{
  //
  //TODO: Implement Predictor training
  //
}
