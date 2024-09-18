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
#include <libLifeSchedulerFramework/Tag.h>


TEST(TagTests_lessOperand, EqualTags) 
{
	LifeScheduler::Tag tag;
	EXPECT_FALSE(tag < tag);
}

TEST(TagTests_lessOperand, Tag1LessTag2_priority)
{
	std::string name1("Tag1");
	std::string name2("Tag1");
	LifeScheduler::Tag tag1(name1, 1);
	LifeScheduler::Tag tag2(name2, 2);
	EXPECT_TRUE(tag1 < tag2);
}

TEST(TagTests_lessOperand, Tag1LessTag2_name)
{
	std::string name1("Tag1");
	std::string name2("Tag2");
	LifeScheduler::Tag tag1(name1, 1);
	LifeScheduler::Tag tag2(name2, 1);
	EXPECT_TRUE(tag1 < tag2);
}

TEST(TagTests_GreaterOperand, Tag1GreatTag2_priority)
{
	std::string name1("Tag1");
	std::string name2("Tag1");
	LifeScheduler::Tag tag1(name1, 2);
	LifeScheduler::Tag tag2(name2, 1);
	EXPECT_TRUE(tag1 > tag2);
}

TEST(TagTests_GreaterOperand, Tag1GreatTag2_name)
{
	std::string name1("Tag10");
	std::string name2("Tag1");
	LifeScheduler::Tag tag1(name1, 1);
	LifeScheduler::Tag tag2(name2, 1);
	EXPECT_TRUE(tag1 > tag2);
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