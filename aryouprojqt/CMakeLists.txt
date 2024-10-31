cmake_minimum_required(VERSION 3.16)

project(aryouprojqt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES aryouprojqt_fr_FR.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(aryouprojqt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ../sources/Classes/Car.cpp ../sources/Classes/Employee.cpp ../sources/Classes/Team.cpp ../sources/Classes/Workfield.cpp
        ../includes/ClassIncludes/Car.h ../includes/ClassIncludes/Employee.h ../includes/ClassIncludes/Team.h ../includes/ClassIncludes/Workfield.h
        ../includes/FactoryHeaders/CarFactory.h ../includes/FactoryHeaders/EmployeeFactory.h ../includes/FactoryHeaders/TeamFactory.h ../includes/FactoryHeaders/WorkFieldFactory.h
        ../includes/ObserverIncludes/CarArrivalObserver.h ../includes/ObserverIncludes/EmployeeStatusObserver.h ../includes/ObserverIncludes/EventManager.h ../includes/ObserverIncludes/Observer.h ../includes/ObserverIncludes/Subject.h
        ../includes/StrategyIncludes/ContractTypeAssignment.h ../includes/StrategyIncludes/ExperienceBasedAssignment.h ../includes/StrategyIncludes/Scheduler.h ../includes/StrategyIncludes/TaskAssignmentStrategy.h
        ../sources/FactoryClasses/CarFactory.cpp ../sources/FactoryClasses/EmployeeFactory.cpp ../sources/FactoryClasses/TeamFactory.cpp ../sources/FactoryClasses/WorkFieldFactory.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET aryouprojqt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(aryouprojqt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(aryouprojqt
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(aryouprojqt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.aryouprojqt)
endif()
set_target_properties(aryouprojqt PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS aryouprojqt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(aryouprojqt)
endif()
