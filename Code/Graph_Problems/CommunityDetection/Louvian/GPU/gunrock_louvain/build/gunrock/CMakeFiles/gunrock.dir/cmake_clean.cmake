file(REMOVE_RECURSE
  "../lib/libgunrock.pdb"
  "../lib/libgunrock.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/gunrock.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
