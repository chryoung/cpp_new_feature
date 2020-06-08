cmake_minimum_required(VERSION 3.10)

project(cpp11_features)

set(FEATURE_TARGETS
  auto
  decltype
  default_func
  delegate_constructor
  lambda
  noexcept
  nullptr
  rvalue
  smart_ptr
  uniform_initializer
  regex
  for_range
  enum_class
  type_alias
  trailing_return
  static_assert
  traits
  override_final
  parameter_pack
)

foreach(TARGET ${FEATURE_TARGETS})
  add_executable(${TARGET} ${TARGET}.cpp)
  target_compile_features(${TARGET} PUBLIC cxx_std_11)
endforeach()
