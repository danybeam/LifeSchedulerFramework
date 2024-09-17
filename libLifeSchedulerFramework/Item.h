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
#include<string>
#include <libLifeSchedulerFramework/Tag.h>

namespace LifeScheduler
{

	class Item
	{
	public:
		// Constructors
		Item();
		Item(std::string& name);
		Item(std::string& name, unsigned int m_priority);
		Item(std::string& name, unsigned int m_priority, Tag& m_tag);
		virtual ~Item();

		// Getters and Setters
		void SetPriority(unsigned int priority);
		unsigned int GetPriority() const;
		void SetName(std::string& name);
		std::string& GetName();
		void SetTag(Tag& tag);
		Tag& GetTag();

		unsigned int GetWorkedUnits() const;

		// Manipulate amount of worked units
		void AddWorkUnits(unsigned int workedUnits);
		void Normalize(unsigned int referenceAmount);

		// Operator overloading
		bool operator<(const Item& right) const;

	private:
		unsigned int m_priority;
		std::string m_name;
		Tag m_tag;
		unsigned int m_workedUnits = 0;
	};
}