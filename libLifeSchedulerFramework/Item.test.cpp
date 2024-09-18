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
#include <queue>
#include <libLifeSchedulerFramework/Item.h>
#include <libLifeSchedulerFramework/Tag.h>


TEST(ItemTests_lessOperand, EqualItems)
{
	LifeScheduler::Item Item;
	ASSERT_FALSE(Item < Item);
}

TEST(ItemTests_lessOperand, Item1LessItem2_priority)
{
	LifeScheduler::Item Item1("Item1", 1);
	LifeScheduler::Item Item2("Item1", 2);
	ASSERT_TRUE(Item1 < Item2);
}

TEST(ItemTests_lessOperand, Item1LessItem2_workedUnits)
{
	LifeScheduler::Item Item1("Item1", 1);
	LifeScheduler::Item Item2("Item1", 1);
	Item2.AddWorkUnits(42);
	ASSERT_TRUE(Item1 < Item2);
}

TEST(ItemTests_lessOperand, Item1LessItem2_Tag)
{
	LifeScheduler::Tag tag1("Tag1",1);
	LifeScheduler::Tag tag2("Tag2",2);
	LifeScheduler::Item Item1("Item1", 1,tag1);
	LifeScheduler::Item Item2("Item1", 1, tag2);
	ASSERT_TRUE(Item1 < Item2);
}

TEST(ItemTests_greatOperand, Item1GreatItem2_priority)
{
	LifeScheduler::Item Item1("Item1", 2);
	LifeScheduler::Item Item2("Item1", 1);
	ASSERT_TRUE(Item1 > Item2);
}

TEST(ItemTests_greatOperand, Item1GreatItem2_workedUnits)
{
	LifeScheduler::Item Item1("Item1", 1);
	LifeScheduler::Item Item2("Item1", 1);
	Item1.AddWorkUnits(42);
	ASSERT_TRUE(Item1 > Item2);
}

TEST(ItemTests_greatOperand, Item1GreatItem2_Tag)
{
	LifeScheduler::Tag tag1("Tag1",2);
	LifeScheduler::Tag tag2("Tag2",1);
	LifeScheduler::Item Item1("Item1", 1,tag1);
	LifeScheduler::Item Item2("Item1", 1, tag2);
	ASSERT_TRUE(Item1 > Item2);
}

TEST(ItemTests_equalOperand, Item1EqualsItem2)
{
	LifeScheduler::Item Item1("Item1", 1);
	LifeScheduler::Item Item2("Item1", 1);
	ASSERT_TRUE(Item1 == Item2);
}

TEST(ItemTests_equalOperand, Item1NotEqualsItem2_name)
{
	LifeScheduler::Item Item1("Item1", 1);
	LifeScheduler::Item Item2("Item2", 1);
	ASSERT_FALSE(Item1 == Item2);
	ASSERT_NE(Item1.GetName(), Item2.GetName());
	ASSERT_EQ(Item1.GetPriority(), Item2.GetPriority());
}

TEST(ItemTests_equalOperand, Item1NotEqualsItem2_priority)
{
	LifeScheduler::Item Item1("Item1", 1);
	LifeScheduler::Item Item2("Item1", 2);
	ASSERT_FALSE(Item1 == Item2);
	ASSERT_EQ(Item1.GetName(), Item2.GetName());
	ASSERT_NE(Item1.GetPriority(), Item2.GetPriority());
}

TEST(ItemTests_equalOperand, Item1NotEqualsItem2_tag)
{
	LifeScheduler::Tag tag1("Tag1", 1);
	LifeScheduler::Tag tag2("Tag1", 2);
	LifeScheduler::Item Item1("Item1", 1, tag1);
	LifeScheduler::Item Item2("Item1", 1, tag2);
	ASSERT_FALSE(Item1 == Item2);
	ASSERT_EQ(Item1.GetName(), Item2.GetName());
	ASSERT_EQ(Item1.GetPriority(), Item2.GetPriority());
	ASSERT_NE(Item1.GetTag(), Item2.GetTag());
}