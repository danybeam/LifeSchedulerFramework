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

#include <libLifeSchedulerFramework/Tag.h>

LifeScheduler::Tag::Tag() :
	m_tagName("EMPTY"),
	m_priority(1)
{
}

LifeScheduler::Tag::Tag(std::string& name) :
	m_tagName(name),
	m_priority(1)
{
}

LifeScheduler::Tag::Tag(std::string& name, unsigned int priority) :
	m_tagName(name),
	m_priority(priority)
{
}

LifeScheduler::Tag::~Tag()
{
}

void LifeScheduler::Tag::SetName(std::string& newName)
{
	this->m_tagName = newName;
}

std::string& LifeScheduler::Tag::GetName()
{
	return this->m_tagName;
}

void LifeScheduler::Tag::SetPriority(unsigned int newPriority)
{
	this->m_priority = newPriority;
}

unsigned int LifeScheduler::Tag::GetPriority() const
{
	return this->m_priority;
}

bool LifeScheduler::Tag::operator<(const Tag& right) const
{
	if (this->m_priority == right.m_priority)
	{
		return this->m_tagName > right.m_tagName;
	}
	return this->m_priority > right.m_priority;
}

bool LifeScheduler::Tag::operator==(const Tag& right) const
{
	return this->m_priority == right.m_priority &&
		this->m_tagName == right.m_tagName;
}