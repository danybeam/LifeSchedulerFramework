#include <gtest/gtest.h>
#include <queue>
#include <libLifeSchedulerFramework/Tag.h>


TEST(TagTests_lessOperand, EqualTags) 
{
	LifeScheduler::Tag tag;
	EXPECT_FALSE(tag < tag);
}

TEST(TagTests_lessOperand, Tag2LessTag1_priority)
{
	std::string name1("Tag1");
	std::string name2("Tag1");
	LifeScheduler::Tag tag1(name1, 1);
	LifeScheduler::Tag tag2(name2, 2);
	EXPECT_TRUE(tag2 < tag1);
}

TEST(TagTests_lessOperand, Tag2LessTag1_name)
{
	std::string name1("Tag1");
	std::string name2("Tag2");
	LifeScheduler::Tag tag1(name1, 1);
	LifeScheduler::Tag tag2(name2, 1);
	EXPECT_TRUE(tag2 < tag1);
}

TEST(TagTests_equalOperand, Tag1EqualsTag2)
{
	std::string name1("Tag1");
	std::string name2("Tag1");
	LifeScheduler::Tag tag1(name1, 1);
	LifeScheduler::Tag tag2(name2, 1);
	EXPECT_TRUE(tag1 == tag2);
}

TEST(TagTests_equalOperand, Tag1NotEqualsTag2_name)
{
	std::string name1("Tag1");
	std::string name2("Tag2");
	LifeScheduler::Tag tag1(name1, 1);
	LifeScheduler::Tag tag2(name2, 1);
	EXPECT_FALSE(tag1 == tag2);
	EXPECT_NE(tag1.GetName(),tag2.GetName());
	EXPECT_EQ(tag1.GetPriority(),tag2.GetPriority());
}

TEST(TagTests_equalOperand, Tag1NotEqualsTag2_priority)
{
	std::string name1("Tag1");
	std::string name2("Tag1");
	LifeScheduler::Tag tag1(name1, 1);
	LifeScheduler::Tag tag2(name2, 2);
	EXPECT_FALSE(tag1 == tag2);
	EXPECT_EQ(tag1.GetName(), tag2.GetName());
	EXPECT_NE(tag1.GetPriority(), tag2.GetPriority());
}