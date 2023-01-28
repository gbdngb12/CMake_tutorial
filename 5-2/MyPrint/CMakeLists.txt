add_library(myprint myprint.cpp myprint.h)
install(TARGETS myprint DESTINATION lib)
install(FILES myprint.h DESTINATION include)