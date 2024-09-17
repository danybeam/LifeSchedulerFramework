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
#include <libLifeSchedulerFramework/Item.h>

LifeScheduler::Item::Item() : 
	m_name("EMPTY"),
	m_priority(1),
	m_tag(Tag())
{
}

LifeScheduler::Item::Item(std::string& name) :
	m_name(name),
	m_priority(1),
	m_tag(Tag())
{
}

LifeScheduler::Item::Item(std::string& name, unsigned int m_priority) :
	m_name(name),
	m_priority(m_priority),
	m_tag(Tag())
{
}

LifeScheduler::Item::Item(std::string& name, unsigned int m_priority, Tag& m_tag) :
	m_name(name),
	m_priority(m_priority),
	m_tag(m_tag)
{
}

LifeScheduler::Item::~Item()
{
}

void LifeScheduler::Item::SetPriority(unsigned int priority)
{
	this->m_priority = priority;
}

unsigned int LifeScheduler::Item::GetPriority() const
{
	return this->m_priority;
}

void LifeScheduler::Item::SetName(std::string& name)
{
	this->m_name = name;
}

std::string& LifeScheduler::Item::GetName()
{
	return this->m_name;
}

void LifeScheduler::Item::SetTag(Tag& tag)
{
	this->m_tag = tag;
}

LifeScheduler::Tag& LifeScheduler::Item::GetTag()
{
	return this->m_tag;
}

unsigned int LifeScheduler::Item::GetWorkedUnits() const
{
	return this->m_workedUnits;
}

void LifeScheduler::Item::AddWorkUnits(unsigned int workedUnits)
{
	this->m_workedUnits += workedUnits;
}

void LifeScheduler::Item::Normalize(unsigned int referenceAmount)
{
	this->m_workedUnits = std::max(this->m_workedUnits - referenceAmount,(unsigned int) 0);
}

bool LifeScheduler::Item::operator<(const Item& right) const
{
	if (right.m_workedUnits == this->m_workedUnits)
	{
		return (this->m_priority * this->m_tag.GetPriority()) > (right.m_priority * right.m_tag.GetPriority());
	}
	return this->m_workedUnits > right.m_workedUnits;
}

bool LifeScheduler::Item::operator==(const Item& right) const
{
	return this->m_name == right.m_name && 
		this->m_priority == right.m_priority && 
		this->m_tag == right.m_tag;
}