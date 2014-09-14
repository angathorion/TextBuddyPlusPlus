#include "stdafx.h"
#include "CppUnitTest.h"
#include "TextBuddy.h"
#include <vector>
#include <string>
#include "SortCmd.h"
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
			Assert::AreEqual(teststr.c_str(), "1. abcd\n");
		}

		TEST_METHOD(TestTextHandlerSingleSort2)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("defg");
			TextBuddy::Instance().getTextHandler()->sortContents();
			std::string teststr;
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
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
			Assert::AreEqual(teststr.c_str(), "1. defg\n2. jkoasca\n3. lmonwp\n");
		}

		//Items that are presented out of order
		TEST_METHOD(TestTextHandlerSort2)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("jkoasca");
			TextBuddy::Instance().getTextHandler()->addText("defg");
			TextBuddy::Instance().getTextHandler()->addText("lmonwp");
			TextBuddy::Instance().getTextHandler()->sortContents();
			std::string teststr;
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			Assert::AreEqual(teststr.c_str(), "1. defg\n2. jkoasca\n3. lmonwp\n");
		}


		//SortCmd class initialization
		//Test sort output message
		TEST_METHOD(TestSortCmdOutput)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			SortCmd cmd("test");
			std::string teststr;
			teststr = cmd.execute();
			Assert::AreEqual(teststr.c_str(), "sorted contents of test\n");
		}

		//Test sort cmd behavior
		TEST_METHOD(TestSortCmdBehavior)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("jkoasca");
			TextBuddy::Instance().getTextHandler()->addText("defg");
			TextBuddy::Instance().getTextHandler()->addText("lmonwp");
			SortCmd cmd("test");
			cmd.execute();
			std::string teststr;
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			Assert::AreEqual(teststr.c_str(), "1. defg\n2. jkoasca\n3. lmonwp\n");
		}

		//Search function tests

		//Search empty
		TEST_METHOD(TestTextHandlerEmptySearch)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->searchContents("test string");
			std::string teststr;
			teststr = TextBuddy::Instance().getTextHandler()->displayContents();
			Assert::AreEqual(teststr.c_str(), "test is empty\n");
		}
	};
}