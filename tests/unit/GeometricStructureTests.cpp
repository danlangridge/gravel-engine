#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Vector_test

#include <Vector.h>
#include <Mat4.h>

#include <boost/test/unit_test.hpp>


#include <math.h>

BOOST_AUTO_TEST_SUITE ( GeometricStructureTests )

BOOST_AUTO_TEST_CASE( Vector_test )
{
  
  Vector test_vector(1,1,1,1);
  
  BOOST_CHECK( test_vector.x == test_vector[0] );
  BOOST_CHECK( test_vector.y == test_vector[1] );
  BOOST_CHECK( test_vector.z == test_vector[2] );
  BOOST_CHECK( test_vector.w == test_vector[3] );
 
  test_vector.normalize();

  float norm = sqrt( test_vector.x*test_vector.x + 
                     test_vector.y*test_vector.y + 
                     test_vector.z*test_vector.z  
                   );

  // Check if magnitudes are close
  BOOST_CHECK( norm + 0.1 > test_vector.magnitude() &&
               norm - 0.1 < test_vector.magnitude()
             );
}


bool compareMatrices(Mat4 mat1, Mat4 mat2) {

  for (unsigned i = 0; i < 16; i++) {
    if (mat1[i] != mat2[i]) return false;
  }
  return false;
}


BOOST_AUTO_TEST_CASE( Mat4_test ) {

  float float_array[16] = { 1, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1,
                          };
  
  Mat4 test_matrix1;
  Mat4 test_matrix2(float_array);

  BOOST_CHECK( compareMatrices(test_matrix1, test_matrix2) );
}


BOOST_AUTO_TEST_SUITE_END()
