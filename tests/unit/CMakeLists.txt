find_package ( Boost COMPONENTS unit_test_framework REQUIRED )

add_executable ( GeometricStructureTests GeometricStructureTests.cpp )

target_link_libraries ( GeometricStructureTests )

enable_testing ()

add_test ( GSTests GeometricStructureTests )
