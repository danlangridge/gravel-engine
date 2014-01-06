#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Vector_test

#include <Vector.h>
#include <Mat4.h>
#include <Quaternion.h>
#include <Conversion.h>

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

  Vector test_vector1(1,1,1,1);
  Vector test_vector2(1,1,1,1);

  Vector result_vector = test_vector1.crossProduct(test_vector2);
  BOOST_CHECK( result_vector == Vector(0,0,0,0)); 
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

BOOST_AUTO_TEST_CASE( Quaternion_test ) {
  Quaternion q;
  q[0] = 0;
  q[1] = 1;
  q[2] = 2;
  q[3] = 3;

  BOOST_CHECK(q[0] == 0);
  BOOST_CHECK(q[1] == 1);
  BOOST_CHECK(q[2] == 2);
  BOOST_CHECK(q[3] == 3);

  Quaternion q2(1,1,1,1);
  GLfloat q2Mag = q2.magnitude();

  BOOST_CHECK(q2Mag == 2);

  q2.normalize();

  BOOST_CHECK( 0.488 < q[0] < 0.522 );
}

BOOST_AUTO_TEST_CASE( Conversion_test ) {
 
  Mat4 identMat;
  Vector vec(1,2,3,4);
  Vector resultVec;
  
  resultVec = Conversion::VectorMat4Mult(vec, identMat);

  BOOST_CHECK(resultVec[0] == 1);
  BOOST_CHECK(resultVec[1] == 2);
  BOOST_CHECK(resultVec[2] == 3);
  BOOST_CHECK(resultVec[3] == 4);

  resultVec = Conversion::Mat4VectorMult(identMat, vec);
  
  BOOST_CHECK(resultVec[0] == 1);
  BOOST_CHECK(resultVec[1] == 2);
  BOOST_CHECK(resultVec[2] == 3);
  BOOST_CHECK(resultVec[3] == 4);

  Quaternion q(1,1,1,10);
 
  Mat4 quatMat = Conversion::QuaternionToMat4(q);  
  
  printf("%s\n", quatMat.output().c_str());

  GLfloat floatMat[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
  
  Mat4 matq(floatMat);

  Quaternion matQuat = Conversion::Mat4ToQuaternion(matq);
  
  printf("%f, %f, %f, %f\n", matQuat[0], matQuat[1], matQuat[2], matQuat[3]);
}



BOOST_AUTO_TEST_SUITE_END()
