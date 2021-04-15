include(CMakeListsImpl.cmake)
message("gen-src" ${IMPL_GEN_SRCS})
set(IMPL_SRCS ${IMPL_SRCS}
    "src/impl/MpwFrameworkCore.h"
    "src/impl/CompositeCommandBase.cpp"
    "src/impl/CompositeCommandBase.h"
    "src/impl/GameViewPresenterBase.cpp"
    "src/impl/GameViewPresenterBase.h"
    ${IMPL_GEN_SRCS}
    PARENT_SCOPE)
    