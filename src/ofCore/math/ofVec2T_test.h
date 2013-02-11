#pragma once

#include "cpptest.h"
#include "_ofVec.h"

class ofVec2T_Suite 
	: public Test::Suite {
public:
	
    ofVec2T_Suite() {
		
        TEST_ADD( ofVec2T_Suite::test_instantiation )
        TEST_ADD( ofVec2T_Suite::test_array_access )
		TEST_ADD( ofVec2T_Suite::test_pointer_access )
		TEST_ADD( ofVec2T_Suite::test_sets_equality )
		TEST_ADD( ofVec2T_Suite::test_operations )
		TEST_ADD( ofVec2T_Suite::test_scale )
    }
	
protected:
	
    void     setup() {}
    void tear_down() {}
	
private:
	
	_ofVec2i v2i;
    _ofVec2f v2f;
	_ofVec2d v2d;
	
    void test_instantiation() {
		
        TEST_ASSERT( v2i.x == 0 )
        TEST_ASSERT( v2i.y == 0 )
		
		TEST_ASSERT( v2f.x == 0 )
        TEST_ASSERT( v2f.y == 0 )
		
		TEST_ASSERT( v2d.x == 0 )
        TEST_ASSERT( v2d.y == 0 )
    }
	
    void test_array_access() {
		
		TEST_ASSERT( v2i[0] == 0 )
        TEST_ASSERT( v2i[1] == 0 )
		
		TEST_ASSERT( v2f[0] == 0 )
        TEST_ASSERT( v2f[1] == 0 )
		
		TEST_ASSERT( v2d[0] == 0 )
        TEST_ASSERT( v2d[1] == 0 )
		
		// since v2T has size of 2
		// this needs review?
		// TEST_ASSERT( v2T[3] == 0 )
    }
	
	void test_pointer_access() {
		
		int *vi;
		float *vf;
		double *vd;
		
		v2i.x = 10;
		v2i.y = 12;
		
		vi = v2i.getPtr();
        TEST_ASSERT( *( vi + 0 ) == 10 )
        TEST_ASSERT( *( vi + 1 ) == 12 )
		
		v2f.x = 10.f;
		v2f.y = 12.f;
		
		vf = v2f.getPtr();
        TEST_ASSERT( *( vf + 0 ) == 10.f )
        TEST_ASSERT( *( vf + 1 ) == 12.f )
		
		v2d.x = 10.;
		v2d.y = 12.;
		
		vd = v2d.getPtr();
        TEST_ASSERT( *( vd + 0 ) == 10 )
        TEST_ASSERT( *( ++vd   ) == 12 )
    }
	
	void test_sets_equality() {
		
		v2i.set( 20, 30 );
        TEST_ASSERT( v2i == _ofVec2<int>( 20, 30 ) )
		TEST_ASSERT( v2i != _ofVec2i( 40, 30 ) )
		
		v2f.set( _ofVec2f( 20, 30 ) );
        TEST_ASSERT( v2f == _ofVec2<float>( 20, 30 ) )
		TEST_ASSERT( v2f != _ofVec2f( 40, 30 ) )
		
		v2d.set( 20 );
        TEST_ASSERT( v2d == _ofVec2<double>( 20, 20 ) )
		TEST_ASSERT( v2d != _ofVec2d( 40, 30 ) )
    }
	
	void test_operations() {
		// the last operation must match 
		// the opposite of this first. 
		// vec( 20, 30 ) == vec( -20, -30 )
		v2i.set( 20, 30 );
				
		v2i += _ofVec2i( 40, 30 );
		TEST_ASSERT( v2i == _ofVec2i( 60, 60 ) ) // <-
		TEST_ASSERT( v2i +  _ofVec2i( 10, 0 ) == _ofVec2i( 70, 60 ) )
		
		v2i -= _ofVec2i( 20, 10 );
		TEST_ASSERT( v2i == _ofVec2i( 40, 50 ) ) // <-
		TEST_ASSERT( v2i -  _ofVec2i( 20, 10 ) == _ofVec2i( 20, 40 ) )
		
		v2i *= _ofVec2i( 20, 60 );
		TEST_ASSERT( v2i == _ofVec2i( 800, 3000 ) ) // <-
		TEST_ASSERT( v2i *  _ofVec2i( 2, 2 ) == _ofVec2i( 1600, 6000 ) )
		
		v2i /= _ofVec2i( 40, 100 );
		TEST_ASSERT( v2i == _ofVec2i( 20, 30 ) ) // <-
		TEST_ASSERT( v2i /  _ofVec2i( 20, 30 ) == _ofVec2i( 1, 1 ) )
		
		v2i = - v2i;
		TEST_ASSERT( v2i == _ofVec2i( -20, -30 ) )
		
		
		v2f.set( 20, 30 );
		
		v2f += _ofVec2f( 40, 30 );
		TEST_ASSERT( v2f == _ofVec2f( 60, 60 ) )
		TEST_ASSERT( v2f +  _ofVec2f( 10, 0 ) == _ofVec2f( 70, 60 ) )
		
		v2f -= _ofVec2f( 20, 10 );
		TEST_ASSERT( v2f == _ofVec2f( 40, 50 ) )
		TEST_ASSERT( v2f -  _ofVec2f( 20, 10 ) == _ofVec2f( 20, 40 ) )
		
		v2f *= _ofVec2f( 20, 60 );
		TEST_ASSERT( v2f == _ofVec2f( 800, 3000 ) )
		TEST_ASSERT( v2f *  _ofVec2f( 2, 2 ) == _ofVec2f( 1600, 6000 ) )
		
		v2f /= _ofVec2f( 40, 100 );
		TEST_ASSERT( v2f == _ofVec2f( 20, 30 ) )
		TEST_ASSERT( v2f /  _ofVec2f( 20, 30 ) == _ofVec2f( 1, 1 ) )
		
		v2f = - v2f;
		TEST_ASSERT( v2f == _ofVec2f( -20, -30 ) )
		
		
		v2d.set( 20, 30 );
		
		v2d += _ofVec2d( 40, 30 );
		TEST_ASSERT( v2d == _ofVec2d( 60, 60 ) )
		TEST_ASSERT( v2d +  _ofVec2d( 10, 0 ) == _ofVec2d( 70, 60 ) )
		
		v2d -= _ofVec2d( 20, 10 );
		TEST_ASSERT( v2d == _ofVec2d( 40, 50 ) )
		TEST_ASSERT( v2d -  _ofVec2d( 20, 10 ) == _ofVec2d( 20, 40 ) )
		
		v2d *= _ofVec2d( 20, 60 );
		TEST_ASSERT( v2d == _ofVec2d( 800, 3000 ) )
		TEST_ASSERT( v2d *  _ofVec2d( 2, 2 ) == _ofVec2d( 1600, 6000 ) )
		
		v2d /= _ofVec2d( 40, 100 );
		TEST_ASSERT( v2d == _ofVec2d( 20, 30 ) )
		TEST_ASSERT( v2d /  _ofVec2d( 20, 30 ) == _ofVec2d( 1, 1 ) )
		
		v2d = - v2d;
		TEST_ASSERT( v2d == _ofVec2d( -20, -30 ) )
    }	
	
	void test_scale() {
//		v2f.set( 1, 10 );
//		v2f.scale( 10 );
		
//		TEST_ASSERT( v2f.x == 10 )
//		TEST_ASSERT( v2f.y == 100 )
	}

};
