/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:37:20 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/17 12:28:26 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
class Array
{
	private :
		unsigned int _size;
		T *_content;
	public :
		class IndexOutOfBoundsException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Error : Index is out of Bounds");
			};
		};
	public :
		Array() : _size(0), _content(NULL)
		{};
		
		Array(unsigned int n) : _size(n)
		{
			_content = new T[n];
		};

		Array(Array const &copy)
		{
			this->_size = copy._size;
			this->_content = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; ++i)
				this->_content[i] = copy._content[i];
		};
		
		Array &operator=(Array const &copy)
		{
			if (this != &copy)
			{
				if (this->_content != NULL)
					delete[] this->_content;
				this->_size = copy._size;
				this->_content = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; ++i)
					this->_content[i] = copy._content[i];
			}
			return *this;
		};
		
		virtual ~Array()
		{
			if (this->_content)
				delete[] _content;
		};
		
		unsigned int size()
		{
			return this->_size;
		}
		
		T &operator[](unsigned int N)
		{
			if (N >= _size || !_size)
				throw IndexOutOfBoundsException();
			return this->_content[N];
		}
};