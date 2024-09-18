/*
* Copyright 2024 Daniel Gerardo Orozco Hernandez
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
* OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <gtest/gtest.h>
#include <libLifeSchedulerFramework/ItemList.h>

/*
* 	// Constructor
		void RemoveItem(int index);
		void RemoveItem(Item& itemRef);

		// Helper funcitons
		void Sort();
*/

// These tests also indirectly test the [] operator and Add
TEST(ItemList_AddItem, AddSingleItem)
{
	LifeScheduler::Item testItem("foo", 42);
	LifeScheduler::ItemList uut;

	uut.AddItem(testItem);
	ASSERT_TRUE(testItem == uut[0]);
}

TEST(ItemList_AddItem, AddMultipleItemsInOrder)
{
	LifeScheduler::Item testItem1("foo", 42);
	LifeScheduler::Item testItem2("bar", 43);
	LifeScheduler::ItemList uut;

	uut.AddItem(testItem1);
	uut.AddItem(testItem2);
	ASSERT_TRUE(testItem1 == uut.At(0));
	ASSERT_TRUE(testItem2 == uut.At(1));
}

TEST(ItemList_AddItem, AddMultipleItemsNotOrdered)
{
	LifeScheduler::Item testItem1("foo", 42);
	LifeScheduler::Item testItem2("bar", 43);
	LifeScheduler::ItemList uut;

	uut.AddItem(testItem2);
	uut.AddItem(testItem1);
	ASSERT_TRUE(testItem1 == uut.At(0));
	ASSERT_TRUE(testItem2 == uut.At(1));
}

TEST(ItemList_RemoveItem, RemoveItemByIndex)
{
	LifeScheduler::Item testItem1("foo", 42);
	LifeScheduler::Item testItem2("bar", 43);
	LifeScheduler::ItemList uut;

	uut.AddItem(testItem1);
	uut.AddItem(testItem2);

	uut.RemoveItem(0);

	ASSERT_EQ(uut.Size(), 1);
	ASSERT_EQ(testItem2, uut[0]);
}