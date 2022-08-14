#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "doubly_linked_list.cpp"

TEST_CASE("Test_doubly_list", "[List]")
{
	List* list = new List();
	SECTION("Checking for an empty list")
	{
		INFO("When creating a new list, it should be empty and return true");
		CHECK(list->Empty() == true);
	}
	SECTION("Checking for the number of elements")
	{
		list->PushFront(10);
		list->PushFront(12);
		list->PushBack(5);
		list->PushBack(2);
		INFO("After adding elements, it should not be empty");
		CHECK(list->Size() != 0);
	}
	SECTION("Checking for cleaning of elements")
	{
		list->Clear();
		INFO("After clearing the list, it should be empty");
		CHECK(list->Size() == 0);
	}
}

int main()
{
	return Catch::Session().run();
}