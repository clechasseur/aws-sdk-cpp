cmake_minimum_required(VERSION 2.6)
project(aws-cpp-sdk-cognito-sync-manager)

file( GLOB COGNITO_SYNC_HEADERS "include/aws/cognito-sync-manager/*.h" )

file( GLOB COGNITO_SYNC_SOURCE "source/*.cpp" )

if(APPLE)
   file ( GLOB COGNITO_SYNC_APPLE_HEADERS "include/aws/cognito-sync-manager/apple/*.h")
   file ( GLOB COGNITO_SYNC_APPLE_SOURCE "source/apple/*.mm")
endif()

if(MSVC)
    source_group("Header Files\\aws\\cognito-sync-manager" FILES ${COGNITO_SYNC_HEADERS})

    source_group("Source Files\\" FILES ${COGNITO_SYNC_SOURCE})
endif()

file(GLOB ALL_COGNITO_SYNC_HEADERS
    ${COGNITO_SYNC_HEADERS}
    ${COGNITO_SYNC_APPLE_HEADERS}
)

file(GLOB ALL_COGNITO_SYNC_SOURCE
    ${COGNITO_SYNC_SOURCE}
    ${COGNITO_SYNC_APPLE_SOURCE}
)

file(GLOB ALL_COGNITO_SYNC
    ${ALL_COGNITO_SYNC_HEADERS}
    ${ALL_COGNITO_SYNC_SOURCE}
)

set(COGNITO_SYNC_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    "${AWS_NATIVE_SDK_ROOT}/aws-cpp-sdk-cognito-sync/include/"
    "${AWS_NATIVE_SDK_ROOT}/aws-cpp-sdk-identity-management/include/"
    "${AWS_NATIVE_SDK_ROOT}/aws-cpp-sdk-cognito-identity/include/"
    "${CORE_DIR}/include/"
  )

if(APPLE)
   FIND_LIBRARY(FOUNDATION Foundation)
   FIND_PATH(FOUNDATION_INCLUDE_DIR Foundation.h)
   FIND_LIBRARY(APP_KIT AppKit)
   FIND_PATH(APP_KIT_INCLUDE_DIR AppKit.h)
   include_directories(${FOUNDATION_INCLUDE_DIR}/Headers)
   include_directories(${APP_KIT_INCLUDE_DIR}/Headers)
   SET(EXTRA_PLATFORM_LIBS ${FOUNDATION} ${APP_KIT})
endif()

include_directories(${COGNITO_SYNC_INCLUDES})

if(MSVC AND BUILD_SHARED_LIBS)
    add_definitions("-DAWS_COGNITO_SYNC_MGR_EXPORTS")
endif()

add_library(aws-cpp-sdk-cognito-sync-manager ${LIBTYPE} ${ALL_COGNITO_SYNC} include/aws/cognito-sync-manager/DefaultDataSetUpdatedListener.h)
target_link_libraries(aws-cpp-sdk-cognito-sync-manager aws-cpp-sdk-cognito-sync aws-cpp-sdk-cognito-identity aws-cpp-sdk-identity-management ${EXTRA_PLATFORM_LIBS})

install (TARGETS aws-cpp-sdk-cognito-sync-manager
         ARCHIVE DESTINATION ${ARCHIVE_DIRECTORY}/${SDK_INSTALL_BINARY_PREFIX}/\${CMAKE_INSTALL_CONFIG_NAME}
         LIBRARY DESTINATION lib/${SDK_INSTALL_BINARY_PREFIX}/\${CMAKE_INSTALL_CONFIG_NAME}
         RUNTIME DESTINATION bin/${SDK_INSTALL_BINARY_PREFIX}/\${CMAKE_INSTALL_CONFIG_NAME})

install (FILES ${ALL_COGNITO_SYNC_HEADERS} DESTINATION include/aws/cognito-sync-manager)
