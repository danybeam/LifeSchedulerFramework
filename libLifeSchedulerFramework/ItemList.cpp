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

#include <libLifeSchedulerFramework/ItemList.h>
#include <algorithm>
#include <stdexcept>

LifeScheduler::ItemList::ItemList()
{
}

LifeScheduler::ItemList::~ItemList()
{
}

void LifeScheduler::ItemList::AddItem(Item& newItem)
{
	m_itemVector.insert(m_itemVector.begin(), newItem);
}

void LifeScheduler::ItemList::RemoveItem(int index)
{
	m_itemVector.erase(m_itemVector.begin() + index);
}

void LifeScheduler::ItemList::RemoveItem(Item& itemRef)
{
	auto it = std::find(m_itemVector.begin(), m_itemVector.end(), itemRef);
	if (it == m_itemVector.end())
	{
		return;
	}
	m_itemVector.erase(it);
}

LifeScheduler::Item& LifeScheduler::ItemList::At(int index)
{
	return m_itemVector.at(index);
}

int LifeScheduler::ItemList::Size()
{
	return m_itemVector.size();
}

LifeScheduler::Item& LifeScheduler::ItemList::operator[](int index)
{
	return m_itemVector[index];
}

void LifeScheduler::ItemList::AddWorkUnits(unsigned int workUnits)
{
	m_itemVector[0].AddWorkUnits(workUnits);
	Sort();
}

void LifeScheduler::ItemList::Normalize()
{
	unsigned int normalizeValue = m_itemVector[0].GetWorkedUnits();
	for (auto& item : m_itemVector)
	{
		item.Normalize(normalizeValue);
	}
}

void LifeScheduler::ItemList::Sort()
{
	std::sort(m_itemVector.begin(), m_itemVector.end());
}
