#pragma once

#include "cpptest.h"
#include "_ofMatrixUtils.h"
#include "_ofMatrix3x3.h"

class ofMatrix3x3_test 
	: public Test::Suite {
public:
	
    ofMatrix3x3_test() {
		
        TEST_ADD( ofMatrix3x3_test::test_instantiation )
		TEST_ADD( ofMatrix3x3_test::test_sets )
		TEST_ADD( ofMatrix3x3_test::test_determinants )
		TEST_ADD( ofMatrix3x3_test::test_transposes )
		TEST_ADD( ofMatrix3x3_test::test_inverses )
	}
	
protected:
	
    void setup() {
       result_transpose1.set(
            -2, -1,  2,
             2,  1,  0,
             3,  3, -1 
       );

       result_transpose2.set(
            1, 4, 7,
            2, 5, 8,
            3, 6, 9 
       );

       result_inverse1.set(
            0.2,  0.2, 0,
           -0.2,  0.3, 1,
            0.2, -0.3, 0 
       );
    }

    void tear_down() {}
	
private:
	
	_ofMatrix3x3i m3x3i;
	_ofMatrix3x3f m3x3f;
	_ofMatrix3x3d m3x3d;
	
    _ofMatrix3x3f result_transpose1;
    _ofMatrix3x3f result_transpose2;
	
    _ofMatrix3x3f result_inverse1;
	
    /*! */
    void test_instantiation() {
		_ofMatrix3x3<float> m3x3f(  
			1,  2,  3,  
			4,  5,  6,  
			7,  8,  9  
		);
		
		int c = 1;
		for ( int i = 1; i < 10; i++ ) {
			TEST_ASSERT( m3x3f[ i - 1 ] == c );
			c++;
		}
	}
	
    /*! */
	void test_sets() {
        float f[9] = {
            -2,  2,  3, 
			-1,  1,  3, 
			 2,  0, -1 
        };

	    m3x3f.set(
			-2,  2,  3,  
			-1,  1,  3,  
			 2,  0,  -1  
		);

		for ( int i = 1; i < 10; i++ ) {
			TEST_ASSERT( m3x3f[ i - 1 ] == f[ i - 1 ] );
		}
	}
	
    /*! Solution:
        http://en.wikipedia.org/wiki/Determinant#3-by-3_matrices */
	void test_determinants() {
		m3x3f.set(
			-2,  2,  3,  
			-1,  1,  3,  
			 2,  0,  -1  
		);
		
		TEST_ASSERT( m3x3f.determinant() == 6 )

		// ? 
		// determinant of other matrix 
		// can be a util (maybe).
        _ofMatrix3x3<float> A(
			-2,  2,  3,  
			-1,  1,  3,  
			 2,  0,  -1  
        );
        
        TEST_ASSERT( m3x3f.determinant( A ) == 6 )
		
        // det 3x3 as utils.
        TEST_ASSERT( matrixDeterminant3x3<float>( A ) == 6 )
	}

    void test_transposes() {
		
        int i;
        _ofMatrix3x3<float> test;
        
        m3x3f.set(
			-2,  2,  3,  
			-1,  1,  3,  
			 2,  0,  -1  
		);

        m3x3f.transpose();
		
        for ( i = 1; i < 10; i++ ) {
			TEST_ASSERT( m3x3f[ i - 1 ] == result_transpose1[ i - 1 ] );
		}

        test.set(
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
        );

        test = m3x3f.transpose( test );

        for ( i = 1; i < 10; i++ ) {
			TEST_ASSERT( test[ i - 1 ] == result_transpose2[ i - 1 ] );
		}
    }

    /*! Solution:
        http://www.mathsisfun.com/algebra/matrix-inverse-row-operations-gauss-jordan.html */
    void test_inverses() {
		
        int i;
        _ofMatrix3x3f test;
        
        m3x3f.set(
			3,  0,  2,  
			2,  0, -2,  
			0,  1,  1  
		);

        m3x3f.invert();
		
        for ( i = 1; i < 10; i++ ) {
			TEST_ASSERT( m3x3f[ i - 1 ] == result_inverse1[ i - 1 ] );
		}

		//
		
        test.set(
			3,  0,  2,  
			2,  0, -2,  
			0,  1,  1  
        );

        test = m3x3f.inverse( test );

        for ( i = 1; i < 10; i++ ) {
			TEST_ASSERT( test[ i - 1 ] == result_inverse1[ i - 1 ] );
		}

		//

        test.set(
			3,  0,  2,  
			2,  0, -2,  
			0,  1,  1  
        );
		
        test = matrixInverse3x3<float>( test );

        for ( i = 1; i < 10; i++ ) {
			TEST_ASSERT( test[ i - 1 ] == result_inverse1[ i - 1 ] );
		}

    }

};
