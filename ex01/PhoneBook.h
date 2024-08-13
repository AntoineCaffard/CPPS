#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>


class PhoneBook {

	private :
		std::string contact_array[8];
		int			oldest_member;
	public:
		int		getOldestContactID();
		void	printContact(int id);
		void	addNewContact();
};


#endif PHONEBOOK_H
