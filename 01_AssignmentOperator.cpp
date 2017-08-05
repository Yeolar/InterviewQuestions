/*
 * Copyright (C) 2017, Yeolar
 */

#include <string.h>
#include <gtest/gtest.h>

namespace ae {

class CMyString {
public:
  CMyString(const char* pData = nullptr) {
    if (pData != nullptr) {
      m_pData = new char[strlen(pData) + 1];
      strcpy(m_pData, pData);
    } else {
      m_pData = new char[1];
      m_pData[0] = '\0';
    }
  }

  CMyString(const CMyString& str) {
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
  }

  ~CMyString() {
    delete[] m_pData;
  }

  CMyString& operator=(const CMyString& str) {
    if (this == &str) return *this;
    delete[] m_pData;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
  }

  char* data() const {
    return m_pData;
  }

private:
  char* m_pData;
};

} // namespace ae

TEST(CMyString, all) {
  const char* text = "Hello world";
  ae::CMyString str1(text);
  ae::CMyString str2, str3;
  str2 = str1;
  EXPECT_STREQ(str2.data(), text);
  str1 = str1;
  EXPECT_STREQ(str1.data(), text);
  str3 = str2 = str1;
  EXPECT_STREQ(str2.data(), text);
  EXPECT_STREQ(str3.data(), text);
}
