#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.h"
# include "Utils.h"


class PhoneBook {

	private :
		Contact 	contact_array[8];
		int			current_index;
	public:
		PhoneBook();
		~PhoneBook();
		void	search();
		void	print();
		void	printContact(int id);
		void	addNewContact();
};

#endif
