#pragma once

#include "cpptest.h"
#include "_ofVec.h"

class ofVec4T_Suite : public Test::Suite {
public:
	
    ofVec4T_Suite() 
    { 
        TEST_ADD( ofVec4T_Suite::test_creation )
		TEST_ADD( ofVec4T_Suite::test_array_access )
		TEST_ADD( ofVec4T_Suite::test_pointer_access )
		TEST_ADD( ofVec4T_Suite::test_sets_equality )
		TEST_ADD( ofVec4T_Suite::test_operations )
    }
    
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
	_ofVec4i v4i;
    _ofVec4f v4f;
	_ofVec4d v4d;
	
    void test_creation() {
		TEST_ASSERT( v4i.x == 0 )
        TEST_ASSERT( v4i.y == 0 )
		TEST_ASSERT( v4i.z == 0 )
        TEST_ASSERT( v4i.w == 0 )
		
		TEST_ASSERT( v4f.x == 0 )
        TEST_ASSERT( v4f.y == 0 )
		TEST_ASSERT( v4f.z == 0 )
        TEST_ASSERT( v4f.w == 0 )
		
		TEST_ASSERT( v4d.x == 0 )
        TEST_ASSERT( v4d.y == 0 )
		TEST_ASSERT( v4d.z == 0 )
		TEST_ASSERT( v4d.w == 0 )
	}
	
	void test_array_access() {
        TEST_ASSERT( v4i[ 0 ] == 0 )
        TEST_ASSERT( v4i[ 1 ] == 0 )
        TEST_ASSERT( v4i[ 2 ] == 0 )
		TEST_ASSERT( v4i[ 3 ] == 0 )
		
        TEST_ASSERT( v4f[ 0 ] == 0 )
        TEST_ASSERT( v4f[ 1 ] == 0 )
        TEST_ASSERT( v4f[ 2 ] == 0 )
		TEST_ASSERT( v4f[ 3 ] == 0 )
		
		TEST_ASSERT( v4d[ 0 ] == 0 )
        TEST_ASSERT( v4d[ 1 ] == 0 )
        TEST_ASSERT( v4d[ 2 ] == 0 )
		TEST_ASSERT( v4d[ 3 ] == 0 )
		// since vec3f has size of 3
		// this needs review?
		// TEST_ASSERT( v4d[ 4 ] == 0 )
    }
	
	void test_pointer_access() {
		float *vf;
		double *vd;
		
		v4f.x = 10.f;
		v4f.y = 12.f;
		v4f.z = 1.f;
		v4f.w = 125.f;
		
		vf = v4f.getPtr();
        TEST_ASSERT( *( vf + 0 ) ==  10.f )
        TEST_ASSERT( *( vf + 1 ) ==  12.f )
		TEST_ASSERT( *( vf + 2 ) ==   1.f )
        TEST_ASSERT( *( vf + 3 ) == 125.f )
		
		v4d.x = 10.;
		v4d.y = 12.;
		v4d.z = 1.;
		v4d.w = 125.;
		
		vd = v4d.getPtr();
        TEST_ASSERT( *( vd   ) ==  10. )
        TEST_ASSERT( *( ++vd ) ==  12. )
		TEST_ASSERT( *( ++vd ) ==   1. )
        TEST_ASSERT( *( ++vd ) == 125. )
    }
	
	void test_sets_equality() {
		v4i.set( 20, 30, 50, 100 );
        TEST_ASSERT( v4i == _ofVec4<int> ( 20, 30, 50, 100 ) )
		
		v4f.set( 20.f, 30.f, 50.f, 100.f );
		TEST_ASSERT( v4f == _ofVec4<float> ( 20.f, 30.f, 50.f, 100.f ) )
		
		v4d.set( 20., 30., 50., 100. );
		TEST_ASSERT( v4d == _ofVec4<double> ( 20., 30., 50., 100. ) )
    }
	
	void test_operations() {
		v4i.set( 20, 30, 40, 10 );
		
		v4i += _ofVec4i( 40, 30, 20, 10 );
		TEST_ASSERT( v4i == _ofVec4i( 60, 60, 60, 20 ) )
		TEST_ASSERT( v4i +  _ofVec4i( 40, 30, 10, 10 ) == _ofVec4<int>( 100, 90, 70, 30 ) )
		
		v4i -= _ofVec4i( 20, 30, 120, 40 );
		TEST_ASSERT( v4i == _ofVec4i( 40, 30, -60, -20 ) )
		TEST_ASSERT( v4i -  _ofVec4i( 20, 10,  50,  10 ) == _ofVec4<int>( 20, 20, -110, -30 ) )
		
		v4i *= _ofVec4i( 2, 5, -4, 10 );
		TEST_ASSERT( v4i == _ofVec4i( 80, 150, 240, -200 ) )
		TEST_ASSERT( v4i *  _ofVec4i( 20,  10,  -2,   -1 ) == _ofVec4<int>( 1600, 1500, -480, 200 ) )
		
		v4i /= _ofVec4i( 4, 5, 6, -20 );
		TEST_ASSERT( v4i == _ofVec4i( 20,  30, 40, 10 ) )
		TEST_ASSERT( v4i /  _ofVec4i(  2, -10, -5,  2 ) == _ofVec4<int>( 10, -3, -8, 5 ) )
		
		v4i = -v4i; 
		TEST_ASSERT( v4i == _ofVec4i( -20, -30, -40, -10 ) );
		
		v4f.set( 20, 30, 40, 10 );
		
		v4f += _ofVec4f( 40, 30, 20, 10 );
		TEST_ASSERT( v4f == _ofVec4f( 60, 60, 60, 20 ) )
		TEST_ASSERT( v4f +  _ofVec4f( 40, 30, 10, 10 ) == _ofVec4<float>( 100, 90, 70, 30 ) )
		
		v4f -= _ofVec4f( 20, 30, 120, 40 );
		TEST_ASSERT( v4f == _ofVec4f( 40, 30, -60, -20 ) )
		TEST_ASSERT( v4f -  _ofVec4f( 20, 10,  50,  10 ) == _ofVec4<float>( 20, 20, -110, -30 ) )
		
		v4f *= _ofVec4f( 2, 5, -4, 10 );
		TEST_ASSERT( v4f == _ofVec4f( 80, 150, 240, -200 ) )
		TEST_ASSERT( v4f *  _ofVec4f( 20,  10,  -2,   -1 ) == _ofVec4<float>( 1600, 1500, -480, 200 ) )
		
		v4f /= _ofVec4f( 4, 5, 6, -20 );
		TEST_ASSERT( v4f == _ofVec4f( 20,  30, 40, 10 ) )
		TEST_ASSERT( v4f /  _ofVec4f(  2, -10, -5,  2 ) == _ofVec4<float>( 10, -3, -8, 5 ) )
		
		v4f = -v4f; 
		TEST_ASSERT( v4f == _ofVec4f( -20, -30, -40, -10 ) );
    }
};
