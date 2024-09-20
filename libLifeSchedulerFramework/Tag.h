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

#include <string>

namespace LifeScheduler
{
	class Tag
	{
	public:
		// Public constants
		static const Tag c_emptyTag;

		// Constructors
		Tag();
		Tag(const char* name);
		Tag(std::string& name);
		Tag(const char* name, unsigned int priority);
		Tag(std::string& name, unsigned int priority);
		virtual ~Tag();

		// Getters and Setters
		void SetName(std::string& newName);
		std::string& GetName();
		void SetPriority(unsigned int newPriority);
		unsigned int GetPriority() const;

		// Operator overloading
		bool operator<(const Tag& right) const;
		bool operator>(const Tag& right) const;
		bool operator==(const Tag& right) const;

	private:
		std::string m_tagName;
		unsigned int m_priority;
	};
}