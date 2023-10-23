include(/home/nanir/gunrock/build/cmake/CPM_0.27.5.cmake)
CPMAddPackage(NAME;RapidJSON;OPTIONS;RAPIDJSON_BUILD_UNITTESTS OFF;GITHUB_REPOSITORY;Tencent/rapidjson;GIT_TAG;v1.1.0-489-g4b3d7c2f;SOURCE_DIR;/home/nanir/gunrock/externals/rapidjson)
set(RapidJSON_FOUND TRUE)