#add_library( mylibs SHARED
#  demo.cpp
#)
#
#target_link_libraries( mylibs
#    ${THIRD_PARTY_LIBS}
#)

add_executable( getimg getimg.cpp )
target_link_libraries( getimg ${THIRD_PARTY_LIBS} )

add_executable( video2img video2img.cpp )
target_link_libraries( video2img ${THIRD_PARTY_LIBS} )
