//===-- Unittests for htonl -----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/__support/endian_internal.h"
#include "src/arpa/inet/htonl.h"
#include "src/arpa/inet/ntohl.h"
#include "test/UnitTest/Test.h"

TEST(LlvmLibcHtonl, SmokeTest) {
  uint32_t original = 0x67452301;
  uint32_t swapped = 0x01234567;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  EXPECT_EQ(LIBC_NAMESPACE::htonl(original), swapped);
#endif
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  EXPECT_EQ(LIBC_NAMESPACE::htonl(original), original);
#endif
}

TEST(LlvmLibcHtonl, CompleteTest) {
  uint32_t original = 0x01234567;
  EXPECT_EQ(LIBC_NAMESPACE::htonl(LIBC_NAMESPACE::ntohl(original)), original);
}
