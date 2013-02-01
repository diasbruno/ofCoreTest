#pragma once

#include "cpptest.h"

#include <limits>
#include "ofMain.h"

using namespace std;

class ofUtils_DateTimeFrame_Suite
: public Test::Suite {
public:
	
    ofUtils_DateTimeFrame_Suite() { 
        TEST_ADD( ofUtils_DateTimeFrame_Suite::test_get_hour                   )
		TEST_ADD( ofUtils_DateTimeFrame_Suite::test_get_minutes                )
		TEST_ADD( ofUtils_DateTimeFrame_Suite::test_get_seconds                )
		TEST_ADD( ofUtils_DateTimeFrame_Suite::test_reset_elapsed_time_counter )
		TEST_ADD( ofUtils_DateTimeFrame_Suite::test_get_frame_num              )
    }
	
	time_t current;
	tm local;
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
	/*!
	 NOTE: must update the time before each test.
	 */
	void updateTime() {
		time(&current);
		local = *(localtime(&current));		
	}	
	
    void test_get_hour() {
		updateTime();
		TEST_ASSERT( ofGetHours() == local.tm_hour )
	}
	void test_get_minutes() {	
		updateTime();
		TEST_ASSERT( ofGetMinutes() == local.tm_min )
	}
	void test_get_seconds() {	
		updateTime();
		TEST_ASSERT( ofGetSeconds() == local.tm_sec )
	}
	void test_reset_elapsed_time_counter() {
		ofResetElapsedTimeCounter();
		TEST_ASSERT( ofGetElapsedTimef() == 0 )
	}
	void test_get_system_time() {
		updateTime();
		TEST_ASSERT( ofGetSystemTime() == 0 )
	}
	void test_get_frame_num() {
		// Get frame num depends on a window.
		//ofResetElapsedTimeCounter();
		//TEST_ASSERT( ofGetFrameNum() == 0 )
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