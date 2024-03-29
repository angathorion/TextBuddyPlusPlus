#include "stdafx.h"
#include "CppUnitTest.h"
#include "TextBuddy.h"
#include <vector>
#include <string>
#include "SortCmd.h"
#include <numeric>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::string strVectorToString(std::vector<std::string> input){
	std::string str = std::accumulate(input.begin(), input.end(), std::string("\n"));
	return str;
}

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
			std::string teststr;
			std::string teststr2;
			teststr2 = strVectorToString(TextBuddy::Instance().getTextHandler()->searchContents("test string"));
			teststr = strVectorToString(TextBuddy::Instance().getTextHandler()->getStringVector());
			Assert::AreEqual(teststr.c_str(), teststr2.c_str());
		}

		//Search 1 item
		TEST_METHOD(TestTextHandlerSingleSearch)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("jkoasca");
			std::vector<std::string> result;
			result.push_back("1. jkoasca\n");

			std::string teststr;
			std::string teststr2;
			teststr2 = strVectorToString(TextBuddy::Instance().getTextHandler()->searchContents("jkoasca"));
			teststr = strVectorToString(result);
			Assert::AreEqual(teststr.c_str(), teststr2.c_str());
		}

		//Search multiple items
		TEST_METHOD(TestTextHandlerMultipleSearch)
		{
			TextBuddy::Instance().initializeTextHandler("test");
			TextBuddy::Instance().getTextHandler()->addText("a dog's world");
			TextBuddy::Instance().getTextHandler()->addText("a dog eat dog world");
			TextBuddy::Instance().getTextHandler()->addText("kool aid");
			TextBuddy::Instance().getTextHandler()->addText("fox jumps over the dog");
			std::vector<std::string> result;
			result.push_back("1. a dog's world\n");
			result.push_back("2. a dog eat dog world\n");
			result.push_back("4. fox jumps over the dog\n");

			std::string teststr;
			std::string teststr2;
			teststr2 = strVectorToString(TextBuddy::Instance().getTextHandler()->searchContents("dog"));
			teststr = strVectorToString(result);
			Assert::AreEqual(teststr.c_str(), teststr2.c_str());
		}
	};
}