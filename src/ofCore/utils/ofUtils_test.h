#pragma once

#include "cpptest.h"

#include <limits>
#include "ofMain.h"

using namespace std;

class ofUtils_DateTime_Suite
	: public Test::Suite {
public:
	
    ofUtils_DateTime_Suite() { 
        TEST_ADD( ofUtils_DateTime_Suite::test_get_hours )
    }
	
	tm local;
		
protected:
	
    void     setup() {
		time_t 	curr;
		time(&curr);
		local = *(localtime(&curr));
	}
    void tear_down() {

	}
	
private:
	
    void test_get_hours() {
		TEST_ASSERT( ofGetHours() == local.tm_hour )
	}
};

/*!
void	ofResetElapsedTimeCounter();		// this happens on the first frame
float 	ofGetElapsedTimef();
unsigned long long ofGetElapsedTimeMillis();
unsigned long long ofGetElapsedTimeMicros();
int 	ofGetFrameNum();

int 	ofGetSeconds();
int 	ofGetMinutes();
int 	ofGetHours();

//number of seconds since 1970
unsigned int ofGetUnixTime();

unsigned long long ofGetSystemTime( );			// system time in milliseconds;
unsigned long long ofGetSystemTimeMicros( );			// system time in microseconds;

//returns 
string ofGetTimestampString();
string ofGetTimestampString(string timestampFormat);


int     ofGetYear();
int     ofGetMonth();
int     ofGetDay();
int     ofGetWeekday();
 */