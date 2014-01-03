find_package ( Boost COMPONENTS unit_test_framework REQUIRED )


#add_definitions ( -DBOOST_TEST_DYN_LINK )

add_executable ( GeometricStructureTests GeometricStructureTests.cpp )

add_dependencies ( GeometricStructureTests GeometricEntities Quaternions )


target_link_libraries ( GeometricStructureTests 
                        GeometricEntities
                        Quaternions
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} 
                      )

enable_testing ()

add_test ( GSTests GeometricStructureTests )
