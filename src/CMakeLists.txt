add_library( mylibs SHARED
  dataset.cpp
)

target_link_libraries( mylibs
    ${THIRD_PARTY_LIBS}
)

add_executable( getimg getimg.cpp )
target_link_libraries( getimg mylibs )

add_executable( video2img video2img.cpp )
target_link_libraries( video2img mylibs )
