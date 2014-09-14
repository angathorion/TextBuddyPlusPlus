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
		
		TEST_METHOD(TestTextHandlerDisplay)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("abcd");
			std::string teststr; 
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			//Logger::WriteMessage(teststr.c_str());
			Assert::AreEqual(teststr.c_str(), "1. abcd\n");
		}

		//Tests for new sort method

		//Sort empty
		TEST_METHOD(TestTextHandlerEmptySort)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->sortContents();
			std::string teststr;
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			//Logger::WriteMessage(teststr.c_str());
			Assert::AreEqual(teststr.c_str(), "test is empty\n");
		}

		//Sort single item
		TEST_METHOD(TestTextHandlerSingleSort1)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("abcd");
			TextBuddy::Instance().getTextHandler()->sortContents();
			std::string teststr;
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			//Logger::WriteMessage(teststr.c_str());
			Assert::AreEqual(teststr.c_str(), "1. abcd\n");
		}

		TEST_METHOD(TestTextHandlerSingleSort2)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("defg");
			TextBuddy::Instance().getTextHandler()->sortContents();
			std::string teststr;
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			//Logger::WriteMessage(teststr.c_str());
			Assert::AreEqual(teststr.c_str(), "1. defg\n");
		}

		//Test for actual sorting behavior. This is the hard(er) part.

		//Items that are presented already in order
		TEST_METHOD(TestTextHandlerSort1)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("defg");
			TextBuddy::Instance().getTextHandler()->addText("jkoasca");
			TextBuddy::Instance().getTextHandler()->addText("lmonwp");
			TextBuddy::Instance().getTextHandler()->sortContents();
			std::string teststr;
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			//Logger::WriteMessage(teststr.c_str());
			Assert::AreEqual(teststr.c_str(), "1. defg\n2. jkoasca\n3. lmonwp\n");
		}

	};
}