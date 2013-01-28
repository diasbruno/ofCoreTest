#pragma once

#include "cpptest.h"

#include <limits>
#include "ofSystemUtils.h"

using namespace std;

class ofSystemUtils_Suite 
	: public Test::Suite {
public:
	
    ofSystemUtils_Suite() { 
        TEST_ADD( ofSystemUtils_Suite::test_of_system_alert_dialog_scenario    )
		TEST_ADD( ofSystemUtils_Suite::test_of_system_text_box_dialog_scenario )
    }
		
	string dialog_error_message;
	string encoding_string_a;
	
protected:
	
    void     setup() {
		dialog_error_message = "Test dialog error message.";
		encoding_string_a = "Esse é um exemplo de texto";
	}
    void tear_down() {
		dialog_error_message.clear();
		encoding_string_a.clear();
	}
	
private:
	
    void test_of_system_alert_dialog_scenario() {
		ofSystemAlertDialog( dialog_error_message );
	}
	void test_of_system_load_dialog_scenario() {
		ofSystemAlertDialog( dialog_error_message );
	}
	void test_of_system_save_dialog_scenario() {
		ofSystemAlertDialog( dialog_error_message );
	}
	void test_of_system_text_box_dialog_scenario() {
		string result;
		
		result = ofSystemTextBoxDialog( "Just hit ok." , encoding_string_a );
		TEST_ASSERT( result == encoding_string_a );
	}
};
/*!
void ofSystemAlertDialog(string errorMessage);
ofFileDialogResult ofSystemLoadDialog(string windowTitle="", bool bFolderSelection = false, string defaultPath="");
ofFileDialogResult ofSystemSaveDialog(string defaultName, string messageName);
string ofSystemTextBoxDialog(string question, string text="");
 */