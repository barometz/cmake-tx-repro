#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

TEST(SimpleTest, Pass) {}
TEST(SimpleTest, Fail) { FAIL(); }

using Fixture = testing::Test;
TEST(Fixture, Pass) {}
TEST(Fixture, Fail) { FAIL(); }

template <typename T> class ClassTemplate {};

namespace namespaced {
template <typename T> class ClassTemplate {};
} // namespace namespaced

template <typename T> using TypedFixture = testing::Test;
using Types = testing::Types<int, char, ClassTemplate<int>,
                             // this one doesn't run.
                             ClassTemplate<ClassTemplate<int>>,
                             namespaced::ClassTemplate<int>,
                             // and this one doesn't run.
                             namespaced::ClassTemplate<ClassTemplate<int>>>;
TYPED_TEST_SUITE(TypedFixture, Types);
TYPED_TEST(TypedFixture, Pass) {}
TYPED_TEST(TypedFixture, Fail) { FAIL(); }

using ParamTest = testing::TestWithParam<std::string>;

TEST_P(ParamTest, Pass) {}
TEST_P(ParamTest, Fail) { FAIL(); }

INSTANTIATE_TEST_SUITE_P(ParamTest, ParamTest, testing::Values("one"));
