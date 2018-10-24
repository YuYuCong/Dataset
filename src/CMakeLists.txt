add_library( mylibs SHARED
  getimg.cpp
)

target_link_libraries( mylibs
    ${THIRD_PARTY_LIBS}
)

add_executable( dataset dataset.cpp )
target_link_libraries( dataset mylibs )
