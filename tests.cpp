#include <gtest/gtest-typed-test.h>
#include <gtest/gtest.h>

TEST(SimpleTest, Test) {}

using Fixture = testing::Test;
TEST(Fixture, Test) {}

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
TYPED_TEST(TypedFixture, Test) {}
