#include "stdafx.h"
#include "CppUnitTest.h"
#include "TextBuddy.h"
#include <vector>
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("abcd");
			std::string teststr; 
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			Logger::WriteMessage(teststr.c_str());
			Assert::AreEqual(teststr.c_str(), "1. abcd\n");
		}

		//Tests for

	};
}