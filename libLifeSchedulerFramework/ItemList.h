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
#pragma once
#include <vector>
#include <libLifeSchedulerFramework/Item.h>

namespace LifeScheduler
{
	class ItemList
	{
	public:
		// Constructor
		ItemList();
		virtual ~ItemList();

		// Operators on the list
		void AddItem(Item& newItem);
		void RemoveItem(int index);
		void RemoveItem(Item& itemRef);
		Item& At(int index);
		int Size();

		Item& operator[](int index);

		// Helper funcitons
		void AddWorkUnits(unsigned int workUnits);
		void Normalize();


	private:
		// Private helper functions
		void Sort();
		
		// Class members
		std::vector<Item> m_itemVector;
	};
}